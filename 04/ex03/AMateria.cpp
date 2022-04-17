#include "AMateria.hpp"

//Дефолтный конструктор
AMateria::AMateria()
{
	this->type = "no_type";
	std::cout << "# AMateria: Default constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Конструктор, определяющий тип
AMateria::AMateria(const std::string &type)
{
	this->type = type;
	std::cout << "# AMateria: Type constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Конструктор, копирующий другой объект
AMateria::AMateria(const AMateria &copy)
{
	this->type = copy.getType();
	std::cout << "# AMateria: Copy constructor called # -> type=«" << this->type << "»" << std::endl;
	*this = copy;
}

//Оператор копирования объекта
AMateria &AMateria::operator=(const AMateria &copy)
{
	this->type = copy.getType();
	std::cout << "# AMateria: Copy operator called # -> type=«" << this->type << "»" << std::endl;
	return *this;
}

//Деструктор
AMateria::~AMateria(){std::cout << "# AMateria: Destructor called #" << std::endl;}

//Метод возврата типа
const std::string	&AMateria::getType(void) const
{
	return (this->type);
}

//Метод использования
void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria: Use - Don't do anything to «" << target.getName() << "»" << std::endl;
}
