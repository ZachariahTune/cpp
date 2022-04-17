#include "WrongCat.hpp"

//Дефолтный конструктор
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "# WrongCat: Default constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Конструктор, копирующий другой объект
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	this->type = copy.type;
	std::cout << "# WrongCat: Copy constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Оператор копирования объекта
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	this->type = copy.type;
	std::cout << "# WrongCat: Copy operator called # -> type=«" << this->type << "»" << std::endl;
	return *this;
}

//Деструктор
WrongCat::~WrongCat(){std::cout << "# WrongCat: Destructor called #" << std::endl;}

//Метод создания звука
void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: My sound is «Myaaaaaaaaaaaow»!" << std::endl;
}
