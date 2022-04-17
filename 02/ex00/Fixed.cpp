#include "Fixed.hpp"

//Конструктор по умолчанию
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_int_value = 0;
}

//Конструктор с копированием другого значения
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_int_value = copy.getRawBits(); //Вариант с прямым назначением значения переменной
	//*this = copy; //Вариант с использованием оператора присваивания
}

//Деструктор
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//Оператор присваивания
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_int_value = copy.getRawBits();
	return (*this);
}

//Назначение значения переменной
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_int_value = raw;
}

//Извлечение значения переменной
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_int_value);
}
