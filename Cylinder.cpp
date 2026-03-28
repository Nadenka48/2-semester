#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "cylinder.h"
Cylinder::Cylinder(Point c, double r, double h)
{
    this->center = c;
    this->radius = r;
    this->height = h;
    if (r <= 0 || h <= 0)
    {
        std::cout << "Ошибка: Радиус и высота должны быть положительными!" << std::endl;
        exit(1);
    }
}
double Cylinder::getVolume() const
{
    return M_PI * this->radius * this->radius * this->height;
}
bool Cylinder::PointInside(Point p) const
{
    if (p.getZ() < this->center.getZ() || p.getZ() > this->center.getZ() + this->height)
    {
        return false;
    }
    double dx = p.getX() - this->center.getX();
    double dy = p.getY() - this->center.getY();
    if ((dx * dx + dy * dy) <= (this->radius * this->radius))
    {
        return true;
    }
    else
    {
        return false;
    }
}
