#include "Convert.hpp"

//Задача заключается в том, чтобы принять аргумент через ARGV,
//распознать его тип и конвертировать в другие типы через приведение

int	main(int argc, char **argv)
{
	//Ошибка количества аргументов
	if (argc != 2)
	{
		std::cerr << "Error: programme neobhodim 1 argument" << std::endl;
		return (1);
	}
	//Если аргумент передан, но пустой
	else if (argv[1][0] == '\0')
	{
		std::cerr << "Error: programme neobhodim 1 NE PUSTOY argument" << std::endl;
		return (1);
	}
	
	//Распечатка аргумента в 4-х приведениях
	Convert	str(argv[1]);
	str.convert_to_char();
	str.convert_to_int();
	str.convert_to_float();
	str.convert_to_double();

	return (0);
}
