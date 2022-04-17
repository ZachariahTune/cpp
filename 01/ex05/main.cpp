#include "Karen.hpp"

int	main(void)
{
	Karen karen;
	std::cout << "----------------------------------------------------------------" << std::endl;

	karen.complain("DEBUG");
	std::cout << "----------------------------------------------------------------" << std::endl;

	karen.complain("INFO");
	std::cout << "----------------------------------------------------------------" << std::endl;

	karen.complain("WARNING");
	std::cout << "----------------------------------------------------------------" << std::endl;
	
	karen.complain("ERROR");
	std::cout << "----------------------------------------------------------------" << std::endl;
	
	karen.complain("OTHER");
	std::cout << "----------------------------------------------------------------" << std::endl;
	
	return (0);
}
