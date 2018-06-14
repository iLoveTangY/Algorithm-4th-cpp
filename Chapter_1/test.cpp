#include "Stack.h"
#include <iostream>

using namespace std;

int main(void)
{
    Stack<int> s;
    s.push(4);
    s.push(5);

    for(auto i : s)
        cout << i << endl;

    return 0;
}
