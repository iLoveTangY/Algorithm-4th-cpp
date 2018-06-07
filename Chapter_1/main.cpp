/*
 * 栈的链表实现
 */
#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    Stack<string> s;
    
    string item;
    while(cin >> item)
    {
        if(item != "-")
        {
            s.push(item);
        }
        else if(!s.isEmpty()) 
        {
            cout << s.pop() << endl;
        }
    }

    cout << "(" << s.size() << " left on stack)" << endl;

    return 0;
}
