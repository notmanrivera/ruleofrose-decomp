// Compiler-identification candidates. Each function below is a reconstruction
// of an inline method emitted in SLUS_214.48. tools/compiler_id.py compiles
// this file with every EE-GCC build and flag set and compares the result
// instruction by instruction (relocations aside).
//
// Result: all three functions match byte for byte with ee-gcc2.96 -Os.
//
// Layouts are only as complete as these three functions need. The #line
// directives reproduce the original __FILE__/__LINE__ that the asserts pass.

// FUN_00215a30: printf("Assertion Failed: %s(%d)   %s\n", file, line, expr),
// then spins forever. Real name unknown.
extern void ror_assert(const char *file, int line, const char *expr);
#define ASSERT(e) ((e) ? (void)0 : ror_assert(__FILE__, __LINE__, #e))

class DogMotionBlend {
public:
	struct Motion {
		int unk0;
		int *link;          // +0x04
		char unk8[0x18];
	};                      // 0x20 bytes

	char unk0[0x18];
	int m_max_motion;       // +0x18
	Motion *m_motion;       // +0x1C
	char unk20[0x10];       // pads to 0x30 so DogActor::m_sub lands at 0x214

	int getLinkTime(int n);
};

class DogActor {
public:
	struct Sub {
		float speed;
		char unk4[0x2C];
	};                      // 0x30 bytes

	char unk0[0x1E4];
	DogMotionBlend m_blend; // +0x1E4
	Sub m_sub[5];           // +0x214

	void setMotionSpeedSub(int n, float speed);
	float getMotionSpeedSub(int n) const;
	int getMotionLinkTime(int n);
};

#line 123 "dog/dogmotionblend.h"
inline int DogMotionBlend::getLinkTime(int n) { ASSERT(m_motion); ASSERT(n>=0 && n<m_max_motion); return *m_motion[n].link; }

// target: setMotionSpeedSub__8DogActorif.s (0x00281030)
#line 233 "dog/dogactor.h"
void DogActor::setMotionSpeedSub(int n, float speed) { ASSERT(n>=0 && n<=4); m_sub[n].speed = speed; }

// target: getMotionSpeedSub__C8DogActori.s (0x0028109C)
#line 234 "dog/dogactor.h"
float DogActor::getMotionSpeedSub(int n) const { ASSERT(n>=0 && n<=4); const Sub &s = m_sub[n]; return s.speed; }

// target: getMotionLinkTime__8DogActori.s (0x00281114)
#line 300 "dog/dogactor.h"
int DogActor::getMotionLinkTime(int n) { return m_blend.getLinkTime(n); }
