#include "ScavTrap.hpp"

//Дефолтный конструктор для объектов без скобок
ScavTrap::ScavTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "# ScavTrap: Default constructor called #->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}

//Конструктор, создающий объект с именем
ScavTrap::ScavTrap(std::string value) : ClapTrap(value)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "# ScavTrap: Constructor Name called #	->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}
//Конструктор, копирующий другой объект
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "# ScavTrap: Copy constructor called #	->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}

//Деструктор
ScavTrap::~ScavTrap(){std::cout << "# ScavTrap: Destructor called #" << std::endl;}

//Атака (вывод сообщения, уменьшение энергии)
void ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints == 0){std::cout << "ScavTrap: !!! NoAttack !!! - «" << this->name << "» can't attack «" << target <<"», no hitPoints!" << std::endl;}
	else if (this->energyPoints == 0){std::cout << "ScavTrap: !!! NoAttack !!! - «" << this->name << "» can't attack «" << target <<"», no energyPoints!" << std::endl;}
	else
	{
		this->energyPoints --;
		std::cout << "ScavTrap: «" << this->name << "» attack «" << target <<"», causing «" << this->attackDamage << "» points of damage!" << std::endl;
	}
}

//Вывод сообщения guardGate
void ScavTrap::guardGate(void)
{	
	std::cout << "# ScavTrap: New method «guardGate» called #" << std::endl;
}
