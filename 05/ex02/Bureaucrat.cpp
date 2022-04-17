#include "Bureaucrat.hpp"
#include "Form.hpp"

//Дефолтный конструктор для объектов без скобок
Bureaucrat::Bureaucrat() : name("DefaultBureaucrat")
{
	this->grade = 150;
	std::cout << "# Bureaucrat: Default constructor called # -> name=«" << this->name << "», grade=«" << this->grade << "»" << std::endl;
}
//Конструктор, создающий объект с именем и грейдом
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1){throw Bureaucrat::GradeTooHighException();}
	else if (grade > 150){throw Bureaucrat::GradeTooLowException();}
	this->grade = grade;
	std::cout << "# Bureaucrat: Constructor Name&Grade called # -> name=«" << this->name << "», grade=«" << this->grade << "»" << std::endl;
}
//Конструктор, копирующий другой объект
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	this->grade = copy.grade;
	std::cout << "# Bureaucrat: Copy constructor called # -> name=«" << this->name << "», grade=«" << this->grade << "»" << std::endl;
}
//Оператор копирования объекта
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->grade = copy.grade;
	std::cout << "# Bureaucrat: Copy operator called # -> name=«" << this->name << "», grade=«" << this->grade << "»" << std::endl;
	return *this;
}
//Деструктор
Bureaucrat::~Bureaucrat(){std::cout << "# Bureaucrat: Destructor of «" << this->name << "» called #" << std::endl;}

//Методы геттеры имени и грейда
const std::string Bureaucrat::getName(void) const{return this->name;}
int Bureaucrat::getGrade(void) const{return this->grade;}

//Методы для увеличения и уменьшения грейда
void Bureaucrat::incrementGrade(void)
{
	if (this->grade > 1){this->grade--;}
	else {throw Bureaucrat::GradeTooHighException();}
}
void Bureaucrat::decrementGrade(void)
{
	if (this->grade < 150){this->grade++;}
	else {throw Bureaucrat::GradeTooLowException();}
}

//Метод what() для обработки ошибочных ситуаций
const char *Bureaucrat::GradeTooHighException::what() const throw(){return "Bureaucrat's grade is already High";}
const char *Bureaucrat::GradeTooLowException::what() const throw(){return "Bureaucrat's grade is already Low";}

//Метод работы с формой
void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat: «" << this->name << "» signed «" << form.getName() << "»" << std::endl;
	}
	catch (std::exception &excep)
	{
		std::cout << "Bureaucrat: «" << this->name << "» couldn’t sign «" << form.getName() << "» because «" << excep.what() << "»\n";
	}
}

//Метод исполнения формы
void Bureaucrat::executeForm(const Form &form) const
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat: «" << this->name << "» executed «" << form.getName() << "»" << std::endl;
	}
	catch (std::exception &excep)
	{
		std::cout << "Bureaucrat: «" << this->name << "» couldn’t execute «" << form.getName() << "» because «" << excep.what() << "»\n";
	}
}

//Обработчик вывода переменной класса в поток
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << "«" << bureaucrat.getName() << "», bureaucrat grade «" << bureaucrat.getGrade() << "»";
	return out;
}
