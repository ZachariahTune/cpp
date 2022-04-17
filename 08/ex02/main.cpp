#include "MutantStack.hpp"
#include <list>

int	main(void)
{
	{
		//***********************************************//
		//*************** Тест по заданию ***************//
		//***********************************************//
		std::cout << std::endl;
		std::cout << "########################" << std::endl;
		std::cout << "##### Subject Test #####" << std::endl;
		std::cout << "########################" << std::endl;
		std::cout << std::endl;

		//Создание стека и наполнение значениями
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack.top = " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "mstack.size = " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		//Создание итераторов и вывод всех элементов стека
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it; --it;
		std::cout << "mstack = ";
		while (it != ite){std::cout << *it << " "; ++it;}
		std::cout << std::endl;

		//Копирование MutantStack в стандартный стек
		std::stack<int> s(mstack);
		std::cout << "s.top = " << s.top() << std::endl;
		std::cout << "s.size = " << s.size() << std::endl;
		//"Кривой" вывод стека S
		std::cout << "s = ";
		for (unsigned int s_size=s.size(); s_size>0; s_size--)
		{
			std::cout << s.top() << " ";
			s.pop();
		}	std::cout << std::endl;

		//************************************************//
		//****** Дополнительный тест на копирование ******//
		//************************************************//
		std::cout << std::endl;
		std::cout << "########################" << std::endl;
		std::cout << "## Dopolnitelniy Test ##" << std::endl;
		std::cout << "########################" << std::endl;
		std::cout << std::endl;

		//Создаем новый MutantStack и копируем старый конструктором копирования
		MutantStack<int> mstack2(mstack);
		mstack2.push(-53);
		std::cout << "mstack2 = ";
		for (MutantStack<int>::iterator i=mstack2.begin(); i!=mstack2.end(); i++){std::cout << *i << " ";}
		std::cout << std::endl;

		//Создаем еще MutantStack и копируем предыдущий оператором присваивания
		MutantStack<int> mstack3;
		mstack3 = mstack2;
		mstack3.push(99);
		std::cout << "mstack3 = ";
		for (MutantStack<int>::iterator i=mstack3.begin(); i!=mstack3.end(); i++){std::cout << *i << " ";}
		std::cout << std::endl;

		//Вывод всех трех MutantStack
		std::cout << "mstack = ";
		for (MutantStack<int>::iterator i=mstack.begin(); i!=mstack.end(); i++){std::cout << *i << " ";}
		std::cout << std::endl;

		std::cout << "mstack2 = ";
		for (MutantStack<int>::iterator i=mstack2.begin(); i!=mstack2.end(); i++){std::cout << *i << " ";}
		std::cout << std::endl;

		std::cout << "mstack3 = ";
		for (MutantStack<int>::iterator i=mstack3.begin(); i!=mstack3.end(); i++){std::cout << *i << " ";}
		std::cout << std::endl;
	}
	
	{
		//**********************************************//
		//************ Тест со списком LIST ************//
		//**********************************************//
		std::cout << std::endl;
		std::cout << "########################" << std::endl;
		std::cout << "#### Test with List ####" << std::endl;
		std::cout << "########################" << std::endl;
		std::cout << std::endl;

		//Создание списка и наполнение значениями
		std::list<int> tlist;
		tlist.push_back(5);
		tlist.push_back(17);
		std::cout << "tlist.back = " << tlist.back() << std::endl;
		tlist.pop_back();
		std::cout << "tlist.size = " << tlist.size() << std::endl;
		tlist.push_back(3);
		tlist.push_back(5);
		tlist.push_back(737);
		tlist.push_back(0);

		//Создание итераторов и вывод всех элементов списка
		std::list<int>::iterator it = tlist.begin();
		std::list<int>::iterator ite = tlist.end();
		++it; --it;
		std::cout << "tlist = ";
		while (it != ite){std::cout << *it << " "; ++it;}
		std::cout << std::endl;
	}
	
	return (0);
}
