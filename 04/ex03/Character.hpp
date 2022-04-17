#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		Character();
		std::string name;
		AMateria *inventory[4];

	public:
		Character(std::string name);
		Character(const Character &copy);
		~Character();

		Character &operator=(const Character &copy);

		const std::string &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		void rename(std::string name);
};

#endif
