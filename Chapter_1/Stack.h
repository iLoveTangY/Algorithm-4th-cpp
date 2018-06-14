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
        // 默认构造函数
        Stack() = default;
        // 拷贝构造函数
        Stack(const Stack<T> &);
        // 拷贝赋值运算符
        const Stack& operator=(const Stack<T>&);
        bool isEmpty() const
        { return first == nullptr;
        }
        int size() const
        {
            return N;
        }
        bool isEmpty()
        {
            return N == 0;
        }
        // 返回但不弹出栈顶元素
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
                Node() = default;
                Node(Node &x)
                {
                    item = x.item;
                    next = x.next;
                }
                T item;
                shared_ptr<Node> next;
        };

        // 拷贝栈
        void copyStack(Stack &lhs, const Stack &rhs)
        {
            if(rhs.first != nullptr)
            {
                lhs.first = make_shared<Node>(*rhs.first);
                for(shared_ptr<Node> x = lhs.first; x->next != nullptr; x = x->next)
                    x->next = make_shared<Node>(*(x->next));
            }
            /*lhs.first = make_shared<Node>();*/
            //lhs.first->item = rhs.first->item;
            //shared_ptr<Node> p, q; 
            //p = lhs.first;
            //q = rhs.first->next;
            //while(q != nullptr)
            //{
                //shared_ptr<Node> tmp = make_shared<Node>();
                //tmp->item = q->item;
                //tmp->next = nullptr;
                //p->next = tmp;
                //p = p->next;
                //q = q->next;
            //}
            /*lhs.N = rhs.N;*/
        }
     
        shared_ptr<Node> first = nullptr;
        int N = 0;
};

template <typename T>
Stack<T>::Stack(const Stack &s)
{
    if(s.first != nullptr)
        copyStack(*this, s);
}

template <typename T>
const Stack<T>& Stack<T>::operator=(const Stack &rhs)
{
    if(rhs.first != nullptr)
        copyStack(*this, rhs);
    return *this;
}

#endif
