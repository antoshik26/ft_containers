#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <string>
#include <cmath>
#include "IteratorVector.hpp"
#include "ReversIteratorVector.hpp"

template<typename T, class Allocator = std::allocator<T> >
class Vector //	: public IteratorVector, public ReversIteratorVector
{
	private:
		T* array;
		Allocator _alloc;
		size_t _size_alloc;
		size_t _n;
		class ExceptionReserve : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("1");
				}
		};
		class ExceptionAt : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("2");
				}
		};
		class ExceptionPushBack :public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("3");
				}
		};
	public:
		// Vector();
		explicit Vector(const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
			_size_alloc = 0;
			_n = 0;
			array = _alloc.allocate(0);
		}

		explicit Vector(size_t count, const T& value = T(), const Allocator& alloc = Allocator())
		{
			_n = 0;
			_size_alloc = count;
			_alloc = alloc;
			array = _alloc.allocate(_size_alloc);
			for (size_t i = 0; i < count; ++i)
    			_alloc.construct(&array[i], value);
		}

		template< class InputIt >
		Vector( InputIt first, InputIt last, const Allocator& alloc = Allocator())
		{
			alloc = Allocator();
			_n = first - last;
			_size_alloc = _n;
			_alloc = alloc;
			while (first != last)
			{
				array = *first;
				*array++;
				first++;
			}
		}

		Vector( const Vector& other )
		{
			_alloc = other._alloc;
			_size_alloc = other._size_alloc;
			_n = other._n;
			//дописать
		}

		~Vector()
		{
			for (size_t i = 0; i < _size_alloc; i++)
				_alloc.destroy(&array[i]);
			_alloc.deallocate(array, _size_alloc); 
		}

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
		
		IteratorVector<T> begin()
		{
			return (IteratorVector<T>(array));
		}

		IteratorVector<T> end()
		{
			return (IteratorVector<T>(array + _n));
		}

		ReversIteratorVector<T> rbegin()
		{
			return (ReversIteratorVector<T>(array + _n));
		}

		ReversIteratorVector<T> rend()
		{
			return (ReversIteratorVector<T>(array));
		}

		T& at(size_t pos) //set
		{
			try
			{
				if (pos > _n || pos < 0)
					throw Vector::ExceptionAt();
				else
					return (&array[pos]);
			}
			catch (std::exception& e)
			{
				throw;
			}
		}
		T& operator[](size_t pos)
		{
			try
			{
					if (pos > _n || pos < 0)
							throw Vector::ExceptionAt();
					else
						return (array[pos]);
			}
			catch (std::exception& e)
			{
				throw;
			}
		}

		T& front()
		{
			return (&array[0]);
		}

		T& back()
		{
			return (&array[_n]);
		}

		T* data()
		{
			return (array);
		}

		
		size_t size() const
		{
			return (_n);
		}

		size_t max_size() const
		{
			size_t max_size;

			if (sizeof(T) == 1)
				max_size = (pow(2, 64) / 2) - 1;
			else
				max_size = (pow(2, 64) / sizeof(T)) - 1;
			return(max_size); 
		}

		void reserve(size_t new_cap )
		{
			try
			{
				if (new_cap > max_size())
					throw Vector::ExceptionReserve();
				if (new_cap > _size_alloc)
					realocateVec(new_cap);
			}
			catch (std::exception &e)
			{
				throw;
			}				
		}

		// size_t capacity() const
		// {

		// }

		// bool empty() const
		// {

		// }

		// void resize( size_type count )
		// {

		// }
		// void resize( size_type count, T value = T() ); ?

		// void shrink_to_fit()
		// {

		// }

		void clear()
		{
			for(size_t i = 0; i < _n; i++)
			{
				_alloc.destroy(&array[i]);
			}
			_n = 0;
		}

		IteratorVector<T>  insert( IteratorVector<T> pos, const T& value );
		// IteratorVector<T>  insert( const_iterator pos, T&& value );
		// void insert( iterator pos, size_type count, const T& value );
		// void insert( iterator pos, InputIt first, InputIt last );
		// constexpr iterator insert( const_iterator pos, InputIt first, InputIt last );
		// iterator insert( const_iterator pos, std::initializer_list<T> ilist );
		// iterator emplace( const_iterator pos, Args&&... args );
		// iterator erase( iterator pos );
		// iterator erase( iterator first, iterator last );
		// void emplace_back( Args&&... args );

		void push_back( const T& value )
		{
			try
			{
				if (_n == _size_alloc)
					throw Vector::ExceptionPushBack();
				else
				{
					array[_n] = value;
					_n++;
				}
			}
			catch(std::exception& e)
			{
				throw;
			}
		}

		void pop_back()
		{
			try
			{
				if (_n == 0)
					throw Vector::ExceptionPushBack();
				else
				{
					_alloc.destroy(array[_n]);
					_n--;					
				}
			}
			catch (std::exception& e)
			{
				throw;
			}
		}

		// void resize( size_type count );
		// void resize( size_type count, T value = T() );
		// void swap( vector& other )
		// {

		// }

		void realocateVec(size_t new_size)
		{
			T* new_vec = _alloc.allocate(new_size);
			for (size_t i = 0; i < new_size; i++)
				_alloc.construct(&new_vec[i], array[i]);
			// _alloc.deallocate(array, _size_alloc);
			this->~Vector();
			_size_alloc = new_size;
			array = new_vec;
		}
		
};

#endif