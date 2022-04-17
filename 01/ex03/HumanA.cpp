#include "HumanA.hpp"

//Конструктор, сразу задает имя и оружие
HumanA::HumanA(std::string name, Weapon &weapon):weapon(weapon){this->name = name;}

//Пустой деструктор
HumanA::~HumanA(){}

//Метод "Атака"
void HumanA::attack(){std::cout << name << " attacks with his " << this->weapon.getType() << std::endl;}
