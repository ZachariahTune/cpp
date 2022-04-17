#include "Ice.hpp"

//Дефолтный конструктор
Ice::Ice()
{
	this->type = "ice";
	std::cout << "# Ice: Default constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Конструктор, копирующий другой объект
Ice::Ice(const Ice &copy) : AMateria(copy)
{
	this->type = copy.getType();
	std::cout << "# Ice: Copy constructor called # -> type=«" << this->type << "»" << std::endl;
	*this = copy;
}

//Оператор копирования объекта
Ice &Ice::operator=(const Ice &copy)
{
	this->type = copy.getType();
	std::cout << "# Ice: Copy operator called # -> type=«" << this->type << "»" << std::endl;
	return *this;
}

//Деструктор
Ice::~Ice()
{
	std::cout << "# Ice: Destructor called #" << std::endl;
}

//Метод клонирования
AMateria *Ice::clone() const
{
	AMateria *newIce = new Ice();
	return (newIce);
}

//Метод использования
void Ice::use(ICharacter &target)
{
	std::cout << "Ice: Personage shoots an ice bolt at «" << target.getName() << "»" << std::endl;
}
