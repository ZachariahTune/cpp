#include "FragTrap.hpp"

//Дефолтный конструктор для объектов без скобок
FragTrap::FragTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "# FragTrap: Default constructor called #->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}

//Конструктор, создающий объект с именем
FragTrap::FragTrap(std::string value) : ClapTrap(value)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "# FragTrap: Constructor Name called #	->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}
//Конструктор, копирующий другой объект
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "# FragTrap: Copy constructor called #	->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}

//Деструктор
FragTrap::~FragTrap(){std::cout << "# FragTrap: Destructor called #" << std::endl;}

//Атака (вывод сообщения, уменьшение энергии)
void FragTrap::attack(const std::string &target)
{
	if (this->hitPoints == 0){std::cout << "FragTrap: !!! NoAttack !!! - «" << this->name << "» can't attack «" << target <<"», no hitPoints!" << std::endl;}
	else if (this->energyPoints == 0){std::cout << "FragTrap: !!! NoAttack !!! - «" << this->name << "» can't attack «" << target <<"», no energyPoints!" << std::endl;}
	else
	{
		this->energyPoints --;
		std::cout << "FragTrap: «" << this->name << "» attack «" << target <<"», causing «" << this->attackDamage << "» points of damage!" << std::endl;
	}
}

//Вывод сообщения highFivesGuys
void FragTrap::highFivesGuys(void)
{	
	std::cout << "# FragTrap: New method «highFivesGuys» called (High Fives) #" << std::endl;
}
