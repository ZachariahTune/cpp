#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class	Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &copy);

		//Геттеры имени и грейда
		const std::string getName(void) const;
		int getGrade(void) const;

		//Методы увеличение и уменьшение грейда
		void incrementGrade(void);
		void decrementGrade(void);

		//методы для определения исключительных ситуаций 
		//являются наследниками стандартного класса std::exception
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw(); //throw() определяет функцию what(), которая будет обрабатывать ошибочную ситуацию
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw(); //throw() определяет функцию what(), которая будет обрабатывать ошибочную ситуацию
		};
};

//Обработчик вывода переменной класса в поток
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
