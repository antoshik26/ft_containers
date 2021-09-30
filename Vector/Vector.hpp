#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <string>

template <typename Type>
class Vector
{
	private:
		
	public:
		Vector();
		Vector(const int n);
		~Vector();
		Vector &operator=(const Vector obj);
		bool &operator!=(const Vector obj1, const Vector obj2);
		bool &operator==(const Vector obj1, const Vector obj2);
		bool &operator<(const Vector obj1, const Vector obj2);
		bool &operator>(const Vector obj1, const Vector obj2);
		bool &operator<=(const Vector obj1, const Vector obj2);
		bool &operator>=(const Vector obj1, const Vector obj2);
};

#endif