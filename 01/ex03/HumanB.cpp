#include "HumanB.hpp"

//Конструктор, сразу задает имя
HumanB::HumanB(std::string name){this->name = name; this->weapon = NULL;}

//Пустой деструктор
HumanB::~HumanB(){}

//Метод-Сеттер, задает/изменяет оружие
void HumanB::setWeapon(Weapon &weapon){this->weapon = &weapon;}

//Метод "Атака"
void HumanB::attack()
{
	if (this->weapon != NULL)
		std::cout << name << " attacks with his " << this->weapon->getType() << std::endl;
	if (this->weapon == NULL)
		std::cout << name << " has no weapon" << std::endl;
}
