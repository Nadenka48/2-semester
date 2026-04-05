#include <iostream>
#include "Money.h"
/**
 * @brief Считывает значение с клавиатуры
 * @param report строка информации
 * @return считанное значение
 */
double getValue(std::string report = "");
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    Fractional f1(1, 2);
    Fractional f2(2.5);
    Fractional f3 = f1 + f2;
    std::cout << "Дробь 1: " << f1 << std::endl;
    std::cout << "Дробь 2: " << f2 << std::endl;
    std::cout << "Сумма: " << f3 << std::endl;
    Money a(10, 50.0);
    Money b(250.0);
    std::cout << "Деньги A: " << a << std::endl;
    std::cout << "Деньги B: " << b << std::endl;
    Money c = a + b;
    std::cout << "Сумма A+B: " << c << std::endl;
    c = a - b;
    std::cout << "Разность A-B: " << c << std::endl;
    c = a.multiply(2.0);
    std::cout << "Умножение A*2: " << c << std::endl;
    double ratio = a / b;
    std::cout << "Отношение A/B: " << ratio << std::endl;
    std::cout << "Сумма A в копейках: " << a.toKopeks() << std::endl;
    Money userMoney = Money::read();
    std::cout << "Вы ввели: " << userMoney << std::endl;
    return 0;
}
double getValue(std::string report)
{
    std::cout << report;
    double value = 0;
    std::cin >> value;
    if (std::cin.fail())
    {
        std::cout << "Ошибка ввода\n";
        exit(1);
    }
    return value;
}
