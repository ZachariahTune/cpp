#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(){std::cout << "# MutantStack: Constructor called #" << std::endl;}
		MutantStack<T>(const MutantStack<T> &copy) : std::stack<T>(copy){std::cout << "# MutantStack: Copy constructor called #" << std::endl;}
		virtual ~MutantStack<T>(){std::cout << "# MutantStack: Destructor called #" << std::endl;}

		MutantStack<T> &operator=(const MutantStack<T> &copy)
		{
			std::cout << "# MutantStack: Copy operator called #" << std::endl;
			if (this != &copy){this->c = copy.c;}
			return (*this);
		}

		//Создание псевдонима
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void){return (this->c.begin());}
		iterator end(void){return (this->c.end());}
};

#endif
