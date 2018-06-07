#include "Rational.hpp"
#include <iostream>

using namespace std;

Rational::Rational(long _num, long _den)
{
    long g = gcd(_num, _den);
    num = _num / g;
    den = _den / g;

    if(den < 0)
    {
        den = -den;
        num = -num;
    }
}

ostream& operator<<(ostream &os, const Rational &r)
{
    if(r.den == 1)
        cout << r.num;
    else
        os << r.num << "/" << r.den;
    return os;
}

bool operator<(const Rational &lhs, const Rational &rhs)
{
    long l = lhs.num * rhs.den;
    long r = lhs.den * rhs.num;
    if(l < r)
        return true;
    else
        return false;
}

bool operator==(const Rational &lhs, const Rational &rhs)
{
    long l = lhs.num * rhs.den;
    long r = lhs.den * rhs.num;
    return l == r;
}

bool operator!=(const Rational &lhs, const Rational &rhs)
{
    return lhs != rhs;
}

Rational operator+(const Rational &lhs, const Rational &rhs)
{
    long f = gcd(lhs.num, rhs.num);
    long g = gcd(lhs.den, rhs.den);

    Rational s((lhs.num/f)*(rhs.den/g)+(rhs.num/f)*(lhs.den/g), lhs.den*(rhs.den/g));
    s.num *= f;
    return s;
}

Rational operator-(const Rational &r)
{
    return Rational(-r.num, r.den);
}

Rational operator-(const Rational &lhs, const Rational &rhs)
{
    return lhs + (-rhs);
}

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    Rational c(lhs.num, rhs.den);
    Rational d(rhs.num, lhs.den);

    return Rational(c.num * d.num, c.den * d.den);
}

Rational operator/(const Rational &lhs, const Rational &rhs)
{
    return lhs * Rational(rhs.den, rhs.num);
}

int main(void)
{
    Rational x(1, 2);
    Rational y(1, 3);
    Rational z = x + y;
    cout << z << endl;

    x = Rational(8, 9);
    y = Rational(1, 9);
    z = x + y;
    cout << z << endl;

    x = Rational(1, 200000000);
    y = Rational(1, 300000000);
    z = x + y;
    cout << z << endl;

    x = Rational(4, 17);
    y = Rational(17, 4);
    z = x * y;
    cout << z << endl;

    x = Rational(1, 6);
    y = Rational(-4, -8);
    z = x - y;
    cout << z << endl;

    x = Rational(1, 3);
    y = Rational(1, 2);
    z = x / y;
    cout << z << endl;

    cout << boolalpha << (x < y) << endl;
    cout << boolalpha << (x == y) << endl;

    return 0;
}
