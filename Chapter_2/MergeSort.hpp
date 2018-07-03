#ifndef MERGESORT_H
#define MERGESORT_H

#include "Sort.hpp"

template<typename T>
class MergeSort : public Sort<T>
{
    public:
        void merge(vector<T> &a, int lo, int mid, int hi)
        {
            for(int i = lo; i < hi; i++)
                aux[i] = a[i];
            int i = lo, j = mid+1;
            for(int k = lo; k < hi; k++)
            {
                if(i > mid)
                    a[k] = aux[j++];
                else if(j > hi)
                    a[k] = aux[i++];
                else if(Sort<T>::less(a[i], a[j]))
                    a[k] = a[i++];
                else
                    a[k] = a[j++];
            }
        }

        void sort(vector<T> &a)
        {
            aux = vector<T>(a.size(), 0);
            sort(a, 0, a.size()-1);
        }

    private:
        vector<T> aux; // 归并时的辅助数组
     
        void sort(vector<T> &a, int lo, int hi)
        {
            if(hi <= lo)
                return;
            int mid = lo + (hi - lo) / 2;
            sort(a, lo, mid);
            sort(a, mid+1, hi);
            merge(a, lo, mid, hi);
        }
};

#endif
