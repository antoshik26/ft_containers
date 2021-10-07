#include "Vector.hpp"
#include "IteratorVector.hpp"

template <typename T, class Allocator>
Vector<T, Allocator>::Vector()
{
	_n = 0;
	_alloc = Allocator(); 	
	array = _alloc.allocate(_n);
}

template <typename T, class Allocator>
Vector<T, Allocator>::Vector( const Allocator& alloc)
{
	alloc = std::allocator<T>();
	_n = 0;
	_alloc = alloc;
	array = _alloc.allocate(_n);
}

template <typename T, class Allocator>
Vector<T, Allocator>::Vector(std::size_t count, const T& value, const Allocator& alloc)
{
	int i = 0;

	_n = count;
	_alloc = alloc;
	array = _alloc.allocate(_n);
	while (i < _n)
	{
		array[i] = value[i]; //не глубокое копирование
		i++;
	}
}

// template< class InputIt >
// template <typename T, class Allocator>
// Vector<T, Allocator>::Vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
// {

// }

// template <typename T, class Allocator>
// Vector<T, Allocator>Vector( const Vector& other )
// {
	
// }

template <typename T, class Allocator>
Vector<T, Allocator>::~Vector()
{
	_alloc.deallocate(array, _alloc); 
}

// IteratorVector Vector::begin()
// {
// 	return(array);
// }

// IteratorVector Vector::end()
// {
// 	return(array+ n);
// }


// const char* Vector::ExceptionFirst::what() const throw()
// {
// 	return ("First")
// }

// const char* Vector::ExceptionSecond::what() const throw()
// {
// 	return ("Second");
// }