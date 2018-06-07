#include "Transaction.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


ostream& operator<<(ostream &os, const Transaction &t)
{
    os << t._who << " " << t._when << " " << t._amount;
    return os;
}

bool operator==(const Transaction &lhs, const Transaction &rhs)
{
    return (lhs._amount == rhs._amount) && (lhs._when == rhs._when) && (lhs._who == rhs._who);
}

bool operator!=(const Transaction &lhs, const Transaction &rhs)
{
    return !(lhs == rhs);
}

bool whoOrder(const Transaction &t1, const Transaction &t2)
{
    return t1._who < t2._who;
}

bool whenOrder(const Transaction &t1, const Transaction &t2)
{
    return t1._when < t2._when;
}

bool amountOrder(const Transaction &t1, const Transaction &t2)
{
    return t1._amount < t2._amount;
}

Transaction::Transaction(const string &transaction)
{
    vector<string> a;
    split(transaction, " ", a);
    _who = a[0];
    _when = Date(a[1]);
    _amount = stof(a[2]);
}

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
