#ifndef LOCALMINIMA_H
#define LOCALMINIMA_H

#include <vector>

using std::vector;

class LocalMinima
{
public:
    int findLocalMinima(const vector<int> &a)
    {
        int N = a.size();
        if(N == 1)
            return 0;
        if(a[0] < a[1])
            return 0;
        if(a[N-1] < a[N-2])
            return N-1;
        int low = 0, high = N - 1;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(a[mid-1] > a[mid] && a[mid] < a[mid+1])
                return mid;
            else if(a[mid-1] < a[mid+1])
                high = mid - 1;
            else if(a[mid+1] < a[mid-1])
                low = mid + 1;
        }
        return -1;
    }
};

#endif // LOCALMINIMA_H

