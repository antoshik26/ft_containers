#ifndef ITERATORVECTOR_HPP
#define ITERATORVECTOR_HPP
#include <memory>
#include <iostream>
#include <string>

template<typename T>
class IteratorVector
{
	public:
		typedef std::random_access_iterator_tag                 iterator_category;
		typedef long int                                        difference_type;
		typedef T                                               value_type;
		typedef size_t                                          size_type;		
		typedef T*                                              pointer;
		typedef T&												reference;
		
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

template<typename T>
class ConstIteratorVector
{
	public:
		typedef std::random_access_iterator_tag                 iterator_category;
		typedef long int                                        difference_type;
		typedef T                                               value_type;
		typedef size_t                                          size_type;		
		typedef T*                                              pointer;
		typedef T&												reference;
	private:
		T* obj;
	public:
		ConstIteratorVector()
		{
			obj = NULL;
		}

		ConstIteratorVector(T* first)
		{
			obj = first;
		}

		~ConstIteratorVector()
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

		size_t operator-(ConstIteratorVector i)
		{
			return (obj - i.obj);
		}
		
		size_t operator+(ConstIteratorVector i)
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

		bool operator!=(const ConstIteratorVector &it)
		{
			if (obj != it.obj)
				return(true);
			return(false);
		}

		bool operator==(const ConstIteratorVector &it)
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