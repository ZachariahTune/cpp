#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

//По заданию все 4 класса НЕ должны быть созданы в классической канонической форме
//Для полноценного теста можно раскомментировать строки, чтобы получить каноническую форму

class Base
{
	public:
		//Base();
		virtual ~Base();
};

class A : public Base
{
	//public: A(); ~A();
};

class B : public Base
{
	//public: B(); ~B();
};

class C : public Base
{
	//public: C(); ~C();
};

Base *generate(void);
void identify(Base *ptr);
void identify(Base &ref);

#endif
