#ifndef THREESUMFAST_H
#define THREESUMFAST_H

#include <vector>
#include <algorithm>
#include "BinarySearch.hpp"

using std::sort;
using std::vector;

class ThreeSumFast
{
    public:
        static int count(vector<int> &a)
        {
            BinarySearch bs;
            sort(a.begin(), a.end());
            int N = a.size();
            int cnt = 0;
            for(int i = 0; i < N; i++)
                for(int j = i+1; j < N; j++)
                    if(bs.rank(-a[i]-a[j], a) > j)
                        cnt++;
            return cnt;
        }
};


#endif // THREESUMFAST_H

