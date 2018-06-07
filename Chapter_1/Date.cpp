#include "Date.hpp"
#include <string>

using namespace std;

bool operator==(const Date &lhs, const Date &rhs)
{
    return lhs._day == rhs._day && lhs._month == rhs._month
        && lhs._year == rhs._year;
}

bool operator!=(const Date &lhs, const Date &rhs)
{
    return !(lhs == rhs);
}

ostream& operator<<(ostream &os, const Date &rhs)
{
    os << rhs._month << "/" << rhs._day << "/" << rhs._year;
    return os;
}

bool operator<(const Date &lhs, const Date &rhs)
{
    if(lhs._year < rhs._year)
        return true;
    else if(lhs._year > rhs._year)
        return false;
    if(lhs._month < rhs._month)
        return true;
    else if(lhs._month > rhs._month)
        return false;
    if(lhs._day < rhs._day)
        return true;
    else if(lhs._day > rhs._day)
        return false;
    return false;
}

//注意：当字符串为空时，也会返回一个空字符串  
void split(const string& s, const string& delim, vector<string>& ret)  
{  
    size_t last = 0;  
    size_t index=s.find_first_of(delim,last);  
    while (index!=std::string::npos)  
    {  
        ret.push_back(s.substr(last,index-last));  
        last=index+1;  
        index=s.find_first_of(delim,last);  
    }  
    if (index-last>0)  
    {  
        ret.push_back(s.substr(last,index-last));  
    }  
}  

Date::Date(string &date)
{
    vector<string> sv;
    split(date, "/", sv);
    _month = stoi(sv[0]);
    _day = stoi(sv[1]);
    _year = stoi(sv[2]);
}
