#ifndef MYREPLACE_HPP
#define MYREPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

class	MyReplace
{
	public:
		MyReplace(std::string readfile, char *search, char *replace);
		~MyReplace();
};

#endif
