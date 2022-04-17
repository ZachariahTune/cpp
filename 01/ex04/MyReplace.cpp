#include "MyReplace.hpp"

//Основная функция, она же конструктор
MyReplace::MyReplace(std::string readfile, char *search, char *replace)
{
	//Переменные
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;
	size_t			search_len = strlen(search);
	size_t			find_position;

	//Открытие файла для считывания
	infile.open(readfile);
	if (!infile)
	{
		std::cerr << "Error: ne udalos otkryt file" << std::endl;
		return ;
	}
	//Создание (открытие) нового файла для записи копии
	outfile.open(readfile + ".replace", std::ios::trunc);
	if (!outfile)
	{
		infile.close();
		std::cerr << "Error: ne udalos zapisat noviy file" << std::endl;
		return;
	}
	//Цикл перебора строк в файле
	while (std::getline(infile, line))
	{
		find_position = line.find(search, 0); //Первое вхождение подстроки в строке
		while (find_position != std::string::npos) //Если позиция вхождения не является концом строки
		{
			line.erase(find_position, search_len); //Удаляет search_len символов в строке line, начиная с позиции find_position
			line.insert(find_position, replace); //Вставляет подстроку replace в строку line, начиная с позиции find_position
			find_position += strlen(replace); //Прибавляет к позиции длину вставленной подстроки
			find_position = line.find(search, find_position); //Новый поиск, начиная с обновленной позиции в строке
		}
		outfile << line; //Записывает модифицированную строку в новый файл
		if (!infile.eof()){outfile << '\n';} //Перенос строки кроме самой последней
	}
	infile.close();
	outfile.close();
}

//Пустой деструктор
MyReplace::~MyReplace(){}
