#include "Money.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
Money::Money(const int rub, const double kop)
{
    double total = rub * 100.0 + kop;
    this->kopeks = Fractional(total);
}
Money::Money(const double kop) : kopeks(kop)
{
}
Money::Money(const Fractional f) : kopeks(f)
{
}
Money Money::operator+(const Money other) const
{
    Fractional result = this->kopeks + other.kopeks;
    return Money(result);
}
Money Money::operator-(const Money other) const
{
    Fractional result = this->kopeks - other.kopeks;
    return Money(result);
}
double Money::operator/(const Money other) const
{
    if (other.toKopeks() == 0)
    {
        std::cout << "Ошибка, деление на ноль\n";
        exit(1);
    }
    Fractional result = this->kopeks / other.kopeks;
    return result.toDouble();
}
Money Money::multiply(const double val) const
{
    Fractional result = this->kopeks * val;
    return Money(result);
}
Money Money::divide(const double val) const
{
    if (val == 0)
    {
        std::cout << "Ошибка, деление на ноль\n";
        exit(1);
    }
    Fractional result = this->kopeks / val;
    return Money(result);
}
double Money::toKopeks() const
{
    return this->kopeks.toDouble();
}
std::ostream &operator<<(std::ostream &os, const Money m)
{
    double all = m.toKopeks();
    long rub = std::abs(all) / 100;
    double kop = std::fmod(std::abs(all), 100.0);

    if (all < 0)
    {
        os << "-";
    }
    os << rub << " руб. " << kop << " коп.";
    return os;
}
Money Money::read()
{
    int rub;
    double kop;
    std::cout << "Введите рубли и копейки через пробел: ";
    std::cin >> rub >> kop;
    if (std::cin.fail())
    {
        std::cout << "Ошибка ввода\n";
        exit(1);
    }
    return Money(rub, kop);
}
