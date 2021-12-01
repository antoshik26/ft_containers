#ifndef REDBLACKMAP_HPP
#define REDBLACKMAP_HPP
#include <memory>
#include <iostream>
#include <string>
#include <cmath>
#include "../Map/map.hpp"
#include "../Map/Less.hpp"
#include "../Map/Pair.hpp"
#include "IteratorRedBlackMap.hpp"
#include "ReversIteratorRedBlackMap.hpp"

namespace ft
{
	template<
		class Key,
		class T,
		class Compare = less<Key>, 
		class Allocator = std::allocator<std::pair<Key, T> >
	>
	class RedBlackmap
	{
		public:
			struct Node 
			{
				Pair</*const*/ Key, T> data;
				Node *parent;
				Node *left;
				Node *right;
				int color;
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
			typedef IteratorRedBlackMap<Key, T, Compare, Node>     						iterator;
			typedef ConstIteratorRedBlackMap<Key, T, Compare, Node>						const_iterator;
			typedef ReversIteratorRedBlackMap<Key, T, Compare, Node> 					reverse_iterator;
			typedef ConstReversIteratorRedBlackMap<Key, T, Compare, Node>				const_reverse_iterator;
			typedef typename  Allocator::template rebind<Node>::other					Node_allocator;
			typedef Node *NodePtr;
		private:
			Allocator _alloc;
			Compare _comp;
			size_t _size_struct;
			size_t _size_alloc;
			NodePtr root;
  			NodePtr TNULL;
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
			class value_compare
			{
				friend class RedBlackmap;

				protected:
					Compare _comp;
					value_compare(Compare comp)
					{
						_comp = comp;
					}
				public:
					bool operator()(const Pair</*const*/ Key, T>& x, const Pair</*const*/ Key, T>& y) const
                    {
                        return _comp(x.first, y.first);
                    }
			};
		public:
			RedBlackmap(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) //работает
			{
				_size_struct = 0;
				_size_alloc = 0;
				_alloc = alloc;
				_comp = comp;

				TNULL = (Node*)_alloc_node.allocate(1);
				TNULL->color = 0;
				TNULL->left = nullptr;
				TNULL->right = nullptr;
				root = TNULL;
			}

			RedBlackmap(RedBlackmap& other )
			{
				_alloc = other._alloc;
				_comp = other._comp;
				// _size_struct = other._size_struct;
				// _size_alloc = other._size_alloc;
				_alloc_node = other._alloc_node;
				root = other.TNULL;
				TNULL = other.TNULL;

				iterator begin = other.begin();
				iterator end = other.end();
				while (begin != end)
				{
					insert(*begin);
					begin++;
				}
				insert(*begin);
			}

			template< class InputIt >
			RedBlackmap( InputIt first, InputIt last,const Compare& comp = Compare(), const Allocator& alloc = Allocator(), typename enable_if<!is_integral<InputIt>::value >::type* = 0) //работает
			{
				_alloc = alloc;;
				_comp = comp;
				_size_struct = 0;;
				_size_alloc = 0;;
				root = TNULL;
				while(first != last)
				{
					insert(*first);
					first++;
				}
				insert(*first);
			}

			RedBlackmap& operator=(RedBlackmap& other) //работает
			{
				_alloc = other._alloc;
				_comp = other._comp;
				// _size_struct = other._size_struct;
				// _size_alloc = other._size_alloc;
				_alloc_node = other._alloc_node;

				iterator begin = other.begin();
				iterator end = other.end();
				while (begin != end)
				{
					insert(*begin);
					begin++;
				}
				insert(*begin);
				return (*this);
			}

			T& at(const Key& key) //работает
			{
				try
				{
					Node* tmp1;
					Node* tmp2;

					tmp1 = root;
					if (root == TNULL)
					{
						throw RedBlackmap::ExceptionAt();
					}
					else
					{
						while (tmp1 != TNULL)
						{
							tmp2 = tmp1;
							if (_comp(tmp2->value.first, key) == 1)
								tmp1 = tmp2->left;
							else
							{
								if (_comp(tmp2->value.first, key) == 0)
									return (tmp2->value.second);
								tmp1 = tmp2->right;
							}
						}
						throw RedBlackmap::ExceptionAt();
					}
				}
				catch(std::exception &e)
				{
					throw;
				}
			}

			T& operator[](Key key) //работает
			{
				Node* tmp1;
				Node* tmp2;
				Pair<Key, T> value(key, static_cast<T>(0));
				
				tmp1 = root;
				if (root == TNULL)
				{
					root = (Node*)_alloc_node.allocate(1);
					// a.construct(Node, value);
					root->data = value;
					root->left = TNULL;
					root->right = TNULL;
					root->root = root->parent;
					root->color = 0;
					_size_struct++;
					return(root->value.second);
				}
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						if (_comp(tmp2->value.first, key) == 1)
							tmp1 = tmp2->left;
						else
						{
							if (_comp(tmp2->value.first, key) == 0)
								return (tmp2->value.second);
							tmp1 = tmp2->right;
						}
					}
					Node* tmp3;
					tmp3 = (Node*)_alloc_node.allocate(1);
					// a.construct(tmp3, value);
					tmp3->data = value;
					tmp3->parent = tmp2;
					tmp3->left = NULL;
					tmp3->right = NULL;
					tmp3->collor = 0; //while brown
					if (_comp(tmp2->value.first, key) == 1)
						tmp2->left = tmp3;
					else
						tmp2->right = tmp3;
					_size_struct++;
					return (tmp3->value.second);
				}
			}

			~RedBlackmap()
			{
				clear();
				_alloc_node.deallocate(TNULL, 1);
			}

			Allocator get_allocator() const //работает
			{
				return (_alloc);
			}

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
				max_size = (pow(2, 64)) / ((sizeof(Key) - 1) + (sizeof(T) - 1) + (sizeof(Node)));
				return (max_size);
			}

			void clear() //работает
			{
				if (_size_struct != 0)
					erase(begin(), end());
				if (_size_struct == 1)
					erase(begin());
			}

			Pair<iterator, bool> insert(const Pair</*const*/ Key, T>& value) //работает
			{
				Pair<iterator, bool> a; //бурда ебаная
				NodePtr node = _alloc_node.allocate(1);
				node->parent = nullptr;
				node->data = value;
				node->left = TNULL;
				node->right = TNULL;
				node->color = 1;

				NodePtr y = nullptr;
				NodePtr x = this->root;

				while (x != TNULL) 
				{
					y = x;
					if (node->data.first < x->data.first) 
					{
						x = x->left;
					} else 
					{
						x = x->right;
					}
				}

				node->parent = y;
				if (y == nullptr) 
				{
					root = node;
				} 
				else if (node->data.first < y->data.first) 
				{
					y->left = node;
				}
				else 
				{
					y->right = node;
				}

				if (node->parent == nullptr) 
				{
					node->color = 0;
					return (a);
				}

				if (node->parent->parent == nullptr) 
				{
					return (a);
				}
				
				_size_struct++;
				insertFix(node);
				return (a);
			}
			
			template<class InputIt>
			void insert(InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value >::type* = 0) //работает
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
				insert(*first);
			}

			iterator insert(iterator hint, const Pair</*const*/ Key, T>& value) //работает
			{
				(void)hint;
				return (insert(value));
			}

			NodePtr getRoot() 
			{
				return this->root;
			}

			void erase(iterator pos)//Pair<Key, T>data) 
			{
				deleteNodeHelper(this->root, pos->first);
				_size_struct--;
			}

			void erase(iterator first, iterator last) //работает
			{
				while (first != last)
				{
					erase(first);
					++first;
				}
				erase(first);
			}

			void swap(RedBlackmap& other) //работает
			{
				swap(root, other.root);
				swap(_size_struct, other._size_struct);
				swap(_size_alloc, other._size_alloc);
				swap(_comp, other._comp);
				swap(_alloc_node, other._alloc_node);
				swap(_alloc, other._alloc);
				swap(TNULL, other.TNULL);

			}

			iterator begin() //работает
			{
				Node* tmp1;
				Node* tmp2;
				iterator it(TNULL, TNULL, _comp);

				tmp1 = root;
				if (root == TNULL)
				{
					return (it);
				}
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						tmp1 = tmp2->left;
					}
					iterator it2(tmp2, TNULL, _comp);
					return (it2);
				}
			}

			const_iterator begin() const
			{
				Node* tmp1;
				Node* tmp2;
				const_iterator it(TNULL, TNULL, _comp);

				tmp1 = root;
				if (root == TNULL)
				{
					return (it);
				}
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						tmp1 = tmp2->left;
					}
					const_iterator it2(tmp2, TNULL, _comp);
					return (it2);
				}
			}

			iterator end() //работает
			{
				Node* tmp1;
				Node* tmp2;
				iterator it(TNULL, TNULL, _comp);

				tmp1 = root;
				if (root == TNULL)
				{
					return (it);
				}
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						tmp1 = tmp2->right;
					}
					iterator it2(tmp2, TNULL, _comp);
					return (it2);
				}
			}

			const_iterator end() const
			{
				Node* tmp1;
				Node* tmp2;
				const_iterator it = NULL;

				tmp1 = root;
				if (root == TNULL)
				{
					return (it);
				}
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						tmp1 = tmp2->right;
					}
					const_iterator it2(tmp2, TNULL, _comp);
					return (it2);
				}
			}

			reverse_iterator rbegin() //работает
			{
				Node* tmp1;
				Node* tmp2;
				iterator it;

				tmp1 = root;
				if (root == TNULL)
				{
					return (it);
				}
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						tmp1 = tmp2->right;
					}
					iterator it2(tmp2, TNULL, _comp);
					return (it2);
				}
			}

			const_reverse_iterator rbegin() const
			{
				Node* tmp1;
				Node* tmp2;
				const_reverse_iterator it;

				tmp1 = root;
				if (root == TNULL)
				{
					return (it);
				}
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						tmp1 = tmp2->right;
					}
					const_reverse_iterator it2(tmp2, TNULL, _comp);
					return (it2);
				}
			}

			size_t count( const Key& key ) const //работает
			{
				NodePtr newNode = searchTreeHelper(this->root, key);
				if (newNode == TNULL)
					return (0);
				return (1);
			}
			
			iterator searchTree(const Key& key ) 
			{
				NodePtr newNode = searchTreeHelper(this->root, key);
				iterator it(newNode, TNULL, _comp);
				return (it);
			}

			const_iterator searchTree(const Key& key ) const
			{
				NodePtr newNode = searchTreeHelper(this->root, key);
				const_iterator it(newNode, TNULL, _comp);
				return (it);
			}

			Pair<iterator, iterator> equal_range(const Key& key) //доделать
			{
				Node* tmp1;
				Node* tmp2;
				Pair<iterator, iterator> combo;

				tmp1 = root;
				if (tmp1 == TNULL)
					return (combo);
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						if (_comp(tmp2->value.first, key) == 1)
							tmp1 = tmp2->left;
						else
						{
							if (_comp(tmp2->value.first, key) == 0)
							{
								iterator iterator1(tmp2, tmp2, _comp);
								iterator1++;
								combo.first = iterator1;
								iterator iterator2(tmp2, tmp2, _comp);
								iterator2--;
								combo.second = iterator2;
								return (combo); 
							}
							tmp1 = tmp2->right;
						}
					}
				}
				return (combo);
			}

			Pair<const_iterator, const_iterator> equal_range( const Key& key ) const
			{
				Node* tmp1;
				Node* tmp2;
				Pair<const_iterator, const_iterator> combo;

				tmp1 = root;
				if (tmp1 == TNULL)
					return (combo);
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						if (_comp(tmp2->value.first, key) == 1)
							tmp1 = tmp2->left;
						else
						{
							if (_comp(tmp2->value.first, key) == 0)
							{
								const_iterator iterator1(tmp2, tmp2, _comp);
								iterator1++;
								combo.first = iterator1;
								const_iterator iterator2(tmp2, tmp2, _comp);
								iterator2--;
								combo.second = iterator2;
								return (combo); 
							}
							tmp1 = tmp2->right;
						}
					}
				}
				return (combo);
			}

			iterator lower_bound(const Key& key) //работает
			{
				Node* tmp1;
				Node* tmp2;
				
				tmp1 = root;
				if (tmp1 == TNULL)
					return (NULL);
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						if (_comp(tmp2->value.first, key) == 1)
							tmp1 = tmp2->left;
						else
						{
							if (_comp(tmp2->value.first, key) == 0)
							{
								iterator iterator(tmp2, tmp2, _comp);
								return (iterator);
							}
							if (_comp(tmp2->value.first, key) == -1)
							{
								iterator iterator(tmp2, tmp2, _comp);
								return (iterator);
							}
						}
					}
				}
				iterator iterator = begin();
				return (iterator);
			}

			const_iterator lower_bound( const Key& key ) const
			{
				Node* tmp1;
				Node* tmp2;
				
				tmp1 = root;
				if (tmp1 == TNULL)
					return (NULL);
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						if (_comp(tmp2->value.first, key) == 1)
							tmp1 = tmp2->left;
						else
						{
							if (_comp(tmp2->value.first, key) == 0)
							{
								const_iterator iterator(tmp2, tmp2, _comp);
								return (iterator);
							}
							if (_comp(tmp2->value.first, key) == -1)
							{
								const_iterator iterator(tmp2, tmp2, _comp);
								return (iterator);
							}
						}
					}
				}
				const_iterator iterator = begin();
				return (iterator);
			}

			iterator upper_bound(const Key& key) //работает
			{
				Node* tmp1;
				Node* tmp2;
				
				tmp1 = root;
				if (tmp1 == TNULL)
					return (NULL);
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						if (_comp(tmp2->value.first, key) == -1)
							tmp1 = tmp2->right;
						else
						{
							if (_comp(tmp2->value.first, key) == 0)
							{
								iterator iterator(tmp2, TNULL, _comp);
								return (iterator);
							}
							if (_comp(tmp2->value.first, key) == 1)
							{
								iterator iterator(tmp2, TNULL, _comp);
								return (iterator);
							}
						}
					}
				}
				iterator iterator = end();
				return (iterator);
			}

			const_iterator upper_bound( const Key& key ) const
			{
				Node* tmp1;
				Node* tmp2;
				
				tmp1 = root;
				if (tmp1 == TNULL)
					return (NULL);
				else
				{
					while (tmp1 != TNULL)
					{
						tmp2 = tmp1;
						if (_comp(tmp2->value.first, key) == -1)
							tmp1 = tmp2->right;
						else
						{
							if (_comp(tmp2->value.first, key) == 0)
							{
								const_iterator iterator(tmp2, TNULL, _comp);
								return (iterator);
							}
							if (_comp(tmp2->value.first, key) == 1)
							{
								const_iterator iterator(tmp2, TNULL, _comp);
								return (iterator);
							}
						}
					}
				}
				const_iterator iterator = end();
				return (iterator);
			}

			Compare key_comp() const //работает
			{
				return (_comp);
			}
			
			value_compare value_comp() const //работает
			{
				return (value_compare(_comp));
			}

			friend bool operator==(const RedBlackmap& lhs, const RedBlackmap& rhs) // работает 
			{
				const_iterator lhsiter = lhs.begin();
				const_iterator rhsiter = rhs.begin();
				size_t i = 0;

				if (lhs._size_struct != rhs._size_struct)
					return (false);
				while (i < lhs._size_struct)
				{
					if ((lhsiter.get_node())->value.first != (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second != (rhsiter.get_node())->value.second)
						return (false);
					lhsiter++;
					rhsiter++;
				}
				return (true);
			}
	
			friend bool operator!=(const RedBlackmap& lhs, const RedBlackmap& rhs)  //работает
			{
				const_iterator lhsiter = lhs.begin();
				const_iterator rhsiter = rhs.begin();
				size_t i = 0;

				if (lhs._size_struct != rhs._size_struct)
					return (true);
				while (i < lhs._size_struct)
				{
					if ((lhsiter.get_node())->value.first != (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second != (rhsiter.get_node())->value.second)
						return (true);
					lhsiter++;
					rhsiter++;
				}
				return (false);
			}

			friend bool operator<(const RedBlackmap& lhs, const RedBlackmap& rhs)  //работает
			{
				const_iterator lhsiter = lhs.begin();
				const_iterator rhsiter = rhs.begin();
				size_t i = 0;

				if (lhs._size_struct > rhs._size_struct)
					return (false);
				while (i < lhs._size_struct)
				{
					if ((lhsiter.get_node())->value.first >= (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second >= (rhsiter.get_node())->value.second)
						return (false);
					lhsiter++;
					rhsiter++;
					i++;
				}
				return (true);
			}

			
			friend bool operator<=(const RedBlackmap& lhs, const RedBlackmap& rhs) //работает
			{
				const_iterator lhsiter = lhs.begin();
				const_iterator rhsiter = rhs.begin();
				size_t i = 0;

				if (lhs._size_struct > rhs._size_struct)
					return (false);
					while (i < lhs._size_struct)
				{
					if ((lhsiter.get_node())->value.first > (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second > (rhsiter.get_node())->value.second)
						return (false);
					lhsiter++;
					rhsiter++;
					i++;
				}
				return (true);
			}

			friend bool operator>(const RedBlackmap& lhs, const RedBlackmap& rhs) //работает
			{
				const_iterator lhsiter = lhs.begin();
				const_iterator rhsiter = rhs.begin();
				size_t i = 0;

				if (lhs._size_struct < rhs._size_struct)
					return (false);
				while(i < lhs._size_struct)
				{
					if ((lhsiter.get_node())->value.first <= (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second <= (rhsiter.get_node())->value.second)
						return (false);
					lhsiter++;
					rhsiter++;
					i++;
				}
				return (true);
			}

			friend bool operator>=(const RedBlackmap& lhs, const RedBlackmap& rhs) //работает
			{
				const_iterator lhsiter = lhs.begin();
				const_iterator rhsiter = rhs.begin();
				size_t i = 0;

				if (lhs._size_struct < rhs._size_struct)
					return (false);
				while(i < lhs._size_struct)
				{
					if ((lhsiter.get_node())->value.first < (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second < (rhsiter.get_node())->value.second)
						return (false);
					lhsiter++;
					rhsiter++;
					i++;
				}
				return (true);
			}

			void printTree() 
			{
				if (root)
				{
					printHelper(this->root, "", true);
				}
			}

		private:
			template <typename U>
			void swap(U& a, U& b)
			{
				U tmp = a;
				a = b;
				b = tmp;
			}

			void initializeNULLNode(NodePtr node, NodePtr parent)
			{
				node->data = 0;
				node->parent = parent;
				node->left = nullptr;
				node->right = nullptr;
				node->color = 0;
			}

			NodePtr searchTreeHelper(NodePtr node, int key)
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

			void rbTransplant(NodePtr u, NodePtr v) 
			{
				if (u->parent == nullptr) 
				{
					root = v;
				}
				else if (u == u->parent->left)
				{
					u->parent->left = v;
				}
				else 
				{
					u->parent->right = v;
				}
				v->parent = u->parent;
			}

			void deleteNodeHelper(NodePtr node, Key key)
			{
				NodePtr z = TNULL;
				NodePtr x, y;
				while (node != TNULL) 
				{
					if (node->data.first == key) 
					{
						z = node;
					}

					if (node->data.first <= key) 
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

			void printHelper(NodePtr root, std::string indent, bool last)
			{
				if (root != TNULL)
				{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}

				std::string sColor = root->color ? "RED" : "BLACK";
				std::cout << root->data.first << "(" << sColor << ")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
				}
			}

			void leftRotate(NodePtr x) 
			{
				NodePtr y = x->right;
				x->right = y->left;
				if (y->left != TNULL) 
				{
					y->left->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == nullptr) 
				{
					this->root = y;
				} 
				else if (x == x->parent->left) 
				{
					x->parent->left = y;
				}
				else
				{
					x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			}

			void rightRotate(NodePtr x) 
			{
				NodePtr y = x->left;
				x->left = y->right;
				if (y->right != TNULL)
				{
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == nullptr) 
				{
					this->root = y;
				} else if (x == x->parent->right)
				{
					x->parent->right = y;
				} else 
				{
					x->parent->left = y;
				}
				y->right = x;
				x->parent = y;
			}

			// Preorder
			void preOrderHelper(NodePtr node) 
			{
				if (node != TNULL) 
				{
					std::cout << node->data << " ";
					preOrderHelper(node->left);
					preOrderHelper(node->right);
				}
  			}

			// Inorder
			void inOrderHelper(NodePtr node) 
			{
				if (node != TNULL) 
				{
					inOrderHelper(node->left);
					std::cout << node->data << " ";
					inOrderHelper(node->right);
				}
			}

			// Post order
			void postOrderHelper(NodePtr node) 
			{
				if (node != TNULL) 
				{
					postOrderHelper(node->left);
					postOrderHelper(node->right);
					std::cout << node->data << " ";
				}
			}

			// For balancing the tree after deletion
			void deleteFix(NodePtr x)
			{
				NodePtr s;
				while (x != root && x->color == 0)
				{
					if (x == x->parent->left) 
					{
						s = x->parent->right;
						if (s->color == 1) 
						{
							s->color = 0;
							x->parent->color = 1;
							leftRotate(x->parent);
							s = x->parent->right;
						}

						if (s->left->color == 0 && s->right->color == 0) 
						{
							s->color = 1;
							x = x->parent;
						}
						else
						{
							if (s->right->color == 0) 
							{
								s->left->color = 0;
								s->color = 1;
								rightRotate(s);
								s = x->parent->right;
							}

							s->color = x->parent->color;
							x->parent->color = 0;
							s->right->color = 0;
							leftRotate(x->parent);
							x = root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s->color == 1)
						{
							s->color = 0;
							x->parent->color = 1;
							rightRotate(x->parent);
							s = x->parent->left;
						}

						if (s->right->color == 0 && s->right->color == 0)
						{
							s->color = 1;
							x = x->parent;
						}
						else
						{
							if (s->left->color == 0) 
							{
								s->right->color = 0;
								s->color = 1;
								leftRotate(s);
								s = x->parent->left;
							}
							s->color = x->parent->color;
							x->parent->color = 0;
							s->left->color = 0;
							rightRotate(x->parent);
							x = root;
						}
					}
				}
				x->color = 0;
			}

			// For balancing the tree after insertion
			void insertFix(NodePtr k)
			{
				NodePtr u;
				while (k->parent->color == 1)
				{
					if (k->parent == k->parent->parent->right)
					{
						u = k->parent->parent->left;
						if (u->color == 1) 
						{
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->left)
							{
								k = k->parent;
								rightRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							leftRotate(k->parent->parent);
						}
					}
					else
					{
						u = k->parent->parent->right;

						if (u->color == 1)
						{
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								leftRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							rightRotate(k->parent->parent);
						}
					}
					if (k == root)
					{
						break;
					}
				}
				root->color = 0;
			}

			NodePtr minimum(NodePtr node)
			{
				while (node->left != TNULL)
				{
					node = node->left;
				}
				return node;
			}

			NodePtr maximum(NodePtr node) 
			{
				while (node->right != TNULL) 
				{
					node = node->right;
				}
				return node;
			}

			NodePtr successor(NodePtr x) 
			{
				if (x->right != TNULL) 
				{
					return minimum(x->right);
				}

				NodePtr y = x->parent;
				while (y != TNULL && x == y->right) 
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr predecessor(NodePtr x) 
			{
				if (x->left != TNULL) 
				{
					return maximum(x->left);
				}

				NodePtr y = x->parent;
				while (y != TNULL && x == y->left) 
				{
					x = y;
					y = y->parent;
				}
				return y;
			}
			void deallocateNode(Node* del)
			{
				_alloc_node.deallocate(del, 1);
			}
	};
}
#endif