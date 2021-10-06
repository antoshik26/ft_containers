#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <string>

template<class T, class Allocator = std::allocator<T>>
template< class InputIt >
class Vector : public IteratorVector
{
	private:
		T* array;
		const Allocator *_alloc;
		size_t _n;
		class ExceptionFirst : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class ExceptionSecond : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	public:
		Vector();
		Vector(const size_t n);
		Vector(size_t count, const T& value, const Allocator& alloc);
		// vector( const vector& other, const Allocator& alloc );
		// vector( vector&& other );
		// vector( vector&& other, const Allocator& alloc );
		~Vector();

		// Vector &operator=(const Vector obj);
		// Vector &operator=( vector&& other );
		// Vector &operator=( std::initializer_list<T> ilist );
		// bool &operator!=(const Vector obj1, const Vector obj2);
		// bool &operator==(const Vector obj1, const Vector obj2);
		// bool &operator<(const Vector obj1, const Vector obj2);
		// bool &operator>(const Vector obj1, const Vector obj2);
		// bool &operator<=(const Vector obj1, const Vector obj2);
		// bool &operator>=(const Vector obj1, const Vector obj2);

		// void assign( size_type count, const T& value );
		// void assign( InputIt first, InputIt last );
		// void assign( std::initializer_list<T> ilist );
		// allocator_type get_allocator() const;
		
		iterator begin();
		iterator end();
		// reverse_iterator rbegin();
		// reverse_iterator rend();

		// reference at( size_type pos );
		// reference operator[]( size_type pos );
		// reference front();
		// reference back();
		// T* data();

		// bool empty() const;
		// size_type size() const;
		// size_type max_size() const;
		// void reserve( size_type new_cap );
		// size_type capacity() const;
		// void shrink_to_fit();


		// void clear();
		// iterator insert( iterator pos, const T& value );
		// iterator insert( const_iterator pos, T&& value );
		// void insert( iterator pos, size_type count, const T& value );
		// void insert( iterator pos, InputIt first, InputIt last );
		// constexpr iterator insert( const_iterator pos, InputIt first, InputIt last );
		// iterator insert( const_iterator pos, std::initializer_list<T> ilist );
		// iterator emplace( const_iterator pos, Args&&... args );
		// iterator erase( iterator pos );
		// iterator erase( iterator first, iterator last );
		// void emplace_back( Args&&... args );
		// void push_back( T&& value );
		// void push_back( const T& value );
		// void pop_back();
		// void resize( size_type count );
		// void resize( size_type count, T value = T() );
		// void swap( vector& other );
};

#endif