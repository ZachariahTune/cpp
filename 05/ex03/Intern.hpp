#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
	private:
		Form *returnShrubberyCreationForm(std::string target);
		Form *returnRobotomyRequestForm(std::string target);
		Form *returnPresidentialPardonForm(std::string target);

	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();

		Intern &operator=(const Intern &copy);

		//Поиск и создания формы по названию и цели
		Form *makeForm(std::string formName, std::string formTarget);
		//Обработки ошибочной ситуации, если форма не найдена
		class NoFormException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
