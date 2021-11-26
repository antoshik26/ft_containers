#ifndef PAIT_HPP
#define PAIT_HPP
#include <iostream>
#include <memory>

template <typename A1, typename A2>
class Pair
{
	public:
		A1 first;
		A2 second;
	public:
		Pair()
		{
			first = 0;
			second = 0;
		}

		Pair(const A1 &v1, const A2 &v2)
		{
			first = v1;
			second = v2;
		}
		
		template <typename U, typename V>
		Pair(const Pair <U, V> &elem)
		{
			first = elem.first;
			second = elem.second;
		}

		~Pair()
		{
		}

		Pair& operator=(const Pair& assign)
		{
			if (this != &assign)
			{
				first = assign.first;
				second = assign.second;
			}
			return (*this);
		}

		Pair make_pair(const A1 &v1, const A2 &v2)
		{ 
			first = v1;
			second = v2;
			return (*this);
		}

		Pair operator->()
		{
			return (*this);
		}

		Pair operator*()
		{
			return (*this);
		}
};
#endif