#include "MyReplace.hpp"

int	main(int argc, char **argv)
{
	//Ошибка количества аргументов
	if (argc != 4)
	{
		std::cerr << "Error: programme neobhodimo 3 argumenta" << std::endl;
		return (1);
	}
	//Запуск конструктора класса MyReplace
	MyReplace(argv[1], argv[2], argv[3]);
	//Перед ретёрном запустится деструктор
	return (0);
}
