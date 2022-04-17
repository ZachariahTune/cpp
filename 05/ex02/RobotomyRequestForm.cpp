#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//Дефолтный конструктор для объектов без скобок
RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
	this->target = "DefaultTarget";
	std::cout << "# RobotomyRequestForm: Default constructor called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
}
//Конструктор, создающий объект с именем и параметрами
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	this->target = target;
	std::cout << "# RobotomyRequestForm: Constructor Target called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
}
//Конструктор, копирующий другой объект
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form("RobotomyRequestForm", 72, 45)
{
	this->target = copy.target;
	std::cout << "# RobotomyRequestForm: Copy constructor called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
}
//Оператор копирования объекта
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	this->target = copy.target;
	std::cout << "# RobotomyRequestForm: Copy operator called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
	return *this;
}
//Деструктор
RobotomyRequestForm::~RobotomyRequestForm(){std::cout << "# RobotomyRequestForm: Destructor of «" << this->getName() << "» called #" << std::endl;}

//Метод what() для обработки ошибочных ситуаций
const char *RobotomyRequestForm::RobotomyExecFail::what() const throw(){return "Robot broke down (!!! try again !!!)";}

//Метод исполнения формы бюрократом
void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (this->getIsSigned() == false){throw Form::ExecWithoutSignException();}
	if (bureaucrat.getGrade() > this->getGradeToExec()){throw Form::GradeTooHighException();}
	std::cout << "RobotomyRequestForm: BBBBBBBBBBBBBBBBBBBBBBBBZZZZZZZZZZZZZZZZZZZZZZZ - ";
	srand(time(0));
	if (rand() % 2 == 0){std::cout << "«" << this->target << "» robotomized (SUCCESS)" << std::endl;}
	else 
	{
		std::cout << "«" << this->target << "» not robotomized (FAIL)" << std::endl;
		throw RobotomyRequestForm::RobotomyExecFail();
	}
}
