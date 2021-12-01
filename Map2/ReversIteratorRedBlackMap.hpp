#ifndef REVERSITERATORREDBLACKMAP_HPP
#define REVERSITERATORREDBLACKMAP_HPP
#include <iostream>
#include <memory>

namespace ft
{
	template<class Key, class T, class Compare, typename Node>
	class ReversIteratorRedBlackMap
	{
		private:
			Node* _node;
			Compare _comp;
			Node* TNULL;
		public:
			ReversIteratorRedBlackMap(Node* node = 0, Node* lastElem = 0, const Compare& comp = Compare())
			{
				_node = node;
				TNULL = lastElem;
				_comp = comp;
			}

			ReversIteratorRedBlackMap(const ReversIteratorRedBlackMap &obj)
			{
				_node = obj._node;
				TNULL = obj.TNULL;
				_comp = obj._comp;
			}

			~ReversIteratorRedBlackMap()
			{
			}

			ReversIteratorRedBlackMap operator=(ReversIteratorRedBlackMap obj)
			{
				_node = obj._node;
				_comp = obj._comp;
				TNULL = obj.TNULL;
				return (*this);
			}

			ReversIteratorRedBlackMap &operator++(int)
			{
				if (_node->right != TNULL)
				{
					_node = searchMinNode(_node->right);
					return (*this);
				}
				Node* tmp;
				tmp = _node->parent;
				while (tmp != TNULL && _node == tmp->right)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				if (tmp != TNULL)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				return (*this);
			}

			ReversIteratorRedBlackMap &operator--(int)
			{
				if (_node->left != TNULL)
				{
					_node = searchMaxNode(_node->left);
					return (*this);
				}
				Node* tmp;
				tmp = _node->parent;			
				while (tmp != TNULL && _node == tmp->left)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				if (tmp != TNULL)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				return (*this);
			}

			ReversIteratorRedBlackMap operator++()
			{
				ReversIteratorRedBlackMap res(*this);
				if (_node->right != TNULL)
				{
					_node = searchMinNode(_node->right);
					return (*this);
				}
				Node* tmp;
				tmp = _node->parent;
				while (tmp != TNULL && _node == tmp->right)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				if (tmp != TNULL)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				return (res);
			}

			ReversIteratorRedBlackMap operator--()
			{
				ReversIteratorRedBlackMap res(*this);
				if (_node->left != TNULL)
				{
					_node = searchMaxNode(_node->left);
					return (*this);
				}
				Node* tmp;
				tmp = _node->root;			
				while (tmp != TNULL && _node == tmp->left)
				{
					_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != TNULL)
				{
					_node = tmp;
					tmp = tmp->root;
				}
				return (res);
			}

			bool operator!=(const ReversIteratorRedBlackMap &it)
			{
					if (_node->data.first != it->first && _node->data.second != it->second)
						return(true);
					return(false);
			}

			bool operator==(const ReversIteratorRedBlackMap &it)
			{
				if (_node->data.first == it->first && _node->data.second == it->second)
					return(true);
				return(false);
			}

			Pair<Key, T>& operator*() const
			{
				return(_node->data);
			}

			Pair<Key, T>* operator->() const
			{
				return(&(_node->data));
			}
		private:
			Node* searchMinNode(Node* node)
			{
				if (node->left == TNULL)
					return (node);
				return searchMinNode(node->left); 
			}

			Node* searchMaxNode(Node* node)
			{
				if (node->right == TNULL)
					return (node);
				return (searchMaxNode(node->right));
			}
	};

	template<class Key, class T, class Compare, typename Node>
	class ConstReversIteratorRedBlackMap
	{
		private:
			Node* _node;
			Compare _comp;
			Node* TNULL;
		public:
			ConstReversIteratorRedBlackMap(Node* node = 0, Node* lastElem = 0, const Compare& comp = Compare())
			{
				_node = node;
				TNULL = lastElem;
				_comp = comp;
			}

			ConstReversIteratorRedBlackMap(const ConstReversIteratorRedBlackMap &obj)
			{
				_node = obj._node;
				TNULL = obj.TNULL;
				_comp = obj._comp;
			}

			~ConstReversIteratorRedBlackMap()
			{
			}

			ConstReversIteratorRedBlackMap operator=(ConstReversIteratorRedBlackMap obj)
			{
				_node = obj._node;
				_comp = obj._comp;
				TNULL = obj.TNULL;
				return (*this);
			}

			ConstReversIteratorRedBlackMap &operator++(int)
			{
				if (_node->right != TNULL)
				{
					_node = searchMinNode(_node->right);
					return (*this);
				}
				Node* tmp;
				tmp = _node->parent;
				while (tmp != TNULL && _node == tmp->right)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				if (tmp != TNULL)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				return (*this);
			}

			ConstReversIteratorRedBlackMap &operator--(int)
			{
				if (_node->left != TNULL)
				{
					_node = searchMaxNode(_node->left);
					return (*this);
				}
				Node* tmp;
				tmp = _node->parent;			
				while (tmp != TNULL && _node == tmp->left)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				if (tmp != TNULL)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				return (*this);
			}

			ConstReversIteratorRedBlackMap operator++()
			{
				ConstReversIteratorRedBlackMap res(*this);
				if (_node->right != TNULL)
				{
					_node = searchMinNode(_node->right);
					return (*this);
				}
				Node* tmp;
				tmp = _node->parent;
				while (tmp != TNULL && _node == tmp->right)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				if (tmp != TNULL)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				return (res);
			}

			ConstReversIteratorRedBlackMap operator--()
			{
				ConstReversIteratorRedBlackMap res(*this);
				if (_node->left != TNULL)
				{
					_node = searchMaxNode(_node->left);
					return (*this);
				}
				Node* tmp;
				tmp = _node->root;			
				while (tmp != TNULL && _node == tmp->left)
				{
					_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != TNULL)
				{
					_node = tmp;
					tmp = tmp->root;
				}
				return (res);
			}

			bool operator!=(const ConstReversIteratorRedBlackMap &it)
			{
					if (_node->data.first != it->first && _node->data.second != it->second)
						return(true);
					return(false);
			}

			bool operator==(const ConstReversIteratorRedBlackMap &it)
			{
				if (_node->data.first == it->first && _node->data.second == it->second)
					return(true);
				return(false);
			}

			Pair<Key, T>& operator*() const
			{
				return(_node->data);
			}

			Pair<Key, T>* operator->() const
			{
				return(&(_node->data));
			}
		private:
			Node* searchMinNode(Node* node)
			{
				if (node->left == TNULL)
					return (node);
				return searchMinNode(node->left); 
			}

			Node* searchMaxNode(Node* node)
			{
				if (node->right == TNULL)
					return (node);
				return (searchMaxNode(node->right));
			}
	};
}
#endif