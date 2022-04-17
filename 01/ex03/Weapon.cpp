#include "Weapon.hpp"

//Конструктор, сразу задает тип
Weapon::Weapon(std::string type){this->type = type;}

//Пустой деструктор
Weapon::~Weapon(){}

//Метод-Геттер, возвращает тип
const std::string	&Weapon::getType(void){return this->type;}

//Метод-Сеттер, задает/изменяет тип
void	Weapon::setType(std::string type){this->type = type;}
