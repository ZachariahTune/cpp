#include "Point.hpp"

//Конструктор по умолчанию
Point::Point() : x(0), y(0)
{
	this->x1 = this->x;
	this->y1 = this->y;
}

//Конструктор, принимающий X и Y
Point::Point(const float x, const float y) : x(x), y(y)
{
	this->x1 = this->x;
	this->y1 = this->y;
}

//Конструктор с копированием другого значения
Point::Point(const Point &copy)
{
	(Fixed)this->x = (Fixed)copy.x;
	(Fixed)this->y = (Fixed)copy.y;
	this->x1 = copy.x1;
	this->y1 = copy.y1;
}

//Деструктор
Point::~Point(){}

//Оператор присваивания
Point &Point::operator=(const Point &copy)
{
	(Fixed)this->x = (Fixed)copy.x;
	(Fixed)this->y = (Fixed)copy.y;
	this->x1 = copy.x1;
	this->y1 = copy.y1;
	return (*this);
}

//Извлечение значений X и Y
Fixed Point::getX(void) const {return (x1);}
Fixed Point::getY(void) const {return (y1);}
