#include "ClapTrap.hpp"

//Функция совершения атаки
void ClapTrapAttack(ClapTrap &obj1, ClapTrap &obj2)
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
	ClapTrap	a;			//Создание объекта без имени
	ClapTrap	b("Anton");	//Создание объекта с именем
	ClapTrap	c(a);		//Создание копии другого объекта
	c = b;					//Переинициализация объекта

	//Перекрестная атака без оружия
	ClapTrapAttack(c, a);
	ClapTrapAttack(a, c);
	std::cout << std::endl;

	//Выдача оружия
	a.setAttackDamage(1);	//Выдача оружия с силой "1"
	c.setAttackDamage(4);	//Выдача оружия с силой "2"

	//Перекрестная атака с оружием
	ClapTrapAttack(c, a);
	ClapTrapAttack(a, c);

	//Лечение / ремонт
	std::cout << std::endl;
	a.beRepaired(5);
	c.beRepaired(2);
	
	//Смена оружия
	a.setAttackDamage(7);	//Выдача оружия с силой "7"
	c.setAttackDamage(8);	//Выдача оружия с силой "8"
	
	//Перекрестная атака с новым оружием
	ClapTrapAttack(c, a);
	ClapTrapAttack(a, c);
	ClapTrapAttack(c, a);
	ClapTrapAttack(a, c); //У персонажа A закончились hitPoints
	ClapTrapAttack(c, a);
	ClapTrapAttack(c, a);
	ClapTrapAttack(c, a);
	ClapTrapAttack(c, a);
	ClapTrapAttack(c, a);
	ClapTrapAttack(c, a);
	std::cout << std::endl;
	
	//Проверка состояния персонажа B
	std::cout << "Info about object B:" << std::endl;
	b.infoAbout();
	std::cout << std::endl;
	
	//Перед ретёрном запускаются деструкторы для A, B и С
	return (0);
}
