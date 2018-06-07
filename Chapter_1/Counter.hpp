/*
 * 计数器
 */

#ifndef COUNTER_H
#define COUNTER_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Counter
{
    friend ostream& operator<<(ostream &os, const Counter &c);
    public:
        Counter(string id) : name(id) {}
     
        Counter& operator++(int)
        {
            count++;
            return *this;
        }
      
        Counter& operator++()
        {
            count++;
            return *this;
        }
     
      
        int tally()
        {
            return count;
        }
     
    private:
        const string name;
        int count = 0;
};

    ostream& operator<<(ostream &os, const Counter &c)
    {
        os << c.count << " " << c.name;
        return os;
    }



#endif
