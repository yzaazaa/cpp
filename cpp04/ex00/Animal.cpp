#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal(Animal const &animal)
{
	*this = animal;
	std::cout << "Animal copy constructor called!" << std::endl;
}

Animal	&Animal::operator=(Animal const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType() const
{
	return this->type;
}