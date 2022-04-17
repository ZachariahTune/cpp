#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class	Span
{
	private:
		std::vector<int> nums;	//Вектор чисел
		unsigned int maxsize;	//Максимальное количество чисел
		unsigned int size;		//Текущее количество чисел

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		~Span();

		Span &operator=(const Span &copy);

		//Геттеры
		std::vector<int> getNums(void) const;
		unsigned int getSize(void) const;

		//Наполнение вектора числами
		void addNumber(const int num);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		//Расстояния между элементами
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

		//Методы для определения исключительных ситуаций
		class Empty :	public std::exception {public: const char *what() const throw(){return ("Span is empty");}};
		class OnlyOne :	public std::exception {public: const char *what() const throw(){return ("Only one element");}};
		class Full :	public std::exception {public: const char *what() const throw(){return ("Span is full");}};
		class NoSpace :	public std::exception {public: const char *what() const throw(){return ("No space for insert");}};
};

//Оператор вывода в поток
std::ostream &operator<<(std::ostream &out, const Span &Span);

#endif
