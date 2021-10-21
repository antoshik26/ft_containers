#ifndef PAIT_HPP
#define PAIT_HPP
#include <iostream>
#include <memory>

template <typename A1, typename A2>
class Pair
{
	private:
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

		Pair(const Pair <A1, A2> &elem)
		{
			first = copy(elem.first);
			second = copy(elem.second);
		}

		~Pair()
		{
		}
		// make_pair
};
#endif