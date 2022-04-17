#include "Bureaucrat.hpp"

//Дефолтный конструктор для объектов без скобок
Bureaucrat::Bureaucrat() : name("DefaultName")
{
	this->grade = 150;
	std::cout << "# Default constructor called #	->	name=«" << this->name << "», grade=«" << this->grade << "»" << std::endl;
}
//Конструктор, создающий объект с именем и грейдом
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1){throw Bureaucrat::GradeTooHighException();}			//Оператор throw определяет тип и значение исключения для блока catch(тип значение){}
	else if (grade > 150){throw Bureaucrat::GradeTooLowException();}	//Оператор throw определяет тип и значение исключения для блока catch(тип значение){}
	this->grade = grade;
	std::cout << "# Constructor Name&Grade called # -> name=«" << this->name << "», grade=«" << this->grade << "»" << std::endl;
}
//Конструктор, копирующий другой объект
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	this->grade = copy.grade;
	std::cout << "# Copy constructor called # -> name=«" << this->name << "», grade=«" << this->grade << "»" << std::endl;
}
//Оператор копирования объекта
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->grade = copy.grade;
	std::cout << "# Copy operator called # -> name=«" << this->name << "», grade=«" << this->grade << "»" << std::endl;
	return *this;
}
//Деструктор
Bureaucrat::~Bureaucrat(){std::cout << "# Destructor of «" << this->name << "» called #" << std::endl;}

//Методы геттеры имени и грейда
const std::string Bureaucrat::getName(void) const{return this->name;}
int Bureaucrat::getGrade(void) const{return this->grade;}

//Метод для увеличения грейда
void Bureaucrat::incrementGrade(void)
{
	if (this->grade > 1){this->grade--;}
	else {throw Bureaucrat::GradeTooHighException();}	//Оператор throw определяет тип и значение исключения для блока catch(тип значение){}
}

//Метод для уменьшения грейда
void Bureaucrat::decrementGrade(void)
{
	if (this->grade < 150){this->grade++;}
	else {throw Bureaucrat::GradeTooLowException();}	//Оператор throw определяет тип и значение исключения для блока catch(тип значение){}
}

//Метод what() подкласса GradeTooHighException для обработки ошибочной ситуации
const char *Bureaucrat::GradeTooHighException::what() const throw()	//throw() определяет функцию what(), которая будет обрабатывать ошибочную ситуацию
{
	return "Grade is already High";
}

//Метод what() подкласса GradeTooLowException для обработки ошибочной ситуации
const char *Bureaucrat::GradeTooLowException::what() const throw()	//throw() определяет функцию what(), которая будет обрабатывать ошибочную ситуацию
{
	return "Grade is already Low";
}

//Обработчик вывода переменной класса в поток
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << "«" << bureaucrat.getName() << "», bureaucrat grade «" << bureaucrat.getGrade() << "»";
	return out;
}
