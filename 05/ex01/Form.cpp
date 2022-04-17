#include "Form.hpp"
#include "Bureaucrat.hpp"

//Дефолтный конструктор для объектов без скобок
Form::Form() : name("DefaultForm"), gradeToSign(150), gradeToExec(150)
{
	this->isSigned = false;
	std::cout << "# Form: Default constructor called # -> name=«" << this->name << "», isSigned=«" << this->isSigned << "», gradeToSign=«" << this->gradeToSign << "», gradeToExec=«" << this->gradeToExec << "»" << std::endl;
}
//Конструктор, создающий объект с именем и параметрами
Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	this->isSigned = false;
	if (gradeToSign < 1 || gradeToExec < 1){throw Form::GradeTooHighException();}
	if (gradeToSign > 150 || gradeToExec > 150){throw Form::GradeTooLowException();}
	std::cout << "# Form: Constructor Name&Grade called # -> name=«" << this->name << "», isSigned=«" << this->isSigned << "», gradeToSign=«" << this->gradeToSign << "», gradeToExec=«" << this->gradeToExec << "»" << std::endl;
}
//Конструктор, копирующий другой объект
Form::Form(const Form &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec)
{
	this->isSigned = copy.getIsSigned();
	std::cout << "# Form: Copy constructor called # -> name=«" << this->name << "», isSigned=«" << this->isSigned << "», gradeToSign=«" << this->gradeToSign << "», gradeToExec=«" << this->gradeToExec << "»" << std::endl;
}
//Оператор копирования объекта
Form &Form::operator=(const Form &copy)
{
	this->isSigned = copy.getIsSigned();
	std::cout << "# Form: Copy operator called # -> name=«" << this->name << "», isSigned=«" << this->isSigned << "», gradeToSign=«" << this->gradeToSign << "», gradeToExec=«" << this->gradeToExec << "»" << std::endl;
	return *this;
}
//Деструктор
Form::~Form(){std::cout << "# Form: Destructor of «" << this->name << "» called #" << std::endl;}

//Методы геттеры переменных
std::string Form::getName(void) const{return this->name;}
bool Form::getIsSigned(void) const{return this->isSigned;}
int Form::getGradeToSign(void) const{return this->gradeToSign;}
int Form::getGradeToExec(void) const{return this->gradeToExec;}

//Метод what() для обработки ошибочных ситуаций
const char *Form::GradeTooHighException::what() const throw(){return "Form's grade is too High";}
const char *Form::GradeTooLowException::what() const throw(){return "Form's grade is too Low";}

//Метод подписания формы
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getGradeToSign() < bureaucrat.getGrade()){throw Form::GradeTooHighException();}
	this->isSigned = true;
}

//Обработчик вывода переменной класса в поток
std::ostream &operator<<(std::ostream &out, const Form &Form)
{
	out << "Form «" << Form.getName() << "» needs grade «" << Form.getGradeToSign() << "» for sign, grade «" << Form.getGradeToExec() << "» for execute. ";
	if (Form.getIsSigned() == true){out << "Form is signed!";}
	if (Form.getIsSigned() == false){out << "Form is not signed!";}
	return out;
}
