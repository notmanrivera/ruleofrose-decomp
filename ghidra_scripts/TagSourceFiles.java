// Tags every function that references a leftover source-path string
// (e.g. "mag/maglife.cpp" from an assert) with that path, then writes
// symbols/function_sources.tsv. Because the linker lays out object files
// contiguously, runs of functions tagged with the same file mark the
// boundaries of the original .o files -- the basis for splitting the
// decomp into per-file C++ sources.
//
// References are found by decoding each function's raw MIPS words
// (lui + addiu/ori pairs), so this works with the plain MIPS language as
// well as the Emotion Engine one and doesn't depend on Ghidra having
// created the references itself. Run it after auto-analysis so function
// bodies exist.
//
// Input: <project>/symbols/source_strings.tsv (or first script argument).
//
//@category RuleOfRose
//@menupath Tools.Rule of Rose.Tag Source Files

import java.io.*;
import java.util.*;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.listing.BookmarkType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryAccessException;

public class TagSourceFiles extends GhidraScript {

	private static final String TAG = "[RoR] source: ";

	@Override
	protected void run() throws Exception {
		File root = getSourceFile().getParentFile().getParentFile().getFile(false);
		String[] args = getScriptArgs();
		File in = args.length > 0 ? new File(args[0]) : new File(root, "symbols/source_strings.tsv");
		File out = new File(in.getParentFile(), "function_sources.tsv");

		Map<Long, String> paths = new HashMap<>();
		try (BufferedReader r = new BufferedReader(new FileReader(in))) {
			String line = r.readLine();
			while ((line = r.readLine()) != null) {
				String[] f = line.split("\t");
				paths.put(Long.parseLong(f[0], 16), f[1]);
			}
		}

		Memory mem = currentProgram.getMemory();
		Set<Long> used = new HashSet<>();
		int tagged = 0, total = 0;
		try (PrintWriter w = new PrintWriter(new FileWriter(out))) {
			w.println("addr\tfunction\tsource_files");
			for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
				monitor.checkCancelled();
				total++;
				TreeSet<String> files = new TreeSet<>();
				for (AddressRange range : fn.getBody()) {
					scan(mem, range, paths, files, used);
				}
				if (files.isEmpty()) {
					continue;
				}
				tagged++;
				String list = String.join(", ", files);
				w.println(fn.getEntryPoint() + "\t" + fn.getName(true) + "\t" + list);
				currentProgram.getBookmarkManager().setBookmark(fn.getEntryPoint(),
					BookmarkType.NOTE, "RoR source", list);
				String c = fn.getComment();
				if (c == null || c.startsWith(TAG)) {
					fn.setComment(TAG + list);
				}
			}
		}
		println(String.format("%d functions, %d tagged; %d/%d source strings referenced -> %s",
			total, tagged, used.size(), paths.size(), out));
	}

	/** Decodes lui/addiu/ori pairs in one address range and collects string hits. */
	private void scan(Memory mem, AddressRange range, Map<Long, String> paths,
			Set<String> files, Set<Long> used) {
		long[] hi = new long[32];
		Arrays.fill(hi, -1);
		Address a = range.getMinAddress();
		Address end = range.getMaxAddress();
		while (a.compareTo(end) <= 0) {
			int word;
			try {
				word = mem.getInt(a);
			}
			catch (MemoryAccessException e) {
				return;
			}
			int op = word >>> 26, rs = (word >>> 21) & 31, rt = (word >>> 16) & 31;
			int imm = word & 0xffff;
			if (op == 0x0f) { // lui
				hi[rt] = ((long) imm) << 16;
			}
			else if ((op == 0x09 || op == 0x0d) && hi[rs] >= 0) { // addiu / ori
				long v = (hi[rs] + (op == 0x09 ? (short) imm : imm)) & 0xffffffffL;
				String p = paths.get(v);
				if (p != null) {
					files.add(p);
					used.add(v);
				}
			}
			if (a.getOffset() + 4 > end.getOffset()) {
				break;
			}
			a = a.add(4);
		}
	}
}
