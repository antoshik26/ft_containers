#ifndef ITERATORMAP_HPP
#define ITERATORMAP_HPP
#include <iostream>
#include <memory>
#include "Map.hpp"
#include "Pair.hpp"
#include "Less.hpp"

template<class Key, class T, class Compare, typename Node_or_leaf_map>
class IteratorMap
{
	public:
		typedef Key												key_type;
		typedef Compare											key_compare;
		typedef T                                               mapped_type;
		typedef	Pair<key_type, mapped_type>						value_type;
		typedef long int										difference_type;
		typedef size_t											size_type;
		typedef Node_or_leaf_map								Node;
		typedef Node&											reference;
		typedef Node*											pointer;

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

		IteratorMap &operator++(int)
		{
			if (_node->right != NULL)
			{
				_node = searchMinNode(_node->right);
				return (*this);
			}
			Node_or_leaf_map* tmp;
			tmp = _node->root;
			while (tmp != NULL && _node == tmp->right)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			if (tmp != NULL)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			return (*this);
		}

		IteratorMap &operator--(int)
		{
			
			if (_node->left != NULL)
			{
				_node = searchMaxNode(_node->left);
				return (*this);
			}
			Node_or_leaf_map* tmp;
			tmp = _node->root;			
			while (tmp != NULL && _node == tmp->left)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			if (tmp != NULL)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			return (*this);
		}

		IteratorMap operator++()
		{
			IteratorMap res(*this);
			if (_node->right != NULL)
			{
				_node = searchMinNode(_node->right);
				return (*this);
			}
			Node_or_leaf_map* tmp;
			tmp = _node->root;
			while (tmp != NULL && _node == tmp->right)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			if (tmp != NULL)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			return (res);
		}

		IteratorMap operator--()
		{
			IteratorMap res(*this);
			if (_node->left != NULL)
			{
				_node = searchMaxNode(_node->left);
				return (*this);
			}
			Node_or_leaf_map* tmp;
			tmp = _node->root;			
			while (tmp != NULL && _node == tmp->left)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			if (tmp != NULL)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			return (res);
		}

		Node_or_leaf_map* get_node()
		{
			return (_node);
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
				if (node->left == NULL)
					return (node);
				return searchMinNode(node->left); 
			}

			Node_or_leaf_map* searchMaxNode(Node_or_leaf_map* node)
			{
				if (node->right == NULL)
					return (node);
				return (searchMaxNode(node->right));
			}
};

template<class Key, class T, class Compare, typename Node_or_leaf_map>
class ConstIteratorMap
{
	public:
		typedef Key												key_type;
		typedef Compare											key_compare;
		typedef T                                               mapped_type;
		typedef	Pair<key_type, mapped_type>						value_type;
		typedef long int										difference_type;
		typedef size_t											size_type;
		typedef Node_or_leaf_map								Node;
		typedef Node&											reference;
		typedef Node*											pointer;
	private:
		Node_or_leaf_map* _node;
		Compare _comp;
		Node_or_leaf_map* _lastElem;
	public:
		ConstIteratorMap(Node_or_leaf_map* node = 0, Node_or_leaf_map* lastElem = 0, const Compare& comp = Compare())
		{
                _node = node;
				_lastElem = lastElem;
				_comp = comp;
		}

		~ConstIteratorMap()
		{
		}

		ConstIteratorMap operator=(ConstIteratorMap obj)
		{
			_node = obj._node;
			_comp = obj._comp;
			_lastElem = obj._lastElem;
			return (*this);
		}

		ConstIteratorMap &operator++(int)
		{
			if (_node->right != NULL)
			{
				_node = searchMinNode(_node->right);
				return (*this);
			}
			Node_or_leaf_map* tmp;
			tmp = _node->root;
			while (tmp != NULL && _node == tmp->right)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			if (tmp != NULL)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			return (*this);
		}

		ConstIteratorMap &operator--(int)
		{
			if (_node->left != NULL)
			{
				_node = searchMaxNode(_node->left);
				return (*this);
			}
			Node_or_leaf_map* tmp;
			tmp = _node->root;			
			while (tmp != NULL && _node == tmp->left)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			if (tmp != NULL)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			return (*this);
		}

		ConstIteratorMap operator++()
		{
			ConstIteratorMap res(*this);
			if (_node->right != NULL)
			{
				_node = searchMinNode(_node->right);
				return (*this);
			}
			Node_or_leaf_map* tmp;
			tmp = _node->root;
			while (tmp != NULL && _node == tmp->right)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			if (tmp != NULL)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			return (res);
		}

		ConstIteratorMap operator--()
		{
			ConstIteratorMap res(*this);
			if (_node->left != NULL)
			{
				_node = searchMaxNode(_node->left);
				return (*this);
			}
			Node_or_leaf_map* tmp;
			tmp = _node->root;			
			while (tmp != NULL && _node == tmp->left)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			if (tmp != NULL)
			{
				_node = tmp;
				tmp = tmp->root;
			}
			return (*this);
		}

	

		Node_or_leaf_map* get_node()
		{
			return (_node);
		}

		bool operator!=(const ConstIteratorMap &it)
		{
				if (_node != it._node)
					return(true);
				return(false);
		}

		bool operator==(const ConstIteratorMap &it)
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
				if (node->left == NULL)
					return (node);
				return searchMinNode(node->left); 
			}

			Node_or_leaf_map* searchMaxNode(Node_or_leaf_map* node)
			{
				if (node->right == NULL)
					return (node);
				return (searchMaxNode(node->right));
			}
};
#endif