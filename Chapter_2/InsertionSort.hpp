#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Sort.hpp"

template<typename T>
class InsertionSort : public Sort<T>
{
    public:
        void sort(vector<T> &a) override
        {
            int N = a.size();

            for(int i = 1; i < N; i++)
            {
                for(int j = i; j > 0 && Sort<T>::less(a[j], a[j-1]); j--)
                    Sort<T>::exch(a, j, j-1);
            }
        }
};

#endif
