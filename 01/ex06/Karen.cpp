#include "Karen.hpp"

//Конструктор и Деструктор
Karen::Karen(){}
Karen::~Karen(){}

//Приватные функции вывода сообщений
void	Karen::debug(void)	{std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;}
void	Karen::info(void)	{std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;}
void	Karen::warning(void){std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;}
void	Karen::error(void)	{std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;}

//Публицная функция вызова приватных функций
void	Karen::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Karen::*methods[])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	int	print = 0;
	for (int i=0; i<4; i++)
	{
        if (level == levels[i] || print == 1)
		{
			(this->*methods[i])();
			std::cout << std::endl;
			print = 1;
		}
	}
	if (print == 0){std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;}
}
