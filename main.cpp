#include <iostream>
#include "point.h"
#include "cylinder.h"
/**
 * @brief Считывает значение, введенное с клавиатуры
 * @param report - строка информации
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
    double cx = getValue("Введите координату X центра: ");
    double cy = getValue("Введите координату Y центра: ");
    double cz = getValue("Введите координату Z центра: ");
    Point center(cx, cy, cz);
    double r = getValue("Введите радиус: ");
    double h = getValue("Введите высоту: ");
    Cylinder myCylinder(center, r, h);
    std::cout << "\nОбъем цилиндра равен: " << myCylinder.getVolume() << std::endl;
    double px = getValue("Введите X проверяемой точки: ");
    double py = getValue("Введите Y проверяемой точки: ");
    double pz = getValue("Введите Z проверяемой точки: ");
    Point p(px, py, pz);
    if (myCylinder.PointInside(p))
    {
        std::cout << "Точка находится ВНУТРИ цилиндра." << std::endl;
    }
    else
    {
        std::cout << "Точка находится СНАРУЖИ цилиндра." << std::endl;
    }

    return 0;
}
double getValue(std::string report)
{
    std::cout << report;
    double value = 0;
    std::cin >> value;
    if (std::cin.fail())
    {
        std::cout << "Ошибка, введено неверное значение!\n";
        exit(1);
    }
    return value;
}
