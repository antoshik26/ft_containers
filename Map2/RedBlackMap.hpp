#ifndef REDBLACKMAP_HPP
#define REVERSITERATORMAP_HPP
#include <memory>
#include <iostream>
#include <string>
#include <cmath>
#include "../Map/Less.hpp"
#include "../Map/Pair.hpp"
#include "IteratorRedBlackMap.hpp"
#include "ReversIteratorRedBlackMap.hpp"

// namespace ft
// {

// }
template<
    class Key,
    class T,
    class Compare = less<Key>, 
    class Allocator = std::allocator<std::pair<const Key, T> >
>
class RedBlackmap
{
	public:
		struct Node_or_leaf_map
		{
			Pair</*const*/ Key, T> value;
			Node_or_leaf_map *right;
			Node_or_leaf_map *left;
			Node_or_leaf_map *root;
			int collor;
			
			Node_or_leaf_map(const Pair</*const*/ Key, T>& value/*, Node_or_leaf_map* right, Node_or_leaf_map* left, Node_or_leaf_map* root, int collor*/)
			{
				// std::cout << "1" << std::endl;
				this->value = value;
				// this->right = right;
				// this->left = left;
				// this->root = root;
				// this->collor = collor;
				// std::cout << "2" << std::endl;
			}
			Node_or_leaf_map& operator=(const Node_or_leaf_map& other)
			{
				(void)other;
				std::cout << "3" << std::endl;
			}

			~Node_or_leaf_map()
			{
				
			}
		};
	public:
		typedef Key																	key_type;
		typedef T																	mapped_type;
		typedef Pair</*const*/ Key, T>												value_type;
		typedef size_t																size_type;
		typedef Compare																key_compare;
		typedef Allocator															allocator_type;
		typedef value_type&															reference;
		typedef const value_type&													const_reference;
		typedef value_type*															pointer;
		typedef const value_type*													const_pointer;
		typedef IteratorRedBlackMap<Key, T, Compare, Node_or_leaf_map>     			IteratorMap;
		typedef ConstIteratorRedBlackMap<Key, T, Compare, Node_or_leaf_map>			ConstIteratorMap;
		typedef ReversIteratorRedBlackMap<Key, T, Compare, Node_or_leaf_map> 		ReversIteratorMap;
		typedef ConstReversIteratorRedBlackMap<Key, T, Compare, Node_or_leaf_map>	ConstReversIteratorMap;
		typedef typename  Allocator::template rebind<Node_or_leaf_map>::other		Node_allocator;
	private:
		Allocator _alloc;
	 	Compare _comp;
		size_t _size_struct;
		size_t _size_alloc;
		Node_or_leaf_map* Node;
		Node_or_leaf_map* TNULL;
		Node_allocator _alloc_node;
		class ExceptionReserve : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("1");
				}
		};
		class ExceptionAt : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("2");
				}
		};
		class ExceptionPushBack :public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("3");
				}
		};
	public:
		RedBlackmap(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) //работает
		{
			_size_struct = 0;
			_size_alloc = 0;
			_alloc = alloc;
			_comp = comp;
			Node = NULL;
		}

		//  RedBlackTree() {
		//     TNULL = new Node;
		//     TNULL->color = 0;
		//     TNULL->left = nullptr;
		//     TNULL->right = nullptr;
		//     root = TNULL;
		//   }
		
			// RedBlackmap(RedBlackmap& other )
			// {
			// 	_alloc = other._alloc;
			// 	_comp = other._comp;
			// 	// _size_struct = other._size_struct;
			// 	// _size_alloc = other._size_alloc;
			// 	_alloc_node = other._alloc_node;

			// 	iterator begin = other.begin();
			// 	iterator end = other.end();
			// 	while (begin != end)
			// 	{
			// 		insert(*begin);
			// 		begin++;
			// 	}
			// 	insert(*begin);
			// }

		// template< class InputIt >
		// RedBlackmap( InputIt first, InputIt last,const Compare& comp = Compare(), const Allocator& alloc = Allocator(), typename enable_if<!is_integral<InputIt>::value >::type* = 0) //провепить
		// {
		// 	_alloc = alloc;;
		// 	_comp = comp;
		// 	_size_struct = 0;;
		// 	_size_alloc = 0;;
		// 	Node = NULL;
		// 	while(first != last)
		// 	{
		// 		insert(*first);
		// 		first++;
		// 	}
		// 	insert(*first);
		// }

		

		// Map& operator=(Map& other) //работает
		// RedBlackmap& operator=(RedBlackmap& other) //работает
		// {
		// 	_alloc = other._alloc;
		// 	_comp = other._comp;
		// 	// _size_struct = other._size_struct;
		// 	// _size_alloc = other._size_alloc;
		// 	_alloc_node = other._alloc_node;

		// 	iterator begin = other.begin();
		// 	iterator end = other.end();
		// 	while (begin != end)
		// 	{
		// 		insert(*begin);
		// 		begin++;
		// 	}
		// 	insert(*begin);
		// }

		~RedBlackmap()
		{
			// clear();
		}

		// Allocator get_allocator() const //работает
		// {
		// 	return (_alloc);
		// }

			// T& at(const Key& key) //работает
			// {
			// 	try
			// 	{
			// 		Node_or_leaf_map* tmp1;
			// 		Node_or_leaf_map* tmp2;

			// 		tmp1 = Node;
			// 		if (Node == NULL)
			// 		{
			// 			throw map::ExceptionAt();
			// 		}
			// 		else
			// 		{
			// 			while (tmp1 != NULL)
			// 			{
			// 				tmp2 = tmp1;
			// 				if (_comp(tmp2->value.first, key) == 1)
			// 					tmp1 = tmp2->left;
			// 				else
			// 				{
			// 					if (_comp(tmp2->value.first, key) == 0)
			// 						return (tmp2->value.second);
			// 					tmp1 = tmp2->right;
			// 				}
			// 			}
			// 			throw map::ExceptionAt();
			// 		}
			// 	}
			// 	catch(std::exception &e)
			// 	{
			// 		throw;
			// 	}
			// }

			// T& operator[](Key key) //работает
			// {
			// 	Node_or_leaf_map* tmp1;
			// 	Node_or_leaf_map* tmp2;
			// 	Node_allocator a;
			// 	Pair<Key, T> value(key, static_cast<T>(0));
				
			// 	tmp1 = Node;
			// 	if (Node == NULL)
			// 	{
			// 		Node = (Node_or_leaf_map*)a.allocate(1);
			// 		a.construct(Node, value);
			// 		Node->left = 0;
			// 		Node->right = 0;
			// 		Node->root = 0;
			// 		Node->collor = 0;
			// 		_size_struct++;
			// 		return(Node->value.second);
			// 	}
			// 	else
			// 	{
			// 		while (tmp1 != NULL)
			// 		{
			// 			tmp2 = tmp1;
			// 			if (_comp(tmp2->value.first, key) == 1)
			// 				tmp1 = tmp2->left;
			// 			else
			// 			{
			// 				if (_comp(tmp2->value.first, key) == 0)
			// 					return (tmp2->value.second);
			// 				tmp1 = tmp2->right;
			// 			}
			// 		}
			// 		Node_or_leaf_map* tmp3;
			// 		tmp3 = (Node_or_leaf_map*)a.allocate(1);
			// 		a.construct(tmp3, value);
			// 		tmp3->root = tmp2;
			// 		tmp3->left = NULL;
			// 		tmp3->right = NULL;
			// 		tmp3->collor = 0; //while brown
			// 		if (_comp(tmp2->value.first, key) == 1)
			// 			tmp2->left = tmp3;
			// 		else
			// 			tmp2->right = tmp3;
			// 		_size_struct++;
			// 		return (tmp3->value.second);
			// 	}
			// }

		// IteratorMap begin() //работает
		// {
		// 	return (IteratorRedBlackMap(searchMinNode(Node), Node, _comp));	
		// }

		// ConstIteratorMap begin() const
		// {
		// 	return (ConstIteratorRedBlackMap(searchMinNode(Node), Node, _comp));
		// }

		// IteratorMap end() //работает
		// {
		// 	return (IteratorRedBlackMap(searchMaxNode(Node), Node, _comp));
		// }

		// ConstIteratorMap end() const
		// {
		// 	return (ConstIteratorRedBlackMap(searchMaxNode(Node), Node, _comp));	
		// }

		// ReversIteratorMap rbegin() //работает
		// {
		// 	return (ReversIteratorRedBlackMap(searchMaxNode(Node), Node, _comp));
		// }
		
		// ConstReversIteratorMap rbegin() const
		// {
		// 	return (ConstReversIteratorRedBlackMap(searchMaxNode(Node), Node, _comp));
		// }

		// ReversIteratorMap rend() //работает
		// {
		// 	return (ReversIteratorRedBlackMap(searchMinNode(Node), Node, _comp));
		// }

		// ConstReversIteratorMap rend() const
		// {
		// 	return (ConstReversIteratorRedBlackMap(searchMinNode(Node, Node, _comp)));
		// }

		bool empty() const //работает
		{
			if (_size_struct == 0)
				return (true);
			else
				return (false);
		}

		size_t size() const //работает
		{
			return (_size_struct);
		}

		size_t max_size() const //работает
		{
			size_t max_size;
			max_size = (pow(2, 64)) / ((sizeof(Key) - 1) + (sizeof(T) - 1) + (sizeof(Node_or_leaf_map)));
			return (max_size);
		}

		// void clear() //работает
		// {
		// 	IteratorMap it1 = begin();
		// 	IteratorMap it2 = end();

		// 	while (it1 != it2)
		// 	{
		// 		erase(it1);	
		// 		it1++;
		// 	}
		// }

		// Pair<IteratorMap, bool> insert(const Pair</*const*/ Key, T>& value) //работает
		// {

		// }
		//   void insert(int key) { //переписать создание нода
		//     NodePtr node = new Node;
		//     node->parent = nullptr;
		//     node->data = key;
		//     node->left = TNULL;
		//     node->right = TNULL;
		//     node->color = 1;

		//     NodePtr y = nullptr;
		//     NodePtr x = this->root;

		//     while (x != TNULL) {
		//       y = x;
		//       if (node->data < x->data) {
		//         x = x->left;
		//       } else {
		//         x = x->right;
		//       }
		//     }

		//     node->parent = y;
		//     if (y == nullptr) {
		//       root = node;
		//     } else if (node->data < y->data) {
		//       y->left = node;
		//     } else {
		//       y->right = node;
		//     }

		//     if (node->parent == nullptr) {
		//       node->color = 0;
		//       return;
		//     }

		//     if (node->parent->parent == nullptr) {
		//       return;
		//     }

		//     insertFix(node);
		//   }


		// template<class InputIt>
		// void insert(InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value >::type* = 0)
		// {
		// 	while (first != last)
		// 	{
		// 		insert(first.get_node()->value);
		// 		first++;
		// 	}
		// 	insert(first.get_node()->value);
		// }

		// IteratorMap insert(IteratorMap hint, const Pair</*const*/ Key, T>& value)
		// {
		// 	insert(value);
		// }

		// void erase(IteratorMap pos) //работает
		// {
		// 	deleteNodeHelper(Node, pos.get_node()->value.first);
		// }
		// void deleteNode(int data)
		// {
		// 	deleteNodeHelper(this->root, data);
		// }


		// void erase( IteratorMap first, IteratorMap last ) //работает
		// {
		// 	while (first != last)
		// 	{
		// 		erase(first);
		// 		first++;
		// 	}
		// 	erase(first);
		// }
		
		void swap(RedBlackmap& other) //работает
		{
			swap(Node, other.Node);
			swap(_size_struct, other._size_struct);
			swap(_size_alloc, other._size_alloc);
			swap(_comp, other._comp);
			swap(_alloc_node, other._alloc_node);
			swap(_alloc, other._alloc);
        }

		// size_t count( const Key& key ) const //работает
		// {
		// 	Node_or_leaf_map* search_node = (searchTreeHelper Node, key);
		// 	if (search_node == NULL)
		// 		return (0);
		// 	return (1);
		// }

		// IteratorMap find(const Key& key) //работает
		// {
		// 	Node_or_leaf_map* search_node = (searchTreeHelper Node, key);
		// 	IteratorMap it2(search_node, search_node, _comp);
		// 	return (it2);
		// }	
		// NodePtr searchTree(int k)
		// {
		// return searchTreeHelper(this->root, k);
		// }

		// ConstIteratorMap find( const Key& key ) const
		// {
		// 	Node_or_leaf_map* search_node = (searchTreeHelper Node, key);
		// 	ConstIteratorMap it2(search_node, search_node, _comp);
		// 	return (it2);
		// }
		// NodePtr searchTree(int k)
		// {
		// return searchTreeHelper(this->root, k);
		// }

			// Pair<const_iterator, const_iterator> equal_range( const Key& key ) const
			// {
			// 	Node_or_leaf_map* tmp1;
			// 	Node_or_leaf_map* tmp2;
			// 	Pair<const_iterator, const_iterator> combo;

			// 	tmp1 = Node;
			// 	if (tmp1 == NULL)
			// 		return (combo);
			// 	else
			// 	{
			// 		while (tmp1 != NULL)
			// 		{
			// 			tmp2 = tmp1;
			// 			if (_comp(tmp2->value.first, key) == 1)
			// 				tmp1 = tmp2->left;
			// 			else
			// 			{
			// 				if (_comp(tmp2->value.first, key) == 0)
			// 				{
			// 					const_iterator iterator1(tmp2, tmp2, _comp);
			// 					iterator1++;
			// 					combo.first = iterator1;
			// 					const_iterator iterator2(tmp2, tmp2, _comp);
			// 					iterator2--;
			// 					combo.second = iterator2;
			// 					return (combo); 
			// 				}
			// 				tmp1 = tmp2->right;
			// 			}
			// 		}
			// 	}
			// 	return (combo);
			// }

			// iterator lower_bound(const Key& key) //работает
			// {
			// 	Node_or_leaf_map* tmp1;
			// 	Node_or_leaf_map* tmp2;
				
			// 	tmp1 = Node;
			// 	if (tmp1 == NULL)
			// 		return (NULL);
			// 	else
			// 	{
			// 		while (tmp1 != NULL)
			// 		{
			// 			tmp2 = tmp1;
			// 			if (_comp(tmp2->value.first, key) == 1)
			// 				tmp1 = tmp2->left;
			// 			else
			// 			{
			// 				if (_comp(tmp2->value.first, key) == 0)
			// 				{
			// 					iterator iterator(tmp2, tmp2, _comp);
			// 					return (iterator);
			// 				}
			// 				if (_comp(tmp2->value.first, key) == -1)
			// 				{
			// 					iterator iterator(tmp2, tmp2, _comp);
			// 					return (iterator);
			// 				}
			// 			}
			// 		}
			// 	}
			// 	iterator iterator = begin();
			// 	return (iterator);
			// }

			// const_iterator lower_bound( const Key& key ) const
			// {
			// 	Node_or_leaf_map* tmp1;
			// 	Node_or_leaf_map* tmp2;
				
			// 	tmp1 = Node;
			// 	if (tmp1 == NULL)
			// 		return (NULL);
			// 	else
			// 	{
			// 		while (tmp1 != NULL)
			// 		{
			// 			tmp2 = tmp1;
			// 			if (_comp(tmp2->value.first, key) == 1)
			// 				tmp1 = tmp2->left;
			// 			else
			// 			{
			// 				if (_comp(tmp2->value.first, key) == 0)
			// 				{
			// 					const_iterator iterator(tmp2, tmp2, _comp);
			// 					return (iterator);
			// 				}
			// 				if (_comp(tmp2->value.first, key) == -1)
			// 				{
			// 					const_iterator iterator(tmp2, tmp2, _comp);
			// 					return (iterator);
			// 				}
			// 			}
			// 		}
			// 	}
			// 	const_iterator iterator = begin();
			// 	return (iterator);
			// }

			// iterator upper_bound(const Key& key) //работает
			// {
			// 	Node_or_leaf_map* tmp1;
			// 	Node_or_leaf_map* tmp2;
				
			// 	tmp1 = Node;
			// 	if (tmp1 == NULL)
			// 		return (NULL);
			// 	else
			// 	{
			// 		while (tmp1 != NULL)
			// 		{
			// 			tmp2 = tmp1;
			// 			if (_comp(tmp2->value.first, key) == -1)
			// 				tmp1 = tmp2->right;
			// 			else
			// 			{
			// 				if (_comp(tmp2->value.first, key) == 0)
			// 				{
			// 					iterator iterator(tmp2, tmp2, _comp);
			// 					return (iterator);
			// 				}
			// 				if (_comp(tmp2->value.first, key) == 1)
			// 				{
			// 					iterator iterator(tmp2, tmp2, _comp);
			// 					return (iterator);
			// 				}
			// 			}
			// 		}
			// 	}
			// 	iterator iterator = end();
			// 	return (iterator);
			// }

			// const_iterator upper_bound( const Key& key ) const
			// {
			// 	Node_or_leaf_map* tmp1;
			// 	Node_or_leaf_map* tmp2;
				
			// 	tmp1 = Node;
			// 	if (tmp1 == NULL)
			// 		return (NULL);
			// 	else
			// 	{
			// 		while (tmp1 != NULL)
			// 		{
			// 			tmp2 = tmp1;
			// 			if (_comp(tmp2->value.first, key) == -1)
			// 				tmp1 = tmp2->right;
			// 			else
			// 			{
			// 				if (_comp(tmp2->value.first, key) == 0)
			// 				{
			// 					const_iterator iterator(tmp2, tmp2, _comp);
			// 					return (iterator);
			// 				}
			// 				if (_comp(tmp2->value.first, key) == 1)
			// 				{
			// 					const_iterator iterator(tmp2, tmp2, _comp);
			// 					return (iterator);
			// 				}
			// 			}
			// 		}
			// 	}
			// 	const_iterator iterator = end();
			// 	return (iterator);
			// }

			// Compare key_comp() const //работает
			// {
			// 	return (_comp);
			// }
			
			// value_compare value_comp() const //работает
			// {
			// 	return (value_compare(_comp));
			// }
			// friend bool operator==(const map& lhs, const map& rhs) //segmentation fault // работает 
			// {
			// 	// (void)lhs;
			// 	// (void)rhs;
			// 	const_iterator lhsiter = lhs.begin();
			// 	const_iterator rhsiter = rhs.begin();
			// 	size_t i = 0;

			// 	if (lhs._size_struct != rhs._size_struct)
			// 		return (false);
			// 	while (i < lhs._size_struct)
			// 	{
			// 		if ((lhsiter.get_node())->value.first != (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second != (rhsiter.get_node())->value.second)
			// 			return (false);
			// 		lhsiter++;
			// 		rhsiter++;
			// 	}
			// 	return (true);
			// 	// Node_or_leaf_map* lastElemlhs = NULL;
			// 	// Node_or_leaf_map* lastElemrhs = NULL;
				
			// 	// if (lhs->_size_struct != rhs->_size_struct)
			// 	// 	return (false);
			// 	// while(lhs->Node != NULL || rhs->Node != NULL)
			// 	// {
			// 	// 	if (lastElemlhs == lhs->Node->root && lastElemrhs == rhs->Node->root)
			// 	// 	{
			// 	// 		if (lhs->Node->left != NULL && rhs->Node->left != NULL)
			// 	// 		{
			// 	// 			lastElemlhs = lhs->Node;
			// 	// 			lhs->Node = lhs->Node->Left;
			// 	// 			lastElemrhs = rhs->Node;
			// 	// 			rhs->Node = rhs->Node->left;
			// 	// 			continue;
			// 	// 		}
			// 	// 		else
			// 	// 		{
			// 	// 			lastElemlhs = NULL;
			// 	// 			lastElemrhs = NULL;
			// 	// 		}
			// 	// 	}
			// 	// 	if (lastElemlhs == lhs->Node->left && lastElemrhs == rhs->Node->left)
			// 	// 	{
			// 	// 		if (lhs->Node->value->first != rhs->Node->value->first || lhs->Node->value->second != rhs->Node->value->second)
			// 	// 			return (false);
			// 	// 		if (lhs->Node->right != NULL && rhs->Node->right != NULL)
			// 	// 		{
			// 	// 			lastElemlhs = lhs->Node;
			// 	// 			lhs->Node = lhs->Node->right;
			// 	// 			lastElemrhs = rhs->Node;
			// 	// 			rhs->Node = rhs->Node->right;
			// 	// 			continue;
			// 	// 		}
			// 	// 		else
			// 	// 		{
			// 	// 			lastElemlhs = NULL;
			// 	// 			lastElemrhs = NULL;
			// 	// 		}
			// 	// 	}
			// 	// 	if (lastElemlhs == lhs->Node->Right && lastElemrhs == rhs->Node->Right)
			// 	// 	{
			// 	// 		lastElemlhs = lhs->Node;
			// 	// 		lhs->Node = lhs->Node.root;
			// 	// 		lastElemrhs = rhs->Node;
			// 	// 		rhs->Node = rhs->Node->right;
			// 	// 	}
			// 	// }
			// 	// if (lhs->Node != NULL || rhs->Node != NULL)
			// 	// {
			// 	// 	return (false);
			// 	// }
			// 	// return (true);
			// }
			
			// friend bool operator!=(const map& lhs, const map& rhs)  //работает
			// {
			// 	// (void)lhs;
			// 	// (void)rhs;
			// 	const_iterator lhsiter = lhs.begin();
			// 	const_iterator rhsiter = rhs.begin();
			// 	size_t i = 0;

			// 	if (lhs._size_struct != rhs._size_struct)
			// 		return (true);
			// 	while (i < lhs._size_struct)
			// 	{
			// 		if ((lhsiter.get_node())->value.first != (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second != (rhsiter.get_node())->value.second)
			// 			return (true);
			// 		lhsiter++;
			// 		rhsiter++;
			// 	}
			// 	return (false);
			// 	// Node_or_leaf_map* lastElemlhs = NULL;
			// 	// Node_or_leaf_map* lastElemrhs = NULL;
				
			// 	// if (lhs->_size_struct != rhs->_size_struct)
			// 	// 	return (true);
			// 	// while(lhs->Node != NULL || rhs->Node != NULL)
			// 	// {
			// 	// 	if (lastElemlhs == lhs->Node->root && lastElemrhs == rhs->Node->root)
			// 	// 	{
			// 	// 		if (lhs->Node->left != NULL && rhs->Node->left != NULL)
			// 	// 		{
			// 	// 			lastElemlhs = lhs->Node;
			// 	// 			lhs->Node = lhs->Node->Left;
			// 	// 			lastElemrhs = rhs->Node;
			// 	// 			rhs->Node = rhs->Node->left;
			// 	// 			continue;
			// 	// 		}
			// 	// 		else
			// 	// 		{
			// 	// 			lastElemlhs = NULL;
			// 	// 			lastElemrhs = NULL;
			// 	// 		}
			// 	// 	}
			// 	// 	if (lastElemlhs == lhs->Node->left && lastElemrhs == rhs->Node->left)
			// 	// 	{
			// 	// 		if (lhs->Node->value->first != rhs->Node->value->first || lhs->Node->value->second != rhs->Node->value->second)
			// 	// 			return (true);
			// 	// 		if (lhs->Node->right != NULL && rhs->Node->right != NULL)
			// 	// 		{
			// 	// 			lastElemlhs = lhs->Node;
			// 	// 			lhs->Node = lhs->Node->right;
			// 	// 			lastElemrhs = rhs->Node;
			// 	// 			rhs->Node = rhs->Node->right;
			// 	// 			continue;
			// 	// 		}
			// 	// 		else
			// 	// 		{
			// 	// 			lastElemlhs = NULL;
			// 	// 			lastElemrhs = NULL;
			// 	// 		}
			// 	// 	}
			// 	// 	if (lastElemlhs == lhs->Node->Right && lastElemrhs == rhs->Node->Right)
			// 	// 	{
			// 	// 		lastElemlhs = lhs->Node;
			// 	// 		lhs->Node = lhs->Node.root;
			// 	// 		lastElemrhs = rhs->Node;
			// 	// 		rhs->Node = rhs->Node->right;
			// 	// 	}
			// 	// }
			// 	// if (lhs->Node != NULL || rhs->Node != NULL)
			// 	// {
			// 	// 	return (true);
			// 	// }
			// 	// return (false);
			// }

			// friend bool operator<(const map& lhs, const map& rhs)  //работает
			// {
			// 	// (void)lhs;
			// 	// (void)rhs;
			// 	const_iterator lhsiter = lhs.begin();
			// 	const_iterator rhsiter = rhs.begin();
			// 	size_t i = 0;

			// 	if (lhs._size_struct > rhs._size_struct)
			// 		return (false);
			// 	while (i < lhs._size_struct)
			// 	{
			// 		if ((lhsiter.get_node())->value.first >= (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second >= (rhsiter.get_node())->value.second)
			// 			return (false);
			// 		lhsiter++;
			// 		rhsiter++;
			// 		i++;
			// 	}
			// 	return (true);
			// }

			
			// friend bool operator<=(const map& lhs, const map& rhs) //работает
			// {
			// 	(void)lhs;
			// 	(void)rhs;
			// 	const_iterator lhsiter = lhs.begin();
			// 	const_iterator rhsiter = rhs.begin();
			// 	size_t i = 0;

			// 	if (lhs._size_struct > rhs._size_struct)
			// 		return (false);
			// 		while (i < lhs._size_struct)
			// 	{
			// 		if ((lhsiter.get_node())->value.first > (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second > (rhsiter.get_node())->value.second)
			// 			return (false);
			// 		lhsiter++;
			// 		rhsiter++;
			// 		i++;
			// 	}
			// 	return (true);
			// }

			// friend bool operator>(const map& lhs, const map& rhs) //работает
			// {
			// 	// (void)lhs;
			// 	// (void)rhs;
			// 	const_iterator lhsiter = lhs.begin();
			// 	const_iterator rhsiter = rhs.begin();
			// 	size_t i = 0;

			// 	if (lhs._size_struct < rhs._size_struct)
			// 		return (false);
			// 	while(i < lhs._size_struct)
			// 	{
			// 		if ((lhsiter.get_node())->value.first <= (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second <= (rhsiter.get_node())->value.second)
			// 			return (false);
			// 		lhsiter++;
			// 		rhsiter++;
			// 		i++;
			// 	}
			// 	return (true);
			// }

			// friend bool operator>=(const map& lhs, const map& rhs) //работает
			// {
			// 	// (void)lhs;
			// 	// (void)rhs;
			// 	const_iterator lhsiter = lhs.begin();
			// 	const_iterator rhsiter = rhs.begin();
			// 	size_t i = 0;

			// 	if (lhs._size_struct < rhs._size_struct)
			// 		return (false);
			// 	while(i < lhs._size_struct)
			// 	{
			// 		if ((lhsiter.get_node())->value.first < (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second < (rhsiter.get_node())->value.second)
			// 			return (false);
			// 		lhsiter++;
			// 		rhsiter++;
			// 		i++;
			// 	}
			// 	return (true);
			// }

	private:
		template <typename U>
		void swap(U& a, U& b)
		{
			U tmp = a;
			a = b;
			b = tmp;
		}

		Node_or_leaf_map* searchMaxNode(Node_or_leaf_map *node) const
		{
			if (node && node->right)
				searchMaxNode(node->right);
			return (node);
		}

		Node_or_leaf_map* searchMinNode(Node_or_leaf_map *node) const
		{
			if (node && node->left)
				searchMinNode(node->left);
			return (node);
		}
		
		template<class InputIt1, class InputIt2>
		bool lexicographical_compare (InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
		{
			for (; (first1 != last1) && (first2 != last2); ++first1, ++last1)
			{
				if (*first1 < *first2) return true;
				if (*first2 < *first1) return false;
			}
			return (first1 == last1) && (first2 != last2);	
		}

		// Preorder
		void preOrderHelper(Node_or_leaf_map* node)
		{
			if (node != TNULL)
			{
				std::cout << node->data << " ";
				preOrderHelper(node->left);
				preOrderHelper(node->right);
			}
		}

		// Inorder
		void inOrderHelper(Node_or_leaf_map* node)
		{
			if (node != TNULL)
			{
				inOrderHelper(node->left);
				std::cout << node->data << " ";
				inOrderHelper(node->right);
			}
		}

		// Post order
		void postOrderHelper(Node_or_leaf_map* node)
		{
			if (node != TNULL)
			{
				postOrderHelper(node->left);
				postOrderHelper(node->right);
				std::cout << node->data << " ";
			}
		}

		// For balancing the tree after deletion
		void deleteFix(Node_or_leaf_map* x)
		{
			Node_or_leaf_map* s;
			while (x != Node && x->color == 0)
			{
				if (x == x->root->left)
				{
					s = x->root->right;
					if (s->color == 1)
					{
						s->color = 0;
						x->root->color = 1;
						leftRotate(x->root);
						s = x->root->right;
					}
					if (s->left->color == 0 && s->right->color == 0)
					{
						s->color = 1;
						x = x->root;
					}
					else
					{
						if (s->right->color == 0)
						{
							s->left->color = 0;
							s->color = 1;
							rightRotate(s);
							s = x->root->right;
						}
						s->color = x->root->color;
						x->root->color = 0;
						s->right->color = 0;
						leftRotate(x->root);
						x = Node;
					}
				}
				else
				{
					s = x->root->left;
					if (s->color == 1)
					{
						s->color = 0;
						x->root->color = 1;
						rightRotate(x->root);
						s = x->root->left;
					}
					if (s->right->color == 0 && s->right->color == 0)
					{
						s->color = 1;
						x = x->root;
					}
					else
					{
						if (s->left->color == 0)
						{
							s->right->color = 0;
							s->color = 1;
							leftRotate(s);
							s = x->root->left;
						}
						s->color = x->root->color;
						x->root->color = 0;
						s->left->color = 0;
						rightRotate(x->root);
						x = Node;
					}
				}
			}
			x->color = 0;
		}

		void leftRotate(Node_or_leaf_map* x)
		{
			Node_or_leaf_map* y = x->right;
			x->right = y->left;
			if (y->left != TNULL)
			{
				y->left->root = x;
			}
			y->root = x->root;
			if (x->root == nullptr)
			{
				this->root = y;
			} 
			else if (x == x->root->left) 
			{
				x->root->left = y;
			}
			else
			{
				x->root->right = y;
			}
			y->left = x;
			x->root = y;
		}

		void rightRotate(Node_or_leaf_map* x)
		{
			Node_or_leaf_map* y = x->left;
			x->left = y->right;
			if (y->right != TNULL)
			{
				y->right->root = x;
			}
			y->root = x->root;
			if (x->root == nullptr)
			{
				this->root = y;
			}
			else if (x == x->root->right)
			{
				x->root->right = y;
			}
			else
			{
				x->root->left = y;
			}
			y->right = x;
			x->root = y;
		}
	
		void insertFix(Node_or_leaf_map* k)
		{
			Node_or_leaf_map* u;
			while (k->root->color == 1)
			{
				if (k->root == k->root->root->right)
				{
					u = k->root->root->left;
					if (u->color == 1)
					{
						u->color = 0;
						k->root->color = 0;
						k->root->root->color = 1;
						k = k->root->root;
					}
					else
					{
						if (k == k->root->left)
						{
							k = k->root;
							rightRotate(k);
						}
						k->root->color = 0;
						k->root->root->color = 1;
						leftRotate(k->root->root);
					}
				}
				else
				{
					u = k->root->root->right;
					if (u->color == 1)
					{
						u->color = 0;
						k->root->color = 0;
						k->root->root->color = 1;
						k = k->root->root;
					}
					else
					{
						if (k == k->root->right)
						{
							k = k->root;
							leftRotate(k);
						}
						k->root->color = 0;
						k->root->root->color = 1;
						rightRotate(k->root->root);
					}
				}
				if (k == Node)
				{
					break;
				}
			}
			Node->color = 0;
		}

		void rbTransplant(Node_or_leaf_map* u, Node_or_leaf_map* v)
		{
			if (u->root == NULL)
			{
				Node = v;
    		}
			else if (u == u->root->left)
			{
				u->root->left = v;
    		}
			else
			{
				u->root->right = v;
    		}
    		v->root = u->root;
		}
		
		void initializeNULLNode(Node_or_leaf_map* node, Node_or_leaf_map* parent)
		{
			node->data = 0;
			node->root = parent;
			node->left = nullptr;
			node->right = nullptr;
			node->color = 0;
		}

		Node_or_leaf_map* searchTreeHelper(Node_or_leaf_map* node, int key)
		{
			if (node == TNULL || key == node->data)
			{
				return node;
			}
			if (key < node->data)
			{
				return searchTreeHelper(node->left, key);
			}
			return searchTreeHelper(node->right, key);
		}

		void deleteNodeHelper(Node_or_leaf_map* node, int key)
		{
			// try
			// {}
			// catch(exception &e)
			// {
			
			// }
			Node_or_leaf_map* z = TNULL;
			Node_or_leaf_map* x, y;
			while (node != TNULL)
			{
				if (node->data == key)
				{
					z = node;
				}
				if (node->data <= key)
				{
					node = node->right;
				}
				else
				{
					node = node->left;
				}
			}
			if (z == TNULL) 
			{
				std::cout << "Key not found in the tree" << std::endl;
				return;
			}
			y = z;
			int y_original_color = y->color;
			if (z->left == TNULL)
			{
				x = z->right;
				rbTransplant(z, z->right);
			}
			else if (z->right == TNULL)
			{
				x = z->left;
				rbTransplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z) 
				{
					x->parent = y;
				}
				else
				{
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			delete z;
			if (y_original_color == 0)
			{
				deleteFix(x);
			}
		}

		//   void printHelper(NodePtr root, string indent, bool last) {
		//     if (root != TNULL) {
		//       cout << indent;
		//       if (last) {
		//         cout << "R----";
		//         indent += "   ";
		//       } else {
		//         cout << "L----";
		//         indent += "|  ";
		//       }

		//       string sColor = root->color ? "RED" : "BLACK";
		//       cout << root->data << "(" << sColor << ")" << endl;
		//       printHelper(root->left, indent, false);
		//       printHelper(root->right, indent, true);
		//     }
		//   }
};
#endif



// #include <iostream>
// using namespace std;

// struct Node {
//   int data;
//   Node *parent;
//   Node *left;
//   Node *right;
//   int color;
// };

// typedef Node *NodePtr;

// class RedBlackTree {
//    private:
//   NodePtr root;
//   NodePtr TNULL;



//    public:
//   RedBlackTree() {
//     TNULL = new Node;
//     TNULL->color = 0;
//     TNULL->left = nullptr;
//     TNULL->right = nullptr;
//     root = TNULL;
//   }

//   void preorder() {
//     preOrderHelper(this->root);
//   }

//   void inorder() {
//     inOrderHelper(this->root);
//   }

//   void postorder() {
//     postOrderHelper(this->root);
//   }

//   NodePtr minimum(NodePtr node) {
//     while (node->left != TNULL) {
//       node = node->left;
//     }
//     return node;
//   }

//   NodePtr maximum(NodePtr node) {
//     while (node->right != TNULL) {
//       node = node->right;
//     }
//     return node;
//   }

//   NodePtr successor(NodePtr x) {
//     if (x->right != TNULL) {
//       return minimum(x->right);
//     }

//     NodePtr y = x->parent;
//     while (y != TNULL && x == y->right) {
//       x = y;
//       y = y->parent;
//     }
//     return y;
//   }

//   NodePtr predecessor(NodePtr x) {
//     if (x->left != TNULL) {
//       return maximum(x->left);
//     }

//     NodePtr y = x->parent;
//     while (y != TNULL && x == y->left) {
//       x = y;
//       y = y->parent;
//     }

//     return y;
//   }

//   NodePtr getRoot() {
//     return this->root;
//   }

// };

// int main() {
//   RedBlackTree bst;
//   bst.insert(55);
//   bst.insert(40);
//   bst.insert(65);
//   bst.insert(60);
//   bst.insert(75);
//   bst.insert(57);

//   bst.printTree();
//   cout << endl
//      << "After deleting" << endl;
//   bst.deleteNode(40);
//   bst.printTree();
// }