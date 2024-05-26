#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->arr = new T[0];
	this->len = 0;
}

template <typename T>
Array<T>::Array(unsigned int const n)
{
	this->arr = new T[n];
	this->len = n;
}

template <typename T>
Array<T>::Array(Array const &arr)
{
	*this = arr;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &rhs)
{
	this->len = rhs.len;
	this->arr = new T[this->len];
	for (unsigned int i = 0; i < this->len; i++)
		this->arr[i] = rhs.arr[i];
	return *this;
}

template <typename T>
T	&Array<T>::operator[](unsigned int i)
{
	if (i < 0 || i >= this->len)
		throw std::out_of_range("Index out of bounds");
	return this->arr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->arr;
	this->len = 0;
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return this->len;
}
