#ifndef BAG_H
#define BAG_H

/*
 * Bag类
 *
 */

#include <memory>

using std::shared_ptr;
using std::make_shared;

template <typename T>
class BagIterator;

template <typename T>
class Bag
{
    friend class BagIterator<T>;
    private:
        class Node
        {
            public:
                T item;
                shared_ptr<Node> next;
        };
        shared_ptr<Node> first = nullptr;


    public:
        void add(T item)
        {
            shared_ptr<Node> oldfirst = first;
            first = make_shared<Node>();
            first->item = item;
            first->next = oldfirst;
        }
        
        BagIterator<T> begin()
        {
            return BagIterator<T>(first);
        }
        
        BagIterator<T> end()
        {
            return BagIterator<T>(nullptr);
        }
};

template <typename T>
class BagIterator
{
    public:
        BagIterator() = default;
        BagIterator(const shared_ptr<class Bag<T>::Node> &_first) : first(_first) {}
        const T& operator*()
        {
            return first->item;
        }
        
        BagIterator& operator++()
        {
            first = first->next;
            return *this;
        }
        
        bool operator!=(const BagIterator<T>& rhs) const
        {
            return first != rhs.first;
        }

    private:
        shared_ptr<class Bag<T>::Node> first;
};

#endif
