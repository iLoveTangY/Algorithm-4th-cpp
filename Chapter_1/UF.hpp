#ifndef UF_H
#define UF_H

#include <vector>

using std::vector;

class UF
{
    protected:
        vector<int> id; // 连通分量 id
        int _count; // 连通分量数量

    public:
        UF(int N)
        {
            _count = N;
            for(int i = 0; i < N; i++)
                id.push_back(i);
        }
        int count_component()
        {
            return _count;
        }
        bool connected(int p, int q)
        {
            return find_id(p) == find_id(q);
        }
        virtual int find_id(int p) = 0;
        virtual void union_componet(int p, int q) = 0;
};

#endif // UF_H

