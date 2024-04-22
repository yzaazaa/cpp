#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(Cat const &cat)
{
	this->brain = NULL;
	*this = cat;
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	delete this->brain;
	this->brain = new Brain(*rhs.brain);
	this->type = rhs.getType();
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat sound." << std::endl;
}