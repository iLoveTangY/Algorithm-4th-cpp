#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

using std::vector;

class BinarySearch
{
    public:
        static int rank(int key, const vector<int> &a, bool r = false)
        {
            int lo = 0;
            int hi = a.size() - 1;
            while(lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if(!r)
                {
                    if(key < a[mid])
                        hi = mid - 1;
                    else if(key > a[mid])
                        lo = mid + 1;
                    else
                        return mid;
                }
                else
                {
                    if(key > a[mid])
                        hi = mid - 1;
                    else if(key < a[mid])
                        lo = mid + 1;
                    else
                        return mid;
                }
            }
            return -1;
        }
};

#endif // BINARYSEARCH_H

