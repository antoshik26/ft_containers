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

		IteratorMap &operator++()
		{
			Node_or_leaf_map* previousNode = _node;

			if (_node == _lastElem)
			{
				_node = _lastElem->right;
				return (*this);
			}
			while (_node != _lastElem && _comp(previousNode->value->first, _node->value->first) == 1)
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
			return (*this);
		}

		IteratorMap &operator--()
		{
			Node_or_leaf_map* previousNode = _node;

			if (_node == _lastElem)
			{
				_node = _lastElem->right;
				return (*this);
			}
			while (_node != _lastElem && _comp(previousNode->value->first, _node->value->first) == -1)
			{
				if (_node->left && (_node->left == _lastElem || _comp(previousNode->value.first, _node->left->value.first)))
				{
					_node == _node->left;
					Node_or_leaf_map* tmp = 0;
					if (_node != _lastElem && (tmp = searchMaxNode(_node)))
						_node = tmp;
				}
				else
				{
					_node = _node->root;
				}
			}
			return (*this);
		}

		IteratorMap &operator++(int)
		{
			IteratorMap res(*this);

			if (_node == _lastElem)
			{
				_node = _lastElem->right;
				return (res);
			}
			while (_node != _lastElem && _comp(res->first, _node->value->first))
			{
				if (_node->right && (_node->right == _lastElem || _comp(res->first, _node->right->value.first)))
				{
					_node = _node->right;
					Node_or_leaf_map* tmp;
					if (_node != _lastElem && (tmp == searchMaxNode(_node)))
						_node = tmp;
				}
				else
					_node = _node->right;
			}
			return (res);
		}

		IteratorMap &operator--(int)
		{
			IteratorMap res(*this);

			if (_node == _lastElem)
			{
				_node = _lastElem->right;
				return (res);
			}
			while (_node != _lastElem && _comp(res->first, _node->value->first))
			{
				if (_node->right && (_node->right == _lastElem || _comp(res->first, _node->right->value.first)))
				{
					_node = _node->right;
					Node_or_leaf_map* tmp;
					if (_node != _lastElem && (tmp == searchMinNode(_node)))
						_node = tmp;
				}
				else
					_node = _node->right;
			}
			return (res);
		}

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
			Node_or_leaf_map* searchMinNode(Node_or_leaf_map* node)
			{
				if (node && node != _lastElem && node->left && node->left != _lastElem)
					return (searchMinNode(node->left));
				return (node);
			}

			Node_or_leaf_map* searchMaxNode(Node_or_leaf_map* node)
			{
				if (node && node != _lastElem && node->right && node->right != _lastElem)
					return (searchMaxNode(node->right));
				return (node);	
			}
};
#endif