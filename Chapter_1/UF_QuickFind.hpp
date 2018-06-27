#ifndef UF_QUICKFIND_H
#define UF_QUICKFIND_H

#include "UF.hpp"

class UF_QuickFind : public UF
{
    public:
        UF_QuickFind(int N) : UF(N) { }

        int find_id(int p) override
        {
            return id[p];
        }
        void union_componet(int p, int q) override
        {
            int pID = find_id(p);
            int qID = find_id(q);

            if(pID == qID)
                return;
            for(int i = 0; i < id.size(); i++)
                if(id[i] == pID)
                    id[i] = qID;
            _count--;
        }
};

#endif // UF_QUICKFIND_H

