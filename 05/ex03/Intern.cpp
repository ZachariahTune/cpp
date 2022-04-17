#include "Intern.hpp"

//Дефолтный конструктор для объектов без скобок
Intern::Intern(){std::cout << "# Intern: Default constructor called #" << std::endl;}
//Конструктор, копирующий другой объект
Intern::Intern(const Intern &copy)
{
	*this = copy;
	std::cout << "# Intern: Copy constructor called #" << std::endl;
}
//Оператор копирования объекта
Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	std::cout << "# Intern: Copy operator called #" << std::endl;
	return *this;
}
//Деструктор
Intern::~Intern(){std::cout << "# Intern: Destructor called #" << std::endl;}

//Методы, возвращающие объекты подклассов Форм
Form *Intern::returnShrubberyCreationForm(std::string target){return (new ShrubberyCreationForm(target));}
Form *Intern::returnRobotomyRequestForm(std::string target){return (new RobotomyRequestForm(target));}
Form *Intern::returnPresidentialPardonForm(std::string target){return (new PresidentialPardonForm(target));}

//Метод поиска и создания формы по названию и цели
Form *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formnames[] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	Form *(Intern::*formmethods[])(std::string) = {&Intern::returnShrubberyCreationForm, &Intern::returnRobotomyRequestForm, &Intern::returnPresidentialPardonForm};
	for (int i=0; i<3; i++)
	{
		if (formName == formnames[i])
		{
			Form *newForm = (this->*formmethods[i])(formTarget);
			std::cout << "Intern created form: formName = «" << formName << "», formTarget = «" << formTarget << "»" << std::endl;
			std::cout << *newForm << std::endl;
			return newForm;
	}	}
	std::cout << "Intern couldn’t create form «" << formName << "»" << std::endl;
	throw NoFormException();
}

//Метод what() для обработки ошибочной ситуации
const char *Intern::NoFormException::what() const throw(){return "Form not found";}
