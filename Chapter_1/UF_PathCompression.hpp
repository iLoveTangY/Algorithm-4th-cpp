#ifndef UF_PATHCOMPRESSION_H
#define UF_PATHCOMPRESSION_H

#include "WeightedQuickUnion.hpp"

class UF_PathCompression : public WeightedQuickUnion
{
    public:
        UF_PathCompression(int N) : WeightedQuickUnion(N) {}
        int find_id(int p) override
        {
            int root = p;
            while(root != id[root])
                root = id[root];

            while(p != root)
            {
                int newp = id[p];
                id[p] = root;
                p = newp;
            }

            return root;
        }
};

#endif
