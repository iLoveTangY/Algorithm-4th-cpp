#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isCircularRotation(const string &s1, const string &s2)
{
    return (s1.size() == s2.size()) && ((s1+s1).find(s2) != string::npos);
}

int main(void)
{
    string s1 = "ACTGACG";
    string s2 = "AGGGGGG";

    cout << boolalpha << isCircularRotation(s1, s2) << endl;

    return 0;
}
