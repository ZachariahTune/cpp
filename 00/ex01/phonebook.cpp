#include "phonebook.hpp"

//Функция обрезки строки с невидимыми символами по краям
std::string mytrim(std::string str)
{
	size_t	i;
	size_t	j;
	size_t	str_len = str.length();
	int		resize = 0;

	//Удаляем пробелы и табы с начала строки
	i = 0;
	while(str[i] == ' ' || str[i] == '\t') 
	{
		i++;
		resize++;
	}
	if (i > 0) 
	{
		for(j = 0; j < str_len; j++)
		{
			str[j] = str[j + i];
		}
		str[j] = '\0';
	}
	//Удаляем пробелы и табы с конца строки:
	i = str_len - i - 1;
	j = i;
	while(str[i] == ' ' || str[i] == '\t') 
	{
		i--;
		resize++;
	}
	if (i < j)
	{
		str[i + 1] = '\0';
	}
	//Урезаем длину строки и выводим
	str.resize(str.size() - resize);
	return (str);
}

//Конструктор и деструктор
Phonebook::Phonebook()
{
	std::cout << "This is PhoneBook" << std::endl;
	std::cout << "Menu:" << std::endl;
	std::cout << "«ADD» - to add a new contact" << std::endl;
	std::cout << "«SEARCH» - to browse contact table" << std::endl;
	std::cout << "«EXIT» - to exit the program" << std::endl;
}
Phonebook::~Phonebook(void){}

//Обзор контактов
void	Phonebook::browse()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << (i + 1) << "|";
		if (contacts[i].get_firstname().length() <= 10)
			std::cout << std::setw(10) << contacts[i].get_firstname() << "|";
		else
			std::cout << std::setw(9) << contacts[i].get_firstname().substr(0,9) << "." << "|";
		if (contacts[i].get_lastname().length() <= 10)
			std::cout << std::setw(10) << contacts[i].get_lastname() << "|";
		else
			std::cout << std::setw(9) << contacts[i].get_lastname().substr(0,9) << "." << "|";
		if (contacts[i].get_nickname().length() <= 10)
			std::cout << std::setw(10) << contacts[i].get_nickname() << "|";
		else
			std::cout << std::setw(9) << contacts[i].get_nickname().substr(0,9) << "." << "|";
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;;
}

//Подробная информация о контакте
void	Phonebook::search()
{
	int	stop = 0;
	std::string index;

	this->browse();
	while (stop == 0)
	{
		std::cout << "More info about contact (index): ";
		std::getline(std::cin, index);
		if (index.length() == 1 && index[0] >= '1' && index[0] <= '8')
			stop = 1;
		else
			std::cout << "Error: Incorrect index" << std::endl;
	}
	contacts[(index[0] - 1) - 48].print_contact();
}

//Добавление нового контакта
void	Phonebook::add(int index)
{
	std::string	input;

	//Циклический запрос 1-го поля
	input = ""; while(input == "") {
		std::cout << "First name: ";
		std::getline(std::cin, input);
		input = mytrim(input);
	}	contacts[index].set_firstname(input);
	//Циклический запрос 2-го поля
	input = ""; while(input == "") {
		std::cout << "Last name: ";
		std::getline(std::cin, input);
		input = mytrim(input);
	}	contacts[index].set_lastname(input);
	//Циклический запрос 3-го поля
	input = ""; while(input == "") {
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		input = mytrim(input);
	}	contacts[index].set_nickname(input);
	//Циклический запрос 4-го поля
	input = ""; while(input == "") {
		std::cout << "Phone number: ";
		std::getline(std::cin, input);
		input = mytrim(input);
	}	contacts[index].set_phonenumber(input);
	//Циклический запрос 5-го поля
	input = ""; while(input == "") {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, input);
		input = mytrim(input);
	}	contacts[index].set_darkestsecret(input);
}
