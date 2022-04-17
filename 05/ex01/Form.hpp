#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &copy);
		~Form();

		Form &operator=(const Form &copy);

		//Методы-геттеры переменных
		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;

		//Методы для определения исключительных ситуаций 
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		//Метод подписания формы
		void beSigned(const Bureaucrat &bureaucrat);
};

//Обработчик вывода переменной класса в поток
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
