/*
 * 下压栈，链表实现<智能指针>
 *
 * */

#ifndef STACK_H
#define STACK_H

#include <memory>

using std::shared_ptr;
using std::make_shared;

template <typename T>
class Stack
{
    public:
        bool isEmpty() const
        {
            return first == nullptr;
        }
        int size() const
        {
            return N;
        }
        bool isEmpty()
        {
            return N == 0;
        }
        T peak()
        {
            return first->item;
        }
        void push(T item)
        {
            shared_ptr<Node> oldfirst = first;
            first = make_shared<Node>();
            first->item = item;
            first->next = oldfirst;
            N++;
        }
        T pop()
        {
            T item = first->item;
            first = first->next;
            N--;
            return item;
        }

    private:
        class Node
        {
            public:
                T item;
                shared_ptr<Node> next;
        };
     
        shared_ptr<Node> first = nullptr;
        int N = 0;
};

#endif
