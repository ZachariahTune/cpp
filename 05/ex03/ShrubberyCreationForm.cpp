#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//Дефолтный конструктор для объектов без скобок
ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	this->target = "DefaultTarget";
	std::cout << "# ShrubberyCreationForm: Default constructor called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
}
//Конструктор, создающий объект с именем и параметрами
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
	std::cout << "# ShrubberyCreationForm: Constructor Target called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
}
//Конструктор, копирующий другой объект
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form("ShrubberyCreationForm", 145, 137)
{
	this->target = copy.target;
	std::cout << "# ShrubberyCreationForm: Copy constructor called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
}
//Оператор копирования объекта
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->target = copy.target;
	std::cout << "# ShrubberyCreationForm: Copy operator called # -> name=«" << this->getName() << "», isSigned=«" << this->getIsSigned() << "», gradeToSign=«" << this->getGradeToSign() << "», gradeToExec=«" << this->getGradeToExec() << "», target=«" << this->target << "»" << std::endl;
	return *this;
}
//Деструктор
ShrubberyCreationForm::~ShrubberyCreationForm(){std::cout << "# ShrubberyCreationForm: Destructor of «" << this->getName() << "» called #" << std::endl;}

//Метод исполнения формы бюрократом
void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (this->getIsSigned() == false){throw Form::ExecWithoutSignException();}
	if (bureaucrat.getGrade() > this->getGradeToExec()){throw Form::GradeTooHighException();}
	std::ofstream outfile;
	outfile.open(this->target + "_shrubbery", std::ios::trunc);
	outfile << "    o|o\n   o\\|/o\n  o\\o|o/o\n ooo\\|/ooo\noo\\oo|oo/oo\noo_\\o|o/_oo\n ooo\\|/ooo\n  oo}|{oo\n    }|{\n    |||";
	std::cout << "ShrubberyCreationForm: «" << this->target << "» is executed!" << std::endl;
}
