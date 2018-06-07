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
        int N = 0;  // 栈内真实数据大小

    public:
        FixedCapacityStackOfStrings(int cap)
        {
            a.reserve(cap);
        }

        bool isEmpty()
        {
            return N == 0;
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
