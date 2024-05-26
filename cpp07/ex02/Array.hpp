#pragma once

template <typename T>
class Array
{
private:
	T			*arr;
	unsigned int len;
public:
	unsigned int	size() const;

	Array();
	Array(Array const &arr);
	Array(unsigned int const n);
	Array	&operator=(Array const &rhs);
	T	&operator[](unsigned int i);
	~Array();
};

#include "Array.tpp"