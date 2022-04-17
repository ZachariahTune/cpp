#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string name;
	int age;
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif
