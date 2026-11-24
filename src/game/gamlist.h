// game/gamlist.h: Fixed-pool intrusive doubly-linked list templates used by
// GamMan (game/gamman.h) and ObjStat / GamTrgMan (game/gamtrg.h).
//
// Evidence: GamMan's constructor (func_001C05C0), ObjStat's constructor
// (func_001D87F4), GamTrgMan's constructor (func_001DD1E8), func_001DD414,
// func_001DDF48, and every iteration/erase loop across game/gamman.cpp and
// game/gamtrg.cpp.
#ifndef GAME_GAMLIST_H
#define GAME_GAMLIST_H

// A list whose nodes come from a fixed pool (inline in GamPool or heap-
// allocated in GamDynPool). Two circular chains, each a sentinel node plus a
// count: the free nodes, then the nodes in use.
// A chain is sizeof(Node) + 4 bytes (padded to Node's alignment), so with
// 4-byte elements m_used is at +0x10 and m_max at +0x20.
template <class T> class GamList {
public:
    struct Node {
        Node *m_prev;       // +0x00
        Node *m_next;       // +0x04
        T m_data;           // +0x08 (+0x10 when T is aligned to 16)
    };

    struct Chain {
        Node m_head;        // +0x00: the sentinel
        int m_num;          // nodes linked, the sentinel not counted

        void init()
        {
            m_num = 0;
            m_head.m_prev = &m_head;
            m_head.m_next = &m_head;
        }
        Node *pop_back()
        {
            Node *n = m_head.m_prev;
            Node *prev = n->m_prev;
            m_head.m_prev = prev;
            prev->m_next = &m_head;
            --m_num;
            return n;
        }
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
        void insert(Node *target, Node *n)
        {
            Node *p = target->m_prev;
            n->m_prev = p;
            p->m_next = n;
            n->m_next = target;
            target->m_prev = n;
            ++m_num;
        }
        // The middle case reuses one variable for both neighbours: that is
        // what puts m_next in the register m_prev was in (func_001CBB80).
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
        // Moves every node of another chain to the end of this one.
        void splice(Chain &theOther)
        {
            if (theOther.m_num != 0) {
                m_head.m_prev->m_next = theOther.m_head.m_next;
                Node *last = m_head.m_prev;
                last->m_next->m_prev = last;
                Node *tail = theOther.m_head.m_prev;
                m_head.m_prev = tail;
                tail->m_next = &m_head;
                m_num += theOther.m_num;
                theOther.init();
            }
        }
    };

    class iterator {
    public:
        Node *m_node;

        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        T &operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator tmp = *this;
            m_node = m_node->m_next;
            return tmp;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };

    Chain m_free;           // +0x00
    Chain m_used;           // +sizeof(Chain)
    int m_max;              // +2 * sizeof(Chain): the pool's size

    void initPool(Node *theNodes, int theMax)
    {
        m_free.init();
        m_used.init();
        m_max = theMax;
        int i = 0;
        Node *p = theNodes;
        for (; i < m_max; i++) {
            p->m_prev = p - 1;
            p->m_next = p + 1;
            p++;
        }
        m_used.init();
        m_free.m_head.m_next = theNodes;
        m_free.m_num = m_max;
        theNodes[0].m_prev = &m_free.m_head;
        m_free.m_head.m_prev = &m_free.m_head.m_next[m_free.m_num - 1];
        m_free.m_head.m_prev->m_next = &m_free.m_head;
    }

    iterator begin() { return iterator(m_used.m_head.m_next); }
    iterator end() { return iterator(&m_used.m_head); }
    int size() const { return m_used.m_num; }

    void push_back(const T &theData)
    {
        Node *n = m_free.pop_back();
        n->m_data = theData;
        m_used.push_back(n);
    }
    iterator insert(iterator where, const T &item)
    {
        Node *n = m_free.m_head.m_prev;
        Node *previous = n->m_prev;
        m_free.m_head.m_prev = previous;
        previous->m_next = &m_free.m_head;
        --m_free.m_num;
        n->m_data = item;
        m_used.insert(where.m_node, n);
        return where;
    }
    void clearUsed()
    {
        if (m_used.m_num != 0)
            m_free.splice(m_used);
    }
    void clear() { m_free.splice(m_used); }
    iterator erase(iterator thePos)
    {
        iterator next = thePos;
        ++next;
        Node *n = thePos.m_node;
        m_used.unlink(n);
        m_free.push_back(n);
        return next;
    }
};

// A GamList and its N nodes inside the object. The nodes start at the next
// multiple of 64, making the whole pool 64-byte aligned.
template <class T, int N> class GamPool : public GamList<T> {
public:
    typename GamList<T>::Node m_nodes[N] __attribute__((aligned(64)));

    void init() { this->initPool(m_nodes, N); }
};

// A GamList whose nodes are heap-allocated (e.g. GamTrgMan::m_ftbPool in
// func_001DD414 and the local ObjStat* list in func_001DDF48).
template <class T> class GamDynPool : public GamList<T> {
public:
    typename GamList<T>::Node *m_nodes __attribute__((aligned(64)));
    unsigned char m_padTail[60];

    GamDynPool(int theMax)
    {
        this->m_free.init();
        this->m_used.init();
        this->m_max = 0;
        typename GamList<T>::Node *pool = new typename GamList<T>::Node[theMax];
        this->m_max = theMax;
        m_nodes = pool;
        GamDynPool *self = this;
        for (int i = 0; i < self->m_max; i++) {
            pool[i].m_prev = &pool[i - 1];
            pool[i].m_next = &pool[i + 1];
        }
        self->m_used.init();
        self->m_free.m_head.m_next = pool;
        self->m_free.m_num = self->m_max;
        pool[0].m_prev = &self->m_free.m_head;
        typename GamList<T>::Node *last = &self->m_free.m_head.m_next[self->m_free.m_num - 1];
        self->m_free.m_head.m_prev = last;
        last->m_next = &self->m_free.m_head;
    }
    ~GamDynPool()
    {
        delete[] m_nodes;
    }
};

#endif
