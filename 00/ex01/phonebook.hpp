#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "contact.hpp"

class Phonebook
{
	private:
		//Приватная переменная класса
		Contact	contacts[8]; //8 контактов в записной книжке
	public:
		//Конструктор и деструктор
		Phonebook(void);
		~Phonebook(void);
		//Методы класса
		void	add(int index);	//Добавление нового контакта
		void	browse(void);	//Обзор всех контактов
		void	search(void);	//Подробная информация о контакте
};

#endif
