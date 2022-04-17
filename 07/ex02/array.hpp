#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

//Описание шаблонного класса массива
template<typename T>
class Array
{
	private:
		unsigned int array_size;
		T *array;

	public:
		Array(void) : array_size(0), array(NULL){};
		Array(unsigned int n) : array_size(n), array(new T[n]){};
		Array(const Array &copy) : array_size(0), array(NULL) {*this = copy;};
		~Array(void){if (this->array != NULL){delete[] this->array;}};
		unsigned int size(void) const{return this->array_size;}

		//Копирование объекта
		Array &operator=(const Array &copy)
		{
			this->array_size = copy.array_size;
			if (this->array != NULL){delete[] this->array;}
			this->array = new T[copy.array_size];
			for (unsigned int i=0; i<copy.array_size; i++){this->array[i] = copy.array[i];}
			return *this;
		};

		//Обращение к элементу массива и исключение для некорректного индекса
		T &operator[](const unsigned int i)
		{
			if (i >= this->array_size){throw Array::outException();}
			return this->array[i];
		};

		//метод для определения исключительных ситуаций 
		class outException : public std::exception
		{
			public:
				const char *what() const throw(){return "Array: incorrect index (out)!";}
		};
};

#endif
