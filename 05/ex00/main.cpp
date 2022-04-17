#include "Bureaucrat.hpp"

//ИСКЛЮЧЕНИЯ

/* Блоки try{}catch{} используются для обработки ошибочных ситуаций
Существует несколько форматов, в данном случае: try{ код_с_ошибкой } catch( тип и идентификатор ){ обработчик } 
Оператор throw определяет тип и значение исключительной ситуации для обработки в блоке catch(){}
Также применяется стандартный класс для работы с исключениями std::exception,
метод what() которого возвращает строку в стиле C (поэтому возвращается char *, а не std::string)
В блоке catch запускаются деструкторы для объектов, созданных в блок try */

int	main(void)
{
	//Тест 1
	std::cout << std::endl << "========== TEST#1 ==========" << std::endl;
	try											//try{ Блок_кода_с_ошибкой }
	{	Bureaucrat bur1("Bureaucrat#1", 100);
		Bureaucrat bur2("Bureaucrat#2", 145);
		std::cout << bur1 << std::endl;
		for (int i=0; i<10; i++)
		{
			bur2.decrementGrade();
			std::cout << bur2 << std::endl;		//можно определить собственное поведение для любого оператора (<<)
	}	}
	catch (std::exception &excep)				//catch ( тип идентификатор ){ обработчик_ошибочной_ситуации }
	{
		std::cout << excep.what() << std::endl;	//what() - возвращает строку char *
	}

	//Тест 2
	std::cout << std::endl << "========== TEST#2 ==========" << std::endl;
	try
	{	Bureaucrat bur("BureaucratName", 3);
		for (int i=0; i<10; i++)
		{
			std::cout << bur << std::endl;
			bur.incrementGrade();
	}	}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}

	//Тест 3
	std::cout << std::endl << "========== TEST#3 ==========" << std::endl;
	try {Bureaucrat bur("BureaucratName", 151);}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}
	
	//Тест 4
	std::cout << std::endl << "========== TEST#4 ==========" << std::endl;
	try {Bureaucrat bur("BureaucratName", -10);}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}
	
	//Тест 5
	std::cout << std::endl << "========== TEST#5 ==========" << std::endl;
	try {Bureaucrat bur("BureaucratName", 10);}
	catch (std::exception &excep){std::cout << excep.what() << std::endl;}

	return (0);
}
