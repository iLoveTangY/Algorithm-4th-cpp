#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::ostream;
using std::vector;

class Date
{
    friend ostream& operator<<(ostream&, const Date&);
    friend bool operator==(const Date&, const Date&);
    friend bool operator!=(const Date&, const Date&);
    friend bool operator<(const Date&, const Date&);

    public:
        Date() = default;
        Date(int m, int d, int y) : _month(m), _day(d), _year(y) {}
        Date(string &date);
     
        int month()
        {
            return _month;
        }
        int day()
        {
            return _day;
        }
        int year()
        {
            return _year;
        }

    private:
        int _month;
        int _day;
        int _year;
};

//注意：当字符串为空时，也会返回一个空字符串  
void split(const string& s, const string& delim,vector<string>& ret);

#endif
