#include "Base.hpp"

//В отличие от оператора static_cast, который преобразует типы данных,
//оператор dynamic_cast преобразует указатели или ссылки (вниз по иерархии наследования)

//По заданию все 4 класса НЕ должны быть созданы в классической канонической форме
//Для полноценного теста можно раскомментировать строки, чтобы получить каноническую форму
//Base::Base(){std::cout << "# Base constructor called #" << std::endl;}
Base::~Base(){/*std::cout << "# Base destructor called #" << std::endl;*/}
//A::A(){std::cout << "# A constructor called #" << std::endl;}
//A::~A(){std::cout << "# A destructor called #" << std::endl;}
//B::B(){std::cout << "# B constructor called #" << std::endl;}
//B::~B(){std::cout << "# B destructor called #" << std::endl;}
//C::C(){std::cout << "# C constructor called #" << std::endl;}
//C::~C(){std::cout << "# C destructor called #" << std::endl;}

//Случайная генерация одного из классов (A, B или C)
Base	*generate(void)
{
	srand(time(0));
	int	i = rand() % 3;

	if (i == 0){return (new A);}
	else if (i == 1){return (new B);}
	else {return (new C);}
}

//Идентификация подкласса через приведение указателя на объект
void identify(Base *ptr)
{
	std::cout << "Created class is ";
	if (dynamic_cast<A*>(ptr)){std::cout << "A-type" << std::endl;}
	else if (dynamic_cast<B*>(ptr)){std::cout << "B-type" << std::endl;}
	else {std::cout << "C-type" << std::endl;}
}

//Идентификация подкласса через приведение ссылки на объект
void identify(Base &ref)
{
	std::cout << "Created class is ";
	try
	{
		(void)dynamic_cast<A&>(ref);
		std::cout << "A-type" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B&>(ref);
			std::cout << "B-type" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "C-type" << std::endl;
}	}	}
