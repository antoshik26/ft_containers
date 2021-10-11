#include "IteratorVector.hpp"

// template <typename T>
// IteratorVector<T>::IteratorVector()
// {
// 	obj = NULL;
// }

template <typename T>
IteratorVector<T>::IteratorVector(T* first)
{
	obj = first;
}

// template <typename T>
// IteratorVector<T>::~IteratorVector()
// {
// }

template <typename T>
T &IteratorVector<T>::operator+(int n)
{
	return *(obj + n);
}

template <typename T>
T &IteratorVector<T>::operator-(int n)
{
	return *(obj - n);
}

template <typename T>
T &IteratorVector<T>::operator++(int)
{
	return (*obj++);
}

template <typename T>
T &IteratorVector<T>::operator--(int)
{
	return(*obj--);
}

template <typename T>
T &IteratorVector<T>::operator++()
{
	return (++*obj);
}

template <typename T>
T &IteratorVector<T>::operator--()
{
	return (--*obj);
}

template <typename T>
bool IteratorVector<T>::operator!=(const IteratorVector &it)
{
	if (obj != it)
		return(true);
	return(false);
}

template <typename T>
bool IteratorVector<T>::operator==(const IteratorVector &it)
{
	if (obj == it)
		return(true);
	return(false);
}

template <typename T>
T &IteratorVector<T>::operator*()
{
	return(*obj);
}