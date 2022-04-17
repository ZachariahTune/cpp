#include "span.hpp"

//Вспомогательная функция вывода методов shortestSpan и longestSpan
void ft_cout_short_long(Span &span)
{
	try {std::cout << "shortestSpan = " << span.shortestSpan() << std::endl;}
	catch (const std::exception &e){std::cerr << e.what() << std::endl;}
	try {std::cout << "longestSpan = " << span.longestSpan() << std::endl;}
	catch (const std::exception &e){std::cerr << e.what() << std::endl;}
}

//Вспомогательная функция для наполнения SPAN
void ft_addNumber(Span &span, int randsize)
{
	try {span.addNumber((rand() % (randsize*2)) - randsize);}
	catch (const std::exception &e){std::cerr << e.what() << std::endl;}
}

//Вспомогательная функция для наполнения SPAN одной вставкой
void ft_addNumbers(Span &span, std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	try {span.addNumbers(begin, end);}
	catch (const std::exception &e){std::cerr << e.what() << std::endl;}
}

int	main(void)
{
	srand(time(0));
	{
		//***********************************************//
		//*************** Тест по заданию ***************//
		//***********************************************//
		std::cout << std::endl;
		std::cout << "########################" << std::endl;
		std::cout << "##### Subject Test #####" << std::endl;
		std::cout << "########################" << std::endl;
		std::cout << std::endl;
		
		//Тест по аданию
		Span sp = Span(7);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Span: " << sp << std::endl;
		std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
		
		//Дополнительные тесты на опирование
		Span new1 = Span(sp);
		new1.addNumber(99);
		Span new2;
		new2 = new1;
		new2.addNumber(-99);
		std::cout << "\nSpan: " << sp << std::endl;
		std::cout << "New1: " << new1 << std::endl;
		std::cout << "New2: " << new2 << std::endl;
	}

	{
		//***********************************************//
		//**************** Основной тест ****************//
		//***********************************************//
		std::cout << std::endl;
		std::cout << "#########################" << std::endl;
		std::cout << "##### Osnovnoy Test #####" << std::endl;
		std::cout << "#########################" << std::endl;
		std::cout << std::endl;
	
		size_t span_size = 100;
		Span span(span_size);
		std::cout << "Span: " << span << std::endl;

		//Вывод shortest и longest в пустом SPAN
		ft_cout_short_long(span);

		//Добавление одного числа
		ft_addNumber(span, 10000);
		std::cout << "Span: " << span << std::endl;

		//Вывод shortest и longest в SPAN с одним элементом
		ft_cout_short_long(span);

		//Добавление еще одного числа
		ft_addNumber(span, 10000);
		std::cout << "Span: " << span << std::endl;

		//Вывод shortest и longest в SPAN с двумя элементами
		ft_cout_short_long(span);

		//Добавление максимального количества чисел
		for (size_t i=0; i<span_size; i++){ft_addNumber(span, 10000);}
		std::cout << "Span: " << span << std::endl;

		//Вывод shortest и longest в заполненном SPAN
		ft_cout_short_long(span);

		//Последний вывод SPAN (отсортированный)
		//std::cout << "Span: " << span << std::endl;
	}

	{
		//************************************************//
		//************* Тест на Unsigned INT *************//
		//************************************************//
		std::cout << std::endl;
		std::cout << "##########################" << std::endl;
		std::cout << "#### Test na Unsigned ####" << std::endl;
		std::cout << "##########################" << std::endl;
		std::cout << std::endl;

		Span span(2);
		span.addNumber(2000000000);
		span.addNumber(-2000000000);
		std::cout << "Span: " << span << std::endl;
		ft_cout_short_long(span);
	}

	{
		//************************************************//
		//********* Тест на диапазон для вставки *********//
		//************************************************//
		std::cout << std::endl;
		std::cout << "##########################" << std::endl;
		std::cout << "####### Range Test #######" << std::endl;
		std::cout << "##########################" << std::endl;
		std::cout << std::endl;

		//Создание пустого SPAN с лимитом на 100 элементов
		Span span(100);
		
		//Создание простого вектора со случайными числами
		std::vector<int> tmp;
		for (int i=0; i<98; i++){tmp.push_back((rand() % 20000) - 10000);}
		std::cout << "Vector: ";
		for (std::vector<int>::iterator i=tmp.begin(); i!=tmp.end(); i++){std::cout << *i << " ";}
		std::cout << std::endl;

		//Вывод пустого SPAN
		std::cout << "Span: " << span << std::endl;

		//Вывод shortest и longest в пустом SPAN
		ft_cout_short_long(span);

		//Добавление одного числа в SPAN
		ft_addNumber(span, 10000);
		std::cout << "Span: " << span << std::endl;

		//Вывод shortest и longest в SPAN с одним эелементом
		ft_cout_short_long(span);
		
		//Добавление еще одного числа в SPAN
		ft_addNumber(span, 10000);
		std::cout << "Span: " << span << std::endl;

		//Вывод shortest и longest в SPAN с двумя эелементами
		ft_cout_short_long(span);
		
		//Добавление в SPAN всех чисел из вектора
		ft_addNumbers(span, tmp.begin(), tmp.end());
		std::cout << "Span: " << span << std::endl;
		
		//Вывод shortest и longest в заполненном SPAN
		ft_cout_short_long(span);
	}

	return (0);
}
