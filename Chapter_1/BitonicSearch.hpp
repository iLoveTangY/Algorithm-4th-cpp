#ifndef BITONICSEARCH_H
#define BITONICSEARCH_H

#include <vector>
#include "BinarySearch.hpp"

using std::vector;

class BitonicSearch
{
    public:
        int search(const vector<int> &a, int value)
        {
            int low = 0;
            int high = a.size() - 1;
            int maxIndex = 0;

            while(low < high)
            {
                int mid = (low + high) / 2;
                if(a[mid] > a[mid+1] && a[mid] > a[mid-1])
                {
                    maxIndex = mid;
                    break;
                }
                else if(a[mid] > a[mid+1])
                    high = mid;
                else if(a[mid] > a[mid-1])
                    low = mid + 1;
            }
            if(a[maxIndex] == value)
                return maxIndex;
            BinarySearch bs;
            int index = bs.rank(value, vector<int>(a.begin(), a.begin()+maxIndex));
            if(index != -1)
                return index;

            index = bs.rank(value, vector<int>(a.begin()+maxIndex, a.end()), true);
            if(index != -1)
                return maxIndex + index;
            return -1;

        };
};

#endif // BITONICSEARCH_H

