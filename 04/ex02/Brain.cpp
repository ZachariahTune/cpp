#include "Brain.hpp"

//Дефолтный конструктор
Brain::Brain()
{
	std::cout << "# Brain: Default constructor called #" << std::endl;
}

//Конструктор, копирующий другой объект
Brain::Brain(const Brain &copy)
{
	for (int i=0; i<100; i++){this->ideas[i] = copy.ideas[i];}
	std::cout << "# Brain: Copy constructor called #" << std::endl;
}

//Оператор копирования объекта
Brain &Brain::operator=(const Brain &copy)
{
	for (int i=0; i<100; i++){this->ideas[i] = copy.ideas[i];}
	std::cout << "# Brain: Copy operator called #" << std::endl;
	return *this;
}

//Деструктор
Brain::~Brain()
{
	std::cout << "# Brain: Destructor called #" << std::endl;
}

//Метод сохранения текста идеи
void Brain::setIdea(unsigned int index, std::string text_of_idea)
{
	ideas[index] = text_of_idea;
	std::cout << "# Brain: setIdea called (index = " << index << ", text = " << text_of_idea << ") #" << std::endl;
}

//Метод извлечения текста идеи
std::string	Brain::getIdea(unsigned int index) const{return (ideas[index]);}

//Распечатка всех идей
void Brain::printIdeas() const
{
	int ideas_empty = 0;
	std::cout << "Brain: All ideas -";
	for (int i=0; i<100; i++)
	{
		if (this->ideas[i] == ""){ideas_empty++;}
		else {std::cout << " #" << i << " «" << this->ideas[i] << "»";}
	}
	if (ideas_empty == 100){std::cout << "[NO IDEAS]";}
	std::cout << "." << std::endl;
}
