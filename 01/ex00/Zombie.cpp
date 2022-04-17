#include "Zombie.hpp"

//Пустой конструктор, если создается экземпляр класса без параметров
Zombie::Zombie(void){}

//Конструктор, если создается экземпляр класса с параметрами
Zombie::Zombie(std::string name){this->name = name;}

//Деструктор
Zombie::~Zombie(void){std::cout << this->name << " destructed" << std::endl;}

//Метод-Сеттер, если нужно задать приватной переменной значение
void	Zombie::setName(std::string name){this->name = name;}

//Метод-Геттер, возвращает значение приватной переменной 
std::string	Zombie::getName(void){return (this->name);}

//Метод-Аннонс, выводит значение приватной переменной на экран
void	Zombie::announce(void){std::cout << getName() <<  ": BraiiiiiiinnnzzzZ..." << std::endl;}
