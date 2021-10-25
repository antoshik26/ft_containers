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
    class Allocator = std::allocator<std::pair<const Key, T> >
>
class Map
{
	private:
		struct Node_or_leaf_map
		{
			T obj;
			Key key;
			Node_or_leaf_map *right;
			Node_or_leaf_map *left;
			Node_or_leaf_map *root;
			int collor;
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
		// Map()
		// {
			
		// }
		Map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
		{
			_size_struct = 0;
			_size_alloc = 0;
			_alloc = alloc;
			_comp = comp;
		}
		
		~Map()
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;

			tmp1 = Node;
			if (tmp1 != NULL)
			{
				while (tmp1)
				{
					while (tmp1) 
					{
						tmp2 = tmp1->left;
						if (tmp2 == NULL)
							tmp2 = tmp1->right;
						if (tmp2 == NULL)
						{
							// _alloc.destroy(tmp2->obj);
							// _alloc.destroy(tmp2->key);
							tmp1 = NULL;
						}					
						else
						{
							// _alloc.destroy(tmp2->obj);
							// _alloc.destroy(tmp2->key);
							tmp2 = NULL;
						}
						tmp1 = tmp2;
					}
					tmp1 = Node;
				}
			}	
			// _alloc.deallocate(Node, _size_struct); 
		}
		
// 		map& operator=( const map& other );
		
		Allocator get_allocator() const
		{
			return (_alloc);
		}

		T& at( const Key& key )
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
						if (_comp(tmp2->key, key) == 1)
							tmp1 = tmp2->left;
						else
						{
							if (_comp(tmp2->key, key) == 0)
								return (tmp2);
							tmp1 = tmp2->right;
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

		T& operator[]( const Key& key )
		{
			Node_or_leaf_map tmp1;
			Node_or_leaf_map tmp2;

			tmp1 = Node;
			if (Node == NULL)
			{
				Node = _alloc.allocate(1);
				_alloc.construct(Node->key, key);
				_alloc.construct(Node->obj, NULL);
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
					if (_comp(tmp2->key, key) == 1)
						tmp1 = tmp2->left;
					else
					{
						if (_comp(tmp2->key, key) == 0)
							return (tmp2);
						tmp1 = tmp2->right;
					}
				}
				*tmp1 = _alloc.allocate(1);
				_alloc.construct(tmp1->key, key);
				_alloc.construct(tmp1->obj, NULL);
				_alloc.construct(tmp1->root, tmp2);
				tmp1->left = NULL;
				tmp1->right = NULL;
				tmp1->collor = 0; //while brown
				_size_struct++;
				return (tmp1);
			}
		}

		IteratorMap<T> begin()
		{
			Node_or_leaf_map tmp1;
			Node_or_leaf_map tmp2;
			IteratorMap<T> it;

			tmp1 = *this->Node_or_leaf_map;
			if (*this->Node_or_leaf_map == NULL)
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
				return (it(tmp2));
			}
		}

		IteratorMap<T> end()
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap<T> it;

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
				return (it(tmp2));
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

		Pair<IteratorMap<T>, bool> insert(/*const*/ Pair</*const*/ Key, T>& value)
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			Pair<IteratorMap<T>, bool> ret;
			IteratorMap<T> iteratorNode;

			tmp1 = Node;
			if (Node == NULL)
			{
				// Node = _alloc.allocate(1);
				// _alloc.construct(Node->key, value.first);
				// _alloc.construct(Node->obj, value.second);
				Node->left = NULL;
				Node->right = NULL;
				Node->root = NULL;
				Node->collor = 0; //while brown
				// iteratorNode(Node);
				// ret = std::make_pair(iterator, false);
				_size_struct++;
				return (ret);
			}
			else
			{
				while (tmp1 != NULL)
				{
					tmp2 = tmp1;
					if (_comp(tmp2->obj, value.second) == 1)
						tmp1 = tmp2->left;
					else
					{
						if (_comp(tmp2->obj, value.second) == 0)
							return (ret); 
						tmp1 = tmp2->right;
					}
				}
				// tmp1 = _alloc.allocate(1);
				// _alloc.construct(tmp1->key, value->ket);
				// _alloc.construct(tmp1->obj, value->T);
				// _alloc.construct(tmp1->root, tmp2);
				tmp1->left = NULL;
				tmp1->right = NULL;
				tmp1->collor = 0; //while brown
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
					if (_comp(tmp2->obj, key) == 1)
						tmp1 = tmp2->left;
					else
					{
						if (_comp(tmp2->obj, key) == 0)
							return (1); 
						tmp1 = tmp2->right;
					}
				}
			}
			return (0);
		}
		
		IteratorMap<T> find( const Key& key )
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap<T> iterator;
			
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
		
		// const_iterator find( const Key& key ) const
		// {

		// }

		Pair<IteratorMap<T>, IteratorMap<T> > equal_range(const Key& key)
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap<T> iterator;
			
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

		IteratorMap<T> lower_bound( const Key& key )
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap<T> iterator;
			
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

		IteratorMap<T> upper_bound( const Key& key )
		{
			Node_or_leaf_map* tmp1;
			Node_or_leaf_map* tmp2;
			IteratorMap<T> iterator;
			
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