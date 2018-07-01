#include<iostream>
#include <vector>
#include"ShellSort.hpp"

using namespace std;

int main(void)
{
    string n;
    vector<string> svec;
    while(cin >> n)
        svec.push_back(n);

    ShellSort<string> s;
    s.sort(svec);
    s.show(svec);

    return 0;
}
