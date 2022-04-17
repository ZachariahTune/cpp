#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//Функция совершения атаки Scav -> Frag
void ScavFragAttack(ScavTrap &obj1, FragTrap &obj2)
{
	std::cout << std::endl << "Attack:" << std::endl;
	obj1.attack(obj2.getName());
	if (obj1.getHitPoints() > 0 && obj1.getEnergyPoints() > 0)
		obj2.takeDamage(obj1.getAttackDamage());
	obj1.infoAbout();
	obj2.infoAbout();
}

//Функция совершения атаки Frag -> Scav
void FragScavAttack(FragTrap &obj1, ScavTrap &obj2)
{
	std::cout << std::endl << "Attack:" << std::endl;
	obj1.attack(obj2.getName());
	if (obj1.getHitPoints() > 0 && obj1.getEnergyPoints() > 0)
		obj2.takeDamage(obj1.getAttackDamage());
	obj1.infoAbout();
	obj2.infoAbout();
}

int	main(void)
{
	ScavTrap	a("Anton");	//Создание объекта одного подкласса
	FragTrap	b("Denis");	//Создание объекта другого подкласса
	
	//Вызов новых методов, отсутствующих в основном классе
	a.guardGate();
	b.highFivesGuys();

	//Перекрестная атака с имеющимся оружием
	ScavFragAttack(a, b);
	FragScavAttack(b, a);
	std::cout << std::endl;

	//Выдача нового оружия
	a.setAttackDamage(5);	//Выдача оружия с силой "5"
	b.setAttackDamage(7);	//Выдача оружия с силой "7"

	//Перекрестная атака с новым оружием
	ScavFragAttack(a, b);
	FragScavAttack(b, a);

	//Лечение / ремонт
	std::cout << std::endl;
	a.beRepaired(20);
	b.beRepaired(10);
	
	//Смена оружия
	a.setAttackDamage(35);	//Выдача оружия с силой "35"
	b.setAttackDamage(45);	//Выдача оружия с силой "45"
	
	//Перекрестная атака с новым оружием
	ScavFragAttack(a, b);
	FragScavAttack(b, a);
	ScavFragAttack(a, b);
	FragScavAttack(b, a);
	ScavFragAttack(a, b); //У персонажа A закончились hitPoints
	std::cout << std::endl;
	
	//Перед ретёрном запускаются деструкторы для A, B и С
	return (0);
}
