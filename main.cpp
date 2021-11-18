#include "./Map/Map.hpp"
#include "./Stack/Stack.hpp"
#include "./Vector/Vector.hpp"
#include "./Map/IteratorMap.hpp"
#include "./Map/Less.hpp"
#include "./Map/Pair.hpp"
#include "./Map2/RedBlackMap.hpp"
#include <vector>
#include <map>

// int main()
// {
// 	try
// 	{
// 		size_t i = 0;
// 		Vector<int> a(0);
// 		Vector<int> a2(15, 5);
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
// 		a.insert(c, 15, d[0]);
// 		c = a.end();
// 		a.insert(c, 26);
// 		c = a2.begin();
// 		b = a2.end();
// 		IteratorVector<int> c2;
// 		c2 = a.begin();
// 		a.insert(c2, c, b);
// 		std::cout << "Avter insert ";
// 		i = 0;
// 		std::cout <<  a.size() <<std::endl;
// 		while(i < a.size())
// 		{
// 			std::cout << a[i] << " ";
// 			i++;
// 		}
// 		std::cout << std::endl;
// 		c = a.begin();
// 		a.erase(c);
// 		c = a.begin();
// 		b = a.end();
// 		c++;
// 		b--;
// 		a.erase(c, b);
// 		std::cout << "Avter erase ";
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
// 	catch(std::exception& e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
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
		Pair<IteratorMap<int, int, less<int>, Map<int, int, less<int>, std::allocator<Pair<int, int> > >::Node_or_leaf_map>, IteratorMap<int, int, less<int>, Map<int, int, less<int>, std::allocator<Pair<int, int> > >::Node_or_leaf_map> > combo;
		
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
		for (size_t i = 0; i < a.size(); i++, d1++)
		{
			std::cout << "int i = " <<  i << " first = " <<  (*d1).first << " second = "  << (*d1).second << std::endl;
		}
		d3 = a.find(4);
		std::cout << (*d3).first << " " << (*d3).second << std::endl;
		a.erase(d3);
		d1 = a.begin();
		d2 = a.end();
		for (size_t i = 0; i < a.size(); i++, d1++)
		{
			std::cout << "int i = " <<  i << " first = " <<  (*d1).first << " second = "  << (*d1).second << std::endl;
		}
		std::cout << std::endl;
		a2 = a;
		d1 = a2.begin();
		d2 = a2.end();
		for (size_t i = 0; i != a2.size(); i++, d1++)
		{
			std::cout << "int i = " <<  i << " first = " <<  (*d1).first << " second = "  << (*d1).second << std::endl;
		}
		d1 = a.begin();
		d2 = a.end();
		std::cout << std::endl;
		a[5] = 3563;
		a[2] = 5678;
		for (size_t i = 0; i < a.size(); i++, d2--)
		{
			std::cout << "int i = " <<  i << " first = " <<  (*d2).first << " second = "  << (*d2).second << std::endl;
		}
		combo = a.equal_range(5);
		d3 = combo.first;
		std::cout << "first = " <<  (*d3).first << " second = "  << (*d3).second << std::endl;
		d3 = combo.second;
		std::cout << "first = " <<  (*d3).first << " second = "  << (*d3).second << std::endl;
		d3 = a.lower_bound(5);
		std::cout << "first = " <<  (*d3).first << " second = "  << (*d3).second << std::endl;
		d3 = a.upper_bound(5);
		std::cout << "first = " <<  (*d3).first << " second = "  << (*d3).second << std::endl;
		std::cout << "Value from key 7 = " << a.at(7) <<std::endl; 
		std::cout << "Size_map = " << a.size() << std::endl;
		std::cout << "Count elem in key 3 = " << a.count(3) << std::endl;
		if (a == a2)
			std::cout << "Map a равна Map a2" << std::endl;
		else
			std::cout << "Map a не равна Map a2" << std::endl;
		if (a != a2)
			std::cout << "Map a не равна Map a2" << std::endl;
		else
			std::cout << "Map a равна Map a2" << std::endl;
		if (a > a2)
			std::cout << "Map a больше Map a2" << std::endl;
		else
			std::cout << "Map a меньше Map a2" << std::endl;
		d1 = a.begin();
		d2 = a.end();
		a.erase(d1, d2);
		a2.clear();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}