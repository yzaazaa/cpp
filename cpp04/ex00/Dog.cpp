#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(Dog const &dog)
{
	*this = dog;
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog sound." << std::endl;
}