#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	//Тест 1
	std::cout << std::endl << "========== TEST#1 ==========" << std::endl;
	try
	{
		Form form("Contract", 10, 5);	//Создаем форму
		std::cout << form << std::endl;	//Выводим информацию по форме
		Bureaucrat bur("Anton", 11);	//Создаем бюрократа
		std::cout << bur << std::endl;	//Выводим информацию по бюрократу
		bur.signForm(form);				//Пытаемся бюрократом подписать форму
		bur.incrementGrade();			//Увеличиваем уровень бюрократа
		std::cout << bur << std::endl;	//Повторно выводим информацию по бюрократу
		bur.signForm(form);				//Повторно пытаемся бюрократом подписать форму
		std::cout << form << std::endl;	//Повторно выводим информацию по форме
	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}

	//Тест 2
	std::cout << std::endl << "========== TEST#2 ==========" << std::endl;
	try
	{
		Form t_form("Contract", 10, 5);	//Создаем форму#1
		Form form(t_form);				//Создаем форму#2, копируя форму#1
		std::cout << form << std::endl;	//Выводим информацию по форме
		Bureaucrat t_bur("Anton", 1);	//Создаем бюрократа#1
		Bureaucrat bur(t_bur);			//Создаем бюрократа#2, копируя бюрократа#1
		std::cout << bur << std::endl;	//Выводим информацию по бюрократу
		bur.incrementGrade();			//Увеличиваем уровень бюрократа - !!!ОШИБКА!!!
		bur.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}

	//Тест 3 (Ошибка на уровне создания формы)
	std::cout << std::endl << "========== TEST#3 ==========" << std::endl;
	try{Form form("Contract", 10, 0);}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}

	//Тест 4 (Ошибка на уровне создания формы)
	std::cout << std::endl << "========== TEST#4 ==========" << std::endl;
	try{Form form("Contract", 10, 151);}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}

	//Тест 5 (Ошибка на уровне создания формы)
	std::cout << std::endl << "========== TEST#5 ==========" << std::endl;
	try{Form form("Contract", -1, 5);}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}

	//Тест 6 (Ошибка на уровне создания формы)
	std::cout << std::endl << "========== TEST#6 ==========" << std::endl;
	try{Form form("Contract", 200, 5);}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}

	return (0);
}
