#include <iostream>
#include <map>
#include <functional>
#include "Stack.h"

using namespace std;

int main(void)
{
    map<char, function<int(int, int)>> binops = {
        {'+', std::plus<int>()},
        {'-', std::minus<int>()},
        {'*', std::multiplies<int>()},
        {'/', std::divides<int>()},
    };

    Stack<int> stack;

    string str;
    cin >> str;
    for(size_t i = 0; i < str.size(); i++)
    {
        if(isdigit(str[i]))
            stack.push(str[i] - '0');
        else
            stack.push(binops[str[i]](stack.pop(), stack.pop()));
    }
    cout << stack.pop() << endl;

    return 0;
}
