#include "Dog.hpp"

//Дефолтный конструктор
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "# Dog: Default constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Конструктор, копирующий другой объект
Dog::Dog(const Dog &copy) : Animal(copy)
{
	this->type = copy.type;
	std::cout << "# Dog: Copy constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Оператор копирования объекта
Dog &Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	std::cout << "# Dog: Copy operator called # -> type=«" << this->type << "»" << std::endl;
	return *this;
}

//Деструктор
Dog::~Dog(){std::cout << "# Dog: Destructor called #" << std::endl;}

//Метод создания звука
void Dog::makeSound(void) const
{
	std::cout << "Dog: My sound is «Gggggav-Gggggav»!" << std::endl;
}
