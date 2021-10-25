#ifndef ITERATORMAP_HPP
#define ITERATORMAP_HPP
#include <iostream>
#include <memory>
#include "Map.hpp"

// template<class T>
template<class Key, class T, class Compare, typename Node_or_leaf_map>
class IteratorMap
{
	private:
		Node_or_leaf_map* _node;
		Compare _comp;
		Node_or_leaf_map* _lastElem;
		// T* obj;
	public:
		IteratorMap(Node_or_leaf_map* node = 0, Node_or_leaf_map* lastElem = 0, const Compare& comp = Compare())
		{
                _node = node;
				_lastElem = lastElem;
				_comp = comp;
		}

		// IteratorMap(Node_or_leaf_map* node, Node_or_leaf_map* lastElem, const Compare& comp)
		// {
		// 	_node = node;
		// 	_lastElem = lastElem;
		// 	_comp = comp;
		// }

		~IteratorMap()
		{
		}

		IteratorMap operator=(IteratorMap obj)
		{
			(void)obj;
			// this->obj = &obj;
			return (*this);
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