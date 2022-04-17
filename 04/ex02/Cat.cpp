#include "Cat.hpp"

//Дефолтный конструктор
Cat::Cat()
{
	this->type = "Cat";
	std::cout << "# Cat: Default constructor called # -> type=«" << this->type << "»" << std::endl;
	this->brain = new Brain();
}

//Конструктор, копирующий другой объект
Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->type = copy.type;
	std::cout << "# Cat: Copy constructor called # -> type=«" << this->type << "»" << std::endl;
	this->brain = new Brain(*(static_cast<Brain *>(copy.brain))); //static_cast<"тип подобъекта" *>("объект.подобъект") - для обращения к подобъекту внутри объекта
	//this->brain = copy.brain; //В таком варианте был бы один мозг на двоих
}

//Оператор копирования объекта
Cat &Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	std::cout << "# Cat: Copy operator called # -> type=«" << this->type << "»" << std::endl;
	this->brain = new Brain(*(static_cast<Brain *>(copy.brain))); //static_cast<"тип подобъекта" *>("объект.подобъект") - для обращения к подобъекту внутри объекта
	//this->brain = copy.brain; //В таком варианте был бы один мозг на двоих
	return *this;
}

//Деструктор
Cat::~Cat()
{
	delete this->brain;
	std::cout << "# Cat: Destructor called #" << std::endl;
}

//Метод создания звука
void Cat::makeSound(void) const
{
	std::cout << "Cat: My sound is «Myaaaaaaaaaaaow»!" << std::endl;
}

//Метод извлечения мозга
Brain &Cat::getBrain() const
{
	return (*this->brain);
}
