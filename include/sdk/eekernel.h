// Sony EE kernel (SDK 3.0), reconstructed: only what the game's code uses.
// The syscall wrappers are named in config/symbol_addrs_manual.txt from
// their syscall numbers.
#ifndef SDK_EEKERNEL_H
#define SDK_EEKERNEL_H

struct SemaParam {
    int currentCount;               // +0x00
    int maxCount;                   // +0x04
    int initCount;                  // +0x08
    int numWaitThreads;             // +0x0C
    unsigned int attr;              // +0x10
    unsigned int option;            // +0x14
};

// The EE timer 0 counter (T0_COUNT).
#define T0_COUNT ((volatile unsigned int *)0x10000000)

// Ends an interrupt handler (the SDK's macro).
#define ExitHandler() __asm__ volatile("sync.l; ei")

extern "C" {

int CreateSema(struct SemaParam *sema);
int DeleteSema(int sema_id);
int iSignalSema(int sema_id);
int WaitSema(int sema_id);
int PollSema(int sema_id);
void FlushCache(int operation);

}

#endif
