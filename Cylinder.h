#pragma once
/**
 * @brief класс Цилиндр
 */
class Cylinder
{
private:
    /**
     * @brief координаты центра основания
     */
    double centerX, centerY, centerZ;
    /**
     *@brief радиус основания
     */
    double radius;
    /**
     * @brief высота цилиндра
     */
    double height;

public:
    /**
     * @brief Конструктор
     * @param cx координата x центра основания
     * @param cy координата y центра основания
     * @param cz координата z центра основания
     * @param r радиус основания
     * @param h высота цилиндра
     */
    Cylinder(const double cx, const double cy, const double cz, const double r, const double h);
    /**
     * @brief вычисление объема цилиндра
     */
    double getV() const;
    /**
     * @brief проверка, лежит ли точка в цилиндре
     * @param x координата точки x
     * @param y координата точки y
     * @param z координата точки z
     */
    bool PointInside(const double x, const double y, const double z) const;
};
