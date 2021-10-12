#ifndef ITERATORVECTOR_HPP
#define ITERATORVECTOR_HPP
#include <memory>
#include <iostream>
#include <string>

template<typename T>
class IteratorVector
{
	private:
		T* obj;
	public:
		IteratorVector()
		{
			obj = NULL;
		}

		IteratorVector(T* first)
		{
			obj = first;
		}

		~IteratorVector()
		{
		}

		T& operator+(int n)
		{
			return *(obj + n);
		}

		T& operator+(size_t n)
		{
			return *(obj + n);
		}

		T& operator-(int n)
		{
			return *(obj - n);
		}

		size_t operator-(IteratorVector i)
		{
			return (obj - i.obj);
		}
		
		size_t operator+(IteratorVector i)
		{
			return (obj + i.obj);
		}

		// size_t operator+(IteratorVector i, size_t k)
		// {
			
		// 	return (obj + i.obj);
		// }

		T &operator++(int)
		{
			return (*obj++);
		}

		T &operator--(int)
		{
			return(*obj--);
		}

		T &operator++()
		{
			return (++*obj);
		}

		T &operator--()
		{
			return (--*obj);
		}

		bool operator!=(const IteratorVector &it)
		{
			if (obj != it.obj)
				return(true);
			return(false);
		}

		bool operator==(const IteratorVector &it)
		{
			if (obj == it.obj)
				return(true);
			return(false);
		}

		T operator*()
		{
			return(*obj);
		}
};

#endif