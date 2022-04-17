#include "Fixed.hpp"

int	main(void)
{
	Fixed a; //Конструктор по умолчанию
	Fixed const b(10); //Конструктор, принимающий INT
	Fixed const c(42.4239f); //Конструктор, принимающий FLOAT
	Fixed const d(b); //Конструктор с копированием другого значения

	a = Fixed(1234.4321f); //Переинициализация (срабатывает деструктор)

	//Вывод значений
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	//Вывод значений в виде INT
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	//Перед ретёрном запускаются деструкторы
	return (0);
}
