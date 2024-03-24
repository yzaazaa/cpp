#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(Cat const &cat)
{
	*this = cat;
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat sound." << std::endl;
}