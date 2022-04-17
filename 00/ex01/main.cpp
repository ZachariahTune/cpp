#include "phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	input;
	int			add_counter = 0;

	while (1 == 1)
	{
		std::cout << "Command > ";
		std::getline(std::cin, input);

		if (input == "SEARCH")
		{
			phonebook.search();
		}
		else if (input == "ADD")
		{
			phonebook.add(add_counter);
			add_counter++;
			if (add_counter == 8){add_counter = 0;}
		}
		else if (input == "EXIT")
		{
			std::cout << "PhoneBook closed, all contacts deleted. GoodBye!!!" << std::endl;
			return (0);
		}
	}
	return (0);
}
