#include "DiamondTrap.hpp"

//Дефолтный конструктор для объектов без скобок
DiamondTrap::DiamondTrap(void)
{
	ScavTrap	STtmp;

	this->name = ClapTrap::getName();
	ClapTrap::name = this->name + "_clap_name";
	this->energyPoints = STtmp.getEnergyPoints();
	std::cout << "# DiamondTrap: Default constructor called #->	name=«" << this->name << "», ClapName=«" << ClapTrap::getName() << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}

//Конструктор, создающий объект с именем
DiamondTrap::DiamondTrap(std::string value) : ClapTrap(value)
{
	ScavTrap	STtmp(value);

	this->name = value;
	ClapTrap::name = this->name + "_clap_name";
	this->energyPoints = STtmp.getEnergyPoints();
	std::cout << "# DiamondTrap: Constructor Name called #->	name=«" << this->name << "», ClapName=«" << ClapTrap::getName() << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}

//Конструктор, копирующий другой объект
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	this->name = copy.name;
	std::cout << "# DiamondTrap: Copy constructor called #->	name=«" << this->name << "», ClapName=«" << ClapTrap::getName() << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}

//Деструктор
DiamondTrap::~DiamondTrap(){std::cout << "# DiamondTrap: Destructor called #" << std::endl;}

//Атака, унаследованная от подкласса ScavTrap
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

//Свой подклассовый метод, выводящий своё имя и родительское имя
void DiamondTrap::whoAmI(void)
{
	std::cout << "# DiamondTrap: My name is «" << this->name << "», my ClapName is «" << ClapTrap::getName() << "» #" << std::endl;
}
