#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	//Создание экземпляра в куче, именование в конструкторе
	Zombie	*zombie = new Zombie(name);
	//Возвращение экземпляра
	return zombie;
}
