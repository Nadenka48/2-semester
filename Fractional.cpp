#include "Fractional.h"
#include <cmath>
#include <cstdlib>
#include <limits>
void Fractional::reduce()
{
    if (this->den == 0)
        return;
    long a = std::abs(this->num);
    long b = std::abs(this->den);
    while (b != 0)
    {
        long temp = b;
        b = a % b;
        a = temp;
    }
    this->num = this->num / a;
    this->den = this->den / a;

    if (this->den < 0)
    {
        this->num = -this->num;
        this->den = -this->den;
    }
}
Fractional::Fractional(const long n, const long d) : num(n), den(d)
{
    if (this->den == 0)
    {
        std::cout << "Ошибка, знаменатель не может быть равен нулю\n";
        exit(1);
    }
    this->reduce();
}
Fractional::Fractional(const double val)
{
    this->den = 10000;
    this->num = round(val * this->den);
    this->reduce();
}
Fractional Fractional::operator+(const Fractional other) const
{
    long newNum = this->num * other.den + other.num * this->den;
    long newDen = this->den * other.den;
    return Fractional(newNum, newDen);
}
Fractional Fractional::operator-(const Fractional other) const
{
    long newNum = this->num * other.den - other.num * this->den;
    long newDen = this->den * other.den;
    return Fractional(newNum, newDen);
}
Fractional Fractional::operator*(const Fractional other) const
{
    long newNum = this->num * other.num;
    long newDen = this->den * other.den;
    return Fractional(newNum, newDen);
}
Fractional Fractional::operator/(const Fractional other) const
{
    if (other.num == 0)
    {
        std::cout << "Ошибка, деление на ноль\n";
        exit(1);
    }
    long newNum = this->num * other.den;
    long newDen = this->den * other.num;
    return Fractional(newNum, newDen);
}
Fractional Fractional::operator+(const double val) const
{
    Fractional temp(val);
    return *this + temp;
}
Fractional Fractional::operator-(const double val) const
{
    Fractional temp(val);
    return *this - temp;
}
Fractional Fractional::operator*(const double val) const
{
    Fractional temp(val);
    return *this * temp;
}
Fractional Fractional::operator/(const double val) const
{
    if (std::abs(val) < std::numeric_limits<double>::epsilon())
    {
        std::cout << "Ошибка, деление на ноль\n";
        exit(1);
    }
    Fractional temp(val);
    return *this / temp;
}
double Fractional::toDouble() const
{
    return (double)this->num / this->den;
}
Fractional operator+(const double val, const Fractional f) { return Fractional(val) + f; }
Fractional operator*(const double val, const Fractional f) { return Fractional(val) * f; }
std::ostream &operator<<(std::ostream &os, const Fractional f)
{
    os << f.num << "/" << f.den;
    return os;
}
std::istream &operator>>(std::istream &is, Fractional &f)
{
    is >> f.num >> f.den;
    if (is.fail() || f.den == 0)
    {
        std::cout << "Ошибка ввода\n";
        exit(1);
    }
    f.reduce();
    return is;
}
