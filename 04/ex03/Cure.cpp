#include "Cure.hpp"

//Дефолтный конструктор
Cure::Cure()
{
	this->type = "cure";
	std::cout << "# Cure: Default constructor called # -> type=«" << this->type << "»" << std::endl;
}

//Конструктор, копирующий другой объект
Cure::Cure(const Cure &copy) : AMateria(copy)
{
	this->type = copy.getType();
	std::cout << "# Cure: Copy constructor called # -> type=«" << this->type << "»" << std::endl;
	*this = copy;
}

//Оператор копирования объекта
Cure &Cure::operator=(const Cure &copy)
{
	this->type = copy.getType();
	std::cout << "# Cure: Copy operator called # -> type=«" << this->type << "»" << std::endl;
	return *this;
}

//Деструктор
Cure::~Cure()
{
	std::cout << "# Cure: Destructor called #" << std::endl;
}

//Метод клонирования
AMateria *Cure::clone() const
{
	AMateria *newCure = new Cure();
	return (newCure);
}

//Метод использования
void Cure::use(ICharacter &target)
{
	std::cout << "Cure: Personage heals «" << target.getName() << "»'s wounds" << std::endl;
}
