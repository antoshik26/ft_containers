#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <iostream>
#include <string>
#include <cmath>
#include "IteratorMap.hpp"
#include "ReversIteratorMap.hpp"
#include "Less.hpp"
#include "Pair.hpp"

// struct Node_or_leaf_map
// {
// 	T obj;
// 	Key key;
// 	Node_or_leaf_map *right;
// 	Node_or_leaf_map *left;
// 	Node_or_leaf_map *root;
// 	int collor;
// };

template<
    class Key,
    class T,
    class Compare = less<Key>, 
    class Allocator = std::allocator<Pair</*const*/ Key, T> >
>
class Map
{
	public:
		struct Node_or_leaf_map
		{
			Pair</*const*/ Key, T> value;
			Node_or_leaf_map *right;
			Node_or_leaf_map *left;
			Node_or_leaf_map *root;
			int collor;
			
			Node_or_leaf_map()
			{
			} 
		};
		Allocator _alloc;
	 	Compare _comp;
		size_t _size_struct;
		size_t _size_alloc;
		Node_or_leaf_map* Node;
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
		typedef IteratorMap<Key, T, Compare, Node_or_leaf_map>     IteratorMap;
		typedef typename  Allocator::template rebind<Node_or_leaf_map>::other  node_allocator;
		// Map()
		// {
			
		// }
		Map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
		{
			_size_struct = 0;
			_size_alloc = 0;
			_alloc = alloc;
			_comp = comp;
			Node = NULL;
		}
		
		~Map()
		{
			Node_or_leaf_map* tmp1;
			// Node_or_leaf_map* tmp2;

			tmp1 = Node;
			if (tmp1 != NULL)
			{
				// while (tmp1)
				// {
				// 	while (tmp1) 
				// 	{
				// 		tmp2 = tmp1->left;
				// 		if (tmp2 == NULL)
				// 			tmp2 = tmp1->right;
				// 		if (tmp2 == NULL)
				// 		{
				// 			_alloc.destroy(&tmp2->value);
				// 			tmp1 = NULL;
				// 		}					
				// 		else
				// 		{
				// 			_alloc.destroy(&tmp2->value);
				// 			tmp2 = NULL;
				// 		}
				// 		tmp1 = tmp2;
				// 	}
				// 	tmp1 = Node;
				// } вечный цикл
			}	
			// _alloc.deallocate((Node_or_leaf_map*)Node, _size_struct); 
		}
		
// 		map& operator=( const map& other );
		
		Allocator get_allocator() const
		{
			return (_alloc);
		}

		T& at(const Key& key)
		{
			try
			{
				Node_or_leaf_map* tmp1;
				Node_or_leaf_map* tmp2;

				tmp1 = Node;
				if (Node == NULL)
				{
					throw Map::ExceptionAt();
				}
				else
				{
					while (tmp1 != NULL)
					{
						tmp2 = tmp1;
						if (_comp(tmp2->value.first, key) == 1)
							tmp1 = tmp2->right;
						else
						{
							if (_comp(tmp2->value.first, key) == 0)
								return (tmp2);
							tmp1 = tmp2->left;
						}
					}
					throw Map::ExceptionAt();
				}
			}
			catch(std::exception &e)
			{
				throw;
			}
		}

		T& operator[](const Key& key)
		{
			Node_or_leaf_map tmp1;
			Node_or_leaf_map tmp2;
			// Pair<const Key, T> value(key, 0);
			
			tmp1 = Node;
			if (Node == NULL)
			{
				Node = _alloc.allocate(1);
				_alloc.construct(&Node->value.first, key);
				_alloc.construct(&Node->value.second, 0);
				Node->left = NULL;
				Node->right = NULL;
				Node->root = NULL;
				Node->collor = 0; //while brown
				_size_struct++;
				return(*this);
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
							return (tmp2);
						tmp1 = tmp2->right;
					}
				}
				*Node = _alloc.allocate(1);
				_alloc.construct(&Node->value.first, key);
				_alloc.construct(&Node->value.second, 0);
				tmp1->root = tmp2;
				tmp1->left = NULL;
				tmp1->right = NULL;
				tmp1->collor = 0; //while brown
				_size_struct++;
				return (tmp1);
			}
		}

		IteratorMap begin()
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap it;

			tmp1 = Node;
			if (Node)
			{
				return (it);
			}
			else
			{
				while (tmp1 != NULL)
				{
					tmp2 = tmp1;
					tmp1 = tmp2->left;
				}
				IteratorMap it2(tmp1, tmp2, _comp);
				return (it2);
			}
		}

		IteratorMap end()
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap it;

			tmp1 = Node;
			if (Node == NULL)
			{
				return (it);
			}
			else
			{
				while (tmp1 != NULL)
				{
					tmp2 = tmp1;
					tmp1 = tmp2->right;
				}
				IteratorMap it2(tmp1, tmp2, _comp);
				return (it2);
			}
		}

		// reverse_iterator rbegin();
		// reverse_iterator rend();

		bool empty() const
		{
			if (_size_struct == 0)
				return (true);
			else
				return (false);
		}

		size_t size() const
		{
			return (_size_struct);
		}

		size_t max_size() const
		{
			size_t max_size;
			max_size = (pow(2, 64)) / ((sizeof(Key) - 1) + (sizeof(T) - 1) + (sizeof(Node_or_leaf_map)));
			return (max_size);
		}

		// void clear();

		Pair<IteratorMap, bool> insert(const Pair</*const*/ Key, T>& value)
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			Pair<IteratorMap, bool> ret;
			IteratorMap iteratorNode;

			tmp1 = Node;
			if (Node == NULL)
			{
				node_allocator a;
				// std::allocator<Pair</*const*/ Key, T>::template rebind<Node_or_leaf_map>::other a;
				Node = (Node_or_leaf_map*)a.allocate(1);
				a.construct(Node->right);
				// _alloc.construct(&Node->value, value);
				_alloc.construct(&Node->value, value);
				// _alloc.construct((void *)&Node->left, NULL);
				Node->left = 0;
				Node->right = 0;
				Node->root = 0;
				Node->collor = 0; //while brown
				// iteratorNode(Node);
				ret.first = iteratorNode;
				ret.second = true;
				_size_struct++;
				return (ret);
			}
			else
			{
				// tmp1->left = Node;
				while (tmp1 != NULL)
				{
					tmp2 = tmp1;
					if (_comp(tmp2->value.first, value.first) == 1)
						tmp1 = tmp2->left;
					else
					{
						if (_comp(tmp2->value.first, value.first) == 0)
							return (ret); 
						tmp1 = tmp2->right;
					}
				}
				tmp1 = Node;
				tmp2 = (Node_or_leaf_map*)_alloc.allocate(1);
				_alloc.construct(&tmp2->value, value);
				tmp2->root = tmp2;
				tmp2->left = NULL;
				tmp2->right = NULL;
				tmp2->collor = 0; //while brown
				tmp1 = tmp2;
				_size_struct++;
			}
			return (ret);
		}

		// iterator insert( iterator hint, const value_type& value );

		// 	void erase( iterator pos );
		// 	void erase( iterator first, iterator last );
		// 	size_t erase( const key_type& key );
		// 	void swap( map& other );
		
		size_t count( const Key& key ) const
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;

			tmp1 = Node;
			if (tmp1 == NULL)
				return (0);
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
							return (1); 
						tmp1 = tmp2->right;
					}
				}
			}
			return (0);
		}
		
		IteratorMap find( const Key& key )
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap iteratorNode;
			
			tmp1 = Node;
			if (tmp1 == NULL)
				return (iteratorNode());
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
							return (iteratorNode(tmp2)); 
						tmp1 = tmp2->right;
					}
				}
			}
			return (iteratorNode());
		}
		
		// const_iterator find( const Key& key ) const
		// {

		// }

		Pair<IteratorMap, IteratorMap> equal_range(const Key& key)
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap iterator;
			
			tmp1 = Node;
			if (tmp1 == NULL)
				return (iterator());
			else
			{
				while (tmp1 != NULL)
				{
					tmp2 = tmp1;
					if (_comp(tmp2->obj, key) == 1)
						tmp1 = tmp2->left;
					else
					{
						if (_comp(tmp2->obj, key) == 0)
							return (iterator(tmp2)); 
						tmp1 = tmp2->right;
					}
				}
			}
			return (iterator());
		}

		// std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

		IteratorMap lower_bound( const Key& key )
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap iterator;
			
			tmp1 = Node;
			if (tmp1 == NULL)
				return (iterator());
			else
			{
				while (tmp1 != NULL)
				{
					tmp2 = tmp1;
					if (_comp(tmp2->obj, key) == -1 || _comp(tmp2->obj, key) == 0)
						tmp1 = tmp2->right;
					else
						break;
				}
			}
			return (iterator(tmp2));
		}

		// const_iterator lower_bound( const Key& key ) const;

		IteratorMap upper_bound( const Key& key )
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap iterator;
			
			tmp1 = Node;
			if (tmp1 == NULL)
				return (iterator());
			else
			{
				while (tmp1 != NULL)
				{
					tmp2 = tmp1;
					if (_comp(tmp2->obj, key) == -1 || _comp(tmp2->obj, key) == 0)
						tmp1 = tmp2->left;
					else
						break;
				}
			}
			return (iterator(tmp2));
		}

		// const_iterator upper_bound( const Key& key ) const;

		Compare key_comp() const
		{
			return (_comp);
		}
		Compare value_comp() const
		{
			return (_comp);
		}

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator==(const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs);

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator!=(const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs);

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<(const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs);

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<=(const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs);

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );

		// void push(Key a, Node_or_leaf_map **t)
		// {
		//     if ((*t) == NULL)                   //Если дерева не существует
		//     {
		//         (*t) = new Node_or_leaf_map;                //Выделяем память
		//         (*t)->info = a;                 //Кладем в выделенное место аргумент a
		//         (*t)->l = (*t)->r = NULL;       //Очищаем память для следующего роста
		//         return;                         //Заложили семечко, выходим
		//     }
		//        //Дерево есть
		//         if (a > (*t)->info) push(a, &(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
		//         else push(a, &(*t)->l);         //Иначе кладем его влево
		// }
		
		// /*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
		// void print (Node_or_leaf_map *t, Key u)
		// {
		//     if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
		//     else //Иначе
		//     {
		//         print(t->l, ++u);                   //С помощью рекурсивного посещаем левое поддерево
		//         for (int i=0; i<u; ++i) std::cout << "|";
		//         std::cout << t->info << std::endl;            //И показываем элемент
		//         u--;
		//     }
		//     print(t->r, ++u);                       //С помощью рекурсии посещаем правое поддерево
		// }
		
};
#endif