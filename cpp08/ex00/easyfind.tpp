#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T &container, int const to_find)
{
	typename T::iterator ret;

	ret = std::find(container.begin(), container.end(), to_find);
	if (ret == container.end())
		throw std::runtime_error("Element not found.");
	return ret;
}