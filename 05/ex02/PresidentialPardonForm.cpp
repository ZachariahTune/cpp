#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//Дефолтный конструктор для объектов без скобок
PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5)
{
	this->target = "DefaultTarget";
	std::cout << "# PresidentialPardonForm: Default constructor called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
}
//Конструктор, создающий объект с именем и параметрами
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
	this->target = target;
	std::cout << "# PresidentialPardonForm: Constructor Target called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
}
//Конструктор, копирующий другой объект
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form("PresidentialPardonForm", 25, 5)
{
	this->target = copy.target;
	std::cout << "# PresidentialPardonForm: Copy constructor called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
}
//Оператор копирования объекта
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	this->target = copy.target;
	std::cout << "# PresidentialPardonForm: Copy operator called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
	return *this;
}
//Деструктор
PresidentialPardonForm::~PresidentialPardonForm(){std::cout << "# PresidentialPardonForm: Destructor of «" << this->getName() << "» called #" << std::endl;}

//Метод исполнения формы бюрократом
void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (this->getIsSigned() == false){throw Form::ExecWithoutSignException();}
	if (bureaucrat.getGrade() > this->getGradeToExec()){throw Form::GradeTooHighException();}
	std::cout << "PresidentialPardonForm: «" << this->target << "» has been pardoned by Zaphod Beeblebrox" << std::endl;
}
