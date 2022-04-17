#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

//Итератор — это такая структура данных, которая используется для обращения к определенному элементу в контейнерах
//то есть итератор - это указатель на элемент контейнера

//Метод begin() отправляет итератор на начало контейнера (на первый элемент).
//Метод end() отправляет итератор на одну ячейку дальше конца контейнера (её нельзя вывести).

//Метод std::find ищет первое вхождение значения в контейнере.
//принимает 3 параметра: итератор начального элемента, итератор конечного элемента и само значение для поиска.
//Возвращает итератор, указывающий на найденный элемент или конец контейнера, если элемент не найден.

//Метод std::logic_error определяет тип объекта, который будет брошен как исключение для информирования об ошибке.

template <typename T>
typename T::iterator easyFind(T &container, const int n)
{
	typename T::iterator iter_begin = container.begin();
	typename T::iterator iter_end = container.end();
	typename T::iterator iter_find = std::find(iter_begin, iter_end, n);

	if (iter_find == iter_end){throw std::logic_error("!!! Not found !!!");}
	return (iter_find);
}

#endif
