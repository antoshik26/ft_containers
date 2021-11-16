#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP
#include <memory>
#include <iostream>
#include <string>
#include <cmath>

template<bool B>
struct 	enable_if
{};

template <>
struct enable_if<true> 
{
	typedef int type;
};

#endif