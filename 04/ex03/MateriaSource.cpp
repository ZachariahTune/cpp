#include "MateriaSource.hpp"

//Дефолтный конструктор
MateriaSource::MateriaSource()
{
	for (int i=0; i<4; i++){this->materias[i] = NULL;}
	std::cout << "# MateriaSource: Default constructor called #" << std::endl;
}

//Конструктор, копирующий другой объект
MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource(copy)
{
	std::cout << "# MateriaSource: Copy constructor called #" << std::endl;
	*this = copy;
}

//Деструктор
MateriaSource::~MateriaSource()
{
	for (int i=0; i<4; i++)
	{
		if (this->materias[i] != NULL){delete this->materias[i];}
	}
	std::cout << "# MateriaSource: Destructor called #" << std::endl;
}

//Оператор копирования объекта
MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "# MateriaSource: Copy operator called #" << std::endl;
	if (this != &copy)
	{
		for (int i=0; i<4; i++)
		{
			if (copy.materias[i] != NULL){this->materias[i] = copy.materias[i]->clone();}
		}
	}
	return *this;
}

//Изучение материи (добавление материи в источник материй)
void MateriaSource::learnMateria(AMateria *toLearn)
{
	if (toLearn == NULL)
	{
		std::cout << "MateriaSource: Invalid AMateria" << std::endl;
		return ;
	}
	for (int i=0; i<4; i++)
	{
		if (this->materias[i] == NULL)
		{
			this->materias[i] = toLearn;
			std::cout << "MateriaSource: «" << toLearn->getType() << "» has been learned" << std::endl;
			break;
		}
	}
}

//Создание материи на основе источника материй перед её добавлением в слот персонажа
AMateria *MateriaSource::createMateria(const std::string &type)
{
	if (type != "ice" && type != "cure")
		return (NULL);
	for (int i=0; i<4; i++)
	{
		if (this->materias[i] != NULL && this->materias[i]->getType() == type)
		{
			std::cout << "MateriaSource: «" << type << "» has been created" << std::endl;
			return (this->materias[i]->clone());
		}
	}
	return (NULL);
}
