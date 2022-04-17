#include "Serialize.hpp"

//В отличие от оператора static_cast оператор приведения reinterpret_cast
//используется для приведения несовместимых типов.
//Может приводить целое число к указателю и указатель к целому числу.
//Это же касается и ссылок.

uintptr_t serialize(Data *ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data *deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}
