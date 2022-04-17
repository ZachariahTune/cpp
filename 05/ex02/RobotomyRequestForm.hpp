#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

		//Исполнение формы бюрократом
		void execute(const Bureaucrat &bureaucrat) const;
		//Метод для определения исключения при исполнении формы
		class RobotomyExecFail : public std::exception
		{
			public:
    			const char *what() const throw();
		};
};

#endif
