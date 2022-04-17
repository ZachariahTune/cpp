#include "Point.hpp"

//Вычисление площади треугольника
float	area(const Point p1, const Point p2, const Point p3)
{
	float area = (
		p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
		p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
		p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())
	) / 2.0;
	if (area < 0)
		return (-area);
	return (area);
}

//Определение нахождения точки внутри треугольника
bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	float	A = area (a, b, c); //Площадь основного треугольника ABC
	float	A1 = area (point, a, b); //Площадь треугольника ABP
	float	A2 = area (point, b, c); //Площадь треугольника PBC
	float	A3 = area (point, a, c); //Площадь треугольника APC

	//TRUE, если площади треугольников положительные и их суммы равны площади основного
	if (A == (A1 + A2 + A3) && A1 > 0 && A2 > 0 && A3 > 0)
		return true;
	else
		return false;
}
