#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

//Описание шаблонной функции по заданию
template<typename T>
void iter(T *array, const size_t size, void(*fun)(T &arg))
{
	for (size_t i=0; i<size; i++){fun(array[i]);}
}

//Шаблонная функция для вывода
template<typename T>
void print(T &arg){std::cout << arg << std::endl;}

//Шаблонная функция для увеличения аргумента
template<typename T>
void plusplus(T &arg){arg++;}

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
		People operator++(int){People ret = *this; this->age++; return(ret);}
		std::string getName() const{return this->name;}
		void setName(std::string name){this->name = name;}
		int getAge() const{return this->age;}
};
std::ostream &operator<<(std::ostream &out, const People &people){out << "«" << people.getName() << "» (" << people.getAge() << ")"; return out;};

//НЕшаблонная функция для переименования человека в классе человека
void newname(People &arg){arg.setName("new_" + arg.getName());}

#endif
