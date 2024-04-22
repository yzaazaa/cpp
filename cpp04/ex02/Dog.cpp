#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(Dog const &dog)
{
	this->brain = NULL;
	*this = dog;
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	delete this->brain;
	this->brain = new Brain(*rhs.brain);
	this->type = rhs.getType();
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog sound." << std::endl;
}