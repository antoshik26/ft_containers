#ifndef REVERSITERATORREDBLACKMAP_HPP
#define REVERSITERATORREDBLACKMAP_HPP
#include <iostream>
#include <memory>

template<class Key, class T, class Compare, typename Node_or_leaf_map>
class ReversIteratorRedBlackMap
{
	private:
		T* obj;
	public:
		ReversIteratorRedBlackMap()
		{
			obj = NULL;
		}

		ReversIteratorRedBlackMap(T* first)
		{
			obj = first;
		}

		~ReversIteratorRedBlackMap()
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
class ConstReversIteratorRedBlackMap
{
	private:
		T* obj;
	public:
		ConstReversIteratorRedBlackMap()
		{
			obj = NULL;
		}

		ConstReversIteratorRedBlackMap(T* first)
		{
			obj = first;
		}

		~ConstReversIteratorRedBlackMap()
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