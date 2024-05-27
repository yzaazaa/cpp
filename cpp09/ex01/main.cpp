#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string	expression(av[1]);
		RPN::calculate(expression);
	}
	else
		std::cerr << "Error: one argument needed." << std::endl;
	return 0;
}