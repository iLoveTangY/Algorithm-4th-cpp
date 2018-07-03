/*
 * 以Date类作为模板实现的Transaction
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <vector>

#include "Date.hpp"

using std::string;
using std::ostream;
using std::vector;

class Transaction
{
    friend ostream& operator<<(ostream&, const Transaction&);
    friend bool operator==(const Transaction&, const Transaction&);
    friend bool operator!=(const Transaction&, const Transaction&);
    friend bool whoOrder(const Transaction&, const Transaction&);
    friend bool whenOrder(const Transaction&, const Transaction&);
    friend bool amountOrder(const Transaction&, const Transaction&);
    friend bool operator<(const Transaction&, const Transaction&);
    friend bool operator>(const Transaction&, const Transaction&);

    private:
       string _who;
       Date _when;
       double _amount;

    public:
       Transaction() = default;
       Transaction(const string &who, const Date &when, const double amount) :
           _who(who), _when(when), _amount(amount) {}
       Transaction(const string &transaction);

       const string& who()
       {
           return _who;
       }

       const Date& when()
       {
           return _when;
       }

       double amount()
       {
           return _amount;
       }

};

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

bool operator<(const Transaction &lhs, const Transaction &rhs)
{
    return lhs._amount < rhs._amount;
}

bool operator>(const Transaction &lhs, const Transaction &rhs)
{
    return lhs._amount > rhs._amount;
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

#endif
