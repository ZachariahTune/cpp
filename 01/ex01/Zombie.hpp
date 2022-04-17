#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

//Описание класса
class Zombie
{
	private:
		std::string	name;
		
	public:
		Zombie();
		~Zombie();
		void	setName(std::string name);
		void	announce(void);
};

//Дополнительная функция
Zombie	*zombieHorde(int N, std::string name);

#endif
