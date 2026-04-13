#pragma once
#include <iostream>
/
 * @brief Класс Дробное число для точных вычислений
 */
class Fractional
{
private:
    long num;
    long den;

    /
     * @brief Метод сокращения дроби
     */
    void reduce();

public:
    /
     * @brief Конструктор, принимающий два целых числа (целая и дробная часть)
     * @param n числитель
     * @param d знаменатель
     */
    Fractional(const long n = 0, const long d = 1);
    /
     * @brief Конструктор, принимающий вещественное число
     * @param val вещественное число
     */
    Fractional(const double val);
    /
     * @brief Оператор сложения двух дробных чисел
     * @param other второе дробное число
     * @return результат сложения
     */
    Fractional operator+(const Fractional other) const;
    /
     * @brief Оператор вычитания двух дробных чисел
     * @param other второе дробное число
     * @return результат вычитания
     */
    Fractional operator-(const Fractional other) const;
    /
     * @brief Оператор умножения двух дробных чисел
     * @param other второе дробное число
     * @return результат умножения
     */
    Fractional operator*(const Fractional other) const;
    /
     * @brief Оператор деления двух дробных чисел
     * @param other второе дробное число
     * @return результат деления
     */
    Fractional operator/(const Fractional other) const;
    /
     * @brief Оператор сложения дробного и вещественного числа
     * @param val вещественное число для прибавления
     * @return результат сложения
     */
    Fractional operator+(const double val) const;
    /
     * @brief Оператор вычитания вещественного числа из дроби
     * @param val вещественное число для вычитания
     * @return результат вычитания
     */
    Fractional operator-(const double val) const;
    /
     * @brief Оператор умножения дроби на вещественное число
     * @param val вещественное число для умножения
     * @return результат умножения
     */
    Fractional operator*(const double val) const;
    /
     * @brief Оператор деления дроби на вещественное число
     * @param val вещественное число для деления
     * @return результат деления
     */
    Fractional operator/(const double val) const;
    /**
     * @brief Метод перевода дроби в вещественное число
     * @return рассчитанное значение
     */
    double toDouble() const;
    friend Fractional operator+(const double val, const Fractional f);
    friend Fractional operator*(const double val, const Fractional f);
    friend std::ostream &operator<<(std::ostream &os, const Fractional f);
    friend std::istream &operator>>(std::istream &is, Fractional &f);
};
