#ifndef STACK_HPP
#define STACK_HPP
#include <memory>
#include <iostream>
#include <string>
#include "../Vector/Vector.hpp"

template<class T, class Container = Vector<T> >
class Stack
{
	private:
		Container obj;
	public:
		// Stack() : Stack(Container()) 
		// {
		// }

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
			return (obj.array[obj._n]);
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
			obj.pop();
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