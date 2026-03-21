#define _USE_MATH_DEFINES
#include <cmath>
#include "Cylinder.h"
Cylinder::Cylinder(const double cx, const double cy, const double cz, const double r, const double h)
{
    this->centerX = cx;
    this->centerY = cy;
    this->centerZ = cz;
    this->radius = r;
    this->height = h;
}
double Cylinder::getV() const
{
    return M_PI * radius * radius * height;
}
bool Cylinder::PointInside(const double x, const double y, const double z) const
{
    if (z < centerZ || z > centerZ + height)
    {
        return false;
    }
    double dx = x - centerX;
    double dy = y - centerY;
    double distanceFromAxis = std::sqrt(dx * dx + dy * dy);
    return distanceFromAxis <= radius;
}
