#include "Queue.hpp"
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void Queue<T>::enqueue(T item)
{
    shared_ptr<Node> oldlast = last;
    last = make_shared<Node>();
    last->item = item;
    last->next = nullptr;
    if(isEmpty())
        first = last;
    else
        oldlast->next = last;
    N++;
}

template <typename T>
T Queue<T>::dequeue()
{
    T item = first->item;
    first = first->next;
    if(isEmpty())
        last = nullptr;
    N--;
    return item;
}

int main(void)
{
    Queue<string> q;
    string item;

    while(cin >> item)
    {
        if(item != "-")
            q.enqueue(item);
        else if(!q.isEmpty())
            cout << q.dequeue() << " " << endl;
    }

    cout << "(" << q.size() << " left on queue)" << endl;

    return 0;
}
