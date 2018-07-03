#include "../Chapter_1/Transaction.hpp"
#include "ShellSort.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    vector<Transaction> a;
    a.push_back(Transaction("Turing 6/17/1990 644.08"));
    a.push_back(Transaction("Tarjan 3/26/2002 4121.85"));
    a.push_back(Transaction("Knuth 6/14/1999 288.34"));

    ShellSort<Transaction>().sort(a);
    ShellSort<Transaction>().show(a);

    return 0;
}
