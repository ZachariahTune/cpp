#include <iostream>
#include <string>

int	main(int argc, const char **argv)
{
	std::string argv_str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			argv_str = argv[i];
			for (size_t j = 0; j < argv_str.length(); j++)
			{
				std::cout << (char)toupper(argv[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
