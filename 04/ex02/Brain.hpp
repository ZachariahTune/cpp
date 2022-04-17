#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class	Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();
		
		Brain &operator=(const Brain &copy);
		
		//Методы мозга
		void setIdea(unsigned int index, std::string text_of_idea);
		std::string	getIdea(unsigned int index) const;
		void printIdeas(void) const;
};

#endif
