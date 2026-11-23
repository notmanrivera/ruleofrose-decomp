// task/cmnitask.h: shared CmnITask base interface and TskVec4 vector type.
//
// Evidence:
// - Inheritance and vtable layout: notes/class_hierarchy.txt and
//   asm/data/vtbl/_vt_*Tsk*.data.s. CmnITask has 5 virtual slots (1..5):
//   get_task_type (get_task_type__8CmnITask), pause (pause__8CmnITaskb),
//   init, exec (exec__11PLScenePlayiiPv), term. CmnITask has no virtual
//   destructor (TskTest has only 6 vtable slots [0..5] and func_001E7C7C
//   calls __builtin_delete directly); most subclasses add virtual ~Class()
//   at slot 6.
// - Inline methods: linkonce copies in asm/inline/ (0x0028A694, 0x00290508).
#ifndef TASK_CMNITASK_H
#define TASK_CMNITASK_H

struct TskVec4 {
    float f[4];
} __attribute__((aligned(16)));

class CmnITask {
public:
    virtual int get_task_type() { return 0; }
    virtual void pause(bool) {}
    virtual void init() = 0;
    virtual int exec(int, int, void *) = 0;
    virtual void term() = 0;
};

#endif
