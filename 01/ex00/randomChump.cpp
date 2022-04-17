#include "Zombie.hpp"

void	randomChump(std::string name)
{
	//Создание экземпляра в стеке, именование в конструкторе
	Zombie	zombie(name);
	//Вывод имени этого экземпляра на экран
	zombie.announce();
}
