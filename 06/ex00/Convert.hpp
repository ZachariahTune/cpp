#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>

#define TYPE_NONE		0
#define TYPE_CHAR		1
#define TYPE_INT		2
#define TYPE_FLOAT		3
#define TYPE_DOUBLE		4
#define TYPE_SPECIAL	5

class Convert
{
	private:
		double num;
		int type;
		std::string str;
		int precision;

	public:
		Convert();
		Convert(const Convert &copy);
		Convert(const std::string &str);
		~Convert();

		Convert &operator=(const Convert &copy);

		//Определение типа переданного значения
		bool is_char(const std::string &str);
		bool is_int(const std::string &str);
		bool is_float(const std::string &str);
		bool is_double(const std::string &str);
		bool is_special(const std::string &str);

		//Преобразование для вывода на экран
		void convert_to_char();
		void convert_to_int();
		void convert_to_float();
		void convert_to_double();
};

#endif
