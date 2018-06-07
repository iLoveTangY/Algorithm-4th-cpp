#ifndef QUEUE_H
#define QUEUE_H

/*
 * 先进先出队列
 */

#include <memory>

template <typename T>
class Queue
{
    private:
        class Node
        {
            public:
                T item;
                std::shared_ptr<Node> next;
        };
        std::shared_ptr<Node> first = nullptr;
        std::shared_ptr<Node> last = nullptr;
        int N;

    public:
        bool isEmpty() const
        {
            return first == nullptr;
        }

        int size()
        {
            return N;
        }

        void enqueue(T item);
        T dequeue();
};


#endif
