#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using std::ostream;

class Rational
{
    friend ostream& operator<<(ostream&, const Rational&);
    friend bool operator<(const Rational&, const Rational&);
    friend bool operator==(const Rational&, const Rational&);
    friend bool operator!=(const Rational&, const Rational&);
    friend Rational operator+(const Rational&, const Rational&);
    friend Rational operator-(const Rational&);
    friend Rational operator-(const Rational&, const Rational&);
    friend Rational operator*(const Rational&, const Rational&);
    friend Rational operator/(const Rational&, const Rational&);

    public:
        Rational() = default;
        Rational(long numerator, long denominator);
        
        long numerator()
        {
            return num;
        }
        long denominator()
        {
            return den;
        }
        
        operator double() const
        {
            return static_cast<double>(num) / den;
        }

        Rational abs()
        {
            if(num >= 0)
                return *this;
            else
                return -(*this);
        }


    private:
        

        long num; // 分子
        long den; // 分母
};

long gcd(long m, long n)
{
    if(m < 0)
        m = -m;
    if(n < 0)
        n = -n;
    if(n == 0)
        return m;
    else
        return gcd(n, m%n);
}

#endif
