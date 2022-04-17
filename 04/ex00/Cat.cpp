#include "Cat.hpp"

//Дефолтный конструктор
Cat::Cat()
{
	this->type = "Cat";
	std::cout << "# Cat: Default constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Конструктор, копирующий другой объект
Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->type = copy.type;
	std::cout << "# Cat: Copy constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Оператор копирования объекта
Cat &Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	std::cout << "# Cat: Copy operator called # -> type=«" << this->type << "»" << std::endl;
	return *this;
}

//Деструктор
Cat::~Cat(){std::cout << "# Cat: Destructor called #" << std::endl;}

//Метод создания звука
void Cat::makeSound(void) const
{
	std::cout << "Cat: My sound is «Myaaaaaaaaaaaow»!" << std::endl;
}
