#include "DiamondTrap.hpp"

//Функция совершения атаки
void DiamondTrapAttack(DiamondTrap &obj1, DiamondTrap &obj2)
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
	DiamondTrap	a("Anton");		//Создание объекта гибридного подкласса
	DiamondTrap	b("Denis");		//Создание объекта гибридного подкласса
	
	//Вызов новых методов, отсутствующих в основном классе
	a.guardGate();
	a.highFivesGuys();
	a.whoAmI(); //Новый подметод, отсутствующих в наследуемом подклассе
	b.guardGate();
	b.highFivesGuys();
	b.whoAmI(); //Новый подметод, отсутствующих в наследуемом подклассе

	//Перекрестная атака с имеющимся оружием
	DiamondTrapAttack(a, b);
	DiamondTrapAttack(b, a);
	std::cout << std::endl;

	//Выдача нового оружия
	a.setAttackDamage(5);	//Выдача оружия с силой "5"
	b.setAttackDamage(7);	//Выдача оружия с силой "7"

	//Перекрестная атака с новым оружием
	DiamondTrapAttack(a, b);
	DiamondTrapAttack(b, a);

	//Лечение / ремонт
	std::cout << std::endl;
	a.beRepaired(20);
	b.beRepaired(10);
	
	//Смена оружия
	a.setAttackDamage(35);	//Выдача оружия с силой "35"
	b.setAttackDamage(45);	//Выдача оружия с силой "45"
	
	//Перекрестная атака с новым оружием
	DiamondTrapAttack(a, b);
	DiamondTrapAttack(b, a);
	DiamondTrapAttack(a, b);
	DiamondTrapAttack(b, a);
	DiamondTrapAttack(a, b); //У персонажа A закончились hitPoints
	std::cout << std::endl;
	
	//Перед ретёрном запускаются деструкторы для A, B и С
	return (0);
}
