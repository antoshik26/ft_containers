#include "Vector.hpp"

#include "IteratorVector.hpp"
#include "Vector.hpp"

Vector::Vector()
{

}

Vector::Vector(const Allocator& alloc);
{
	_alloc = alloc;
}

Vector(std::size_t count, const T& value, const Allocator& alloc)
{
	_n = count;
	T = value;
	_alloc = alloc;
}

Vector::~Vector()
{
	_alloc.deallocate(T, _alloc); 
}

IteratorVector Vector::begin()
{
	return(array);
}

IteratorVector Vector::end()
{
	return(array+ n);
}


const char* Vector::ExceptionFirst::what() const throw()
{
	return ("First")
}

const char* Vector::ExceptionSecond::what() const throw()
{
	return ("Second");
}