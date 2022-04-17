#include "Fixed.hpp"

int	main(void)
{
	Fixed a; //Конструктор по умолчанию
	Fixed b(a); //Конструктор с копированием другого значения
	Fixed c; //Конструктор по умолчанию
	
	c = b; //Оператор присваивания
	
	//Извлечение значений
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	//Перед ретёрном запускаются деструкторы
	return (0);
}
