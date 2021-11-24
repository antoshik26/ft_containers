#ifndef STACK_HPP
#define STACK_HPP
#include <memory>
#include <iostream>
#include <string>
#include "../Vector/vector.hpp"

template<class T, class Container = ft::vector<T> >
class Stack
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
		explicit Stack( const Container& cont = Container() )
		{
			obj = cont;
		}

		Stack( const Stack& other )
		{
			obj = other;
		}

		~Stack()
		{	
		}

		Stack& operator=( const Stack& other )
		{
			obj = other;
		}

		T top()
		{
			return (obj.array[obj._n]); //front
		}

		T top() const
		{
			return (obj.array[obj._n]);
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
			obj.push(value);	
		}

		void pop()
		{
			obj.pop(); //pop_back
		}

		void swap(Stack& other )
		{
			obj.swap(other);
		}
		
		friend bool operator==( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
		{
			return (lhs.obj == rhs.obj);
		}

		friend bool operator!=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
		{
			return (lhs.obj != rhs.obj);
		}

		friend bool operator<( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
		{
			return (lhs.obj < rhs.obj);
		}

		friend bool operator<=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
		{
			return (lhs.obj <= rhs.obj);
		}

		friend bool operator>( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
		{
			return (lhs.obj > rhs.obj);
		}

		friend bool operator>=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
		{
			return (lhs.obj >= rhs.obj);
		}
};

#endif