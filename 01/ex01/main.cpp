#include "Zombie.hpp"

int main(void)
{
	//Переменные
	Zombie*	zHorde;
	int		zCount = 9;

	//Создание "Армии Зомби"
	zHorde = zombieHorde(zCount, "Zombie");
	if (zHorde == NULL)
	{
		std::cerr << "Error: Chislo zCount dolzhno byt polozhitelnim" << std::endl;
		return (1);
	}
	//Вывод имён каждого зомби
	for (int i = 0; i < zCount; i++)
	{
		zHorde[i].announce();
	}
	//Очистка памяти
	delete[] zHorde;
	//Перед ретёрном запускаются деструкторы для всех экземпляров
	return (0);
}
