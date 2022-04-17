#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#pragma once
#include <iostream>
#include <cmath>

class	ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &copy);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		//Собственные методы
		void setAttackDamage(unsigned int value);
		std::string getName(void) const;
		unsigned int getHitPoints(void) const;
		unsigned int getEnergyPoints(void) const;
		unsigned int getAttackDamage(void) const;
		void infoAbout(void);
};

#endif
