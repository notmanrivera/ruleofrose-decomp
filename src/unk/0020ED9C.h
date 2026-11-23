// unk/0020ED9C.h: script VM and context manager layouts recovered from
// unk/0020ED9C.cpp accesses.
#ifndef UNK_0020ED9C_H
#define UNK_0020ED9C_H

#include "target.h"

struct ScrBlock80 {
    unsigned char b[0x80];
}; // size 0x80

struct ScrBlock780 {
    unsigned char b[0x780];
}; // size 0x780

// One 0xB0-byte script execution context (embedded at ScrCtxNode + 0x10 and
// ScrMan + 0xDC30).
struct ScrCtx {
    int m_flags;                        // +0x00
    unsigned int m_id;                  // +0x04
    int m_pc;                           // +0x08
    int m_regSlot;                      // +0x0C
    char m_name[12];                    // +0x10..+0x1B
    int m_timer;                        // +0x1C
    int m_trgId;                        // +0x20
    int m_state;                        // +0x24
    int m_arg;                          // +0x28
    ScrBlock80 m_savedRegs;             // +0x2C..+0xAB
    ScrBlock780 *m_savedStack;          // +0xAC
}; // size 0xB0

struct ScrCtxNode {
    ScrCtxNode *m_prev;                 // +0x00
    ScrCtxNode *m_next;                 // +0x04
    int m_pad08;                        // +0x08
    int m_pad0C;                        // +0x0C
    ScrCtx m_ctx;                       // +0x10..+0xBF
} ALIGNED(16); // size 0xC0

struct ScrCtxChain {
    ScrCtxNode m_head;                  // +0x00..+0xBF
    int m_num;                          // +0xC0

    ScrCtxNode *pop_back()
    {
        ScrCtxNode *n = m_head.m_prev;
        ScrCtxNode *prev = n->m_prev;
        m_head.m_prev = prev;
        prev->m_next = &m_head;
        --m_num;
        return n;
    }

    void push_back(ScrCtxNode *theNode)
    {
        if (m_num == 0) {
            m_head.m_next = theNode;
            theNode->m_prev = &m_head;
        } else {
            m_head.m_prev->m_next = theNode;
            theNode->m_prev = m_head.m_prev;
        }
        theNode->m_next = &m_head;
        m_head.m_prev = theNode;
        ++m_num;
    }
}; // size 0xD0

struct ScrCtxList {
    ScrCtxChain m_free;                 // +0x00..+0xCF
    ScrCtxChain m_used;                 // +0xD0..+0x19F
    int m_pad1A0[8];                    // +0x1A0..+0x1BF
    void *m_poolBuf;                    // +0x1C0
    int m_pad1C4[3];                    // +0x1C4..+0x1CF

    void push_back(const ScrCtx &theData)
    {
        ScrCtxNode *n = m_free.pop_back();
        n->m_ctx = theData;
        m_used.push_back(n);
    }
}; // size 0x1D0

struct ScrHookItem {
    unsigned int a;                     // +0x00
    int b;                              // +0x04
    int c;                              // +0x08
    int d;                              // +0x0C
}; // size 0x10

struct ScrHookList {
    struct Node {
        Node *m_prev;                   // +0x00
        Node *m_next;                   // +0x04
        ScrHookItem m_data;             // +0x08..+0x17
    }; // size 0x18

    struct Chain {
        Node m_head;                    // +0x00..+0x17
        int m_num;                      // +0x18

        void push_back(Node *theNode)
        {
            if (m_num == 0) {
                m_head.m_next = theNode;
                theNode->m_prev = &m_head;
            } else {
                m_head.m_prev->m_next = theNode;
                theNode->m_prev = m_head.m_prev;
            }
            theNode->m_next = &m_head;
            m_head.m_prev = theNode;
            ++m_num;
        }

        void unlink(Node *theNode)
        {
            if (theNode == m_head.m_next) {
                Node *next = theNode->m_next;
                m_head.m_next = next;
                next->m_prev = &m_head;
            } else {
                Node *p = theNode->m_prev;
                if (theNode == m_head.m_prev) {
                    m_head.m_prev = p;
                    p->m_next = &m_head;
                } else {
                    p->m_next = theNode->m_next;
                    Node *prev = theNode->m_prev;
                    p = theNode->m_next;
                    p->m_prev = prev;
                }
            }
            --m_num;
        }
    }; // size 0x1C

    struct iterator {
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        ScrHookItem &operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };

    Chain m_free;                       // +0x00..+0x1B
    Chain m_used;                       // +0x1C..+0x37

    iterator begin() { return iterator(m_used.m_head.m_next); }
    iterator end() { return iterator(&m_used.m_head); }
    iterator erase(iterator thePos)
    {
        iterator next = thePos;
        ++next;
        Node *n = thePos.m_node;
        m_used.unlink(n);
        m_free.push_back(n);
        return next;
    }
}; // size 0x38

struct ScrMan {
    void *m_buf0;                       // +0x0000
    void *m_buf1;                       // +0x0004
    void *m_buf2;                       // +0x0008
    int m_unk0C;                        // +0x000C
    ScrCtxList *m_slot0;                // +0x0010
    ScrCtxList *m_slot1;                // +0x0014
    ScrCtxList *m_slot2;                // +0x0018
    unsigned char m_pad1C[0x24];        // +0x001C..+0x003F
    ScrCtxList m_queueList;             // +0x0040..+0x020F
    unsigned char m_pad210[0x5FF0];     // +0x0210..+0x61FF
    ScrCtxList m_doneList;              // +0x6200..+0x63CF
    unsigned char m_pad63D0[0x5FF0];    // +0x63D0..+0xC3BF
    ScrHookList m_hookList;             // +0xC3C0..+0xC3F7
    unsigned char m_padC3F8[0x1810];    // +0xC3F8..+0xDC07
    int m_slotBase[3];                  // +0xDC08..+0xDC13
    int m_padDC14[2];                   // +0xDC14..+0xDC1B
    char *m_varBufA;                    // +0xDC1C
    char *m_varBufB;                    // +0xDC20
    int m_flags;                        // +0xDC24
    int m_padDC28[2];                   // +0xDC28..+0xDC2F
    ScrCtx m_immCtx;                    // +0xDC30..+0xDCDF
    ScrCtx *m_savedCtx;                 // +0xDCE0
}; // size 0xDCF0 (16-byte aligned due to ScrCtxList)

struct ScrEntryBlock {
    unsigned char m_pad00[0x94];
    int m_insn94;                       // +0x94
    int m_insn98;                       // +0x98
    int m_insn9C;                       // +0x9C
    int m_insnA0;                       // +0xA0
    int m_insnA4;                       // +0xA4
    int m_insnA8;                       // +0xA8
    int m_insnAC;                       // +0xAC
    int m_insnB0;                       // +0xB0
};

struct ScrBindRec {
    unsigned char m_pad00[0x2C];
    unsigned int m_slotTag;             // +0x2C
    int m_id;                           // +0x30
    int m_entryOff;                     // +0x34
};

struct ScrBinHdr {
    int m_unk00[3];                     // +0x00..+0x0B
    int m_unk0C;                        // +0x0C
    int m_unk10;                        // +0x10
    int m_unk14;                        // +0x14
    int m_unk18;                        // +0x18
    int m_unk1C;                        // +0x1C
    int m_unk20;                        // +0x20
    int m_unk24;                        // +0x24
};

STATIC_ASSERT(sizeof(ScrCtx) == 0xB0, ScrCtx_size);
STATIC_ASSERT(sizeof(ScrCtxNode) == 0xC0, ScrCtxNode_size);
STATIC_ASSERT(sizeof(ScrCtxChain) == 0xD0, ScrCtxChain_size);
STATIC_ASSERT(sizeof(ScrCtxList) == 0x1D0, ScrCtxList_size);
STATIC_ASSERT(sizeof(ScrHookList) == 0x38, ScrHookList_size);

#endif // UNK_0020ED9C_H
