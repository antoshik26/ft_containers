#ifndef REVERSITERATORVECTOR_HPP
#define REVERSITERATORVECTOR_HPP
#include <memory>
#include <iostream>
#include <string>

template<typename T>
class ReversIteratorVector
{
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

#endif