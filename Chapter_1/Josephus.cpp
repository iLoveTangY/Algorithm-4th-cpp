#include <iostream>
#include "Queue.hpp"

using namespace std;

int main(void)
{
    Queue<int> queue;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        queue.enqueue(i);

    while(!queue.isEmpty())
    {
        for(int i = 0; i < m-1; i++)
            queue.enqueue(queue.dequeue());
        cout << queue.dequeue() << " " << endl;
    }
    cout << endl;

    return 0;
}
