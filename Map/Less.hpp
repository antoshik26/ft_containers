#ifndef LESS_HPP
#define LESS_HPP
#include "Pair.hpp"

namespace ft
{
	template <typename A1, typename A2>
	class Pair;

	template<class T >
	struct less
	{ 
		int operator() (const T& obj1, const T& obj2) const
		{
			if (obj1 > obj2)
				return (1);
			if (obj1 < obj2)
				return (-1);
			return (0);
		}
	};
}
#endif