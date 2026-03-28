#pragma once
#include "point.h"
/**
 * @brief Класс Цилиндр
 */
class Cylinder
{
private:
    /**
     * @brief Центр нижнего основания
     */
    Point center;
    /**
     * @brief Радиус основания
     */
    double radius;
    /**
     * @brief Высота цилиндра
     */
    double height;
public:
    /**
     * @brief Конструктор
     * @param c - координата центра основания (Точка)
     * @param r - радиус основания
     * @param h - высота цилиндра
     */
    Cylinder(Point c, double r, double h);
    /**
     * @brief Расчет объема цилиндра
     */
    double getVolume() const;
    /**
     * @brief Проверка, лежит ли точка внутри цилиндра
     * @param p - проверяемая точка
     */
    bool PointInside(Point p) const;
};
