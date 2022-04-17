#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once
#include <iostream>
#include <string>

//Так как в тесте создаются объекты одного типа, то для создания разных функций подклассов
//с одинаковыми названиями используется ключевое слово "virtual".
//Это называется "полиморфизм".

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();					//Для разделения функций в классе и его подклассах для объектов одного типа

		Animal &operator=(const Animal &copy);

		std::string getType(void) const;
		virtual void makeSound(void) const;	//Для разделения функций в классе и его подклассах для объектов одного типа
};

#endif
