#include "ScavTrap.hpp"

//Функция совершения атаки
void ScavTrapAttack(ScavTrap &obj1, ScavTrap &obj2)
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
	ScavTrap	a;			//Создание объекта без имени
	ScavTrap	b("Anton");	//Создание объекта с именем
	ScavTrap	c(a);		//Создание копии другого объекта
	c = b;					//Переинициализация объекта
	
	//Вызов нового метода, отсутствующего в основном классе
	a.guardGate();
	b.guardGate();
	c.guardGate();

	//Перекрестная атака с имеющимся оружием
	ScavTrapAttack(c, a);
	ScavTrapAttack(a, c);
	std::cout << std::endl;

	//Выдача нового оружия
	a.setAttackDamage(10);	//Выдача оружия с силой "10"
	c.setAttackDamage(30);	//Выдача оружия с силой "30"

	//Перекрестная атака с новым оружием
	ScavTrapAttack(c, a);
	ScavTrapAttack(a, c);

	//Лечение / ремонт
	std::cout << std::endl;
	a.beRepaired(20);
	c.beRepaired(10);
	
	//Смена оружия
	a.setAttackDamage(20);	//Выдача оружия с силой "20"
	c.setAttackDamage(40);	//Выдача оружия с силой "40"
	
	//Перекрестная атака с новым оружием
	ScavTrapAttack(c, a);
	ScavTrapAttack(a, c);
	ScavTrapAttack(c, a);
	ScavTrapAttack(a, c); //У персонажа A закончились hitPoints
	std::cout << std::endl;
	
	//Проверка состояния персонажа B
	std::cout << "Info about object B:" << std::endl;
	b.infoAbout();
	std::cout << std::endl;
	
	//Перед ретёрном запускаются деструкторы для A, B и С
	return (0);
}
