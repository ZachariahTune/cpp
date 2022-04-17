#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	//Если указано некорректное число
	if (N <= 0)
		return NULL;
	//Создание массива экземпляров
    Zombie *ret = new Zombie[N];
	//Задание уникального имени
    for (int i=0; i < N; i++)
	{
	    ret[i].setName(name + " #" + std::to_string(i + 1));
    }
	//Возвращение результата
    return ret;
}
