#ifndef REVERSITERATORVECTOR_HPP
#define REVERSITERATORVECTOR_HPP
#include <memory>
#include <iostream>
#include <string>

template<typename T>
class ReversIteratorVector
{
	private:
		T* obj;
	public:
		ReversIteratorVector();
		ReversIteratorVector(T* first);
		~ReversIteratorVector();
		T &operator+(int n);
		T &operator-(int n);
		T &operator++(int);
		T &operator--(int);
		T &operator++();
		T &operator--();

		bool operator!=(const ReversIteratorVector &it);
		bool operator==(const ReversIteratorVector &it);
		T &operator*();

};

#endif