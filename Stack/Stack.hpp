#ifndef STACK_HPP
#define STACK_HPP
#include <memory>
#include <iostream>
#include <string>
#include "../Vector/vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container									container_type;
			typedef T                                           value_type;
			typedef size_t                                      size_type;
			typedef T&                                          reference;
			typedef const T&                                    const_reference;
		
		private:
			Container obj;
		public:
			explicit stack( const Container& cont = Container() )
			{
				obj = cont;
			}

			stack( const stack& other )
			{
				obj = other;
			}

			~stack()
			{	
			}

			stack& operator=( const stack& other )
			{
				obj = other;
			}

			T top()
			{
				return (obj.front());
			}

			T top() const
			{
				return (obj.front());
			}
			
			bool empty() const
			{
				return (obj.empty());
			}

			size_t size() const
			{
				return (obj.size());
			}

			void push( const T& value )
			{
				obj.push_back(value);	
			}

			void pop()
			{
				obj.pop_back();
			}

			void swap(stack& other )
			{
				obj.swap(other);
			}
			
			friend bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
			{
				return (lhs.obj == rhs.obj);
			}

			friend bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
			{
				return (lhs.obj != rhs.obj);
			}

			friend bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
			{
				return (lhs.obj < rhs.obj);
			}

			friend bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
			{
				return (lhs.obj <= rhs.obj);
			}

			friend bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
			{
				return (lhs.obj > rhs.obj);
			}

			friend bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
			{
				return (lhs.obj >= rhs.obj);
			}
	};
}

#endif