#include "Stack.h"
#include <string>
#include <iostream>
#include <cctype>


using namespace std;


bool comparePriority(char lhs, char rhs)
{
    if(lhs == '(')
        return true;
    if ((lhs == '+' || lhs == '-') && (rhs == '/' || rhs == '*'))
        return true;
    else
        return false;
}


int main(void)
{
    Stack<char> stack;
    string str;
    getline(cin, str);

    for(size_t i = 0; i < str.size(); i++)
    {
        if(isdigit(str[i]))
            cout << str[i];
        else if(str[i] == '(')
            stack.push(str[i]);
        else if(str[i] == ')')
        {
            char c;
            while(!stack.isEmpty() && (c = stack.pop()) != '(')
                cout << c;
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if(stack.isEmpty())
                stack.push(str[i]);
            else
            {
                char c = stack.peak();
                if(comparePriority(c, str[i]))
                {
                    stack.push(str[i]);
                }
                else
                {
                    while(!stack.isEmpty() || !comparePriority(c, str[i]))
                    {
                        stack.pop();
                        cout << c;
                        c = stack.peak();
                    }
                }
            }
        }
        else
            cout << "Error Occur in parse character" << endl;
    }

    while(!stack.isEmpty())
        cout << stack.pop();

    cout << endl;

    return 0;
}
