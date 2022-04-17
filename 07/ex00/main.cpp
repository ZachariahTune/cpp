#include "whatever.hpp"

//Задача состоит в том, чтобы описать шаблоны функций, которые будут работать с любыми типами данных
//Шаблонные функции не являются методами конкретного класса, поэтому перед "::" не ставится ничего

int	main(void)
{
	//************************************************//
	//********** Тестовый пример по заданию **********//
	//************************************************//
	std::cout << std::endl;
	std::cout << "################" << std::endl;
	std::cout << "# Subject Test #" << std::endl;
	std::cout << "################" << std::endl;
	std::cout << std::endl;
	//Переменные типа INT
	int a = 2;
	int b = 3;
	::swap(a, b);												//Меняем местами A и B
	std::cout << "a = " << a << ", b = " << b << std::endl;		//Выводим обновленные A и B
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;	//Выводим минимум из A и B
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;	//Выводим максимум из A и B
	//Переменные типа STRING
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);												//Меняем местами C и D
	std::cout << "c = " << c << ", d = " << d << std::endl;		//Выводим обновленные C и D
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;	//Выводим минимум из C и D
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;	//Выводим максимум из C и D

	//*************************************************//
	//******** Доп. пример с объектами классов ********//
	//*************************************************//
	std::cout << std::endl;
	std::cout << "######################" << std::endl;
	std::cout << "# Class objects Test #" << std::endl;
	std::cout << "######################" << std::endl;
	std::cout << std::endl;
	//Переменные класса People
	People m1("Anton", 42);
	People m2("Denis", 35);
	std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;
	::swap(m1, m2);													//Меняем местами M1 и M2
	std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;		//Выводим обновленные M1 и M2
	std::cout << "min(m1, m2) = " << ::min(m1, m2) << std::endl;	//Выводим минимум из M1 и M2
	std::cout << "max(m1, m2) = " << ::max(m1, m2) << std::endl;	//Выводим максимум из M1 и M2

	return (0);
}
