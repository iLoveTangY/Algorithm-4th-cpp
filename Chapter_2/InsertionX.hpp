#ifndef INSERTIONX_H
#define INSERTIONX_H

#include "Sort.hpp"

template<typename T>
class InsertionX : public Sort<T>
{
    public:
        void sort(vector<T> &a)
        {
            int N = a.size();
            int minIndex = 0;
            for(int i = 1; i < N; i++)
                if(Sort<T>::less(a[i], a[minIndex]))
                    minIndex = i;
            Sort<T>::exch(a, 0, minIndex);

            for(int i = 1; i < N; i++)
                for(int j = 1; Sort<T>::less(a[j], a[j-1]); j--)
                    Sort<T>::exch(a, j, j-1);
        }
};

#endif
