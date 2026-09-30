// game/gamman.h (a guess from game/gamman.cpp): GamMan, the game manager,
// reduced to what decompiled code uses so far. GamMan and getVFchrListPtr
// are original names (linkonce copies of its inline methods); GamList and
// the rest are ours.
#ifndef GAME_GAMMAN_H
#define GAME_GAMMAN_H

// GamMan's character lists keep their nodes inside the object: a circular
// list whose sentinel is m_head. What the first 0x10 bytes hold is unknown.
template <class T> class GamList {
public:
    struct Node {
        Node *m_prev;       // +0x00
        Node *m_next;       // +0x04
        T m_data;           // +0x08
    };

    class iterator {
    public:
        Node *m_node;

        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        T &operator*() const { return m_node->m_data; }
        iterator operator++(int)
        {
            iterator tmp = *this;
            m_node = m_node->m_next;
            return tmp;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };

    unsigned char m_unk00[0x10];
    Node m_head;            // +0x10

    iterator begin() { return iterator(m_head.m_next); }
    iterator end() { return iterator(&m_head); }
};

class ObjStat;

class GamMan {
public:
    unsigned char m_unk00000[0x1DCC0];
    GamList<ObjStat *> m_vfchrList;     // +0x1DCC0

    GamList<ObjStat *> *getVFchrListPtr() { return &m_vfchrList; }
};

// The game manager, constructed by the main file's static initialiser.
extern GamMan D_007812C0;

#endif
