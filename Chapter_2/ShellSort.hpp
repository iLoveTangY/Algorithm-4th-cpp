#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "Sort.hpp"

template<typename T>
class ShellSort : public Sort<T>
{
    public:
        void sort(vector<T> &a) override
        {
            int N = a.size();
            int h = 1;
            while(h < N/3)
                h = h * 3 + 1;
            while(h >= 1)
            {
                for(int i = h; i < N; i++)
                    for(int j = i; j >= h && Sort<T>::less(a[j], a[j-h]); j -= h)
                        Sort<T>::exch(a, j, j-h);
                h /= 3;
            }
        }
};

#endif
