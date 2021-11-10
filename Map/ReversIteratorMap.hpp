#ifndef REVERSITERATORMAP_HPP
#define REVERSITERATORMAP_HPP
#include <iostream>
#include <memory>

template<class Key, class T, class Compare, typename Node_or_leaf_map>
class ReversIteratorMap
{
	private:
		Node_or_leaf_map* _node;
		Compare _comp;
		Node_or_leaf_map* _lastElem;
	public:
		ReversIteratorMap(Node_or_leaf_map* node = 0, Node_or_leaf_map* lastElem = 0, const Compare& comp = Compare())
		{
                _node = node;
				_lastElem = lastElem;
				_comp = comp;
		}

		~ReversIteratorMap()
		{
		}

		ReversIteratorMap operator=(ReversIteratorMap obj)
		{
			_node = obj->_node;
			_lastElem = obj->_lastElem;
			_comp = obj->_comp;
			return (*this);
		}

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

		bool operator!=(const ReversIteratorMap &it)
		{
			if (_node != it._node)
				return(true);
			return(false);
		}

		bool operator==(const ReversIteratorMap &it)
		{
			if (_node == it._node)
				return(true);
			return(false);
		}

		Pair<Key, T> operator*()
		{
			return (_node->value->first);
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