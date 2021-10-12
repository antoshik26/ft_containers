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

		Vector &operator=(const Vector obj)
		{
			_alloc = obj._alloc;
			_size_alloc = obj._size_alloc;
			_n = obj._n;
			array = _alloc.allocate(_size_alloc);
			for (size_t i = 0; i < _n; i++)
			{
    			_alloc.construct(&array[i]);
				array[i] = obj.get_data(i);
			}
			return (*this);
		}

		T get_data(size_t i)
		{
			return (array[i]);
		}

		// friends bool &operator!=(const Vector obj1, const Vector obj2)
		// {

		// }

		// friends bool &operator==(const Vector obj1, const Vector obj2)
		// {

		// }

		// friends bool &operator<(const Vector obj1, const Vector obj2)
		// {

		// }

		// friends bool &operator>(const Vector obj1, const Vector obj2)
		// {

		// }

		// friends bool &operator<=(const Vector obj1, const Vector obj2)
		// {

		// }

		// friends bool &operator>=(const Vector obj1, const Vector obj2)
		// {

		// }

		// void assign( size_type count, const T& value )
		// {

		// }

		// template< class InputIt >
		// void assign( InputIt first, InputIt last )
		// {

		// }
		
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

		size_t capacity() const
		{
			return (_size_alloc);
		}

		bool empty() const
		{
			if (_n == 0)
				return (true);
			else
				return (false);
		}

		void resize(size_t count)
		{
			T* new_vec = _alloc.allocate(count);
			for (size_t i = 0; i < _n; ++i)
                    _alloc.construct(&new_vec[i], array[i]);
			realocateVec(count);
			if (count < _n)
				_n = count;
			for (size_t i = 0; i < _n; i++)
				 _alloc.construct(array[i], &new_vec[i]);
		}
		
		void resize(size_t count, T value = T())
		{
			if (count > _size_alloc)
                    realocateVec(count);
                while (count > _n)
                    push_back(value);
                while (count < _n)
                    pop_back();
		}

		void clear()
		{
			for(size_t i = 0; i < _n; i++)
			{
				_alloc.destroy(&array[i]);
			}
			_n = 0;
		}

		// IteratorVector<T>  insert(IteratorVector<T> pos, const T& value)
		// {
			
		// }

		void insert(IteratorVector<T> pos, size_t count, const T& value )
		{
			size_t i = pos - begin();
			// size_t k = end() - pos;
			if (static_cast<size_t>(pos + count) > _size_alloc)
				realocateVec(pos + count);
			IteratorVector<T> new_pos(&array[i]);
			for (size_t j = 0; j < pos - end(); j--)
			{
				_alloc.construct(&array[j + 1], array[j]);
				_alloc.destroy(&array[j]);
				// array[j] = array[j + 1];
			}
			// (void)value;
			for (size_t j = 0; j < count; j++)
			{
				_alloc.construct(&array[new_pos + j], value);
				_n++;
			}	
		}

		// template< class InputIt >
		// void insert( iterator pos, InputIt first, InputIt last )
		// {

		// }

		// iterator erase( iterator pos )
		// {

		// }

		// iterator erase( iterator first, iterator last )
		// {

		// }

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

		// void swap(Vector& other)
		// {

		// }

		void realocateVec(size_t new_size)
		{
			T* new_vec = _alloc.allocate(new_size);
			for (size_t i = 0; i < new_size; i++)
				_alloc.construct(&new_vec[i], array[i]);
			this->~Vector();
			_size_alloc = new_size;
			array = new_vec;
		}
		
};

#endif