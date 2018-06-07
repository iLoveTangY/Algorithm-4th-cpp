/*
 * 模板定容栈
 *
 */
#ifndef FIXEDCAPACITYSTACKOFSTRINGS_H
#define FIXEDCAPACITYSTACKOFSTRINGS_H

#include <vector>
#include <string>

template <typename T>
class FixedCapacityStack
{
    private:
        std::vector<T> a;
        int N = 0;  // 栈内真实数据大小

    public:
        FixedCapacityStack(int cap)
        {
            a.reserve(cap);
        }

        bool isEmpty() const
        {
            return N == 0;
        }

        int size() const
        {
            return N;
        }

        void push(T item)
        {
            a.push_back(item);
            N++;
        }

        T pop()
        {
            return a[--N];
        }
};

#endif
