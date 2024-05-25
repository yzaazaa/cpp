#include "iter.hpp"
#include <iostream>

void	ft_inc(int &i)
{
	i++;
}

void	ft_add_a(std::string &str)
{
	str += "a";
}

int	main(void)
{
	int	int_array[5] = {0, 1, 2, 3, 4};
	std::string	str_array[3] = {"Hello", "World", "1337"};

	std::cout << "int array: " << std::endl;
	::iter(int_array, 5, print<int>);
	std::cout << "string array: " << std::endl;
	::iter(str_array, 3, print<std::string>);
	std::cout << "int array: " << std::endl;
	::iter(int_array, 5, ft_inc);
	::iter(int_array, 5, print<int>);
	std::cout << "string array: " << std::endl;
	::iter(str_array, 3, ft_add_a);
	::iter(str_array, 3, print<std::string>);
}