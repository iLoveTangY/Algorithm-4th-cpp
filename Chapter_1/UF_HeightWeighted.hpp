#ifndef UF_HEIGHTWEIGHTED_H
#define  UF_HEIGHTWEIGHTED_H

#include "UF.hpp"

class UF_HeightWeighted : public UF
{
    public:
        UF_HeightWeighted(int N) : UF(N)
        {
            for(int i = 0; i < N; i++)
                height.push_back(0);
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
            if(height[i] < height[j])
            {
                id[i] = j;
            }
            else if(height[i] > height[j])
            {
                id[j] = i;
            }
            else
            {
                id[j] = i;
                height[i]++;
            }
            _count--;
        }


    private:
        vector<int> height;
};

#endif
