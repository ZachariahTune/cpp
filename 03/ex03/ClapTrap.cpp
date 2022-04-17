#include "ClapTrap.hpp"

//Дефолтный конструктор для объектов без скобок
ClapTrap::ClapTrap()
{
	this->name = "DefaultName";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "# ClapTrap: Default constructor called #->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}
//Конструктор, создающий объект с именем
ClapTrap::ClapTrap(std::string value)
{
	this->name = value;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "# ClapTrap: Constructor Name called #	->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}
//Конструктор, копирующий другой объект
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	std::cout << "# ClapTrap: Copy constructor called #	->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}
//Оператор копирования объекта
ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	std::cout << "# ClapTrap: Copy operator called #	->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
	return *this;
}
//Деструктор
ClapTrap::~ClapTrap(){std::cout << "# ClapTrap: Destructor called #" << std::endl;}

// ********************************************** //
// ******* Обязательные методы по заданию ******* //
// ********************************************** //

//Атака (вывод сообщения, уменьшение энергии)
void ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints == 0){std::cout << "ClapTrap: !!! NoAttack !!! - «" << this->name << "» can't attack «" << target <<"», no hitPoints!" << std::endl;}
	else if (this->energyPoints == 0){std::cout << "ClapTrap: !!! NoAttack !!! - «" << this->name << "» can't attack «" << target <<"», no energyPoints!" << std::endl;}
	else
	{
		this->energyPoints --;
		std::cout << "ClapTrap: «" << this->name << "» attack «" << target <<"», causing «" << this->attackDamage << "» points of damage!" << std::endl;
	}
}
//Получение ущерба
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap: «" << this->name << "» received «" << amount << "» points of damage" << std::endl;
	if (this->hitPoints >= amount){this->hitPoints -= amount;}
	else {this->hitPoints = 0;}
}
//Лечение / Ремонт
void ClapTrap::beRepaired(unsigned int amount)
{
	this->hitPoints += amount;
	this->energyPoints --;
	std::cout << "# ClapTrap: Repairing of «" << this->name << "» # -> +" << amount << " hitPoints, -1 energyPoints -> hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}

// ********************************************** //
// ********* Свои дополнительные методы ********* //
// ********************************************** //

//Изменение величины "attackDamage"
void ClapTrap::setAttackDamage(unsigned int value)
{
	this->attackDamage = value;
	std::cout << "# ClapTrap: Changing of attackDamage #	->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;
}
//Извлечение имени
std::string ClapTrap::getName(void) const {return (this->name);}
//Извлечение величины "hitPoints"
unsigned int ClapTrap::getHitPoints(void) const {return (this->hitPoints);}
//Извлечение величины "energyPoints"
unsigned int ClapTrap::getEnergyPoints(void) const {return (this->energyPoints);}
//Извлечение величины "attackDamage"
unsigned int ClapTrap::getAttackDamage(void) const {return (this->attackDamage);}
//Вывод информации о персонаже
void ClapTrap::infoAbout(void){std::cout << "ClapTrap: Info About ->	name=«" << this->name << "», hitPoints=«" << this->hitPoints << "», energyPoints=«" << this->energyPoints << "», attackDamage=«" << this->attackDamage << "»" << std::endl;}
