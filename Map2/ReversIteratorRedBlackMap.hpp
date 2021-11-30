#ifndef REVERSITERATORREDBLACKMAP_HPP
#define REVERSITERATORREDBLACKMAP_HPP
#include <iostream>
#include <memory>

template<class Key, class T, class Compare, typename Node>
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

template<class Key, class T, class Compare, typename Node>
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

// namespace ft
// {
// 	template<class Key, class T, class Compare, typename Node_or_leaf_map>
// 	class ReversIteratorMap
// 	{
// 		public:
// 			public:
// 			typedef Key												key_type;
// 			typedef Compare											key_compare;
// 			typedef T                                               mapped_type;
// 			typedef	Pair<key_type, mapped_type>						value_type;
// 			typedef long int										difference_type;
// 			typedef size_t											size_type;
// 			typedef Node_or_leaf_map								Node;
// 			typedef Node&											reference;
// 			typedef Node*											pointer;
// 		private:
// 			Node_or_leaf_map* _node;
// 			Compare _comp;
// 			Node_or_leaf_map* _lastElem;
// 		public:
// 			ReversIteratorMap(Node_or_leaf_map* node = 0, Node_or_leaf_map* lastElem = 0, const Compare& comp = Compare())
// 			{
// 					_node = node;
// 					_lastElem = lastElem;
// 					_comp = comp;
// 			}

// 			~ReversIteratorMap()
// 			{
// 			}

// 			ReversIteratorMap operator=(ReversIteratorMap obj)
// 			{
// 				_node = obj->_node;
// 				_lastElem = obj->_lastElem;
// 				_comp = obj->_comp;
// 				return (*this);
// 			}

// 			ReversIteratorMap &operator--(int)
// 			{
// 				if (_node->right != NULL)
// 				{
// 					_node = searchMinNode(_node->right);
// 					return (*this);
// 				}
// 				Node_or_leaf_map* tmp;
// 				tmp = _node->root;
// 				while (tmp != NULL && _node == tmp->right)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				if (tmp != NULL)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				return (*this);
// 			}

// 			ReversIteratorMap &operator++(int)
// 			{
				
// 				if (_node->left != NULL)
// 				{
// 					_node = searchMaxNode(_node->left);
// 					return (*this);
// 				}
// 				Node_or_leaf_map* tmp;
// 				tmp = _node->root;			
// 				while (tmp != NULL && _node == tmp->left)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				if (tmp != NULL)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				return (*this);
// 			}

// 			ReversIteratorMap operator--()
// 			{
// 				ReversIteratorMap res(*this);
// 				if (_node->right != NULL)
// 				{
// 					_node = searchMinNode(_node->right);
// 					return (*this);
// 				}
// 				Node_or_leaf_map* tmp;
// 				tmp = _node->root;
// 				while (tmp != NULL && _node == tmp->right)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				if (tmp != NULL)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				return (res);
// 			}

// 			ReversIteratorMap operator++()
// 			{
// 				ReversIteratorMap res(*this);
// 				if (_node->left != NULL)
// 				{
// 					_node = searchMaxNode(_node->left);
// 					return (*this);
// 				}
// 				Node_or_leaf_map* tmp;
// 				tmp = _node->root;			
// 				while (tmp != NULL && _node == tmp->left)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				if (tmp != NULL)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				return (res);
// 			}

// 			bool operator!=(const ReversIteratorMap &it)
// 			{
// 				if (_node != it._node)
// 					return(true);
// 				return(false);
// 			}

// 			bool operator==(const ReversIteratorMap &it)
// 			{
// 				if (_node == it._node)
// 					return(true);
// 				return(false);
// 			}

// 			Pair<Key, T> operator*()
// 			{
// 				return (_node->value->first);
// 			}

// 			private:
// 				Node_or_leaf_map* searchMinNode(Node_or_leaf_map* node)
// 				{
// 					if (node && node != _lastElem && node->left && node->left != _lastElem)
// 						return (searchMinNode(node->left));
// 					return (node);
// 				}

// 				Node_or_leaf_map* searchMaxNode(Node_or_leaf_map* node)
// 				{
// 					if (node && node != _lastElem && node->right && node->right != _lastElem)
// 						return (searchMaxNode(node->right));
// 					return (node);	
// 				}
// 	};


// 	template<class Key, class T, class Compare, typename Node_or_leaf_map>
// 	class ConstReversIteratorMap
// 	{
// 		public:
// 			public:
// 			typedef Key												key_type;
// 			typedef Compare											key_compare;
// 			typedef T                                               mapped_type;
// 			typedef	Pair<key_type, mapped_type>						value_type;
// 			typedef long int										difference_type;
// 			typedef size_t											size_type;
// 			typedef Node_or_leaf_map								Node;
// 			typedef Node&											reference;
// 			typedef Node*											pointer;
// 		private:
// 			Node_or_leaf_map* _node;
// 			Compare _comp;
// 			Node_or_leaf_map* _lastElem;
// 		public:
// 			ConstReversIteratorMap(Node_or_leaf_map* node = 0, Node_or_leaf_map* lastElem = 0, const Compare& comp = Compare())
// 			{
// 					_node = node;
// 					_lastElem = lastElem;
// 					_comp = comp;
// 			}

// 			~ConstReversIteratorMap()
// 			{
// 			}

// 			ConstReversIteratorMap operator=(ConstReversIteratorMap obj)
// 			{
// 				_node = obj->_node;
// 				_lastElem = obj->_lastElem;
// 				_comp = obj->_comp;
// 				return (*this);
// 			}

// 			ConstReversIteratorMap &operator--(int)
// 			{
// 				if (_node->right != NULL)
// 				{
// 					_node = searchMinNode(_node->right);
// 					return (*this);
// 				}
// 				Node_or_leaf_map* tmp;
// 				tmp = _node->root;
// 				while (tmp != NULL && _node == tmp->right)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				if (tmp != NULL)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				return (*this);
// 			}

// 			ConstReversIteratorMap &operator++(int)
// 			{
				
// 				if (_node->left != NULL)
// 				{
// 					_node = searchMaxNode(_node->left);
// 					return (*this);
// 				}
// 				Node_or_leaf_map* tmp;
// 				tmp = _node->root;			
// 				while (tmp != NULL && _node == tmp->left)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				if (tmp != NULL)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				return (*this);
// 			}

// 			ConstReversIteratorMap operator--()
// 			{
// 				ConstReversIteratorMap res(*this);
// 				if (_node->right != NULL)
// 				{
// 					_node = searchMinNode(_node->right);
// 					return (*this);
// 				}
// 				Node_or_leaf_map* tmp;
// 				tmp = _node->root;
// 				while (tmp != NULL && _node == tmp->right)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				if (tmp != NULL)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				return (res);
// 			}

// 			ConstReversIteratorMap operator++()
// 			{
// 				ConstReversIteratorMap res(*this);
// 				if (_node->left != NULL)
// 				{
// 					_node = searchMaxNode(_node->left);
// 					return (*this);
// 				}
// 				Node_or_leaf_map* tmp;
// 				tmp = _node->root;			
// 				while (tmp != NULL && _node == tmp->left)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				if (tmp != NULL)
// 				{
// 					_node = tmp;
// 					tmp = tmp->root;
// 				}
// 				return (res);
// 			}

// 			bool operator!=(const ConstReversIteratorMap &it)
// 			{
// 				if (_node != it._node)
// 					return(true);
// 				return(false);
// 			}

// 			bool operator==(const ConstReversIteratorMap &it)
// 			{
// 				if (_node == it._node)
// 					return(true);
// 				return(false);
// 			}

// 			Pair<Key, T> operator*()
// 			{
// 				return (_node->value->first);
// 			}

// 			private:
// 				Node_or_leaf_map* searchMinNode(Node_or_leaf_map* node)
// 				{
// 					if (node && node != _lastElem && node->left && node->left != _lastElem)
// 						return (searchMinNode(node->left));
// 					return (node);
// 				}

// 				Node_or_leaf_map* searchMaxNode(Node_or_leaf_map* node)
// 				{
// 					if (node && node != _lastElem && node->right && node->right != _lastElem)
// 						return (searchMaxNode(node->right));
// 					return (node);	
// 				}
// 	};
// 	#endif
// }
