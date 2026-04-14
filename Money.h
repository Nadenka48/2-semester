#pragma once
#include "Fractional.h"
/**
 * @brief Класс Деньги
 */
class Money
{
private:
    Fractional kopeks;

public:
    /**
     * @brief Конструктор, принимающий рубли и копейки
     * @param rub рубли
     * @param kop копейки
     */
    Money(const int rub = 0, const double kop = 0.0);
    /**
     * @brief Конструктор, принимающий только копейки
     * @param kop копейки
     */
    Money(const double kop);
    /**
     * @brief Конструктор, принимающий тип Дробное число
     * @param f дробное число
     */
    Money(const Fractional f);
    /**
     * @brief Конструктор копирования
     * @param other объект для копирования
     */
    Money(const Money &other);
    /**
     * @brief Конструктор перемещения
     * @param other объект для перемещения
     */
    Money(Money &&other);
    /**
     * @brief Оператор присваивания копированием
     * @param other присваиваемый объект
     * @return ссылка на текущий объект
     */
    Money &operator=(const Money &other);
    /**
     * @brief Оператор присваивания перемещением
     * @param other присваиваемый объект
     * @return ссылка на текущий объект
     */
    Money &operator=(Money &&other);
    /**
     * @brief Оператор сложения двух объектов класса Деньги
     * @param other вторая денежная сумма
     * @return результат сложения
     */
    Money operator+(const Money other) const;
    /**
     * @brief Оператор вычитания двух объектов класса Деньги
     * @param other вторая денежная сумма
     * @return результат вычитания
     */
    Money operator-(const Money other) const;
    /**
     * @brief Оператор деления двух объектов класса Деньги
     * @param other вторая денежная сумма
     * @return результат деления (коэффициент)
     */
    double operator/(const Money other) const;
    /**
     * @brief Метод умножения на вещественное число
     * @param val число для умножения
     * @return рассчитанная денежная сумма
     */
    Money multiply(const double val) const;
    /**
     * @brief Метод деления на вещественное число
     * @param val число для деления
     * @return рассчитанная денежная сумма
     */
    Money divide(const double val) const;
    /**
     * @brief Метод преобразования денежной суммы в число (в копейки)
     * @return сумма в копейках
     */
    double toKopeks() const;
    /**
     * @brief Статический метод чтения объекта из стандартного потока
     * @return считанный объект Деньги
     */
    static Money read();
    friend std::ostream &operator<<(std::ostream &os, const Money m);
};
