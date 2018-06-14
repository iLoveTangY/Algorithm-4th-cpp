/*
 * 下压栈，链表实现<智能指针>
 *
 * */

#ifndef STACK_H
#define STACK_H

#include <memory>
using std::shared_ptr;
using std::make_shared;

// 提前声明
template <typename T>
class StackIterator;

// 链表的下压栈实现
template <typename T>
class Stack
{
    friend class StackIterator<T>;

    public:
        // 默认构造函数
        Stack() = default;
        // 拷贝构造函数
        Stack(const Stack<T> &);
        // 拷贝赋值运算符
        const Stack& operator=(const Stack<T>&);
        bool isEmpty() const
        {
			return first == nullptr;
        }
        int size() const
        {
            return N;
        }
        // 返回但不弹出栈顶元素
        T peak() const
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

        // 范围for循环需要的 begin 函数
        StackIterator<T> begin()
        {
            return StackIterator<T>(first);
        }

        // 范围for循环函数需要的 end 函数
        StackIterator<T> end()
        {
            return StackIterator<T>();
        }

    private:
        // 链表数据结构的嵌套类
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
        }

        shared_ptr<Node> first = nullptr;
        int N = 0;
};

// 栈的迭代器类
template <typename T>
class StackIterator
{
    public:
        StackIterator() = default;
        StackIterator(shared_ptr<class Stack<T>::Node> &_first) : first(_first) {}

        // 如果要求能执行范围for循环，则必须实现下面三个函数
        const T& operator*() const
        {
            return first->item;
        }
        StackIterator operator++()
        {
            first = first->next;
            return *this;
        }
        bool operator!=(const StackIterator<T> &rhs) const
        {
            return first != rhs.first;
        }

    private:
        // 跟Stack中的first指向同样一块数据
        shared_ptr<class Stack<T>::Node> first = nullptr;
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
