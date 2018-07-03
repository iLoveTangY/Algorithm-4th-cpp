#include "Transaction.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector<Transaction> a;
    a.push_back(Transaction("Turing 6/17/1990 644.08"));
    a.push_back(Transaction("Tarjan 3/26/2002 4121.85"));
    a.push_back(Transaction("Knuth 6/14/1999 288.34"));

    cout << "Unsorted" << endl;
    for(auto t : a)
        cout << t << endl;
    cout << endl;

    cout << "Sort by date" << endl;
    sort(a.begin(), a.end(), whenOrder);
    for(auto t : a)
        cout << t << endl;
    cout << endl;

    cout << "Sort by customer" << endl;
    sort(a.begin(), a.end(), whoOrder);
    for(auto t : a)
        cout << t << endl;
    cout << endl;

    cout << "Sort by amount" << endl;
    sort(a.begin(), a.end(), amountOrder);
    for(auto t : a)
        cout << t << endl;
    cout << endl;

    return 0;
}
