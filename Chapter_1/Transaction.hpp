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

#endif
