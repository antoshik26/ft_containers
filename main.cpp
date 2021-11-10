#include "./Map/Map.hpp"
#include "./Stack/Stack.hpp"
#include "./Vector/Vector.hpp"
#include "./Map/IteratorMap.hpp"
#include "./Map/Less.hpp"
#include "./Map/Pair.hpp"
#include <map>

// int main()
// {
// 	try
// 	{
// 		size_t i = 0;
// 		Vector<int> a(10);
// 		std::cout << "Vector empty " << a.empty() << std::endl;
// 		std::cout << "Vector max_size " << a.max_size() << std::endl;
// 		a.push_back(15);
// 		a.push_back(12);
// 		a.push_back(13);
// 		std::cout << "Vector empty " << a.empty() << std::endl;
// 		std::cout << "Vector size " << a.size() << std::endl;
// 		std::cout << "Vector data ";
// 		while ( i < a.size())
// 		{
// 			std::cout << a[i] << " ";
// 			i++;
// 		}
// 		std::cout << std::endl;
// 		std::cout << "Vector data through iterator ";
// 		IteratorVector<int> c;
// 		IteratorVector<int> b;
// 		c = a.begin();
// 		b = a.end();
// 		while(c != b)
// 		{
// 			std::cout << *c << " ";
// 			c++;
// 		}
// 		std::cout << std::endl;
// 		std::cout << "Insert in vetor " << std::endl;
// 		const int d[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// 		c = a.begin();
// 		c++;
// 		a.insert(c, 2, d[0]);
// 		std::cout << "Avter insert ";
// 		i = 0;
// 		std::cout <<  a.size() <<std::endl;
// 		while(i < a.size())
// 		{
// 			std::cout << a[i] << " ";
// 			i++;
// 		}
// 		std::cout << std::endl;
// 		a.clear();
// 		i = 0;
// 		std::cout << "Vector data after clear ";
// 		while ( i < a.size())
// 		{
// 			std::cout << a[i] << " ";
// 			i++;
// 		}
// 		std::cout << std::endl;

// 		// a.reserve(a.max_size() + 1);
// 	}
	// catch(std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
// 	return(0);
// }

int main()
{
	try
	{
		Map<int, int> a;
		Map<int, int> a2;
		std::map<int, int> b;

		// Pair</*const*/ int, int> c1;
		// Pair</*const*/ int, int> c2(50000000, 1);
		const Pair</*const*/ int, int> c1(4, 1);
		const Pair</*const*/ int, int> c2(3, 2);
		const Pair</*const*/ int, int> c3(5, 3);
		const Pair</*const*/ int, int> c4(2, 4);
		const Pair</*const*/ int, int> c5(1, 5);
		const Pair</*const*/ int, int> c6(6, 6);
		const Pair</*const*/ int, int> c7(7, 7);
		// a.insert(c2);
		// for (int i = 0; i < 50; i++)
		// {
		// 	c1.first = rand();
		// 	c1.second = rand();
		// 	a.insert(c1);
		// }
		// Pair<IteratorMap<int, int, less<int>, void*>, bool> ret;
		IteratorMap<int, int, less<int>, Map<int, int, less<int>, std::allocator<Pair<int, int> > >::Node_or_leaf_map> d1;
		IteratorMap<int, int, less<int>, Map<int, int, less<int>, std::allocator<Pair<int, int> > >::Node_or_leaf_map> d2;
		IteratorMap<int, int, less<int>, Map<int, int, less<int>, std::allocator<Pair<int, int> > >::Node_or_leaf_map> d3;
		
		std::cout << a.max_size() << std::endl;
		std::cout << b.max_size() << std::endl;
		a.insert(c1);
		a.insert(c2);
		a.insert(c3);
		a.insert(c4);
		a.insert(c5);
		a.insert(c6);
		a.insert(c7);
		d1 = a.begin();
		d2 = a.end();
		d3 = a.find(6);
		std::cout << (*d3).first << " " << (*d3).second << std::endl;
		a.erase(d3);
		// for (int i = 0; d1 != d2; i++, d1++)
		{
			std::cout << (*d1).first << " "  << (*d1).second << std::endl;
		}
		a2 = a;
		// d1 = a2.begin();
		// d2 = a2.end();
		// for (int i = 0; d1 != d2; i++, d1++)
		// {
		// 	std::cout << (*d1).first << " "  << (*d1).second << std::endl;
		// }
		std::cout << a.size() << std::endl;
		std::cout << a.count(3) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}