#include "Convert.hpp"

//Для работы со строками и преобразованием их в различные типы данных
//в данной реализации используется стандартный класс std::istringstream,
//который реализует операции ввода для потоков на основе строк.
//С его помощью можно из строки вынуть данные, соответствующие определенным типам

//Конструктор по умолчанию
Convert::Convert(){}

//Конструктор копирования
Convert::Convert(const Convert &copy){*this = copy;}

//Конструктор, принимающий строку
Convert::Convert(const std::string &str)
{
	this->type = TYPE_NONE;	//Тип 0 по умолчанию
	this->str = str;		//Сохраняем строку в параметре класса
	this->precision = 1;	//Точность вывода дробей по умолчанию

	//Определение типа строки
	if (str.length() == 1 && str[0] == ' '){type = TYPE_CHAR;} //Исключение для символа пробела
	else if (is_special(str)){type = TYPE_SPECIAL;}
	else if (is_int(str)){type = TYPE_INT;}		//важна последовательность
	else if (is_char(str)){type = TYPE_CHAR;}	//важна последовательность
	else if (is_float(str)){type = TYPE_FLOAT;}
	else if (is_double(str)){type = TYPE_DOUBLE;}

	//Сохраняем в параметре NUM строку, пропуская строку через поток
	std::istringstream iss(str);
	if (type == TYPE_CHAR)
	{
		if (str.length() == 1 && str[0] == ' '){this->num = ' ';} //Исключение для символа пробела
		else
		{
			char c;
			iss >> c;
			this->num = c;
	}	}
	if (type  == TYPE_INT || type == TYPE_FLOAT || type == TYPE_DOUBLE)
		iss >> this->num;

	//Подсчет количества знаков после запятой для увеличения точности
	double tmp1 = this->num - static_cast<double>(static_cast<int>(this->num));
	double tmp2 = tmp1;
	while (tmp2 > 0.00000001 && tmp2 < 0.99999999 && this->precision < 8)
	{
		tmp2 = tmp1*10 - static_cast<double>(static_cast<int>(tmp1*10));
		if (tmp2 > 0.00000001 && tmp2 < 0.99999999){this->precision++; tmp1 = tmp2;}
}	}

//Оператор копирования
Convert &Convert::operator=(const Convert& copy)
{
	if (this == &copy){return *this;}
	this->num = copy.num;
	this->type = copy.type;
	this->str = copy.str;
	this->precision = copy.precision;
	return *this;
}

//Деструктор
Convert::~Convert(){}

//Определение типа переданного значения
bool Convert::is_char(const std::string &str)
{
	return (str.length() == 1 && std::isprint(str[0]));
}
bool Convert::is_int(const std::string &str)
{
	std::istringstream iss(str);
	int num;

	iss >> num;
	return (iss.eof()==1 && iss.fail()==0);
}
bool Convert::is_float(const std::string &str)
{
	std::istringstream iss(str);
	float num;
	std::string	letterF;

	iss >> num;		//важна последовательность
	iss >> letterF;	//важна последовательность
	return (letterF=="f" && iss.eof()==1 && iss.fail()==0);
}
bool Convert::is_double(const std::string &str)
{
	std::istringstream iss(str);
	double num;

	iss >> num;
	return (iss.eof()==1 && iss.fail()==0);
}
bool Convert::is_special(const std::string &str)
{
	std::istringstream iss("inf -inf +inf nan inff -inff +inff nanf");
	std::string tmp;

	while (iss.eof()==0)
	{
		iss >> tmp;
		if (tmp==str){return (1);}
	}
	return (0);
}

//Преобразование для вывода на экран
void Convert::convert_to_char()
{
	std::cout << "char: ";
	if (type == TYPE_NONE){std::cout << "bad input" << std::endl;}
	else if (type == TYPE_SPECIAL){std::cout << "impossible" << std::endl;}
	else if (num < 0. || num > 255.){std::cout << "overflow" << std::endl;}
	else if (std::isprint(static_cast<char>(num))){std::cout << "'" << static_cast<char>(num) << "'" << std::endl;}
	else {std::cout << "non displayable" << std::endl;}
}
void Convert::convert_to_int()
{
	std::cout << "int: ";
	if (type == TYPE_NONE){std::cout << "bad input" << std::endl;}
	else if (type == TYPE_SPECIAL){std::cout << "impossible" << std::endl;}
	else if (num < static_cast<double>(INT_MIN) || num > static_cast<double>(INT_MAX)){std::cout << "overflow" << std::endl;}
	else {std::cout << static_cast<int>(num) << std::endl;}
}
void Convert::convert_to_float()
{
	std::cout << "float: ";
	if (type == TYPE_NONE){std::cout << "bad input" << std::endl;}
	else if (type == TYPE_SPECIAL)
	{
		if (str=="inff" || str=="-inff" || str=="+inff" || str=="nanf"){std::cout << str << std::endl;}
		if (str=="inf" || str=="-inf" || str=="+inf" || str=="nan"){std::cout << str << 'f' << std::endl;}
	}
	else {std::cout << std::fixed << std::setprecision(this->precision) << static_cast<float>(num) << 'f' << std::endl;}
}
void Convert::convert_to_double()
{
	std::cout << "double: ";
	if (type == TYPE_NONE){std::cout << "bad input" << std::endl;}
	else if (type  == TYPE_SPECIAL)
	{
		if (str=="inf" || str=="-inf" || str=="+inf" || str=="nan"){std::cout << str << std::endl;}
		if (str=="inff" || str=="-inff" || str=="+inff" || str=="nanf"){std::cout << str.substr(0, str.length()-1) << std::endl;}
	}
	else {std::cout << std::fixed << std::setprecision(this->precision) << num << std::endl;}
}
