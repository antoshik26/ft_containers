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
		class Allocator = std::allocator<std::pair<const Key, T> >
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

				// Node(const Pair</*const*/ Key, T>& value)
				// {
				// 	this->value = value;
				// }

				// Node& operator=(const Node& other)
				// {
				// 	(void)other;
				// 	std::cout << "3" << std::endl;
				// }

				// ~Node()
				// {
					
				// }
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

				TNULL = new Node; //alloc
				TNULL->color = 0;
				TNULL->left = nullptr;
				TNULL->right = nullptr;
				root = TNULL;
			}

			~RedBlackmap()
			{

			}
			
			NodePtr searchTree(int k) 
			{
				return searchTreeHelper(this->root, k);
			}


			Pair<iterator, bool> insert(const Pair</*const*/ Key, T>& value) //работает
			{
				Pair<iterator, bool> a; //бурда ебаная
				NodePtr node = new Node; //allocater
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

				insertFix(node);
				return (a);
			}

			NodePtr getRoot() 
			{
				return this->root;
			}

			// void erase(iterator pos)
			void deleteNode(Pair<Key, T>data) 
			{
				deleteNodeHelper(this->root, data.first);
			}

			void printTree() 
			{
				if (root)
				{
					printHelper(this->root, "", true);
				}
			}

		private:
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
	};
}
#endif

// map(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) //работает
// 			{
// 				_size_struct = 0;
// 				_size_alloc = 0;
// 				_alloc = alloc;
// 				_comp = comp;
// 				Node = NULL;
// 			}
			
// 			map(map& other )
// 			{
// 				_alloc = other._alloc;
// 				_comp = other._comp;
// 				// _size_struct = other._size_struct;
// 				// _size_alloc = other._size_alloc;
// 				_alloc_node = other._alloc_node;

// 				iterator begin = other.begin();
// 				iterator end = other.end();
// 				while (begin != end)
// 				{
// 					insert(*begin);
// 					begin++;
// 				}
// 				insert(*begin);
// 			}
			
// 			template< class InputIt >
// 			map( InputIt first, InputIt last,const Compare& comp = Compare(), const Allocator& alloc = Allocator(), typename enable_if<!is_integral<InputIt>::value >::type* = 0) //работает
// 			{
// 				_alloc = alloc;;
// 				_comp = comp;
// 				_size_struct = 0;;
// 				_size_alloc = 0;;
// 				Node = NULL;
// 				while(first != last)
// 				{
// 					insert(*first);
// 					first++;
// 				}
// 				insert(*first);
// 			}

// 			~map()
// 			{
// 				clear();
// 				// Node_or_leaf_map* tmp1;
// 				// Node_or_leaf_map* tmp2;

// 				// tmp1 = Node;
// 				// if (tmp1 != NULL)
// 				// {
// 					// while (tmp1)
// 					// {
// 					// 	while (tmp1) 
// 					// 	{
// 					// 		tmp2 = tmp1->left;
// 					// 		if (tmp2 == NULL)
// 					// 			tmp2 = tmp1->right;
// 					// 		if (tmp2 == NULL)
// 					// 		{
// 					// 			_alloc.destroy(&tmp2->value);
// 					// 			tmp1 = NULL;
// 					// 		}					
// 					// 		else
// 					// 		{
// 					// 			_alloc.destroy(&tmp2->value);
// 					// 			tmp2 = NULL;
// 					// 		}
// 					// 		tmp1 = tmp2;
// 					// 	}
// 					// 	tmp1 = Node;
// 					// } вечный цикл
// 				// }	
// 				// _alloc.deallocate((Node_or_leaf_map*)Node, _size_struct); 
// 			}
			
// 			map& operator=(map& other) //работает
// 			{
// 				_alloc = other._alloc;
// 				_comp = other._comp;
// 				// _size_struct = other._size_struct;
// 				// _size_alloc = other._size_alloc;
// 				_alloc_node = other._alloc_node;

// 				iterator begin = other.begin();
// 				iterator end = other.end();
// 				while (begin != end)
// 				{
// 					insert(*begin);
// 					begin++;
// 				}
// 				insert(*begin);
// 				// Node_allocator alloc_node;
// 				// Node_or_leaf_map* Copy_Node; 
// 				// _alloc = other._alloc;
// 				// _comp = other._comp;
// 				// _size_struct = other._size_struct;
// 				// _size_alloc = other._size_alloc;

// 				// Node_or_leaf_map* lastNode = NULL;
// 				// Node_or_leaf_map* Node = other.Node;
// 				// while (Node != NULL)
// 				// {
// 				// 	if (lastNode == Node->root)
// 				// 	{
// 				// 		if (Node->left != NULL)
// 				// 		{
// 				// 			lastNode = Node;
// 				// 			Node = Node->left;
// 				// 			continue;
// 				// 		}
// 				// 		else
// 				// 			lastNode = NULL;
// 				// 	}
// 				// 	if (lastNode == Node->left)
// 				// 	{
// 				// 		// Node_or_leaf_map* root = Node;
// 				// 		// std::cout << Node->value.first << " " << Node->value.second << std::endl;
// 				// 		Copy_Node = alloc_node.allocate(1);
// 				// 		alloc_node.construct(Copy_Node, Node->value);
// 				// 		Copy_Node->right = NULL;
// 				// 		Copy_Node->left = NULL;
// 				// 		Copy_Node->root = NULL;
// 				// 		 //изменить на предыдущий добавляемый элемент
// 				// 		Copy_Node->collor = other.Node->collor;
// 				// 		if (Node->right != NULL)
// 				// 		{
// 				// 			lastNode = Node;
// 				// 			Node = Node->right;
// 				// 			continue;
// 				// 		}
// 				// 		else
// 				// 			lastNode = NULL;
// 				// 	}
// 				// 	if (lastNode == Node->right)
// 				// 	{
// 				// 		lastNode = Node;
// 				// 		Node = Node->root;
// 				// 	}
// 				// }
// 				return (*this);
// 			}
			
// 			Allocator get_allocator() const //работает
// 			{
// 				return (_alloc);
// 			}

// 			T& at(const Key& key) //работает
// 			{
// 				try
// 				{
// 					Node_or_leaf_map* tmp1;
// 					Node_or_leaf_map* tmp2;

// 					tmp1 = Node;
// 					if (Node == NULL)
// 					{
// 						throw map::ExceptionAt();
// 					}
// 					else
// 					{
// 						while (tmp1 != NULL)
// 						{
// 							tmp2 = tmp1;
// 							if (_comp(tmp2->value.first, key) == 1)
// 								tmp1 = tmp2->left;
// 							else
// 							{
// 								if (_comp(tmp2->value.first, key) == 0)
// 									return (tmp2->value.second);
// 								tmp1 = tmp2->right;
// 							}
// 						}
// 						throw map::ExceptionAt();
// 					}
// 				}
// 				catch(std::exception &e)
// 				{
// 					throw;
// 				}
// 			}

// 			T& operator[](Key key) //работает
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				Node_allocator a;
// 				Pair<Key, T> value(key, static_cast<T>(0));
				
// 				tmp1 = Node;
// 				if (Node == NULL)
// 				{
// 					Node = (Node_or_leaf_map*)a.allocate(1);
// 					a.construct(Node, value);
// 					Node->left = 0;
// 					Node->right = 0;
// 					Node->root = 0;
// 					Node->collor = 0;
// 					_size_struct++;
// 					return(Node->value.second);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, key) == 1)
// 							tmp1 = tmp2->left;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, key) == 0)
// 								return (tmp2->value.second);
// 							tmp1 = tmp2->right;
// 						}
// 					}
// 					Node_or_leaf_map* tmp3;
// 					tmp3 = (Node_or_leaf_map*)a.allocate(1);
// 					a.construct(tmp3, value);
// 					tmp3->root = tmp2;
// 					tmp3->left = NULL;
// 					tmp3->right = NULL;
// 					tmp3->collor = 0; //while brown
// 					if (_comp(tmp2->value.first, key) == 1)
// 						tmp2->left = tmp3;
// 					else
// 						tmp2->right = tmp3;
// 					_size_struct++;
// 					return (tmp3->value.second);
// 				}
// 			}

// 			iterator begin() //работает
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				iterator it = NULL;

// 				tmp1 = Node;
// 				if (Node == NULL)
// 				{
// 					return (it);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						tmp1 = tmp2->left;
// 					}
// 					iterator it2(tmp2, tmp2->root, _comp);
// 					return (it2);
// 				}
// 			}

// 			const_iterator begin() const
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				const_iterator it = NULL;

// 				tmp1 = Node;
// 				if (Node == NULL)
// 				{
// 					return (it);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						tmp1 = tmp2->left;
// 					}
// 					const_iterator it2(tmp2, tmp2->root, _comp);
// 					return (it2);
// 				}
// 			}

// 			iterator end() //работает
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				iterator it = NULL;

// 				tmp1 = Node;
// 				if (Node == NULL)
// 				{
// 					return (it);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						tmp1 = tmp2->right;
// 					}
// 					iterator it2(tmp2, tmp2->root, _comp);
// 					return (it2);
// 				}
// 			}

// 			const_iterator end() const
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				const_iterator it = NULL;

// 				tmp1 = Node;
// 				if (Node == NULL)
// 				{
// 					return (it);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						tmp1 = tmp2->right;
// 					}
// 					const_iterator it2(tmp2, tmp2->root, _comp);
// 					return (it2);
// 				}
// 			}

// 			reverse_iterator rbegin() //работает
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				iterator it;

// 				tmp1 = Node;
// 				if (Node == NULL)
// 				{
// 					return (it);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						tmp1 = tmp2->right;
// 					}
// 					iterator it2(tmp2, tmp2->root, _comp);
// 					return (it2);
// 				}
// 			}

// 			const_reverse_iterator rbegin() const
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				const_reverse_iterator it;

// 				tmp1 = Node;
// 				if (Node == NULL)
// 				{
// 					return (it);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						tmp1 = tmp2->right;
// 					}
// 					const_reverse_iterator it2(tmp2, tmp2->root, _comp);
// 					return (it2);
// 				}
// 			}

// 			reverse_iterator rend() //работает
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				iterator it = NULL;

// 				tmp1 = Node;
// 				if (Node == NULL)
// 				{
// 					return (it);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						tmp1 = tmp2->left;
// 					}
// 					iterator it2(tmp2, tmp2->root, _comp);
// 					return (it2);
// 				}
// 			}

// 			const_reverse_iterator rend() const
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				const_reverse_iterator it = NULL;

// 				tmp1 = Node;
// 				if (Node == NULL)
// 				{
// 					return (it);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						tmp1 = tmp2->left;
// 					}
// 					const_reverse_iterator it2(tmp2, tmp2->root, _comp);
// 					return (it2);
// 				}
// 			}

// 			bool empty() const //работает
// 			{
// 				if (_size_struct == 0)
// 					return (true);
// 				else
// 					return (false);
// 			}

// 			size_t size() const //работает
// 			{
// 				return (_size_struct);
// 			}

// 			size_t max_size() const //работает
// 			{
// 				size_t max_size;
// 				max_size = (pow(2, 64)) / ((sizeof(Key) - 1) + (sizeof(T) - 1) + (sizeof(Node_or_leaf_map)));
// 				return (max_size);
// 			}

// 			void clear() //работает
// 			{
// 				if (_size_struct != 0)
// 					erase(begin(), end());
// 				if (_size_struct == 1)
// 					erase(begin());

// 			}

// 			Pair<iterator, bool> insert(const Pair</*const*/ Key, T>& value) //работает
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				Pair<iterator, bool> ret;
// 				Node_allocator a;
				
// 				tmp1 = Node;
// 				if (Node == NULL)
// 				{	
// 					Node = (Node_or_leaf_map*)a.allocate(1);
// 					a.construct(Node, value);
// 					Node->left = 0;
// 					Node->right = 0;
// 					Node->root = 0;
// 					Node->collor = 0;
// 					iterator iteratorNode(Node, Node, _comp);
// 					ret.first = iteratorNode;
// 					ret.second = true;
// 					_size_struct++;
// 					return (ret);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, value.first) == 1)
// 							tmp1 = tmp2->left;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, value.first) == 0)
// 							{
// 								iterator iteratorNode(tmp2, tmp2, _comp);
// 								ret.first = iteratorNode;
// 								ret.second = true;
// 								return (ret);
// 							}
// 							tmp1 = tmp2->right;
// 						}
// 					}
// 					Node_or_leaf_map* tmp3;
// 					tmp3 = (Node_or_leaf_map*)a.allocate(1);
// 					a.construct(tmp3, value);
// 					tmp3->root = tmp2;
// 					tmp3->left = NULL;
// 					tmp3->right = NULL;
// 					tmp3->collor = 0; //while brown
// 					if (_comp(tmp2->value.first, value.first) == 1)
// 						tmp2->left = tmp3;
// 					else
// 						tmp2->right = tmp3;
// 					_size_struct++;
// 					iterator iteratorNode(tmp3, tmp3, _comp);
// 					ret.first = iteratorNode;
// 					ret.second = true;
// 				}
// 				return (ret);
// 			}

// 			template<class InputIt>
// 			void insert(InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value >::type* = 0) //работает
// 			{
// 				while (first != last)
// 				{
// 					insert(*first);
// 					first++;
// 				}
// 				insert(*first);
// 			}

// 			iterator insert(iterator hint, const Pair</*const*/ Key, T>& value) //работает
// 			{
// 				if (hint.get_node()->value.first > value.first)
// 				{
// 					iterator prev(hint);
// 					--prev;
// 					while (prev != end() && prev.get_node()->value.first >= value.first)
// 					{
// 						hint--;
// 						prev--;
// 					}
// 				}
// 				if (hint.get_node()->value.first < value.first)
// 				{
// 					iterator next(hint);
// 					++next;
// 					while (next != begin() && next.get_node()->value.first <= value.first)
// 					{
// 						++hint;
// 						++next;
// 					}
// 				}
// 				if (hint != end() && value.first == hint.get_node()->value.first)
// 					return (hint);
// 				_size_struct = _size_struct + 1;
// 				//создание нода 
// 				Node_allocator a;
// 				Node_or_leaf_map* newNode;

// 				newNode = a.allocate(1);
// 				a.construct(newNode, value);
// 				newNode->root = hint.get_node();
// 				newNode->left = NULL;
// 				newNode->right = NULL;
// 				newNode->collor = 0;
// 				iterator iteratorNewNode(newNode, newNode->root, _comp);
// 				return (iteratorNewNode);
// 			}

// 			void erase(iterator pos) //работает
// 			{
// 				Node_allocator _alloc_node;
// 				Node_or_leaf_map* tmp;
// 				Node_or_leaf_map* pos2 = pos.get_node();
// 				tmp = pos.get_node()->root;
// 				if (tmp == NULL)
// 					tmp = Node;
// 				if (pos2->right == NULL && pos2->left == NULL) //нет подлистьев
// 				{
// 					if (tmp->left == pos2)
// 					{
// 						// _alloc.destroy(pos2);
// 						tmp->left = NULL;
// 					}

// 					if (tmp->right == pos2)
// 					{
// 						// _alloc_node.destroy(pos2);
// 						tmp->right = NULL;
// 					}
// 				}
// 				else if (pos2->right == NULL || pos2->left == NULL) //есть подлистья
// 				{
// 					if (pos2->left == NULL)
// 					{
// 						if (tmp->left == pos2)
// 						{
// 							tmp->left = pos2->right;
// 						}
// 						else
// 						{
// 							tmp->right = pos2->right;
// 						}
// 						pos2->right->root = tmp;
// 					}
// 					else
// 					{
// 						if (tmp->left == pos2)
// 						{
// 							tmp->left = pos2->left;
// 						}
// 						else
// 						{
// 							tmp->right = pos2->left;
// 						}
// 						pos2->left->root = tmp;
// 					}
// 				}
// 				else
// 				{
// 					iterator itmp2(pos2, pos2, _comp);
// 					itmp2++;
// 					Node_or_leaf_map* tmp2 = itmp2.get_node();
// 					pos2->value.first = tmp2->value.first;
// 					pos2->value.second = tmp2->value.second;
// 					if (tmp2->root->left == tmp2)
// 					{
// 						tmp2->root->left = tmp2->right;
// 						if (tmp2->right != NULL)
// 							tmp2->right->root = tmp2->root;
// 					}
// 					else
// 					{
// 						tmp2->root->right = tmp2->right;
// 						if (tmp->right != NULL)
// 							tmp2->right->root = tmp2->root;
// 					}
// 				}
// 				_size_struct--;
// 			}

// 			void erase( iterator first, iterator last ) //работает
// 			{
// 				while (first != last)
// 				{
// 					erase(first);
// 					++first;
// 				}
// 				erase(first);
// 			}
			
// 			void swap(map& other) //работает
// 			{
// 				swap(Node, other.Node);
// 				swap(_size_struct, other._size_struct);
// 				swap(_size_alloc, other._size_alloc);
// 				swap(_comp, other._comp);
// 				swap(_alloc_node, other._alloc_node);
// 				swap(_alloc, other._alloc);
// 			}
			
// 			size_t count( const Key& key ) const //работает
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;

// 				tmp1 = Node;
// 				if (tmp1 == NULL)
// 					return (0);
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, key) == 1)
// 							tmp1 = tmp2->left;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, key) == 0)
// 								return (1); 
// 							tmp1 = tmp2->right;
// 						}
// 					}
// 				}
// 				return (0);
// 			}

// 			// size_type erase(const Key& key)
			
// 			iterator find(const Key& key ) //работает
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
				
// 				tmp1 = Node;
// 				if (tmp1 == NULL)
// 				{
// 					return (NULL);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, key) == 1)
// 							tmp1 = tmp2->left;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, key) == 0)
// 							{
// 								iterator iteratorNode(tmp2, tmp1, _comp);
// 								return (iteratorNode);
// 							}
// 							tmp1 = tmp2->right;
// 						}
// 					}
// 				}
// 				return (NULL);
// 			}
			
// 			const_iterator find( const Key& key ) const
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
				
// 				tmp1 = Node;
// 				if (tmp1 == NULL)
// 				{
// 					return (NULL);
// 				}
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, key) == 1)
// 							tmp1 = tmp2->left;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, key) == 0)
// 							{
// 								const_iterator iteratorNode(tmp2, tmp1, _comp);
// 								return (iteratorNode);
// 							}
// 							tmp1 = tmp2->right;
// 						}
// 					}
// 				}
// 				return (NULL);
// 			}

// 			Pair<iterator, iterator> equal_range(const Key& key) //доделать
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				Pair<iterator, iterator> combo;

// 				tmp1 = Node;
// 				if (tmp1 == NULL)
// 					return (combo);
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, key) == 1)
// 							tmp1 = tmp2->left;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, key) == 0)
// 							{
// 								iterator iterator1(tmp2, tmp2, _comp);
// 								iterator1++;
// 								combo.first = iterator1;
// 								iterator iterator2(tmp2, tmp2, _comp);
// 								iterator2--;
// 								combo.second = iterator2;
// 								return (combo); 
// 							}
// 							tmp1 = tmp2->right;
// 						}
// 					}
// 				}
// 				return (combo);
// 			}

// 			Pair<const_iterator, const_iterator> equal_range( const Key& key ) const
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
// 				Pair<const_iterator, const_iterator> combo;

// 				tmp1 = Node;
// 				if (tmp1 == NULL)
// 					return (combo);
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, key) == 1)
// 							tmp1 = tmp2->left;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, key) == 0)
// 							{
// 								const_iterator iterator1(tmp2, tmp2, _comp);
// 								iterator1++;
// 								combo.first = iterator1;
// 								const_iterator iterator2(tmp2, tmp2, _comp);
// 								iterator2--;
// 								combo.second = iterator2;
// 								return (combo); 
// 							}
// 							tmp1 = tmp2->right;
// 						}
// 					}
// 				}
// 				return (combo);
// 			}

// 			iterator lower_bound(const Key& key) //работает
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
				
// 				tmp1 = Node;
// 				if (tmp1 == NULL)
// 					return (NULL);
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, key) == 1)
// 							tmp1 = tmp2->left;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, key) == 0)
// 							{
// 								iterator iterator(tmp2, tmp2, _comp);
// 								return (iterator);
// 							}
// 							if (_comp(tmp2->value.first, key) == -1)
// 							{
// 								iterator iterator(tmp2, tmp2, _comp);
// 								return (iterator);
// 							}
// 						}
// 					}
// 				}
// 				iterator iterator = begin();
// 				return (iterator);
// 			}

// 			const_iterator lower_bound( const Key& key ) const
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
				
// 				tmp1 = Node;
// 				if (tmp1 == NULL)
// 					return (NULL);
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, key) == 1)
// 							tmp1 = tmp2->left;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, key) == 0)
// 							{
// 								const_iterator iterator(tmp2, tmp2, _comp);
// 								return (iterator);
// 							}
// 							if (_comp(tmp2->value.first, key) == -1)
// 							{
// 								const_iterator iterator(tmp2, tmp2, _comp);
// 								return (iterator);
// 							}
// 						}
// 					}
// 				}
// 				const_iterator iterator = begin();
// 				return (iterator);
// 			}

// 			iterator upper_bound(const Key& key) //работает
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
				
// 				tmp1 = Node;
// 				if (tmp1 == NULL)
// 					return (NULL);
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, key) == -1)
// 							tmp1 = tmp2->right;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, key) == 0)
// 							{
// 								iterator iterator(tmp2, tmp2, _comp);
// 								return (iterator);
// 							}
// 							if (_comp(tmp2->value.first, key) == 1)
// 							{
// 								iterator iterator(tmp2, tmp2, _comp);
// 								return (iterator);
// 							}
// 						}
// 					}
// 				}
// 				iterator iterator = end();
// 				return (iterator);
// 			}

// 			const_iterator upper_bound( const Key& key ) const
// 			{
// 				Node_or_leaf_map* tmp1;
// 				Node_or_leaf_map* tmp2;
				
// 				tmp1 = Node;
// 				if (tmp1 == NULL)
// 					return (NULL);
// 				else
// 				{
// 					while (tmp1 != NULL)
// 					{
// 						tmp2 = tmp1;
// 						if (_comp(tmp2->value.first, key) == -1)
// 							tmp1 = tmp2->right;
// 						else
// 						{
// 							if (_comp(tmp2->value.first, key) == 0)
// 							{
// 								const_iterator iterator(tmp2, tmp2, _comp);
// 								return (iterator);
// 							}
// 							if (_comp(tmp2->value.first, key) == 1)
// 							{
// 								const_iterator iterator(tmp2, tmp2, _comp);
// 								return (iterator);
// 							}
// 						}
// 					}
// 				}
// 				const_iterator iterator = end();
// 				return (iterator);
// 			}

// 			Compare key_comp() const //работает
// 			{
// 				return (_comp);
// 			}
			
// 			value_compare value_comp() const //работает
// 			{
// 				return (value_compare(_comp));
// 			}

			
// 			friend bool operator==(const map& lhs, const map& rhs) //segmentation fault // работает 
// 			{
// 				// (void)lhs;
// 				// (void)rhs;
// 				const_iterator lhsiter = lhs.begin();
// 				const_iterator rhsiter = rhs.begin();
// 				size_t i = 0;

// 				if (lhs._size_struct != rhs._size_struct)
// 					return (false);
// 				while (i < lhs._size_struct)
// 				{
// 					if ((lhsiter.get_node())->value.first != (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second != (rhsiter.get_node())->value.second)
// 						return (false);
// 					lhsiter++;
// 					rhsiter++;
// 				}
// 				return (true);
// 				// Node_or_leaf_map* lastElemlhs = NULL;
// 				// Node_or_leaf_map* lastElemrhs = NULL;
				
// 				// if (lhs->_size_struct != rhs->_size_struct)
// 				// 	return (false);
// 				// while(lhs->Node != NULL || rhs->Node != NULL)
// 				// {
// 				// 	if (lastElemlhs == lhs->Node->root && lastElemrhs == rhs->Node->root)
// 				// 	{
// 				// 		if (lhs->Node->left != NULL && rhs->Node->left != NULL)
// 				// 		{
// 				// 			lastElemlhs = lhs->Node;
// 				// 			lhs->Node = lhs->Node->Left;
// 				// 			lastElemrhs = rhs->Node;
// 				// 			rhs->Node = rhs->Node->left;
// 				// 			continue;
// 				// 		}
// 				// 		else
// 				// 		{
// 				// 			lastElemlhs = NULL;
// 				// 			lastElemrhs = NULL;
// 				// 		}
// 				// 	}
// 				// 	if (lastElemlhs == lhs->Node->left && lastElemrhs == rhs->Node->left)
// 				// 	{
// 				// 		if (lhs->Node->value->first != rhs->Node->value->first || lhs->Node->value->second != rhs->Node->value->second)
// 				// 			return (false);
// 				// 		if (lhs->Node->right != NULL && rhs->Node->right != NULL)
// 				// 		{
// 				// 			lastElemlhs = lhs->Node;
// 				// 			lhs->Node = lhs->Node->right;
// 				// 			lastElemrhs = rhs->Node;
// 				// 			rhs->Node = rhs->Node->right;
// 				// 			continue;
// 				// 		}
// 				// 		else
// 				// 		{
// 				// 			lastElemlhs = NULL;
// 				// 			lastElemrhs = NULL;
// 				// 		}
// 				// 	}
// 				// 	if (lastElemlhs == lhs->Node->Right && lastElemrhs == rhs->Node->Right)
// 				// 	{
// 				// 		lastElemlhs = lhs->Node;
// 				// 		lhs->Node = lhs->Node.root;
// 				// 		lastElemrhs = rhs->Node;
// 				// 		rhs->Node = rhs->Node->right;
// 				// 	}
// 				// }
// 				// if (lhs->Node != NULL || rhs->Node != NULL)
// 				// {
// 				// 	return (false);
// 				// }
// 				// return (true);
// 			}

			
// 			friend bool operator!=(const map& lhs, const map& rhs)  //работает
// 			{
// 				// (void)lhs;
// 				// (void)rhs;
// 				const_iterator lhsiter = lhs.begin();
// 				const_iterator rhsiter = rhs.begin();
// 				size_t i = 0;

// 				if (lhs._size_struct != rhs._size_struct)
// 					return (true);
// 				while (i < lhs._size_struct)
// 				{
// 					if ((lhsiter.get_node())->value.first != (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second != (rhsiter.get_node())->value.second)
// 						return (true);
// 					lhsiter++;
// 					rhsiter++;
// 				}
// 				return (false);
// 				// Node_or_leaf_map* lastElemlhs = NULL;
// 				// Node_or_leaf_map* lastElemrhs = NULL;
				
// 				// if (lhs->_size_struct != rhs->_size_struct)
// 				// 	return (true);
// 				// while(lhs->Node != NULL || rhs->Node != NULL)
// 				// {
// 				// 	if (lastElemlhs == lhs->Node->root && lastElemrhs == rhs->Node->root)
// 				// 	{
// 				// 		if (lhs->Node->left != NULL && rhs->Node->left != NULL)
// 				// 		{
// 				// 			lastElemlhs = lhs->Node;
// 				// 			lhs->Node = lhs->Node->Left;
// 				// 			lastElemrhs = rhs->Node;
// 				// 			rhs->Node = rhs->Node->left;
// 				// 			continue;
// 				// 		}
// 				// 		else
// 				// 		{
// 				// 			lastElemlhs = NULL;
// 				// 			lastElemrhs = NULL;
// 				// 		}
// 				// 	}
// 				// 	if (lastElemlhs == lhs->Node->left && lastElemrhs == rhs->Node->left)
// 				// 	{
// 				// 		if (lhs->Node->value->first != rhs->Node->value->first || lhs->Node->value->second != rhs->Node->value->second)
// 				// 			return (true);
// 				// 		if (lhs->Node->right != NULL && rhs->Node->right != NULL)
// 				// 		{
// 				// 			lastElemlhs = lhs->Node;
// 				// 			lhs->Node = lhs->Node->right;
// 				// 			lastElemrhs = rhs->Node;
// 				// 			rhs->Node = rhs->Node->right;
// 				// 			continue;
// 				// 		}
// 				// 		else
// 				// 		{
// 				// 			lastElemlhs = NULL;
// 				// 			lastElemrhs = NULL;
// 				// 		}
// 				// 	}
// 				// 	if (lastElemlhs == lhs->Node->Right && lastElemrhs == rhs->Node->Right)
// 				// 	{
// 				// 		lastElemlhs = lhs->Node;
// 				// 		lhs->Node = lhs->Node.root;
// 				// 		lastElemrhs = rhs->Node;
// 				// 		rhs->Node = rhs->Node->right;
// 				// 	}
// 				// }
// 				// if (lhs->Node != NULL || rhs->Node != NULL)
// 				// {
// 				// 	return (true);
// 				// }
// 				// return (false);
// 			}

// 			friend bool operator<(const map& lhs, const map& rhs)  //работает
// 			{
// 				// (void)lhs;
// 				// (void)rhs;
// 				const_iterator lhsiter = lhs.begin();
// 				const_iterator rhsiter = rhs.begin();
// 				size_t i = 0;

// 				if (lhs._size_struct > rhs._size_struct)
// 					return (false);
// 				while (i < lhs._size_struct)
// 				{
// 					if ((lhsiter.get_node())->value.first >= (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second >= (rhsiter.get_node())->value.second)
// 						return (false);
// 					lhsiter++;
// 					rhsiter++;
// 					i++;
// 				}
// 				return (true);
// 			}

			
// 			friend bool operator<=(const map& lhs, const map& rhs) //работает
// 			{
// 				(void)lhs;
// 				(void)rhs;
// 				const_iterator lhsiter = lhs.begin();
// 				const_iterator rhsiter = rhs.begin();
// 				size_t i = 0;

// 				if (lhs._size_struct > rhs._size_struct)
// 					return (false);
// 					while (i < lhs._size_struct)
// 				{
// 					if ((lhsiter.get_node())->value.first > (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second > (rhsiter.get_node())->value.second)
// 						return (false);
// 					lhsiter++;
// 					rhsiter++;
// 					i++;
// 				}
// 				return (true);
// 			}

// 			friend bool operator>(const map& lhs, const map& rhs) //работает
// 			{
// 				// (void)lhs;
// 				// (void)rhs;
// 				const_iterator lhsiter = lhs.begin();
// 				const_iterator rhsiter = rhs.begin();
// 				size_t i = 0;

// 				if (lhs._size_struct < rhs._size_struct)
// 					return (false);
// 				while(i < lhs._size_struct)
// 				{
// 					if ((lhsiter.get_node())->value.first <= (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second <= (rhsiter.get_node())->value.second)
// 						return (false);
// 					lhsiter++;
// 					rhsiter++;
// 					i++;
// 				}
// 				return (true);
// 			}

// 			friend bool operator>=(const map& lhs, const map& rhs) //работает
// 			{
// 				// (void)lhs;
// 				// (void)rhs;
// 				const_iterator lhsiter = lhs.begin();
// 				const_iterator rhsiter = rhs.begin();
// 				size_t i = 0;

// 				if (lhs._size_struct < rhs._size_struct)
// 					return (false);
// 				while(i < lhs._size_struct)
// 				{
// 					if ((lhsiter.get_node())->value.first < (rhsiter.get_node())->value.first || (lhsiter.get_node())->value.second < (rhsiter.get_node())->value.second)
// 						return (false);
// 					lhsiter++;
// 					rhsiter++;
// 					i++;
// 				}
// 				return (true);
// 			}

// 			private:
// 				template <typename U>
// 				void swap(U& a, U& b)
// 				{
// 					U tmp = a;
// 					a = b;
// 					b = tmp;
// 				}

// 				Node_or_leaf_map* searchMaxNode(Node_or_leaf_map *node) const
// 				{
// 					if (node && node->right)
// 						searchMaxNode(node->right);
// 					return (node);
// 				}

// 				Node_or_leaf_map* searchMinNode(Node_or_leaf_map *node) const
// 				{
// 					if (node && node->left)
// 						searchMinNode(node->left);
// 					return (node);
// 				}
				
// 				// void Walk(Node_or_leaf_map node)
// 				// {
// 				// 	Node_or_leaf_map lastNode = NULL;
// 				// 	while (node != NULL)
// 				// 	{
// 				// 		if (lastNode == node.root)
// 				// 		{
// 				// 			if (node.left != NULL)
// 				// 			{
// 				// 				lastNode = node;
// 				// 				node = node.left;
// 				// 				continue;
// 				// 			}
// 				// 			else
// 				// 				lastNode = NULL;
// 				// 		}
// 				// 		if (lastNode == node.left)
// 				// 		{
// 				// 			Output(node);

// 				// 			if (node.right != NULL)
// 				// 			{
// 				// 				lastNode = node;
// 				// 				node = node.right;
// 				// 				continue;
// 				// 			}
// 				// 			else
// 				// 				lastNode = NULL;
// 				// 		}
// 				// 		if (lastNode == node.right)
// 				// 		{
// 				// 			lastNode = node;
// 				// 			node = node.root;
// 				// 		}
// 				// 	}
// 				// }
// 				template<class InputIt1, class InputIt2>
// 				bool lexicographical_compare (InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
// 				{
// 					for (; (first1 != last1) && (first2 != last2); ++first1, ++last1)
// 					{
// 						if (*first1 < *first2) return true;
// 						if (*first2 < *first1) return false;
// 					}
// 					return (first1 == last1) && (first2 != last2);	
// 				}
// 			// protected:
// 	};