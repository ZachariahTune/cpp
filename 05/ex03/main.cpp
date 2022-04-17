#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	//ShrubberyCreationForm
	std::cout << std::endl << "\033[32m============ ShrubberyCreationForm ============\033[0m" << std::endl;
	try
	{
		Intern intern;													//Создаем интерна
		Form *form = intern.makeForm("ShrubberyCreation", "Contract");	//Интерн создает форму "кустарник" с именем "контракт"
		Bureaucrat bur("Anton", 6);
		std::cout << bur << std::endl;
		bur.signForm(*form);
		std::cout << *form << std::endl;
		bur.executeForm(*form);
		delete form;
	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}

	//RobotomyRequestForm
	std::cout << std::endl << "\033[32m============= RobotomyRequestForm =============\033[0m" << std::endl;
	try
	{
		Intern intern;													//Создаем интерна
		Form *form = intern.makeForm("RobotomyRequest", "Contract");	//Интерн создает форму "роботизация" с именем "контракт"
		Bureaucrat bur("Anton", 73);
		std::cout << bur << std::endl;
		bur.executeForm(*form);
		bur.signForm(*form);
		bur.incrementGrade();
		std::cout << bur << std::endl;
		bur.signForm(*form);
		std::cout << *form << std::endl;
		bur.executeForm(*form);
		for (int i=0; i<30; i++){bur.incrementGrade();}
		std::cout << bur << std::endl;
		bur.executeForm(*form);
		delete form;
	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}

	//PresidentialPardonForm
	std::cout << std::endl << "\033[32m============= PresidentialPardonForm =============\033[0m" << std::endl;
	try
	{
		Intern intern;													//Создаем интерна
		Form *form = intern.makeForm("PresidentialPardon", "Contract");	//Создаем "президентскую" форму с именем "контракт"
		Bureaucrat bur("Anton", 26);
		std::cout << bur << std::endl;
		bur.executeForm(*form);
		bur.signForm(*form);
		bur.incrementGrade();
		std::cout << bur << std::endl;
		bur.signForm(*form);
		std::cout << *form << std::endl;
		bur.executeForm(*form);
		for (int i=0; i<20; i++)
		{
			bur.incrementGrade();
			std::cout << bur << std::endl;
		}
		bur.executeForm(*form);
		delete form;
	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}
	
	return (0);
}
