#include "IteratorVector.hpp"

IteratorVector::IteratorVector()
{
	obj = NULL;
}

IteratorVector::IteratorVector(*T first)
{
	obj = first;
}

IteratorVector::~IteratorVector()
{
}

T &IteratorVector::operator+(int n)
{
	return *(obj + n);
}

T &IteratorVector::operator-(int n)
{
	return *(obj - n);
}

T &IteratorVector::operator++(int)
{
	return (*obj++);
}

T &IteratorVector::operator--(int)
{
	return(*obj--);
}

T &IteratorVector::operator++()
{
	return (++*obj);
}

T &IteratorVector::operator--()
{
	return (--*obj);
}

bool IteratorVector::operator!=(const IteratorVector &it)
{
	if (obj != it)
		return(true);
	return(false);
}

bool IteratorVector::operator==(const IteratorVector &it)
{
	if (obj == if)
		return(true);
	return(false);
}

T &IteratorVector::operator*()
{
	return(*obj);
}