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
