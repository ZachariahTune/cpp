#include "array.hpp"
#include <cstdlib>
#define MAX_VAL 750

//Задача заключается в том, чтобы создать шаблон для работы с массивом любого типа данных
//В угловых скобках мажду типом переменной и именем переменной будет указываться тип данных

int	main(void)
{
	//***********************************************//
	//*************** Тест из задания ***************//
	//***********************************************//
	Array<int>numbers(MAX_VAL);			//Создаем шаблонный INT массив "numbers" (с индексами 0-749)
	int *mirror = new int[MAX_VAL];		//Создаем обычный INT массив "mirror" (с индексами 0-749) 
	srand(time(NULL));
	for (int i=0; i<MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;				//Наполняем массив "numbers" случайными числами
		mirror[i] = value;				//Наполняем массив "mirror" такими же случайными числами
		//std::cerr << "numbers[" << i << "] = " << numbers[i] << "; mirror[" << i << "] = " << mirror[i] << std::endl;
	}
	{
		Array<int>tmp = numbers;		//Создаем шаблонный массив "tmp" в который копируем "numbers"
		Array<int>test(tmp);			//Создаем шаблонный массив "test" в который копируем "tmp"
	}
	for (int i=0; i<MAX_VAL; i++)
	{	if (mirror[i] != numbers[i])	//Если хоть один элемент "mirror" не равен элементу "numbers",
		{								//то программа остановится
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
	}	}
	try {numbers[-2] = 0;}				// !!! Некорректный индекс массива (-2)
	catch (const std::exception &e){std::cerr << e.what() << '\n';}
	try {numbers[MAX_VAL] = 0;}			// !!! Некорректный индекс массива (750)
	catch (const std::exception &e){std::cerr << e.what() << '\n';}
	for (int i=0; i<MAX_VAL; i++)
	{
		numbers[i] = rand();			//Назначаем новые значения массиву "numbers"
		//std::cerr << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}	delete [] mirror;
	
	//************************************************//
	//************* Тест с типом INTEGER *************//
	//************************************************//
	std::cout << std::endl;
	std::cout << "##################" << std::endl;
	std::cout << "## Integer Test ##" << std::endl;
	std::cout << "##################" << std::endl;
	std::cout << std::endl;
	try
	{
		Array<int>array1(5);
		for (unsigned int i=0; i<array1.size(); i++){array1[i] = i + 1;}
		for (unsigned int i=0; i<array1.size(); i++){std::cout << array1[i] << " ";}
		std::cout << std::endl;

		Array<int>array2(array1);
		for (unsigned int i=0; i<array2.size(); i++){array2[i] *= 10;}
		for (unsigned int i=0; i<array2.size(); i++){std::cout << array2[i] << " ";}
		std::cout << std::endl;

		Array<int>array3;
		array3 = array2;
		for (unsigned int i=0; i<array3.size(); i++){array3[i] *= 10;}
		for (unsigned int i=0; i<array3.size(); i++){std::cout << array3[i] << " ";}
		std::cout << std::endl;

		std::cout << array1[5] << std::endl; //Некорректный индекс
		std::cout << array1[6] << std::endl; //Не выводится!!!
	}
	catch (std::exception &e){std::cout << e.what() << std::endl;}

	//************************************************//
	//************** Тест с типом FLOAT **************//
	//************************************************//
	std::cout << std::endl;
	std::cout << "##################" << std::endl;
	std::cout << "### Float Test ###" << std::endl;
	std::cout << "##################" << std::endl;
	std::cout << std::endl;
	try
	{
		float floats[3] = {9.999, 99.99, 999.9};
		Array<float>array1(3);
		for (unsigned int i=0; i<array1.size(); i++){array1[i] = floats[i];}
		for (unsigned int i=0; i<array1.size(); i++){std::cout << array1[i] << " ";}
		std::cout << std::endl;

		Array<float>array2(array1);
		for (unsigned int i=0; i<array2.size(); i++){array2[i] *= 10;}
		for (unsigned int i=0; i<array2.size(); i++){std::cout << array2[i] << " ";}
		std::cout << std::endl;

		Array<float>array3;
		array3 = array2;
		for (unsigned int i=0; i<array3.size(); i++){array3[i] *= 10;}
		for (unsigned int i=0; i<array3.size(); i++){std::cout << array3[i] << " ";}
		std::cout << std::endl;

		std::cout << array1[3] << std::endl; //Некорректный индекс
		std::cout << array1[4] << std::endl; //Не выводится!!!
	}
	catch (std::exception &e){std::cout << e.what() << std::endl;}

	//*************************************************//
	//************** Тест с типом STRING **************//
	//*************************************************//
	std::cout << std::endl;
	std::cout << "###################" << std::endl;
	std::cout << "### String Test ###" << std::endl;
	std::cout << "###################" << std::endl;
	std::cout << std::endl;
	try
	{
		std::string str[2];
		str[0] = "Hello";
		str[1] = "World";
		
		Array<std::string>array1(2);
		for (unsigned int i=0; i<array1.size(); i++){array1[i] = str[i];}
		for (unsigned int i=0; i<array1.size(); i++){std::cout << array1[i] << " ";}
		std::cout << std::endl;
		
		Array<std::string>array2(array1);
		for (unsigned int i=0; i<array2.size(); i++){array2[i] = "*" + array2[i];}
		for (unsigned int i=0; i<array2.size(); i++){std::cout << array2[i] << " ";}
		std::cout << std::endl;
		
		Array<std::string>array3;
		array3 = array2;
		for (unsigned int i=0; i<array3.size(); i++){array3[i] = array3[i] + "*";}
		for (unsigned int i=0; i<array3.size(); i++){std::cout << array3[i] << " ";}
		std::cout << std::endl;

		std::cout << array1[2] << std::endl; //Некорректный индекс
		std::cout << array1[3] << std::endl; //Не выводится!!!
	}
	catch (std::exception &e){std::cout << e.what() << std::endl;}

	return (0);
}
