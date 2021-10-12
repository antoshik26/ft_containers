// #include "Map.hpp"
// #include "Stack.hpp"
#include "./Vector/Vector.hpp"

int main()
{
	try
	{
		
		size_t i = 0;
		Vector<int> a(10);
		std::cout << "Vector empty " << a.empty() << std::endl;
		std::cout << "Vector max_size " << a.max_size() << std::endl;
		a.push_back(15);
		a.push_back(12);
		a.push_back(13);
		std::cout << "Vector empty " << a.empty() << std::endl;
		std::cout << "Vector size " << a.size() << std::endl;
		std::cout << "Vector data ";
		while ( i < a.size())
		{
			std::cout << a[i] << " ";
			i++;
		}
		std::cout << std::endl;
		std::cout << "Vector data through iterator ";
		IteratorVector<int> c;
		IteratorVector<int> b;
		c = a.begin();
		b = a.end();
		while(c != b)
		{
			std::cout << *c << " ";
			c++;
		}
		std::cout << std::endl;
		std::cout << "Insert in vetor " << std::endl;
		const int d[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		c = a.begin();
		c++;
		a.insert(c, 1, d[0]);
		std::cout << "Avter insert ";
		while(c != b)
		{
			std::cout << *c << " ";
			c++;
		}
		std::cout << std::endl;
		a.clear();
		i = 0;
		std::cout << "Vector data after clear ";
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