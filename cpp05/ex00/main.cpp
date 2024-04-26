#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	b1;
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		Bureaucrat	b2("bot", 1);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		Bureaucrat	b3("bo2", 50);
		b3 = b2;
		std::cout << b3 << std::endl;
		Bureaucrat	b4("bot3", 161);
		std::cout << b4 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b1("bot", 0);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}