#ifndef STACK_HPP
#define STACK_HPP
#include <memory>
#include <iostream>
#include <string>

class IteratorStack
{
	protected:

	public:

};


template<class T,class Container = std::deque<T>>> class Stack;
class Stack
{
	private:
	
	public:
		Stack() : Stack(Container()) { }
		explicit Stack( const Container& cont = Container() )
		explicit Stack( Container&& cont );
		Stack( const Stack& other );
		Stack( Stack&& other );
		~Stack();

		Stack& operator=( const Stack& other );
		Stack& operator=( Stack&& other );

		reference top();
		const_reference top() const;
		
		bool empty() const;
		size_type size() const;

		void push( const value_type& value );
		void push( value_type&& value );
		void pop();
		// void swap( stack& other ) noexcept(/* see below */);
		
		bool operator==( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
		bool operator!=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
		bool operator<( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
		bool operator<=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
		bool operator>( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
		bool operator>=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
		std::compare_three_way_result_t<Container> operator<=>( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
};

#endif