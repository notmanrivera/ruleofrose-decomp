// Imports the symbols recovered by tools/ror_symbols.py into a Rule of Rose
// (SLUS-214.48) program: C++ class namespaces, named functions, parameter
// types from the GCC2 mangled names, vtables typed as GCC2 vtable-entry
// arrays, and a plate comment with the demangled signature.
//
// Safe to re-run: names and signatures you set by hand (USER_DEFINED) are
// never overwritten. Run it before or after auto-analysis; running it first
// seeds ~2,500 function starts, which helps the analyzer.
//
// Signatures: methods get an explicit `this` (the r5900 cspec has no
// __thiscall), GCC2 destructors get their hidden `int __in_chrg` (bit 0 =
// delete after destroying), and return types are left to the decompiler
// because GCC2 mangling doesn't encode them. Unknown named types are created
// as empty placeholders under /RuleOfRose/types; ALL_CAPS types passed by
// value are assumed to be 4-byte enums. A function with a by-value struct
// of unknown size keeps its old signature.
//
// Input: <project>/symbols/ghidra_symbols.tsv, found relative to this script,
// or passed as the first script argument in headless mode.
//
//@category RuleOfRose
//@menupath Tools.Rule of Rose.Import Recovered Symbols

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.*;

public class ImportRoRSymbols extends GhidraScript {

	private static final String TAG = "[RoR] ";
	private static final CategoryPath TYPES = new CategoryPath("/RuleOfRose/types");
	private static final Pattern DIM = Pattern.compile("\\[(\\d+)\\]");
	private static final Map<String, DataType> BUILTIN = new HashMap<>();
	static {
		BUILTIN.put("void", VoidDataType.dataType);
		BUILTIN.put("bool", BooleanDataType.dataType);
		BUILTIN.put("char", CharDataType.dataType);
		BUILTIN.put("signed char", SignedCharDataType.dataType);
		BUILTIN.put("unsigned char", UnsignedCharDataType.dataType);
		BUILTIN.put("short", ShortDataType.dataType);
		BUILTIN.put("unsigned short", UnsignedShortDataType.dataType);
		BUILTIN.put("int", IntegerDataType.dataType);
		BUILTIN.put("unsigned int", UnsignedIntegerDataType.dataType);
		BUILTIN.put("long", LongDataType.dataType); // 8 bytes on the EE (see r5900.cspec)
		BUILTIN.put("unsigned long", UnsignedLongDataType.dataType);
		BUILTIN.put("long long", LongLongDataType.dataType);
		BUILTIN.put("unsigned long long", UnsignedLongLongDataType.dataType);
		BUILTIN.put("float", FloatDataType.dataType);
		BUILTIN.put("double", DoubleDataType.dataType);
		BUILTIN.put("long double", LongDoubleDataType.dataType);
		BUILTIN.put("wchar_t", WideCharDataType.dataType);
	}

	private final Map<String, Namespace> classCache = new HashMap<>();
	private DataTypeManager dtm;
	private DataType vtblEntry;
	private int sigsApplied, sigsSkipped;

	@Override
	protected void run() throws Exception {
		File tsv = locateInput();
		println("Reading " + tsv);
		dtm = currentProgram.getDataTypeManager();
		vtblEntry = defineVtableEntry();

		List<String[]> rows = new ArrayList<>();
		try (BufferedReader r = new BufferedReader(new FileReader(tsv))) {
			String line = r.readLine(); // header
			while ((line = r.readLine()) != null) {
				rows.add(line.split("\t", -1));
			}
		}
		// Create every class first so parameter types can refer to any of them.
		for (String[] f : rows) {
			if (!f[2].isEmpty()) {
				classNamespace(f[2]);
			}
		}

		int funcs = 0, vtables = 0, kept = 0, failed = 0;
		{
			for (String[] f : rows) {
				monitor.checkCancelled();
				// addr kind class name size source mangled signature params
				Address addr = toAddr(Long.parseLong(f[0], 16));
				String kind = f[1], cls = f[2], name = f[3], source = f[5];
				int size = Integer.parseInt(f[4], 16);
				Namespace ns = cls.isEmpty() ? currentProgram.getGlobalNamespace() : classNamespace(cls);
				try {
					if (kind.equals("vtable")) {
						applyVtable(addr, size, ns, name);
						vtables++;
					}
					else if (applyFunction(addr, ns, name)) {
						funcs++;
						if (!f[8].isEmpty()) {
							applySignature(getFunctionAt(addr), kind, ns, f[8]);
						}
					}
					else {
						kept++;
					}
					setTaggedComment(addr, f[7], source, f[6]);
				}
				catch (Exception e) {
					failed++;
					printerr(f[0] + " " + cls + "::" + name + ": " + e.getMessage());
				}
			}
		}
		println(String.format("Functions named: %d, signatures applied: %d (skipped %d), " +
			"vtables typed: %d, kept user names: %d, errors: %d",
			funcs, sigsApplied, sigsSkipped, vtables, kept, failed));
	}

	private File locateInput() throws Exception {
		String[] args = getScriptArgs();
		if (args.length > 0) {
			return new File(args[0]);
		}
		File guess = new File(getSourceFile().getParentFile().getParentFile().getFile(false),
			"symbols/ghidra_symbols.tsv");
		if (guess.isFile()) {
			return guess;
		}
		return askFile("Select symbols/ghidra_symbols.tsv", "Import");
	}

	/** Returns the class namespace for "A::B", creating it (and parents) if needed. */
	private Namespace classNamespace(String qualified) throws Exception {
		Namespace cached = classCache.get(qualified);
		if (cached != null) {
			return cached;
		}
		SymbolTable st = currentProgram.getSymbolTable();
		Namespace parent = currentProgram.getGlobalNamespace();
		for (String part : qualified.split("::")) {
			Namespace ns = st.getNamespace(part, parent);
			if (ns == null) {
				ns = st.createClass(parent, part, SourceType.IMPORTED);
			}
			parent = ns;
		}
		classCache.put(qualified, parent);
		return parent;
	}

	/** Creates/renames the function at addr. Returns false if a user name was kept. */
	private boolean applyFunction(Address addr, Namespace ns, String name) throws Exception {
		Function fn = getFunctionAt(addr);
		if (fn == null) {
			disassemble(addr);
			fn = createFunction(addr, null);
		}
		if (fn == null) {
			createLabel(addr, name, ns, true, SourceType.IMPORTED);
			return false;
		}
		if (fn.getSymbol().getSource() == SourceType.USER_DEFINED) {
			return false;
		}
		fn.setParentNamespace(ns);
		fn.setName(name, SourceType.IMPORTED);
		return true;
	}

	/** params: ';'-joined demangled types, or "-" for none. */
	private void applySignature(Function fn, String kind, Namespace ns, String params)
			throws Exception {
		if (fn == null || fn.getSignatureSource() == SourceType.USER_DEFINED) {
			return;
		}
		List<Variable> vars = new ArrayList<>();
		boolean varArgs = false;
		if (ns instanceof GhidraClass && !kind.equals("function")) {
			DataType cls = VariableUtilities.findOrCreateClassStruct((GhidraClass) ns, dtm);
			vars.add(new ParameterImpl("this", new PointerDataType(cls), currentProgram));
		}
		if (!params.equals("-")) {
			int i = 1;
			for (String t : params.split(";")) {
				if (t.equals("...")) {
					varArgs = true;
					continue;
				}
				DataType dt = parseType(t);
				if (dt == null) {
					sigsSkipped++;
					return;
				}
				vars.add(new ParameterImpl("param_" + i++, dt, currentProgram));
			}
		}
		if (kind.equals("dtor")) {
			vars.add(new ParameterImpl("__in_chrg", IntegerDataType.dataType, currentProgram));
		}
		fn.updateFunction(null, fn.getReturn(), vars,
			FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.IMPORTED);
		fn.setVarArgs(varArgs);
		sigsApplied++;
	}

	/**
	 * Parses a demangled type such as "const float[3][3] *" or "SND_PARAM * *".
	 * Returns null when the type can't be used safely (a by-value struct of
	 * unknown size).
	 */
	private DataType parseType(String t) {
		t = t.replaceAll("\\b(const|volatile)\\b", "").replaceAll("\\s+", " ").trim();
		if (t.contains("(*)")) {
			return PointerDataType.dataType; // function pointer
		}
		int k = indexOfAny(t, "*&[");
		String base = (k < 0 ? t : t.substring(0, k)).trim();
		String suffix = k < 0 ? "" : t.substring(k);
		boolean byValue = !suffix.contains("*") && !suffix.contains("&");

		DataType dt = baseType(base, byValue);
		if (dt == null) {
			return null;
		}
		List<Integer> dims = new ArrayList<>();
		Matcher m = DIM.matcher(suffix);
		while (m.find()) {
			dims.add(Integer.parseInt(m.group(1)));
		}
		for (int i = dims.size() - 1; i >= 0; i--) {
			dt = new ArrayDataType(dt, dims.get(i), dt.getLength());
		}
		for (char c : suffix.replaceAll("\\[\\d+\\]", "").toCharArray()) {
			if (c == '*' || c == '&') {
				dt = new PointerDataType(dt);
			}
		}
		return dt;
	}

	private DataType baseType(String name, boolean byValue) {
		DataType dt = BUILTIN.get(name);
		if (dt != null) {
			return dt;
		}
		Namespace ns = classCache.get(name);
		if (ns instanceof GhidraClass) {
			dt = VariableUtilities.findOrCreateClassStruct((GhidraClass) ns, dtm);
			return byValue && dt.isNotYetDefined() ? null : dt;
		}
		String[] parts = name.split("::");
		CategoryPath cat = TYPES;
		for (int i = 0; i < parts.length - 1; i++) {
			cat = new CategoryPath(cat, parts[i]);
		}
		String leaf = parts[parts.length - 1];
		dt = dtm.getDataType(cat, leaf);
		if (dt == null) {
			boolean enumLike = byValue && (leaf.matches("[A-Z0-9_]+") || leaf.equals("sub_kind"));
			dt = enumLike ? new EnumDataType(cat, leaf, 4) : new StructureDataType(cat, leaf, 0);
			dt = dtm.addDataType(dt, DataTypeConflictHandler.KEEP_HANDLER);
		}
		return byValue && dt.isNotYetDefined() ? null : dt;
	}

	private static int indexOfAny(String s, String chars) {
		for (int i = 0; i < s.length(); i++) {
			if (chars.indexOf(s.charAt(i)) >= 0) {
				return i;
			}
		}
		return -1;
	}

	/** GCC 2.x (non-thunk) vtable entry: { short delta; short index; void *pfn; } */
	private DataType defineVtableEntry() {
		CategoryPath cat = new CategoryPath("/RuleOfRose");
		StructureDataType s = new StructureDataType(cat, "gcc2_vtbl_entry", 0);
		s.add(ShortDataType.dataType, "delta", "this-pointer adjustment");
		s.add(ShortDataType.dataType, "index", "virtual base index");
		s.add(PointerDataType.dataType, "pfn", "entry 0: RTTI function; others: virtual methods");
		return dtm.addDataType(s, DataTypeConflictHandler.REPLACE_HANDLER);
	}

	private void applyVtable(Address addr, int size, Namespace ns, String name) throws Exception {
		createLabel(addr, name, ns, true, SourceType.IMPORTED);
		int n = size / vtblEntry.getLength();
		if (n > 0) {
			clearListing(addr, addr.add(size - 1));
			createData(addr, new ArrayDataType(vtblEntry, n, vtblEntry.getLength()));
		}
	}

	/** Plate comment owned by this script; never replaces a comment you wrote. */
	private void setTaggedComment(Address addr, String sig, String source, String mangled) {
		String existing = getPlateComment(addr);
		if (existing != null && !existing.startsWith(TAG)) {
			return;
		}
		StringBuilder c = new StringBuilder(TAG).append(source);
		if (!sig.isEmpty()) {
			c.append("\n").append(sig);
		}
		if (!mangled.isEmpty()) {
			c.append("\nmangled: ").append(mangled);
		}
		setPlateComment(addr, c.toString());
	}
}
