#include "Serialize.hpp"

//uintptr_t является беззнаковым целочисленным типом, способным безопасно хранить в себе указатель
//в независимости от разрядности платформы

int	main(void)
{
	Data	*data1 = new Data;
	uintptr_t raw;

	std::cout << std::endl << "# ====== Create Structure ====== #" << std::endl;
	data1->name = "Anton";
	data1->age = 42;
	std::cout << "Strukture: name = " << data1->name << "; age = " << data1->age << std::endl;

	std::cout << std::endl << "# ========= Serialize ========= #" << std::endl;
	raw = serialize(data1);
	std::cout << "ptr = " << data1 << std::endl;
	std::cout << "raw = " << raw << std::endl;
	std::cout << "hex-raw = " << std::hex << raw << std::dec << std::endl;
	std::cout << "Strukture: name = " << data1->name << "; age = " << data1->age << std::endl;

	std::cout << std::endl << "# ======= Deserialize 1 ======= #" << std::endl;
	data1 = deserialize(raw);
	std::cout << "ptr = " << data1 << std::endl;
	std::cout << "raw = " << raw << std::endl;
	std::cout << "hex-raw = " << std::hex << raw << std::dec << std::endl;
	std::cout << "Strukture: name = " << data1->name << "; age = " << data1->age << std::endl;

	std::cout << std::endl << "# ======= Deserialize 2 ======= #" << std::endl;
	Data *data2 = deserialize(raw);
	std::cout << "ptr = " << data2 << std::endl;
	std::cout << "raw = " << raw << std::endl;
	std::cout << "hex-raw = " << std::hex << raw << std::dec << std::endl;
	std::cout << "Strukture: name = " << data2->name << "; age = " << data2->age << std::endl;

	std::cout << std::endl;
	delete data1;

	return (0);
}
