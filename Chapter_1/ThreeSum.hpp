#ifndef THREE_SUM_H
#define THREE_SUM_H

#include <vector>

using std::vector;

class ThreeSum
{
    public:
        static int count(const vector<int> &a)
        {
            int N = a.size();
            int cnt = 0;
            for(int i = 0; i < N; i++)
                for(int j = i+1; j < N; j++)
                    for(int k = j+1; k < N; k++)
                        if(a[i] + a[j] + a[k] == 0)
                            cnt++;
            return cnt;
        }
};

#endif // THREE_SUM_H

