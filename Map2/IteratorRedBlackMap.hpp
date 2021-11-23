#ifndef ITERATORREDBLACKMAP_HPP
#define ITERATORREDBLACKMAP_HPP
#include <iostream>
#include <memory>

template<class Key, class T, class Compare, typename Node_or_leaf_map>
class IteratorRedBlackMap
{
	private:
		T* obj;
	public:
		IteratorRedBlackMap()
		{
			obj = NULL;
		}

		IteratorRedBlackMap(T* first)
		{
			obj = first;
		}

		~IteratorRedBlackMap()
		{
		}

		// T& operator+(int n)
		// {
		// 	return *(obj + n);
		// }

		// T& operator+(size_t n)
		// {
		// 	return *(obj + n);
		// }

		// T& operator-(int n)
		// {
		// 	return *(obj - n);
		// }

		// size_t operator-(IteratorVector i)
		// {
		// 	return (obj - i.obj);
		// }
		
		// size_t operator+(IteratorVector i)
		// {
		// 	return (obj + i.obj);
		// }

		// size_t operator+(IteratorVector i, size_t k)
		// {
			
		// 	return (obj + i.obj);
		// }

		// T &operator++(int)
		// {
		// 	return (*obj++);
		// }

		// T &operator--(int)
		// {
		// 	return(*obj--);
		// }

		// T &operator++()
		// {
		// 	return (++*obj);
		// }

		// T &operator--()
		// {
		// 	return (--*obj);
		// }

		// bool operator!=(const IteratorVector &it)
		// {
		// 	if (obj != it.obj)
		// 		return(true);
		// 	return(false);
		// }

		// bool operator==(const IteratorVector &it)
		// {
		// 	if (obj == it.obj)
		// 		return(true);
		// 	return(false);
		// }

		// T operator*()
		// {
		// 	return(*obj);
		// }
};

template<class Key, class T, class Compare, typename Node_or_leaf_map>
class ConstIteratorRedBlackMap
{
	private:
		T* obj;
	public:
		ConstIteratorRedBlackMap()
		{
			obj = NULL;
		}

		ConstIteratorRedBlackMap(T* first)
		{
			obj = first;
		}

		~ConstIteratorRedBlackMap()
		{
		}

		// T& operator+(int n)
		// {
		// 	return *(obj + n);
		// }

		// T& operator+(size_t n)
		// {
		// 	return *(obj + n);
		// }

		// T& operator-(int n)
		// {
		// 	return *(obj - n);
		// }

		// size_t operator-(IteratorVector i)
		// {
		// 	return (obj - i.obj);
		// }
		
		// size_t operator+(IteratorVector i)
		// {
		// 	return (obj + i.obj);
		// }

		// size_t operator+(IteratorVector i, size_t k)
		// {
			
		// 	return (obj + i.obj);
		// }

		// T &operator++(int)
		// {
		// 	return (*obj++);
		// }

		// T &operator--(int)
		// {
		// 	return(*obj--);
		// }

		// T &operator++()
		// {
		// 	return (++*obj);
		// }

		// T &operator--()
		// {
		// 	return (--*obj);
		// }

		// bool operator!=(const IteratorVector &it)
		// {
		// 	if (obj != it.obj)
		// 		return(true);
		// 	return(false);
		// }

		// bool operator==(const IteratorVector &it)
		// {
		// 	if (obj == it.obj)
		// 		return(true);
		// 	return(false);
		// }

		// T operator*()
		// {
		// 	return(*obj);
		// }
};

#endif