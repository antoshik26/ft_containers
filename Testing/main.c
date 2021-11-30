#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct str
{
	int a;
	struct str *right;
	struct str *left;
	struct str *root;
}				t_str;


int main()
{
	
	t_str *a;
	a = (t_str *)malloc(sizeof(t_str));
	a->a = 12;
	a->right = NULL;
	a->left = NULL;
	a->root = NULL;
	
	t_str *b;
	b = (t_str *)malloc(sizeof(t_str));
	b->right = NULL;
	b->left = NULL;
	b->root = a;
	
	a->left = b;
	return (0);
}

	RedBlackmap(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) //работает
			{
				_size_struct = 0;
				_size_alloc = 0;
				_alloc = alloc;
				_comp = comp;
				Node = new Node_or_leaf_map(Pair<Key, T>(0 , 0));
				Node->root = nullptr;
				Node->left = nullptr;
				Node->right = nullptr;
				Node->color = 0;

				// NULL = new Node_or_leaf_map(0,0);
			    // NULL->color = 0;
			    // NULL->left = nullptr;
			    // NULL->right = nullptr;
			    // Node = NULL;
			}

			//  RedBlackTree() {
			//     NULL = new Node;
			//     NULL->color = 0;
			//     NULL->left = nullptr;
			//     NULL->right = nullptr;
			//     root = NULL;
			//   }
			
			RedBlackmap(RedBlackmap& other )
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
			}

			template< class InputIt >
			RedBlackmap( InputIt first, InputIt last,const Compare& comp = Compare(), const Allocator& alloc = Allocator(), typename enable_if<!is_integral<InputIt>::value >::type* = 0) //провепить
			{
				_alloc = alloc;;
				_comp = comp;
				_size_struct = 0;;
				_size_alloc = 0;;
				Node = NULL;
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
			}

			~RedBlackmap()
			{
				// clear();
			}

			Allocator get_allocator() const //работает
			{
				return (_alloc);
			}

			T& at(const Key& key) //работает
			{
				try
				{
					Node_or_leaf_map* tmp1;
					Node_or_leaf_map* tmp2;

					tmp1 = Node;
					if (Node == NULL)
					{
						throw RedBlackmap::ExceptionAt();
					}
					else
					{
						while (tmp1 != NULL)
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
				Node_or_leaf_map* tmp1;
				Node_or_leaf_map* tmp2;
				Node_allocator a;
				Pair<Key, T> value(key, static_cast<T>(0));
				
				tmp1 = Node;
				if (Node == NULL)
				{
					Node = (Node_or_leaf_map*)a.allocate(1);
					a.construct(Node, value);
					Node->left = 0;
					Node->right = 0;
					Node->root = 0;
					Node->collor = 0;
					_size_struct++;
					return(Node->value.second);
				}
				else
				{
					while (tmp1 != NULL)
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
					Node_or_leaf_map* tmp3;
					tmp3 = (Node_or_leaf_map*)a.allocate(1);
					a.construct(tmp3, value);
					tmp3->root = tmp2;
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

			iterator begin() //работает
			{
				return (iterator(searchMinNode(Node), Node, _comp));	
			}

			const_iterator begin() const
			{
				return (const_iterator(searchMinNode(Node), Node, _comp));
			}

			iterator end() //работает
			{
				return (iterator(searchMaxNode(Node), Node, _comp));
			}

			const_iterator end() const
			{
				return (const_iterator(searchMaxNode(Node), Node, _comp));	
			}

			reverse_iterator rbegin() //работает
			{
				return (reverse_iterator(searchMaxNode(Node), Node, _comp));
			}
			
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(searchMaxNode(Node), Node, _comp));
			}

			reverse_iterator rend() //работает
			{
				return (reverse_iterator(searchMinNode(Node), Node, _comp));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(searchMinNode(Node, Node, _comp)));
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
				max_size = (pow(2, 64)) / ((sizeof(Key) - 1) + (sizeof(T) - 1) + (sizeof(Node_or_leaf_map)));
				return (max_size);
			}

			void clear() //работает
			{
				iterator it1 = begin();
				iterator it2 = end();

				while (it1 != it2)
				{
					erase(it1);	
					it1++;
				}
			}

			Pair<iterator, bool> insert(const Pair</*const*/ Key, T>& value) //работает
			{
				Node_or_leaf_map* node = new Node_or_leaf_map(value);
			    node->root = nullptr;
			    node->value = value;
			    node->left = NULL;
			    node->right = NULL;
			    node->color = 1;
				iterator a1;
				bool a2 = false;
				Pair<iterator, bool> a;
				a.first = a1;
				a.second = a2;

			    Node_or_leaf_map* y = nullptr;
			    Node_or_leaf_map* x = Node->root;

			    while (x != NULL) {
			      y = x;
			      if (node->value.first < x->value.first) {
			        x = x->left;
			      } else {
			        x = x->right;
			      }
			    }

			    node->root = y;
			    if (y == nullptr) {
			      node->root = node;
			    } else if (node->value.first < y->value.first) {
			      y->left = node;
			    } else {
			      y->right = node;
			    }

			    if (node->root == nullptr) {
			      node->color = 0;
			      return (a);
			    }

			    if (node->root->root == nullptr) {
			      return (a);
			    }
				// std::cout << "b" << std::endl;

			    // insertFix(node);
				// std::cout << "c" << std::endl;
				return (a);
			}
			//   void insert(int key) { //переписать создание нода
			    
			//   }


			template<class InputIt>
			void insert(InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value >::type* = 0)
			{
				while (first != last)
				{
					insert(first.get_node()->value);
					first++;
				}
				insert(first.get_node()->value);
			}

			iterator insert(iterator hint, const Pair</*const*/ Key, T>& value)
			{
				(void)hint;
				insert(value);
				return (iterator(Node, Node, _comp));
			}

			void erase(iterator pos) //работает
			{
				deleteNodeHelper(Node, pos.get_node()->value.first);
			}
			// void deleteNode(int data)
			// {
			// 	deleteNodeHelper(this->root, data);
			// }


			void erase(iterator first, iterator last) //работает
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
				erase(first);
			}
			
			void swap(RedBlackmap& other) //работает
			{
				swap(Node, other.Node);
				swap(_size_struct, other._size_struct);
				swap(_size_alloc, other._size_alloc);
				swap(_comp, other._comp);
				swap(_alloc_node, other._alloc_node);
				swap(_alloc, other._alloc);
			}

			size_t count( const Key& key ) const //работает
			{
				Node_or_leaf_map* search_node = searchTreeHelper(Node, key);
				if (search_node == NULL)
					return (0);
				return (1);
			}

			iterator find(const Key& key) //работает
			{
				Node_or_leaf_map* search_node = searchTreeHelper(Node, key);
				iterator it2(search_node, search_node, _comp);
				return (it2);
			}

			// Node_or_leaf_map* searchTree(int k)
			// {
			// 	return searchTreeHelper(this->root, k);
			// }

			const_iterator find( const Key& key ) const
			{
				Node_or_leaf_map* search_node = searchTreeHelper(Node, key);
				const_iterator it2(search_node, search_node, _comp);
				return (it2);
			}
			// NodePtr searchTree(int k)
			// {
			// 	return searchTreeHelper(this->root, k);
			// }

				Pair<const_iterator, const_iterator> equal_range( const Key& key ) const
				{
					Node_or_leaf_map* tmp1;
					Node_or_leaf_map* tmp2;
					Pair<const_iterator, const_iterator> combo;

					tmp1 = Node;
					if (tmp1 == NULL)
						return (combo);
					else
					{
						while (tmp1 != NULL)
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
					Node_or_leaf_map* tmp1;
					Node_or_leaf_map* tmp2;
					
					tmp1 = Node;
					if (tmp1 == NULL)
						return (NULL);
					else
					{
						while (tmp1 != NULL)
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
					Node_or_leaf_map* tmp1;
					Node_or_leaf_map* tmp2;
					
					tmp1 = Node;
					if (tmp1 == NULL)
						return (NULL);
					else
					{
						while (tmp1 != NULL)
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
					Node_or_leaf_map* tmp1;
					Node_or_leaf_map* tmp2;
					
					tmp1 = Node;
					if (tmp1 == NULL)
						return (NULL);
					else
					{
						while (tmp1 != NULL)
						{
							tmp2 = tmp1;
							if (_comp(tmp2->value.first, key) == -1)
								tmp1 = tmp2->right;
							else
							{
								if (_comp(tmp2->value.first, key) == 0)
								{
									iterator iterator(tmp2, tmp2, _comp);
									return (iterator);
								}
								if (_comp(tmp2->value.first, key) == 1)
								{
									iterator iterator(tmp2, tmp2, _comp);
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
					Node_or_leaf_map* tmp1;
					Node_or_leaf_map* tmp2;
					
					tmp1 = Node;
					if (tmp1 == NULL)
						return (NULL);
					else
					{
						while (tmp1 != NULL)
						{
							tmp2 = tmp1;
							if (_comp(tmp2->value.first, key) == -1)
								tmp1 = tmp2->right;
							else
							{
								if (_comp(tmp2->value.first, key) == 0)
								{
									const_iterator iterator(tmp2, tmp2, _comp);
									return (iterator);
								}
								if (_comp(tmp2->value.first, key) == 1)
								{
									const_iterator iterator(tmp2, tmp2, _comp);
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

				void printTree() 
				{
					if (Node) 
					{
						printHelper(this->Node, "", true);
					}
				}
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
				if (node != NULL)
				{
					std::cout << node->data << " ";
					preOrderHelper(node->left);
					preOrderHelper(node->right);
				}
			}

			// Inorder
			void inOrderHelper(Node_or_leaf_map* node)
			{
				if (node != NULL)
				{
					inOrderHelper(node->left);
					std::cout << node->data << " ";
					inOrderHelper(node->right);
				}
			}

			// Post order
			void postOrderHelper(Node_or_leaf_map* node)
			{
				if (node != NULL)
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
				if (y->left != NULL)
				{
					y->left->root = x;
				}
				y->root = x->root;
				if (x->root == nullptr)
				{
					Node = y;
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
				if (y->right != NULL)
				{
					y->right->root = x;
				}
				y->root = x->root;
				if (x->root == nullptr)
				{
					Node = y;
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
				if (node == NULL || key == node->data)
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
				Node_or_leaf_map* z = NULL;
				Node_or_leaf_map* x, y;
				while (node != NULL)
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
				if (z == NULL) 
				{
					std::cout << "Key not found in the tree" << std::endl;
					return;
				}
				y = z;
				int y_original_color = y->color;
				if (z->left == NULL)
				{
					x = z->right;
					rbTransplant(z, z->right);
				}
				else if (z->right == NULL)
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

			void printHelper(Node_or_leaf_map* root, std::string indent, bool last) 
			{
				if (root != NULL) {
			    std::cout << indent;
			    if (last) {
			    std::cout << "R----";
			    indent += "   ";
			    } else {
			    std::cout << "L----";
			    indent += "|  ";
			    }

			    std::string sColor = root->color ? "RED" : "BLACK";
			    std::cout << root->value.first << " " << root->value.second << "(" << sColor << ")" << std::endl;
			    printHelper(root->left, indent, false);
			    printHelper(root->right, indent, true);
			    }
			}
	};
}



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
	//   NodePtr NULL;



	//    public:
	//   RedBlackTree() {
	//     NULL = new Node;
	//     NULL->color = 0;
	//     NULL->left = nullptr;
	//     NULL->right = nullptr;
	//     root = NULL;
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
	//     while (node->left != NULL) {
	//       node = node->left;
	//     }
	//     return node;
	//   }

	//   NodePtr maximum(NodePtr node) {
	//     while (node->right != NULL) {
	//       node = node->right;
	//     }
	//     return node;
	//   }

	//   NodePtr successor(NodePtr x) {
	//     if (x->right != NULL) {
	//       return minimum(x->right);
	//     }

	//     NodePtr y = x->parent;
	//     while (y != NULL && x == y->right) {
	//       x = y;
	//       y = y->parent;
	//     }
	//     return y;
	//   }

	//   NodePtr predecessor(NodePtr x) {
	//     if (x->left != NULL) {
	//       return maximum(x->left);
	//     }

	//     NodePtr y = x->parent;
	//     while (y != NULL && x == y->left) {
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