#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "\n# ========== Correct version ========== #\n" << std::endl;
	
	//Создание переменных ОДНОГО ТИПА, но разных подклассов
	const Animal	*animal = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();
	
	//Вывод типов объектов
	std::cout << "Type of animal is «" << animal->getType() << "»" << std::endl;
	std::cout << "Type of dog is «" << dog->getType() << "»" << std::endl;
	std::cout << "Type of cat is «" << cat->getType() << "»" << std::endl;

	//Вывод звуков объектов
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	//Очистка памяти
	delete animal;
	delete dog;
	delete cat;
	
	std::cout << "\n# =========== Wrong version =========== #\n" << std::endl;
	
	//Создание переменных ОДНОГО ТИПА, но разных подклассов
	const WrongAnimal	*wronganimal = new WrongAnimal();
	const WrongAnimal	*wrongcat = new WrongCat();
	
	//Вывод типов объектов
	std::cout << "Type of wronganimal is «" << wronganimal->getType() << "»" << std::endl;
	std::cout << "Type of wrongcat is «" << wrongcat->getType() << "»" << std::endl;

	//Вывод звуков объектов
	wronganimal->makeSound();
	wrongcat->makeSound();

	//Очистка памяти
	delete wronganimal;
	delete wrongcat;
	
	//Перед ретёрном запускаются деструкторы
	return (0);
}
