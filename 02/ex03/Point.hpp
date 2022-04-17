#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed x; //Переменные по заданию
		const Fixed y; //Переменные по заданию
		Fixed x1; //Копии переменных для реального применения
		Fixed y1; //Копии переменных для реального применения

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &copy);
		~Point();

		Point &operator=(const Point &copy);

		Fixed getX(void) const; //Извлечение значения X1
		Fixed getY(void) const; //Извлечение значения Y1
};

//Определение нахождения точки внутри треугольника
bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif
