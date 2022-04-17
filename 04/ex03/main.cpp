#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int	main(void)
{
	//Создание источников материй
	std::cout << std::endl << "\033[32m########### Sozdanie istochnika materiy ###########\033[0m" << std::endl;
	std::cout << "\x1b[38;5;242m========== Opredelenie ustochnika materiy ==========\033[0m" << std::endl;
	IMateriaSource *source = new MateriaSource();
	std::cout << "\x1b[38;5;242m=============== Sozdanie materii ICE ===============\033[0m" << std::endl;
	source->learnMateria(new Ice());
	std::cout << "\x1b[38;5;242m============== Sozdanie materii CURE ==============\033[0m" << std::endl;
	source->learnMateria(new Cure());

	//Создание персонажей
	std::cout << std::endl << "\033[32m############### Sozdanie personazhey ###############\033[0m" << std::endl;
	ICharacter *anton = new Character("Anton");
	ICharacter *denis = new Character("Denis");

	//Создание материй и выдача их персонажам
	std::cout << std::endl << "\033[32m###### Sozdanie materiy i vydacha personazham ######\033[0m" << std::endl;
	
	std::cout << "\x1b[38;5;242m====== Sozdanie materii ICE dlya 1-go slota ======\033[0m" << std::endl;
	AMateria *tmp1 = source->createMateria("ice"); anton->equip(tmp1);
	std::cout << "\x1b[38;5;242m====== Sozdanie materii CURE dlya 2-go slota =====\033[0m" << std::endl;
	AMateria *tmp2 = source->createMateria("cure"); anton->equip(tmp2);
	std::cout << "\x1b[38;5;242m====== Sozdanie materii ICE dlya 3-go slota ======\033[0m" << std::endl;
	AMateria *tmp3 = source->createMateria("ice"); anton->equip(tmp3);
	std::cout << "\x1b[38;5;242m====== Sozdanie materii CURE dlya 4-go slota =====\033[0m" << std::endl;
	AMateria *tmp4 = source->createMateria("cure"); anton->equip(tmp4);
	std::cout << "\x1b[38;5;242m====== Sozdanie materii ICE dlya 5-go slota ======\033[0m" << std::endl;
	AMateria *tmp5 = source->createMateria("ice"); anton->equip(tmp5);
	anton->unequip(1); delete tmp2; anton->equip(tmp5);

	//Применение материй персонажем Anton
	std::cout << std::endl << "\033[32m########## ANTON primenyaet materii ##########\033[0m" << std::endl;
	anton->use(0, *denis);
	anton->use(1, *denis);
	anton->use(2, *denis);
	anton->use(3, *denis);

	//Применение материй персонажем Denis
	std::cout << std::endl << "\033[32m########## DENIS primenyaet materii ##########\033[0m" << std::endl;
	denis->use(0, *anton);
	denis->unequip(0);
	
	//Создание нового персонажа копированием
	std::cout << std::endl << "\033[32m######## Kopirovanie personazha RUSLAN ########\033[0m" << std::endl;
	std::cout << "\x1b[38;5;242m========= Kopirovanie personazha ANTON =========\033[0m" << std::endl;
	ICharacter *ruslan = new Character(*(static_cast<Character *>(anton)));
	std::cout << "\x1b[38;5;242m====== Pereimenovivaem repsonazha v RUSLAN ======\033[0m" << std::endl;
	ruslan->rename("Ruslan");
	std::cout << "\x1b[38;5;242m=========== RUSLAN primenyaet materii ===========\033[0m" << std::endl;
	ruslan->use(0, *denis);
	ruslan->use(1, *denis);
	ruslan->use(2, *denis);
	ruslan->use(3, *denis);

	//Удаление персонажей и материй
	std::cout << std::endl << "\033[32m########## Udalnie personazhey ##########\033[0m" << std::endl;
	std::cout << "\x1b[38;5;242m=========== Udalenie personazha ANTON ===========\033[0m" << std::endl;
	delete anton;
	std::cout << "\x1b[38;5;242m=========== Udalenie personazha DENIS ===========\033[0m" << std::endl;
	delete denis;
	std::cout << "\x1b[38;5;242m=========== Udalenie personazha RUSLAN ===========\033[0m" << std::endl;
	delete ruslan;
	std::cout << "\x1b[38;5;242m========== Udalenie istochnikov materiy =========\033[0m" << std::endl;
	delete source;

	return (0);
}
