#include "span.hpp"

//Дефолтный конструктор
Span::Span() : maxsize(0), size(0) {}

//Конструктор с размером 
Span::Span(unsigned int N) : maxsize(N), size(0){}

//Конструктор, копирующий другой объект
Span::Span(const Span &copy){*this = copy;}

//Оператор копирования объекта
Span &Span::operator=(const Span &copy)
{
	if (this == &copy){return *this;}
	this->nums = copy.nums;
	this->maxsize = copy.maxsize;
	this->size = copy.size;
	return *this;
}

//Деструктор
Span::~Span(){}

//Методы геттеры
std::vector<int> Span::getNums(void) const{return this->nums;}
unsigned int Span::getSize(void) const{return this->size;}

//Добавление числа
void Span::addNumber(const int num)
{
	if (this->size < this->maxsize)
	{
		this->nums.push_back(num);
		this->size++;
	}
	else {throw Span::Full();}
}

//Добавление диапазона чисел
void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((end - begin) <= (this->maxsize - this->size))
	{
		this->nums.insert(this->nums.end(), begin, end);
		this->size += (end - begin);
	}
	else {throw Span::NoSpace();}
}

//Максимальное расстояние между элементами
unsigned int Span::shortestSpan(void)
{
	if (this->size == 0){throw Span::Empty();}
	if (this->size == 1){throw Span::OnlyOne();}

	unsigned int min = UINT_MAX;
	unsigned int min_tmp;
	std::vector<int>::iterator i;
	std::sort(this->nums.begin(), this->nums.end());
	for (i=this->nums.begin(); i!=(this->nums.end()-1); i++)
	{
		min_tmp = static_cast<unsigned int>(*(i + 1) - *i);
		if (min_tmp < min){min = min_tmp;}
	}
	return (min);
}

//Максимальное расстояние между элементами
unsigned int Span::longestSpan(void)
{
	if (this->size == 0){throw Span::Empty();}
	if (this->size == 1){throw Span::OnlyOne();}

	unsigned int min = *std::min_element(this->nums.begin(), this->nums.end());
	unsigned int max = *std::max_element(this->nums.begin(), this->nums.end());
	return (max - min);
}

//Оператор вывода в поток
std::ostream &operator<<(std::ostream &out, const Span &Span)
{
	std::vector<int>::iterator i;
	std::vector<int> nums = Span.getNums();

	if(Span.getSize() > 0)
		for (i=nums.begin(); i!=nums.end(); i++){out << *i << " ";}
	if(Span.getSize() == 0)
		out << "[empty]";
	return out;
}
