#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string value);
		FragTrap(const FragTrap &copy);
		~FragTrap();

		void attack(const std::string &target);
		void highFivesGuys(void);
};

#endif
