#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Sort.hpp"

template<typename T>
class SelectionSort : public Sort<T>
{
    public:
        void sort(vector<T> &a) override
        {
            int N = a.size();
            for(int i = 0; i < N; i++)
            {
                int m = i;
                for(int j = i+1; j < N; j++)
                    if(Sort<T>::less(a[j], a[m]))
                        m = j;

                Sort<T>::exch(a, i, m);
            }
        }
};

#endif
