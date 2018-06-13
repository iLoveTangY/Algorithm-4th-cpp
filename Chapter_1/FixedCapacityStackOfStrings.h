/*
 * 定容栈
 *
 * */
#ifndef FIXEDCAPACITYSTACKOFSTRINGS_H
#define FIXEDCAPACITYSTACKOFSTRINGS_H

#include <vector>
#include <string>

class FixedCapacityStackOfStrings
{
    private:
        std::vector<std::string> a;
        int cap; // 栈的容量
        int N = 0;  // 栈内真实数据大小

    public:
        FixedCapacityStackOfStrings(int _cap)
        {
            cap = _cap;
            a.reserve(_cap);
        }

        bool isEmpty()
        {
            return N == 0;
        }

        bool isFull()
        {
            return N == cap;
        }

        int size()
        {
            return N;
        }

        void push(std::string item)
        {
            a.push_back(item);
            N++;
        }

        std::string pop()
        {
            return a[--N];
        }
};

#endif
