#include <string>
#include <iostream>

int main(void)
{
	//Создание строки и указателей на неё
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

	//Вывод тестов на экран
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "# Create a string! Value of string = " << str << " #" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Address of string: " << &str << std::endl;
    std::cout << "Value of stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;
    std::cout << "Value of value of stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of stringREF: " << stringREF << std::endl;
	//Новое значение для текстовой переменной
	str = "NEW VALUE OF STRING";
	//Вывод тестов на экран еще раз
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "# Value change! New value of string = " << str << " #" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "Address of string: " << &str << std::endl;
    std::cout << "Value of stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;
    std::cout << "Value of value of stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of stringREF: " << stringREF << std::endl;
    std::cout << "------------------------------------------" << std::endl;
	return (0);
}
