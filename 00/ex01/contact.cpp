#include "contact.hpp"

//Конструктор и деструктор
Contact::Contact(void){}
Contact::~Contact(void){}

//Методы-сеттеры
void	Contact::set_firstname(std::string arg){this->firstname = arg;}
void	Contact::set_lastname(std::string arg){this->lastname = arg;}
void	Contact::set_nickname(std::string arg){this->nickname = arg;}
void	Contact::set_phonenumber(std::string arg){this->phonenumber = arg;}
void	Contact::set_darkestsecret(std::string arg){this->darkestsecret = arg;}

//Методы-геттеры
std::string	Contact::get_firstname(void){return (this->firstname);}
std::string	Contact::get_lastname(void){return (this->lastname);}
std::string	Contact::get_nickname(void){return (this->nickname);}
std::string	Contact::get_phonenumber(void){return (this->phonenumber);}
std::string	Contact::get_darkestsecret(void){return (this->darkestsecret);}

//Распечатка контакта
void	Contact::print_contact()
{
	std::cout << "First name: " << this->firstname << std::endl;
	std::cout << "Last name: " << this->lastname << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phonenumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestsecret << std::endl;
}
