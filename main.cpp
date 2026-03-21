#include <iostream>
#include "Cylinder.h"
/**
 * @brief Считывает значение, введенное с клавиатуры
 * @param report - строка информации
 * @return считанное значение
 */
double getValue(const std::string report);
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    double centerX = getValue("Введите координату X центра:");
    double centerY = getValue("Введите координату Y центра:");
    double centerZ = getValue("Введите координату Z центра:");
    double radius = getValue("Введите радиус цилиндра:");
    double height = getValue("Введите высоту цилиндра:");
    Cylinder myCylinder(centerX, centerY, centerZ, radius, height);
    std::cout << "Объем цилиндра равен: " << myCylinder.getV() << std::endl;
    double pointX = getValue("Введите координату X точки:");
    double pointY = getValue("Введите координату Y точки:");
    double pointZ = getValue("Введите координату Z точки:");
    if (myCylinder.PointInside(pointX, pointY, pointZ))
    {
        std::cout << "Точка (" << pointX << ", " << pointY << ", " << pointZ << ") находится внутри цилиндра." << std::endl;
    }
    else
    {
        std::cout << "Точка (" << pointX << ", " << pointY << ", " << pointZ << ") находится снраужи цилиндра." << std::endl;
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
