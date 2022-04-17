#include "Animal.hpp"

//Дефолтный конструктор
Animal::Animal()
{
	this->type = "Animal";
	std::cout << "# Animal: Default constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Конструктор, копирующий другой объект
Animal::Animal(const Animal &copy)
{
	this->type = copy.type;
	std::cout << "# Animal: Copy constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Оператор копирования объекта
Animal &Animal::operator=(const Animal &copy)
{
	this->type = copy.type;
	std::cout << "# Animal: Copy operator called # -> type=«" << this->type << "»" << std::endl;
	return *this;
}

//Деструктор
Animal::~Animal(){std::cout << "# Animal: Destructor called #" << std::endl;}

//Метод создания звука
void Animal::makeSound(void) const
{
	std::cout << "Animal: My sound is «Rrrrrrrrrrrrr»!" << std::endl;
}

//Метод вывода типа
std::string	Animal::getType(void) const
{
	return (this->type);
}
