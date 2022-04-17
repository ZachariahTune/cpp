#include "Zombie.hpp"

//Конструктор
Zombie::Zombie(void){std::cout << "Cоnstructor called" << std::endl;}

//Деструктор
Zombie::~Zombie(void){std::cout << this->name << " destructed" << std::endl;}

//Метод-Сеттер для назначения уникального имени
void	Zombie::setName(std::string name){this->name = name;}

//Метод-Аннонс
void	Zombie::announce(void){std::cout << this->name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;}
