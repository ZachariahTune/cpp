#include "Character.hpp"

//Дефолтный конструктор
Character::Character()
{
	this->name = "no_name";
	std::cout << "# Character: Default constructor called # -> name=«" << this->name << "»" << std::endl;
}

//Конструктор, определяющий имя
Character::Character(std::string name)
{
	this->name = name;
	for (int i=0; i<4; i++){inventory[i] = NULL;}
	std::cout << "# Character: Name constructor called # -> name=«" << this->name << "»" << std::endl;
}

//Конструктор, копирующий другой объект
Character::Character(const Character &copy) : ICharacter(copy)
{
	this->name = copy.getName();
	std::cout << "# Character: Copy constructor called # -> name=«" << this->name << "»" << std::endl;
	*this = copy;
}

//Оператор копирования объекта
Character &Character::operator=(const Character &copy)
{
	if (this != &copy){this->name = copy.getName();}
	std::cout << "# Character: Copy operator called # -> name=«" << this->name << "»" << std::endl;
	if (this != &copy)
	{
		for (int i=0; i<4; i++)
		{
			if (inventory[i] != NULL){delete inventory[i]; inventory[i] = NULL;}
		}
		for (int i=0; i<4; i++)
		{
			if (copy.inventory[i] != NULL){equip(copy.inventory[i]->clone());}
			else {inventory[i] = NULL;}
		}
	}
	return *this;
}

//Деструктор
Character::~Character()
{
	for (int i=0; i<4; i++)
	{
		if (inventory[i] != NULL){delete inventory[i];}
	}
	std::cout << "# Character: Destructor called #" << std::endl;
}

//Метод извлечения имени
const std::string &Character::getName(void) const
{
	return (this->name);
}

//Добавление инвенторя в слот
void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Character: Invalid AMateria" << std::endl;
		return ;
	}
	for (int i=0; i<4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << "Character: «" << m->getType() << "» has been added to «" << this->name << "» inventory" << std::endl;
			return ;
		}
	}
	std::cout << "Character: All inventory slots are full!" << std::endl;
}

//Удаление инвенторя из слота
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || inventory[idx] == NULL)
	{
		std::cout << "Character: Nothing to unequip" << std::endl; // Может быть Incorrect idx
		return ;
	}
	std::cout << "Character: «" << inventory[idx]->getType() << " has been removed to «" << this->name << "» inventory" << std::endl;
	inventory[idx] = NULL;
}

//Применение инвенторя
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || inventory[idx] == NULL)
	{
		std::cout << "Character: Invalid Materia's slot to use" << std::endl; //???
		return ;
	}
	inventory[idx]->use(target);
}

//Изменение имени
void Character::rename(std::string name)
{
	this->name = name;
	std::cout << "Character: Rename personage -> name=«" << this->name << "»" << std::endl;
}
