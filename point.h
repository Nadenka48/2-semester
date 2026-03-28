#pragma once
/**
 * @brief Класс Точка
 */
class Point
{
private:
    /**
     * @brief Координата x
     */
    double x;
    /**
     * @brief Координата y
     */
    double y;
    /**
     * @brief Координата z
     */
    double z;
public:
    /**
     * @brief Конструктор точки
     */
    Point(double x = 0, double y = 0, double z = 0);
    /**
     * @brief Получение координаты x
     */
    double getX() const;
    /**
     * @brief Получение координаты y
     */
    double getY() const;
    /**
     * @brief Получение координаты z
     */
    double getZ() const;
    /**
     * @brief Проверка на равенство оператора
     */
    bool operator==(Point p) const;
    /**
     * @brief Проверка на неравенство оператора
     */
    bool operator!=(Point p) const;
};
