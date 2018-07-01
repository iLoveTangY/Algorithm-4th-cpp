#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template <typename T>
class Sort
{
    public:
        virtual void sort(vector<T> &a) = 0;
        virtual bool isSorted(vector<T> &a)
        {
            for(int i = 1; i < a.size(); i++)
                if(less(a[i], a[i-1]))
                    return false;
        }
        void show(const vector<T> &a)
        {
            for(auto t : a)
                cout << t << " ";
            cout << endl;
        }

    protected:
        bool less(const T &v, const T &w)
        {
            return v < w;
        }
        void exch(vector<T> &a, int i, int j)
        {
            T t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
};

#endif
