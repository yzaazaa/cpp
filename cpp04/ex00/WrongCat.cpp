#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called!" << std::endl;
}

WrongCat::WrongCat(WrongCat const &wrongCat)
{
	*this = wrongCat;
	std::cout << "WrongCat copy constructor called!" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat sound." << std::endl;
}