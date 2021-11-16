#ifndef REVERSITERATORVECTOR_HPP
#define REVERSITERATORVECTOR_HPP
#include <memory>
#include <iostream>
#include <string>

template<typename T>
class ReversIteratorVector
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
		ReversIteratorVector()
		{
			obj = NULL;
		}

		ReversIteratorVector(T* first)
		{
			obj = first;
		}

		~ReversIteratorVector()
		{
		}
		
		T &operator+(int n)
		{
			return *(obj + n);
		}
		
		T &operator-(int n)
		{
			return *(obj - n);
		}
		
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

		bool operator!=(const ReversIteratorVector &it)
		{
			if (obj != it.obj)
				return(true);
			return(false);
		}

		bool operator==(const ReversIteratorVector &it)
		{
			if (obj == it.obj)
				return(true);
			return(false);
		}

		T &operator*()
		{
			return(*obj);
		}

};

template<typename T>
class ConstReversIteratorVector
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
		ConstReversIteratorVector()
		{
			obj = NULL;
		}

		ConstReversIteratorVector(T* first)
		{
			obj = first;
		}

		~ConstReversIteratorVector()
		{
		}
		
		T &operator+(int n)
		{
			return *(obj + n);
		}
		
		T &operator-(int n)
		{
			return *(obj - n);
		}
		
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

		bool operator!=(const ConstReversIteratorVector &it)
		{
			if (obj != it.obj)
				return(true);
			return(false);
		}

		bool operator==(const ConstReversIteratorVector &it)
		{
			if (obj == it.obj)
				return(true);
			return(false);
		}

		T &operator*()
		{
			return(*obj);
		}

};
#endif