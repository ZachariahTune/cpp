#include "Dog.hpp"

//Дефолтный конструктор
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "# Dog: Default constructor called # -> type=«" << this->type << "»" << std::endl;
	this->brain = new Brain();
}

//Конструктор, копирующий другой объект
Dog::Dog(const Dog &copy) : Animal(copy)
{
	this->type = copy.type;
	std::cout << "# Dog: Copy constructor called # -> type=«" << this->type << "»" << std::endl;
	this->brain = new Brain(*(static_cast<Brain *>(copy.brain))); //static_cast<"тип подобъекта" *>("объект.подобъект") - для обращения к подобъекту внутри объекта
	//this->brain = copy.brain; //В таком варианте был бы один мозг на двоих
}

//Оператор копирования объекта
Dog &Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	std::cout << "# Dog: Copy operator called # -> type=«" << this->type << "»" << std::endl;
	this->brain = new Brain(*(static_cast<Brain *>(copy.brain))); //static_cast<"тип подобъекта" *>("объект.подобъект") - для обращения к подобъекту внутри объекта
	//this->brain = copy.brain; //В таком варианте был бы один мозг на двоих
	return *this;
}

//Деструктор
Dog::~Dog()
{
	delete this->brain;
	std::cout << "# Dog: Destructor called #" << std::endl;
}

//Метод создания звука
void Dog::makeSound(void) const
{
	std::cout << "Dog: My sound is «Gggggav-Gggggav»!" << std::endl;
}

//Метод извлечения мозга
Brain &Dog::getBrain() const
{
	return (*this->brain);
}
