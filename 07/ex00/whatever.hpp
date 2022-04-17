#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

//Описание шаблонных функций по заданию
template <typename T> //Синтаксическая конструкция для обозначения шаблонной функции
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T &min(const T &a, const T &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
	if (a > b)
		return a;
	return b;
}

//Дополнительный класс для тестирования шаблонных функций с объектами класса
class People
{
	private:
		std::string name;
		unsigned int age;

	public:
		People(void) : name("DefaultName"), age(0){}
		People(std::string name, unsigned int age) : name(name), age(age){}
		People(const People &copy) : name(copy.name), age(copy.age){};
		People &operator=(People &copy){this->name = copy.name; this->age = copy.age; return (*this);}
		bool operator==(People const &obj) const{return (this->age == obj.age);}
		bool operator!=(People const &obj) const{return (this->age != obj.age);}
		bool operator> (People const &obj) const{return (this->age >  obj.age);}
		bool operator< (People const &obj) const{return (this->age <  obj.age);}
		bool operator>=(People const &obj) const{return (this->age >= obj.age);}
		bool operator<=(People const &obj) const{return (this->age <= obj.age);}
		std::string getName() const{return this->name;}
		int getAge() const{return this->age;}
};
std::ostream &operator<<(std::ostream &out, const People &people){out << "«" << people.getName() << "» (" << people.getAge() << ")"; return out;};

#endif
