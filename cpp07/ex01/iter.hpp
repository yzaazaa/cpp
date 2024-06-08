#pragma once

#include <iostream>

template <typename LIST, typename FUNC>
void	iter(LIST *arr, int size, FUNC f)
{
	for (int i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void	print(T &var)
{
	std::cout << var << std::endl;
}
