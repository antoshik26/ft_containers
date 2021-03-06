#include "./Map/map.hpp"
#include "./Stack/stack.hpp"
#include "./Vector/vector.hpp"
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
// 		ft::vector<int> a(0);
// 		ft::vector<int> a2(15, 5);
// 		ft::vector<int> a3(0);
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
// 		ft::IteratorVector<int> c;
// 		ft::IteratorVector<int> b;
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
// 		ft::IteratorVector<int> c2;
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

// int main()
// {
// 	try
// 	{
// 		ft::map<int, int> a;
// 		ft::map<int, int> a2;
// 		std::map<int, int> b;

// 		// Pair</*const*/ int, int> c1;
// 		// Pair</*const*/ int, int> c2(50000000, 1);
// 		const ft::Pair< int, int> c1(4, 1);
// 		const ft::Pair<int, int> c2(3, 2);
// 		const ft::Pair<int, int> c3(5, 3);
// 		const ft::Pair<int, int> c4(2, 4);
// 		const ft::Pair<int, int> c5(1, 5);
// 		const ft::Pair< int, int> c6(6, 6);
// 		const ft::Pair< int, int> c7(7, 7);
// 		const ft::Pair< int, int> c8(8, 7);
// 		const ft::Pair< int, int> c9(9, 7);
// 		const ft::Pair< int, int> c10(10, 7);
// 		const ft::Pair< int, int> c11(11, 7);
// 		const ft::Pair< int, int> c12(12, 7);
// 		const ft::Pair<int, int> c13(13, 7);
// 		const ft::Pair<int, int> c14(14, 7);
// 		// a.insert(c2);
// 		// for (int i = 0; i < 50; i++)
// 		// {
// 		// 	c1.first = rand();
// 		// 	c1.second = rand();
// 		// 	a.insert(c1);
// 		// }
// 		// Pair<IteratorMap<int, int, less<int>, void*>, bool> ret;
// 		// ft::map::iterator d4;
// 		ft::IteratorMap<int, int, ft::less<int>, ft::map<int, int, ft::less<int>, std::allocator<ft::Pair<int, int> > >::Node_or_leaf_map> d1;
// 		ft::IteratorMap<int, int, ft::less<int>, ft::map<int, int, ft::less<int>, std::allocator<ft::Pair<int, int> > >::Node_or_leaf_map> d2;
// 		ft::IteratorMap<int, int, ft::less<int>, ft::map<int, int, ft::less<int>, std::allocator<ft::Pair<int, int> > >::Node_or_leaf_map> d3;
// 		ft::Pair<ft::IteratorMap<int, int, ft::less<int>, ft::map<int, int, ft::less<int>, std::allocator<ft::Pair<int, int> > >::Node_or_leaf_map>, ft::IteratorMap<int, int, ft::less<int>, ft::map<int, int, ft::less<int>, std::allocator<ft::Pair<int, int> > >::Node_or_leaf_map> > combo;
// 		std::cout << a.max_size() << std::endl;
// 		std::cout << b.max_size() << std::endl;
// 		a.insert(c1);
// 		a.insert(c2);
// 		a.insert(c3);
// 		a.insert(c4);
// 		a.insert(c5);
// 		a.insert(c6);
// 		a.insert(c7);
// 		d1 = a.begin();
// 		d2 = a.end();
// 		for (size_t i = 0; i < a.size(); i++, d1++)
// 		{
// 			std::cout << "int i = " <<  i << " first = " <<  (*d1).first << " second = "  << (*d1).second << std::endl;
// 		}
// 		d3 = a.find(4);
// 		std::cout << (*d3).first << " " << (*d3).second << std::endl;
// 		a.erase(d3);
// 		d1 = a.begin();
// 		d2 = a.end();
// 		std::cout << "erase key 4" << std::endl;
// 		for (size_t i = 0; i < a.size(); i++, d1++)
// 		{
// 			std::cout << "int i = " <<  i << " first = " <<  (*d1).first << " second = "  << (*d1).second << std::endl;
// 		}
// 		std::cout << std::endl;
// 		a2 = a;
// 		a2.insert(c8);
// 		a2.insert(c9);
// 		a2.insert(c10);
// 		a2.insert(c11);
// 		a2.insert(c12);
// 		a2.insert(c13);
// 		a2.insert(c14);
// 		d1 = a2.begin();
// 		d2 = a2.end();
// 		a.insert(d1, d2);
// 		std::cout << "a2" << std::endl;
// 		for (size_t i = 0; i != a2.size(); i++, d1++)
// 		{
// 			std::cout << "int i = " <<  i << " first = " <<  (*d1).first << " second = "  << (*d1).second << std::endl;
// 		}
// 		std::cout << std::endl;
// 		d1 = a.begin();
// 		d2 = a.end();
// 		std::cout << "a1" << std::endl;
// 		for (size_t i = 0; i != a.size(); i++, d1++)
// 		{
// 			std::cout << "int i = " <<  i << " first = " <<  (*d1).first << " second = "  << (*d1).second << std::endl;
// 		}
// 		std::cout << std::endl;
// 		a[5] = 3563;
// 		a[2] = 5678;
// 		d2 = a.end();
// 		for (size_t i = 0; i < a.size(); i++, d2--)
// 		{
// 			std::cout << "int i = " <<  i << " first = " <<  (*d2).first << " second = "  << (*d2).second << std::endl;
// 		}
// 		combo = a.equal_range(5);
// 		d3 = combo.first;
// 		std::cout << "first = " <<  (*d3).first << " second = "  << (*d3).second << std::endl;
// 		d3 = combo.second;
// 		std::cout << "first = " <<  (*d3).first << " second = "  << (*d3).second << std::endl;
// 		d3 = a.lower_bound(5);
// 		std::cout << "first = " <<  (*d3).first << " second = "  << (*d3).second << std::endl;
// 		d3 = a.upper_bound(5);
// 		std::cout << "first = " <<  (*d3).first << " second = "  << (*d3).second << std::endl;
// 		std::cout << "Value from key 7 = " << a.at(7) <<std::endl; 
// 		std::cout << "Size_map = " << a.size() << std::endl;
// 		std::cout << "Count elem in key 3 = " << a.count(3) << std::endl;
// 		if (a == a2)
// 			std::cout << "Map a ?????????? Map a2" << std::endl;
// 		else
// 			std::cout << "Map a ???? ?????????? Map a2" << std::endl;
// 		if (a != a2)
// 			std::cout << "Map a ???? ?????????? Map a2" << std::endl;
// 		else
// 			std::cout << "Map a ?????????? Map a2" << std::endl;
// 		if (a > a2)
// 			std::cout << "Map a ???????????? Map a2" << std::endl;
// 		else
// 			std::cout << "Map a ???????????? Map a2" << std::endl;
// 		d1 = a.begin();
// 		d2 = a.end();
// 		a.erase(d1, d2);
// 		a2.clear();
// 	}
// 	catch(std::exception& e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	return (0);
// }

// int main() 
// {
// 	ft::RedBlackmap<int, int> bst;
// 	ft::Pair<int, int> c1;
// 	ft::IteratorRedBlackMap<int, int, ft::less<int>, ft::RedBlackmap<int, int, ft::less<int>, std::__1::allocator<std::__1::pair<int, int> > >::Node> it;
	
	// c1.first = 55;
	// c1.second = 1234;
	// bst.insert(c1);
	// c1.first = 40;
	// c1.second = 1234;
	// bst.insert(c1);
	// c1.first = 65;
	// c1.second = 1234;
	// bst.insert(c1);
	// c1.first = 60;
	// c1.second = 1234;
	// bst.insert(c1);
	// c1.first = 75;
	// c1.second = 1234;
	// bst.insert(c1);
	// c1.first = 57;
	// c1.second = 1234;
	// bst.insert(c1);
	// c1.first = 56;
	// c1.second = 1234;
	// bst.insert(c1);
	// c1.first = 58;
	// c1.second = 1234;
// 	// bst.insert(c1);
// 	for (int i = 0; i < 50; i++)
// 	{
// 		c1.first = rand();
// 		c1.second = rand();
// 		bst.insert(c1);
// 	}

// 	it = bst.begin();
// 	bst.printTree();
// 	std::cout << std::endl
// 		<< "After deleting" << std::endl;
// 	bst.erase(it);
//  	bst.printTree();
// }