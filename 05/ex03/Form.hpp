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
		virtual ~Form(); //Деструктор стал виртуальным

		Form &operator=(const Form &copy);

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
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
		void beSigned(const Bureaucrat &bureaucrat);

		//Метод для исполнения формы
		virtual void execute(const Bureaucrat &bureaucrat) const = 0;
		//Метод для определения исключения при исполнении формы
		class ExecWithoutSignException : public std::exception
		{
			public:
    			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
