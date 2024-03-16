#include <iostream>
#include <string>

void	print_uppercase(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		std::cout << (char)toupper(str[i]);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		print_uppercase(str);
	}
	std::cout << std::endl;
	return (0);
}