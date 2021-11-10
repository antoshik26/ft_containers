// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>

// int main()
// {
// 	std::vector<std::string> a;
// 	std::cout << a.max_size() << std::endl;
// 	std::cout << sizeof(std::string) << std::endl;
// 	return (0);
// }

// #include <iostream>
// #include <vector>
 
// int main()
// {
//     std::vector<int> data = { 1, 2, 4, 5, 5, 6 };
 
//     // Set element 1
//     data.at(1) = 88;
 
//     // Read element 2
//     std::cout << "Element at index 2 has value " << data.at(2) << '\n';
 
//     std::cout << "data size = " << data.size() << '\n';
 
//     try {
//         // Set element 6
//         data.at(6) = 666;
//     } catch (std::out_of_range const& exc) {
//         std::cout << exc.what() << '\n';
//     }
 
//     // Print final values
//     std::cout << "data:";
//     for (int elem : data)
//         std::cout << " " << elem;
//     std::cout << '\n';
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>

// template <typename T>
// int comp(T obj1, T obj2)
// {
// 	if (obj1 > obj2)
// 		return (1);
// 	if (obj1 < obj2)
// 		return (-1);
// 	if (obj1 == obj2)
// 		return (0);
// }

// int main()
// {
// 	std::string a = "asfdhghdsfg";
// 	std::string b = "asfdg";

// 	std::cout << comp(a, b) <<std::endl;
// 	return (0);
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
#include <string>
#include <complex>
#include <tuple>
#include <iostream>

int main()
{
	std::map<int, double> a;
	std::map<int, double> a2;
	std::pair<int, double> b(1, 1.1);
	std::pair<int, double> b2(1, 1.1);
	std::pair<int, double> c(4, 1.2);
	std::pair<int, double> c2(4, 1.2);
	std::pair<int, double> d(3, 1.1);
	std::pair<int, double> d2(3, 1.1);
	std::pair<int, double> e(5, 1.5);
	std::pair<int, double> e2(5, 1.5);
	a.insert(b);
	a.insert(c);
	a.insert(e);
	a.insert(d);
	a2.insert(b);
	a2.insert(c);
	a2.insert(e2);
	a2.insert(d);
	// std::cout << a << std::endl;
	// std::map<int, double>::iterator it2
	// std::map<int, double>::iterator it3;
	std::pair<std::map<int, double>::iterator, std::map<int, double>::iterator> count;
	count = a.equal_range(2);
	int j = 0;
	if (count.first == count.second)
	{
		std::cout << "asdfghjk" << std::endl;
		std::cout << count.first->first << " " << count.second->second << std::endl;
 	}
	while (count.first != count.second)
	{
		std::cout << j << " " << count.first->first << " " << count.second->second << std::endl;
		count.first++;
		j++;
	}
	std::map<int, double>::iterator it = a.begin();
	for (int i = 0; it != a.end(); it++, i++)
	{
		std::cout << i << " " << it->first << " " << it->second << std::endl; 
	}
	if (a == a2)
		std::cout << "равно" << std::endl;
	std::cout << a.max_size() << std::endl;
	std::cout << sizeof(double) << std::endl;
	std::cout << sizeof(int) << std::endl;
	return (0);
}