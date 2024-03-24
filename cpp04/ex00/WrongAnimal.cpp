#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimal)
{
	*this = wrongAnimal;
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}