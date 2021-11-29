#ifndef PAIT_HPP
#define PAIT_HPP
#include <iostream>
#include <memory>

namespace ft
{
	template <typename A1, typename A2>
	class Pair
	{
		public:
			A1 first;
			A2 second;
		public:
			Pair()
			{
				first = static_cast<A1>(0);
				second = static_cast<A2>(0);
			}

			Pair(const A1 &v1, const A2 &v2)
			{
				first = static_cast<A1>(v1);
				second = static_cast<A2>(v2);
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
}
#endif