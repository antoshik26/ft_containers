#ifndef ITERATORMAP_HPP
#define ITERATORMAP_HPP
#include <iostream>
#include <memory>
#include "Map.hpp"
#include "Pair.hpp"
#include "Less.hpp"

// template<class T>
template<class Key, class T, class Compare, typename Node_or_leaf_map>
class IteratorMap
{
	private:
		Node_or_leaf_map* _node;
		Compare _comp;
		Node_or_leaf_map* _lastElem;
	public:
		IteratorMap(Node_or_leaf_map* node = 0, Node_or_leaf_map* lastElem = 0, const Compare& comp = Compare())
		{
                _node = node;
				_lastElem = lastElem;
				_comp = comp;
		}

		~IteratorMap()
		{
		}

		IteratorMap operator=(IteratorMap obj)
		{
			_node = obj._node;
			_comp = obj._comp;
			_lastElem = obj._lastElem;
			return (*this);
		}

		// Pair</*const*/ Key, T>& operator+(int n)
		// {
		// 	return *(obj + n);
		// }

		// Pair</*const*/ Key, T>& operator+(size_t n)
		// {
		// 	return *(obj + n);
		// }

		// Pair</*const*/ Key, T>& operator-(int n)
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

		IteratorMap &operator++(int)
		{
			Node_or_leaf_map* previousNode = _node;

			if (_node == _lastElem)
			{
				while (_node != _lastElem && !_comp(previousNode->value->first, _node->value->first))
				{
					if (_node->right && (_node->right == _lastElem || _comp(previousNode->content.first, _node->right->content.first)))
					{
						_node = _node->right;
						Node_or_leaf_map* tmp = 0;
                        if (_node != _lastElem && (tmp = searchMinNode(_node)))
                            _node = tmp;
					}
					else
					{
						_node = _node->root;
					}
				}
			}
			return (*this);
		}

		// IteratorMap &operator--(int)
		// {
		// 	return(*obj--);
		// }

		// IteratorMap &operator++()
		// {
		// 	return (++*obj);
		// }

		// IteratorMap &operator--()
		// {
		// 	return (--*obj);
		// }

		bool operator!=(const IteratorMap &it)
		{
				if (_node != it._node)
					return(true);
				return(false);
		}

		bool operator==(const IteratorMap &it)
		{
			if (_node == it._node)
				return(true);
			return(false);
		}

		Pair</*const*/ Key, T> operator*()
		{
			return(_node->value);
		}

		private:
			Node_or_leaf_map searchMinNode(Node_or_leaf_map node)
			{
				
			}

			Node_or_leaf_map searchMaxNode(Node_or_leaf_map node)
			{
				
			}
};

#endif