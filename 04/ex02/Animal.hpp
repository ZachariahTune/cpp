#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once
#include <iostream>
#include <string>

//Абстрактный класс в C++ - это класс, в котором объявлена хотя бы одна чисто виртуальная функция.
//Для запрета создания "пустого" объекта родительского класса, можно приравнять к 0 виртуальную функцию звука!
class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal &copy);
		Animal(Animal &copy);
		virtual ~Animal();

		Animal &operator=(const Animal &copy);

		std::string getType(void) const;
		virtual void makeSound(void) const = 0; //Это делает данный класс абстрактным
};

#endif
