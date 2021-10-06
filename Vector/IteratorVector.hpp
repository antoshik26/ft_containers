#ifndef ITERATORVECTOR_HPP
#define ITERATORVECTOR_HPP
#include <memory>
#include <iostream>
#include <string>

template<typename T>
class IteratorVector
{
	private:
		T* obj;
	public:
		IteratorVector();
		IteratorVector(T* first);
		~IteratorVector();
		T &operator+(int n);
		T &operator-(int n);
		T &operator++(int);
		T &operator--(int);
		T &operator++();
		T &operator--();

		bool operator!=(const IteratorVector &it);
		bool operator==(const IteratorVector &it);
		T &operator*();
};

#endif