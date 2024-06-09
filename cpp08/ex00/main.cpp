#include "easyfind.hpp"
#include <iostream>
#include <list>

int	main()
{
	std::list<int>	container;

	container.push_back(5);
	container.push_back(690);
	container.push_back(-199);
	container.push_back(420);

	try
	{
		std::list<int>::iterator	it = ::easyfind(container, 690);
		std::cout << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::list<int>::iterator	it = ::easyfind(container, 199);
		std::cout << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
