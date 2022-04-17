#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	private:
		//Приватные переменные класса
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	darkestsecret;
	public:
		//Конструктор и деструктор
		Contact(void);
		~Contact(void);
		//Методы-сеттеры
		void		set_firstname(std::string arg);
		void		set_lastname(std::string arg);
		void		set_nickname(std::string arg);
		void		set_phonenumber(std::string arg);
		void		set_darkestsecret(std::string arg);
		//Методы-геттеры
		std::string	get_firstname(void);
		std::string	get_lastname(void);
		std::string	get_nickname(void);
		std::string	get_phonenumber(void);
		std::string	get_darkestsecret(void);
		//Распечатка контакта
		void		print_contact(void);
};

#endif
