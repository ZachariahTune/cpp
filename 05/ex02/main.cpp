#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	//***********************************//
	//****** ShrubberyCreationForm ******//
	//***********************************//
	std::cout << std::endl << "\033[32m============ ShrubberyCreationForm ============\033[0m" << std::endl;

	//Корректный тест
	std::cout << "\x1b[38;5;242m=============== Korrektniy test ===============\033[0m" << std::endl;
	try
	{
		Form *form = new ShrubberyCreationForm("Contract1");//Создаем форму "кустарник" с именем "контракт"
		std::cout << *form << std::endl;					//Выводим информацию по форме
		Bureaucrat bur("Anton", 6);							//Создаем бюрократа Антона с уровнем 6
		std::cout << bur << std::endl;						//Выводим информацию по Антону
		bur.signForm(*form);								//Антон подписывает форму
		std::cout << *form << std::endl;					//Повторно выводим информацию по форме
		bur.executeForm(*form);								//Антон исполняет форму (сажает дерефо в файле)
		delete form;										//Удаляем форму
	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;} //В блоке catch запускается деструктор Антона

	//Тест без подписи и грейда для исполнения
	std::cout << "\x1b[38;5;242m======== Test bez podpisi i greida dlya ispolneniya ========\033[0m" << std::endl;
	try
	{
		Form *form = new ShrubberyCreationForm("Contract2");//Создаем форму "кустарник" с именем "контракт"
		std::cout << *form << std::endl;					//Выводим информацию по форме
		Bureaucrat bur("Anton", 138);						//Создаем бюрократа Антона с уровнем 138
		std::cout << bur << std::endl;						//Выводим информацию по Антону
		bur.executeForm(*form);								//Антон пытается выполнить форму (форма не подписана)
		bur.signForm(*form);								//Антон подписывает форму
		bur.executeForm(*form);								//Антон пытается выполнить форму (не хватает грейда)
		bur.incrementGrade();								//Повышаем грейд Антону
		std::cout << bur << std::endl;						//Выводим информацию по Антону
		bur.executeForm(*form);								//Антон исполняет форму (сажает дерефо в файле)
		delete form;										//Удаляем форму
	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;} //В блоке catch запускается деструктор Антона

	//Тест с низким грейдом
	std::cout << "\x1b[38;5;242m============= Test s nizkim greidom =============\033[0m" << std::endl;
	try
	{
		Form *form = new ShrubberyCreationForm("Contract3");//Создаем форму "кустарник" с именем "контракт"
		std::cout << *form << std::endl;					//Выводим информацию по форме
		Bureaucrat bur("Anton", 146);						//Создаем бюрократа Антона с уровнем 146
		std::cout << bur << std::endl;						//Выводим информацию по Антону
		bur.signForm(*form);								//Антон пытается подписать форму (не хватает грейда)
		bur.incrementGrade();								//Повышаем грейд Антону
		std::cout << bur << std::endl;						//Выводим информацию по Антону
		bur.signForm(*form);								//Антон подписывает форму
		std::cout << *form << std::endl;					//Выводим информацию по форме
		bur.executeForm(*form);								//Антон пытается выполнить форму (не хватает грейда)
		delete form;										//Удаляем форму (не исполнена)
	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;} //В блоке catch запускается деструктор Антона

	//***********************************//
	//******* RobotomyRequestForm *******//
	//***********************************//
	std::cout << std::endl << "\033[32m============= RobotomyRequestForm =============\033[0m" << std::endl;
	try
	{
		Form *form = new RobotomyRequestForm("Contract");	//Создаем форму "роботизация" с именем "контракт"
		std::cout << *form << std::endl;					//Выводим информацию по форме
		Bureaucrat bur("Anton", 73);						//Создаем бюрократа Антона с уровнем 73
		std::cout << bur << std::endl;						//Выводим информацию по Антону
		bur.executeForm(*form);								//Антон пытается выполнить форму (форма не подписана)
		bur.signForm(*form);								//Антон пытается подписать форму (не хватает грейда)
		bur.incrementGrade();								//Повышаем грейд Антону
		std::cout << bur << std::endl;						//Выводим информацию по Антону
		bur.signForm(*form);								//Антон подписывает форму
		std::cout << *form << std::endl;					//Выводим информацию по форме
		bur.executeForm(*form);								//Антон пытается выполнить форму (не хватает грейда)
		for (int i=0; i<30; i++){bur.incrementGrade();}		//Повышаем грейд Антону
		std::cout << bur << std::endl;						//Выводим информацию по Антону
		bur.executeForm(*form);								//Антон исполняет форму (выпускает робота, который может и сломаться 50/50%)
		delete form;										//Удаляем форму (не исполнена)
	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;} //В блоке catch запускается деструктор Антона

	//************************************//
	//****** PresidentialPardonForm ******//
	//************************************//
	std::cout << std::endl << "\033[32m============= PresidentialPardonForm =============\033[0m" << std::endl;
	try
	{
		Form *form = new PresidentialPardonForm("Contract");//Создаем "президентскую" форму с именем "контракт"
		std::cout << *form << std::endl;					//Выводим информацию по форме
		Bureaucrat bur("Anton", 26);						//Создаем бюрократа Антона с уровнем 26
		std::cout << bur << std::endl;						//Выводим информацию по Антону
		bur.executeForm(*form);								//Антон пытается выполнить форму (форма не подписана)
		bur.signForm(*form);								//Антон пытается подписать форму (не хватает грейда)
		bur.incrementGrade();								//Повышаем грейд Антону
		std::cout << bur << std::endl;						//Выводим информацию по Антону
		bur.signForm(*form);								//Антон подписывает форму
		std::cout << *form << std::endl;					//Выводим информацию по форме
		bur.executeForm(*form);								//Антон пытается выполнить форму (не хватает грейда)
		for (int i=0; i<20; i++) //Если поставить 25, то исполнение кода прервется из-за ошибки увеличения грейда
		{
			bur.incrementGrade();							//Повышаем грейд Антону
			std::cout << bur << std::endl;					//Выводим информацию по Антону
		}
		bur.executeForm(*form);								//Антон исполняет форму (выпускает робота, который может и сломаться 50/50%)
		delete form;										//Удаляем форму (не исполнена)
	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;} //В блоке catch запускается деструктор Антона
	
	return (0);
}
