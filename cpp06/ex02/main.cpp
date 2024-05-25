#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base	*generate(void)
{
	srand(time(NULL));
	switch (std::rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The actual type of the object pointed to by p is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The actual type of the object pointed to by p is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The actual type of the object pointed to by p is C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A	&test = dynamic_cast<A&>(p);
		(void)test;
		std::cout << "The actual type of the object pointed to by p is A" << std::endl;
	}
	catch (const std::bad_cast& e)
	{
		try
		{
			B	&test = dynamic_cast<B&>(p);
			(void)test;
			std::cout << "The actual type of the object pointed to by p is B" << std::endl;
		}
		catch (const std::bad_cast& e)
		{
			try
			{
				C	&test = dynamic_cast<C&>(p);
			(void)test;
				std::cout << "The actual type of the object pointed to by p is C" << std::endl;
			}
			catch (const std::bad_cast& e) {}
		}
	}
}

int	main(void)
{
	Base	*generated = generate();
	identify(generated);
	identify(*generated);
	delete generated;
	return 0;
}