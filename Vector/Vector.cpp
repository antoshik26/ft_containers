// #include "Vector.hpp"

// template <typename T, class Allocator>
// Vector<T, Allocator>::Vector()
// {
// 	_n = 0;
// 	_size_alloc = 0;
// 	_alloc = Allocator(); 	
// 	array = _alloc.allocate(_size_alloc);
// }

// template <typename T, class Allocator>
// Vector<T, Allocator>::Vector( const Allocator& alloc)
// {
// 	// alloc = Allocator();
// 	_n = 0;
// 	_size_alloc = 0;
// 	_alloc = alloc;
// 	array = _alloc.allocate(_size_alloc);
// }

// template <typename T, class Allocator>
// Vector<T, Allocator>::Vector(std::size_t count, const T& value, const Allocator& alloc)
// {
// 	// int i = 0;

// 	_n = count;
// 	_size_alloc = count;
// 	_alloc = alloc;
// 	array = _alloc.allocate(_size_alloc);
// 	for (size_t i = 0; i < count; ++i)
//     		_alloc.construct(&array[i], value);
// }

// template <typename T, class Allocator>
// template< class InputIt>
// Vector<T, Allocator>::Vector(InputIt first, InputIt last, const Allocator& alloc)
// {
// 	alloc = Allocator();
// 	_n = first - last;
// 	_size_alloc = _n;
// 	_alloc = alloc;
// 	while (first != last)
// 	{
// 		array = *first;
// 		*array++;
// 		first++;
// 	}

// }

// template <typename T, class Allocator>
// Vector<T, Allocator>::Vector(const Vector& other)
// {
// 	_alloc = other._alloc;
// 	_size_alloc = other._size_alloc;
// 	_n = other._n;
// 	//дописать
// }

// template <typename T, class Allocator>
// Vector<T, Allocator>::~Vector()
// {
// 	_alloc.deallocate(array, _alloc); 
// }

// template <typename T, class Allocator>
// IteratorVector<T> Vector<T, Allocator>::begin()
// {
// 	return (IteratorVector<T>(array));
// }

// template <typename T, class Allocator>
// IteratorVector<T> Vector<T, Allocator>::end()
// {
// 	return (IteratorVector<T>(array + _n));
// }

// template <typename T, class Allocator>
// ReversIteratorVector<T> Vector<T, Allocator>::rbegin()
// {
// 	return (ReversIteratorVector<T>(array + _n));
// }

// template <typename T, class Allocator>
// ReversIteratorVector<T> Vector<T, Allocator>::rend()
// {
// 	return (ReversIteratorVector<T>(array));
// }


// const char* Vector::ExceptionFirst::what() const throw()
// {
// 	return ("First")
// }

// const char* Vector::ExceptionSecond::what() const throw()
// {
// 	return ("Second");
// }