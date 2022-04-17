#include "easyfind.hpp"
#include <array>
#include <list>
#include <vector>
#include <deque>

//Контейнер — способ хранения набора объектов в памяти.

int	main(void)
{
	//************************************************//
	//*********** Тест с контейнером ARRAY ***********//
	//************************************************//
	std::cout << std::endl;
	std::cout << "################" << std::endl;
	std::cout << "## Array Test ##" << std::endl;
	std::cout << "################" << std::endl;
	std::cout << std::endl;

	//C++ включает в себя функционал, упрощающий управление массивами - std::array
	//Функциональность такого массива не пропадает при передаче в функцию

	std::array<int,6>myArray = {12, 5, -19, 0, 23, -2};
	std::array<int,6>::const_iterator cItAr;
	for (cItAr=myArray.begin(); cItAr!=myArray.end(); cItAr++){std::cout << *cItAr << " ";}
	std::cout << std::endl;

	try
	{	std::cout << "Value «5» of myArray -> ";
		cItAr = easyFind(myArray, 5);
		std::cout << *cItAr << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	try
	{	std::cout << "Value «9» of myArray -> ";
		cItAr = easyFind(myArray, 9);
		std::cout << *cItAr << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	try
	{	std::cout << "Value «0» of myArray -> ";
		cItAr = easyFind(myArray, 0);
		std::cout << *cItAr << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	try
	{	std::cout << "Value «-19» of myArray -> ";
		cItAr = easyFind(myArray, -19);
		std::cout << *cItAr << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	//***********************************************//
	//*********** Тест с контейнером LIST ***********//
	//***********************************************//
	std::cout << std::endl;
	std::cout << "#################" << std::endl;
	std::cout << "### List Test ###" << std::endl;
	std::cout << "#################" << std::endl;
	std::cout << std::endl;

	//Также C++ включает в себя функционал, упрощающий управление списками - std::list
	//push_front() добавляет элемент к списку, помещая в начало списка
	//push_back() добавляет элемент к списку, помещая в конец списка

	std::list<int>myList;
	std::list<int>::const_iterator cItLi;
	for (int i=0; i<5; i++){myList.push_back(i);}
	for (cItLi=myList.begin(); cItLi!=myList.end(); cItLi++){std::cout << *cItLi << " ";}
	std::cout << std::endl;
	for (int i=5; i<10; i++){myList.push_front(i);}
	for (cItLi=myList.begin(); cItLi!=myList.end(); cItLi++){std::cout << *cItLi << " ";}
	std::cout << std::endl;

	try
	{	std::cout << "Value «5» of myList -> ";
		cItLi = easyFind(myList, 5);
		std::cout << *cItLi << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	try
	{	std::cout << "Value «11» of myList -> ";
		cItLi = easyFind(myList, 11);
		std::cout << *cItLi << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	try
	{	std::cout << "Value «2» of myList -> ";
		cItLi = easyFind(myList, 2);
		std::cout << *cItLi << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	//***********************************************//
	//********** Тест с контейнером VECTOR **********//
	//***********************************************//
	std::cout << std::endl;
	std::cout << "#################" << std::endl;
	std::cout << "## Vector Test ##" << std::endl;
	std::cout << "#################" << std::endl;
	std::cout << std::endl;

	//Также C++ включает в себя функционал, работающий с векторами - std::vector
	//Что-то вроде упрощенного списка, помещать элементы в который можно только в конец
	//push_back() добавляет элемент к вектору, помещая его в конец
	//push_front() - не поддерживается!!!

	std::vector<int>myVector;
	std::vector<int>::const_iterator cItVe;
	for (int i=0; i<10; i++){myVector.push_back(i * 2);}
	for (cItVe=myVector.begin(); cItVe!=myVector.end(); cItVe++){std::cout << *cItVe << " ";}
	std::cout << std::endl;

	try
	{	std::cout << "Value «4» of myVector -> ";
		cItVe = easyFind(myVector, 4);
		std::cout << *cItVe << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	try
	{	std::cout << "Value «5» of myVector -> ";
		cItVe = easyFind(myVector, 5);
		std::cout << *cItVe << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	try
	{	std::cout << "Value «6» of myVector -> ";
		cItVe = easyFind(myVector, 6);
		std::cout << *cItVe << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	//************************************************//
	//*********** Тест с контейнером DEQUE ***********//
	//************************************************//
	std::cout << std::endl;
	std::cout << "################" << std::endl;
	std::cout << "## Deque Test ##" << std::endl;
	std::cout << "################" << std::endl;
	std::cout << std::endl;

	//Также C++ включает в себя функционал, работающий с деками (двусторонняя очередь) - std::deque
	//Является списком, но дополнен некоторыми свойствами
	//push_back() добавляет элемент в конец
	//push_front() добавляет элемент в начало

	std::deque<int>myDeque;
	std::deque<int>::const_iterator cItDe;
	for (int i=0; i<5; i++){myDeque.push_back(i * 2);}
	for (cItDe=myDeque.begin(); cItDe!=myDeque.end(); cItDe++){std::cout << *cItDe << " ";}
	std::cout << std::endl;
	for (int i=5; i<10; i++){myDeque.push_front(i * 2);}
	for (cItDe=myDeque.begin(); cItDe!=myDeque.end(); cItDe++){std::cout << *cItDe << " ";}
	std::cout << std::endl;

	try
	{	std::cout << "Value «4» of myDeque -> ";
		cItDe = easyFind(myDeque, 4);
		std::cout << *cItDe << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	try
	{	std::cout << "Value «5» of myDeque -> ";
		cItDe = easyFind(myDeque, 5);
		std::cout << *cItDe << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	try
	{	std::cout << "Value «6» of myDeque -> ";
		cItDe = easyFind(myDeque, 6);
		std::cout << *cItDe << std::endl;
	}	catch(std::exception &e){std::cout << e.what() << std::endl;}

	return (0);
}
