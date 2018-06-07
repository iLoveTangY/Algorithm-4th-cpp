/*
 * 定容栈
 */
#include "FixedCapacityStackOfStrings.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    FixedCapacityStackOfStrings s(100);
    
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
