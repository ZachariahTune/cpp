#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#pragma once
#include <iostream>
#include <string>

//Для демонстрации работы без слова "virtual"
//создаем точно такой же класс без слова "virtual"
class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &copy);

		std::string getType(void) const;
		void makeSound(void) const;
};

#endif
