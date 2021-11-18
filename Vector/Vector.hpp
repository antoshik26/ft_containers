#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <string>
#include <cmath>
#include "IteratorVector.hpp"
#include "ReversIteratorVector.hpp"
#include "../include/Enable_if.hpp"
#include "../include/Is_integral.hpp"

template<typename T, class Allocator = std::allocator<T> >
class Vector
{
	public:
		typedef T                                           value_type;
		typedef Allocator                                   allocator_type;
		typedef long int                                    difference_type;
		typedef size_t                                      size_type;

		typedef T&                                          reference;
		typedef const T&                                    const_reference;
		typedef T*                                          pointer;
		typedef const T*                                    const_pointer;
		
		typedef IteratorVector<T>							iterator;
		typedef ConstIteratorVector<T>						const_iterator;

		typedef ReversIteratorVector<T>						reverse_iterator;
		typedef ConstReversIteratorVector<T>   				const_reverse_iterator;
	
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
		Vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename enable_if<!is_integral<InputIt>::value >::type* = 0)
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

		Vector(const Vector& other)
		{
			_alloc = other._alloc;
			_size_alloc = other._size_alloc;
			_n = other._n;
			array = _alloc.allocate(_size_alloc);
			for (size_t i = 0; i < _n; i++)
			{
    			_alloc.construct(&array[i]);
				array[i] = other.get_data(i);
			}
			return (*this);
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

		friend bool operator!=(const Vector obj1, const Vector obj2)
		{
			if (obj1._n != obj2._n)
				return (true);
			for (size_t i = 0; i < obj1._n; i++)
			{
				if (obj1.array[i] != obj2.array[i])
					return (true);
			}
			return (false);
		}

		friend bool operator==(const Vector obj1, const Vector obj2)
		{
			if (obj1._n != obj2._n)
				return (false);
			for (size_t i = 0; i < obj1._n; i++)
			{
				if (obj1.array[i] != obj2.array[i])
					return (false);
			}
			return (true); 
		}

		friend bool operator<(const Vector obj1, const Vector obj2)
		{
			if (obj1._n < obj2._n)
				return (true);
			if (obj1._n > obj2._n)
				return (false);
			for (size_t i = 0; i < obj1._n; i++)
			{
				if (obj1.array[i] > obj2.array[i])
					return (false);
			}
			return (true);
		}

		friend bool operator>(const Vector obj1, const Vector obj2)
		{
			if (obj1._n > obj2._n)
				return (true);
			if (obj1._n < obj2._n)
				return (false);
			for (size_t i = 0; i < obj1._n; i++)
			{
				if (obj1.array[i] < obj2.array[i])
					return (false);
			}
			return (true);
		}

		friend bool operator<=(const Vector obj1, const Vector obj2)
		{
			if (obj1._n < obj2._n)
				return (true);
			if (obj1._n > obj2._n)
				return (false);
			for (size_t i = 0; i < obj1._n; i++)
			{
				if (obj1.array[i] > obj2.array[i])
					return (false);
			}
			return (true);
		}

		friend bool operator>=(const Vector obj1, const Vector obj2)
		{
			if (obj1._n > obj1._n)
				return (true);
			if (obj1._n < obj2._n)
				return (false);
			for (size_t i = 0; i < obj2._n; i++)
			{
				if (obj1.array[i] < obj2.array[i])
					return (false);
			}
			return (true);
		}

		void assign(size_t count, const T& value )
		{
			clear();
			if (_size_alloc < count)
				realocateVec(count);
			for (size_t i = 0; i < count; i++)
				_alloc.construct(value);
			_n = count;
		}

		template< class InputIt >
		void assign( InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value >::type* = 0 )
		{
			clear();
			size_t count = first - last;
			if (_size_alloc < count)
				realocateVec(count);
			for (size_t i = 0; i < count; i++)
			{
				_alloc.construct(*first);
				first++;
			} 
		}
		
		IteratorVector<T> begin()
		{
			return (IteratorVector<T>(array));
		}

		const_iterator begin() const
		{
			return (ConstIteratorVector<T>(array));
		}

		IteratorVector<T> end()
		{
			return (IteratorVector<T>(array + _n));
		}
		
		const_iterator end() const
		{
			return (ConstIteratorVector<T>(array + _n));
		}

		ReversIteratorVector<T> rbegin()
		{
			return (ReversIteratorVector<T>(array + _n));
		}

		const_reverse_iterator rbegin() const
		{
			return (ConstReversIteratorVector<T>(array + _n));
		}

		ReversIteratorVector<T> rend()
		{
			return (ReversIteratorVector<T>(array));
		}

		const_reverse_iterator rend() const
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

		const_reference at( size_type pos ) const
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

		const_reference operator[]( size_type pos ) const
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

		const_reference front() const
		{
			return (&array[0]);
		}

		T& back()
		{
			return (&array[_n]);
		}

		const_reference back() const
		{
			return (&array[_n]);
		}

		T* data()
		{
			return (array);
		}

		const T* data() const
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

		IteratorVector<T>  insert(IteratorVector<T> pos, const T& value) //проверить //- 
		{
			size_t i = pos - begin();
			if ((_n + 1) > _size_alloc)
				realocateVec(_n + 1);
			for (size_t j = (_n - 1); j > i - 1; j--)
			{
				_alloc.construct(&array[j + 1], array[j]);
				_alloc.destroy(&array[j]);
			}
			_alloc.construct(&array[i], value);
			IteratorVector<T> a(&array[i]);
			return (a);
		}

		void insert(IteratorVector<T> pos, size_t count, const T& value )
		{
			size_t i = pos - begin();
			// size_t k = end() - pos;
			if (static_cast<size_t>(_n + count) > _size_alloc)
				realocateVec(_n + count);
			// IteratorVector<T> new_pos(&array[i]);
			// std::cout << i << std::endl;
			for (size_t j = (_n - 1); j > i - 1 ; j--)
			{

				_alloc.construct(&array[j + count], array[j]);
				// std::cout << array[j + count] << std::endl;
				// std::cout << j + count << std::endl;
				_alloc.destroy(&array[j]);
			}
			// size_t z = 0;
			// while (z < _n + 5)
			// {
			// 	std::cout << array[z] << " ";
			// 	z++;
			// }
			// std::cout << std::endl;
			// (void)value;
			for (size_t j = 0; j < count; j++)
			{
				_alloc.construct(&array[i + j], value);
				_n++;
			}
			// z = 0;
			// while (z < _n + 5)
			// {
			// 	std::cout << array[z] << " ";
			// 	z++;
			// }
			// std::cout << std::endl;
		}

		template< class InputIt >
		void insert(InputIt pos, InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value >::type* = 0) //проверить //-
		{
			size_t i = pos - begin();
			size_t count = last - first;
			if ((_n + count) < _size_alloc)
				realocateVec(_n + count);
			for (size_t j = (_n - 1); j > i - 1; j--)
			{
				_alloc.construct(&array[j + count], array[j]);
				_alloc.destroy(&array[j]);
			}
			for (size_t j = 0; j < count; j++)
			{
				_alloc.construct(&array[j + i], *first);
				first++;
			}
			_n = _n + count;
		}

		IteratorVector<T> erase(IteratorVector<T> pos) //проверить //-
		{
			size_t k = pos - begin();
			_n--;
			_alloc.destroy(&array[k]);
			for (size_t i = k; i < k + (end() - k) - 1; i++)
			{
				_alloc.construct(&array[i], array[i + 1]);
				_alloc.destroy(&array[i + 1]);
			}
			IteratorVector<T> a;
			return (a);
		}

		IteratorVector<T> erase(IteratorVector<T> first, IteratorVector<T> last) //проверить //-
		{
			size_t k = first - begin();
			size_t count = first - last;
			_n = _n - count;
			for (size_t i = 0; i < count; i++)
				_alloc.destroy(&array[i]);
			for (size_t i = k; i < k + (end() - k - count); i++)
			{
				_alloc.construct(&array[i], array[i + count]);
				_alloc.destroy(&array[i + count]);
			}
			IteratorVector<T> a;
			return (a);
		}

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

		friend void swap (Vector& x, Vector& y)
		{
			x.swap(y);
		}

		template <typename U>
		friend void swap(U& a, U&b)
		{
			U tmp = a;
			a = b;
			b = tmp;
		}

		void realocateVec(size_t new_size)
		{
			T* new_vec = _alloc.allocate(new_size);
			for (size_t i = 0; i < new_size; i++)
				_alloc.construct(&new_vec[i], array[i]);
			this->~Vector();
			_size_alloc = new_size;
			array = new_vec;
		}

		template<class InputIt1, class InputIt2>
		bool lexicographical_compare (InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
		{
			for (; (first1 != last1) && (first2 != last2); ++first1, ++last1)
			{
				if (*first1 < *first2) return true;
       			if (*first2 < *first1) return false;
    		}
    		return (first1 == last1) && (first2 != last2);	
		}
};

#endif