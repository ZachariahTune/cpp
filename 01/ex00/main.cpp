#include "Zombie.hpp"

int main(void)
{
	//Создание экземпляра в стеке, именование в сеттере
	Zombie	zom1;
	zom1.setName("Zombie #1 (stack & setter)");
	zom1.announce();

	//Создание экземпляра в стеке, именование в конструкторе
	Zombie	zom2("Zombie #2 (stack & constructor)");
	zom2.announce();

	//Создание экземпляра в куче при помощи дополнительной функции
	Zombie	*zom3 = newZombie("Zombie #3 (heap)");
	zom3->announce();

	//Совершение всех действий внутри дополнительной функции
	randomChump("Zombie #4 (function)");

	//Очистка памяти для экземпляра, созданного в куче
	delete	zom3;
	
	//Перед ретёрном запускаются деструкторы для всех экземпляров
	return (0);
}
