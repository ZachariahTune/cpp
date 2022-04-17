#include "Karen.hpp"

//Конструктор и Деструктор
Karen::Karen(){std::cout << "# This is constructor of Karen class #" << std::endl;}
Karen::~Karen(){std::cout << "# This is destructor of Karen class #" << std::endl;}

//Приватные функции вывода сообщений
void	Karen::debug(void)	{std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;}
void	Karen::info(void)	{std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;}
void	Karen::warning(void){std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;}
void	Karen::error(void)	{std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;}

//Публицная функция вызова приватных функций
void	Karen::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Karen::*methods[])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	for (int i=0; i<4; i++)
	{
        if (level == levels[i])
		{
			(this->*methods[i])();
			return ;
		}
	}
	std::cout << level << ": There is no such private method!" << std::endl;
}
