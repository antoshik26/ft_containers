#ifndef ITERATORREDBLACKMAP_HPP
#define ITERATORREDBLACKMAP_HPP
#include <iostream>
#include <memory>

namespace ft
{
	template<class Key, class T, class Compare, typename Node>
	class IteratorRedBlackMap
	{
		private:
			Node* _node;
			Compare _comp;
			Node* TNULL;
		public:
			IteratorRedBlackMap(Node* node = 0, Node* lastElem = 0, const Compare& comp = Compare())
			{
				_node = node;
				TNULL = lastElem;
				_comp = comp;
			}

			IteratorRedBlackMap(const IteratorRedBlackMap &obj)
			{
				_node = obj._node;
				TNULL = obj.TNULL;
				_comp = obj._comp;
			}

			~IteratorRedBlackMap()
			{
			}

			IteratorRedBlackMap operator=(IteratorRedBlackMap obj)
			{
				_node = obj._node;
				_comp = obj._comp;
				TNULL = obj.TNULL;
				return (*this);
			}

			IteratorRedBlackMap &operator++(int)
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

			IteratorRedBlackMap &operator--(int)
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

			IteratorRedBlackMap operator++()
			{
				IteratorRedBlackMap res(*this);
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

			IteratorRedBlackMap operator--()
			{
				IteratorRedBlackMap res(*this);
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

			bool operator!=(const IteratorRedBlackMap &it)
			{
					if (_node->data.first != it->first && _node->data.second != it->second)
						return(true);
					return(false);
			}

			bool operator==(const IteratorRedBlackMap &it)
			{
				if (_node->data.first == it->first && _node->data.second == it->second)
					return(true);
				return(false);
			}

			Node* get_node()
			{
				return (_node);
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
	class ConstIteratorRedBlackMap
	{
		private:
			Node* _node;
			Compare _comp;
			Node* TNULL;
		public:
			ConstIteratorRedBlackMap(Node* node = 0, Node* lastElem = 0, const Compare& comp = Compare())
			{
				_node = node;
				TNULL = lastElem;
				_comp = comp;
			}

			ConstIteratorRedBlackMap(const ConstIteratorRedBlackMap &obj)
			{
				_node = obj._node;
				TNULL = obj.TNULL;
				_comp = obj._comp;
			}

			~ConstIteratorRedBlackMap()
			{
			}

			ConstIteratorRedBlackMap operator=(ConstIteratorRedBlackMap obj)
			{
				_node = obj._node;
				_comp = obj._comp;
				TNULL = obj.TNULL;
				return (*this);
			}

			ConstIteratorRedBlackMap &operator++(int)
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

			ConstIteratorRedBlackMap &operator--(int)
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

			ConstIteratorRedBlackMap operator++()
			{
				ConstIteratorRedBlackMap res(*this);
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

			ConstIteratorRedBlackMap operator--()
			{
				ConstIteratorRedBlackMap res(*this);
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

			bool operator!=(const ConstIteratorRedBlackMap &it)
			{
					if (_node->data.first != it->first && _node->data.second != it->second)
						return(true);
					return(false);
			}

			bool operator==(const ConstIteratorRedBlackMap &it)
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