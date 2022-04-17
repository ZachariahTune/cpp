#include "iter.hpp"

//Задача состоит в том, чтобы описать шаблон функции, работающей с любым типом массивов
//Функция принимает 3 параметра:
// 1. адрес массива;
// 2. размер массива;
// 3. функция, вызывающаяся для каждого элемента массива (она тоже может быть шаблонной).

int	main(void)
{
	//************************************************//
	//************* Тест с типом INTEGER *************//
	//************************************************//
	std::cout << std::endl;
	std::cout << "##################" << std::endl;
	std::cout << "## Integer Test ##" << std::endl;
	std::cout << "##################" << std::endl;
	std::cout << std::endl;
	//Переменные типа INT
	int array_int[5] = {1, 2, 3, 4, 5};
	iter(array_int, 5, print);		std::cout << std::endl;
	iter(array_int, 5, plusplus);	std::cout << "PlusPlus()\n" << std::endl;
	iter(array_int, 5, print);		std::cout << std::endl;

	//************************************************//
	//************** Тест с типом FLOAT **************//
	//************************************************//
	std::cout << "##################" << std::endl;
	std::cout << "### Float Test ###" << std::endl;
	std::cout << "##################" << std::endl;
	std::cout << std::endl;
	//Переменные типа FLOAT
	float array_float[5] = {1.23f, 2.23f, 3.23f, 4.23f, 5.23f};
	iter(array_float, 5, print);	std::cout << std::endl;
	iter(array_float, 5, plusplus);	std::cout << "PlusPlus()\n" << std::endl;
	iter(array_float, 5, print);	std::cout << std::endl;

	//************************************************//
	//************** Тест с типом CHAR ***************//
	//************************************************//
	std::cout << "#################" << std::endl;
	std::cout << "### Char Test ###" << std::endl;
	std::cout << "#################" << std::endl;
	std::cout << std::endl;
	//Переменные типа CHAR
	char array_char[5] = {'A', 'B', 'C', 'D', 'E'};
	iter(array_char, 5, print);		std::cout << std::endl;
	iter(array_char, 5, plusplus);	std::cout << "PlusPlus()\n" << std::endl;
	iter(array_char, 5, print);		std::cout << std::endl;

	//************************************************//
	//************* Тест с типом PEOPLE **************//
	//************************************************//
	std::cout << "#################" << std::endl;
	std::cout << "## People Test ##" << std::endl;
	std::cout << "#################" << std::endl;
	std::cout << std::endl;
	//Переменные типа PEOPLE
	People array_people[3] = {People("Anton", 42), People("Denis", 35), People("Ded_Ivan", 73)};
	iter(array_people, 3, print);		std::cout << std::endl;
	iter(array_people, 3, plusplus);	std::cout << "PlusPlus()\n" << std::endl;
	iter(array_people, 3, print);		std::cout << std::endl;
	iter(array_people, 3, newname);		std::cout << "NewName()\n" << std::endl;
	iter(array_people, 3, print);		std::cout << std::endl;
	iter(array_people, 3, newname);		std::cout << "NewName()\n" << std::endl;
	iter(array_people, 3, print);		std::cout << std::endl;

	return (0);
}
