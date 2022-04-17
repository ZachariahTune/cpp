#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once
#include <iostream>
#include <string>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal &copy);
		Animal(Animal &copy);
		virtual ~Animal();					//Для разделения функций в классе и его подклассах для объектов одного типа

		Animal &operator=(const Animal &copy);

		std::string getType(void) const;
		virtual void makeSound(void) const;	//Для разделения функций в классе и его подклассах для объектов одного типа
};

#endif
