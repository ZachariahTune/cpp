#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	int AniCount = 10;
	
	//Создание массива переменных класса
	std::cout << std::endl << "########## Sozdanie massiva Animal[" << AniCount << "] ##########" << std::endl;
	Animal	*animal[AniCount];
	for (int i=0; i<AniCount; i++)
	{
		if (i % 2 == 0){animal[i] = new Dog();}
		else {animal[i] = new Cat();}
	}
	
	//Вывод типов объектов
	std::cout << std::endl << "########## Vivod vseh tipov ##########" << std::endl;
	for (int i=0; i<AniCount; i++){std::cout << "Type of animal#" << i << " is «" << animal[i]->getType() << "»" << std::endl;}
	
	//Вывод звуков объектов
	std::cout << std::endl << "########## Vivod vseh zvukov ##########" << std::endl;
	for (int i=0; i<AniCount; i++){animal[i]->makeSound();}
	
	//Вывод всех идей
	std::cout << std::endl << "########## Vivod vseh idey ##########" << std::endl;
	for (int i=0; i<AniCount; i++)
	{
		if (i % 2 == 0){static_cast<Dog *>(animal[i])->getBrain().printIdeas();}	//static_cast<"подтип объекта" *>("объект") - для обращения к объекту как к подтипу
		else {static_cast<Cat *>(animal[i])->getBrain().printIdeas();}				//static_cast<"подтип объекта" *>("объект") - для обращения к объекту как к подтипу
	}
	
	//Создание идей
	std::cout << std::endl << "########## Sozdanie idey ##########" << std::endl;
	static_cast<Dog *>(animal[4])->getBrain().setIdea(2, "xxxxxxxx");
	static_cast<Cat *>(animal[5])->getBrain().setIdea(3, "I wont to eat");
	static_cast<Dog *>(animal[4])->getBrain().setIdea(25, "Zzzzzzzzzzzzzzz");
	static_cast<Cat *>(animal[5])->getBrain().setIdea(74, "Where is restroom?");
	static_cast<Dog *>(animal[4])->getBrain().setIdea(2, "I wont to sleep");
	
	//Повторный вывод всех идей
	std::cout << std::endl << "########## Povtorniy vivod vseh idey ##########" << std::endl;
	for (int i=0; i<AniCount; i++)
	{
		if (i % 2 == 0){static_cast<Dog *>(animal[i])->getBrain().printIdeas();}	//static_cast<"подтип объекта" *>("объект") - для обращения к объекту как к подтипу
		else {static_cast<Cat *>(animal[i])->getBrain().printIdeas();}				//static_cast<"подтип объекта" *>("объект") - для обращения к объекту как к подтипу
	}
	
	//Создание объекта для копии
	std::cout << std::endl << "########## Sozdanie obyekta dlya kopii ##########" << std::endl;
	Animal	*newDog = new Dog(*(static_cast<Dog *>(animal[4])));					//static_cast<"подтип объекта" *>("объект") - для обращения к объекту как к подтипу
	//Вывод свойств копии
	std::cout << "Type of animal" << " is «" << newDog->getType() << "»" << std::endl;
	newDog->makeSound();
	static_cast<Dog *>(newDog)->getBrain().printIdeas();
	//Замена одной идеи 4-го животного
	static_cast<Dog *>(animal[4])->getBrain().setIdea(2, "I still wont to sleep");
	static_cast<Dog *>(animal[4])->getBrain().printIdeas();
	//Повторный вывод идей нового животного
	static_cast<Dog *>(newDog)->getBrain().printIdeas();
	//Удаление скопированного объекта
	delete newDog;
	
	//Очистка памяти
	std::cout << std::endl << "########## Udalenie vseh obyektov ##########" << std::endl;
	for (int i=0; i<AniCount; i++){delete animal[i];}
	
	//Перед ретёрном запускаются деструкторы (в стеке)
	return (0);
}
