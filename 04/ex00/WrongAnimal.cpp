#include "WrongAnimal.hpp"

//Дефолтный конструктор
WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "# WrongAnimal: Default constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Конструктор, копирующий другой объект
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->type = copy.type;
	std::cout << "# WrongAnimal: Copy constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Оператор копирования объекта
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->type = copy.type;
	std::cout << "# WrongAnimal: Copy operator called # -> type=«" << this->type << "»" << std::endl;
	return *this;
}

//Деструктор
WrongAnimal::~WrongAnimal(){std::cout << "# WrongAnimal: Destructor called #" << std::endl;}

//Метод создания звука
void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal: My sound is «Rrrrrrrrrrrrr»!" << std::endl;
}

//Метод вывода типа
std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
