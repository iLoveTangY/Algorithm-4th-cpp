#ifndef WEIGHTEDQUICKUNION_H
#define WEIGHTEDQUICKUNION_H

#include "UF.hpp"

class WeightedQuickUnion : public UF
{
    public:
        WeightedQuickUnion(int N) : UF(N)
        {
            for(int i = 0; i < N; i++)
                sz.push_back(1);
        }

        int find_id(int p) override
        {
            while(p != id[p])
                p = id[p];
            return p;
        }

        void union_componet(int p, int q) override
        {
            int i = find_id(p);
            int j = find_id(q);
            if(i == j)
                return;
            // 将较小的树连接到较大的树上面
            if(sz[i] < sz[j])
            {
                id[i] = j;
                sz[j] += sz[i];
            }
            else
            {
                id[j] = i;
                sz[i] += sz[j];
            }
            _count--;
        }

    private:
        vector<int> sz;  // 各个根节点所对应的分量大小
};

#endif // WEIGHTEDQUICKUNION_H
