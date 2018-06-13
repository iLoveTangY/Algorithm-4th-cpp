#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;

bool isBalanced(string s)
{
    Stack<char> stack;
    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack.push(s[i]);
        }
        else if(s[i] == ')')
        {
            if(stack.isEmpty())
            {
                return false;
            }
            if((stack.pop()) != '(')
            {
                return false;
            }
        }
        else if(s[i] == ']')
        {
            if(stack.isEmpty())
                return false;
            if(stack.pop() != '[')
                return false;
        }
        else if(s[i] == '}')
        {
            if(stack.isEmpty())
                return false;
            if(stack.pop() != '{')
                return false;
        }
    }
    return stack.isEmpty();
}

int main(void)
{
    string s;
    cin >> s;
    cout << boolalpha << isBalanced(s) << endl;
    return 0;
}
