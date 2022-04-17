#include "Fixed.hpp"

//Конструктор по умолчанию
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_int_value = 0;
}

//Конструктор, принимающий INT
Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_int_value = (value << this->frac_bits);
}

//Конструктор, принимающий Float
Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_int_value = roundf(value * (1 << this->frac_bits));
}

//Конструктор с копированием другого значения
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	//this->fixed_int_value = copy.getRawBits(); //Вариант с прямым назначением значения переменной
	*this = copy; //Вариант с использованием оператора присваивания
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
	this->fixed_int_value = raw;
}

//Извлечение значения переменной
int Fixed::getRawBits(void) const
{
	return (this->fixed_int_value);
}

//Преобразование Fixed в Float
float Fixed::toFloat(void) const
{
	return ((float)this->fixed_int_value / (float)(1 << this->frac_bits));
}

//Преобразование Fixed в Int
int Fixed::toInt(void) const
{
	return (this->fixed_int_value >> this->frac_bits);
}

//Вывод Fixed в поток в формате Float
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return (out);
}
