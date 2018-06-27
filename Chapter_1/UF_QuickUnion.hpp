#ifndef UF_QUICKUNION_H
#define UF_QUICKUNION_H

#include "UF.hpp"

class UF_QuickUnion : public UF
{
public:
    UF_QuickUnion(int N) : UF(N) { }

    int find_id(int p) override
    {
        while (p != id[p])
            p = id[p];
        return p;
    }

    void union_componet(int p, int q) override
    {
        int pRoot = find_id(p);
        int qRoot = find_id(q);
        if(pRoot == qRoot)
            return;
        id[pRoot] = id[qRoot];

        _count--;
    }
};

#endif // UF_QUICKUNION_H
