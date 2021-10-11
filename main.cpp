// #include "Map.hpp"
// #include "Stack.hpp"
#include "./Vector/Vector.hpp"

int main()
{
	try
	{
		size_t i = 0;
		Vector<int> a(10);
		// std::cout << a.max_size() << std::endl;
		a.push_back(15);
		a.push_back(12);
		a.push_back(13);
		std::cout << a.size() << std::endl;
		while ( i < a.size())
		{
			std::cout << a[i] << " ";
			i++;
		}
		std::cout << std::endl;
		a.clear();
		i = 0;
		while ( i < a.size())
		{
			std::cout << a[i] << " ";
			i++;
		}
		std::cout << std::endl;
		// a.reserve(a.max_size() + 1);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return(0);
}