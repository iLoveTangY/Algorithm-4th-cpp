#ifndef FOURSUM_H
#define FOURSUM_H

#include <vector>

using std::vector;

class FourSum
{
    public:
        static int count(const vector<int> &a)
        {
            int N = a.size();
            int cnt = 0;
            for(int i = 0; i < N; i++)
                for(int j = i+1; j < N; j++)
                    for(int k = j+1; k < N; k++)
                        for(int l = k+1; l < N; l++)
                            if(a[i] + a[j] + a[k] + a[l] == 0)
                                cnt++;
            return cnt;
        }
};

#endif // FOURSUM_H

