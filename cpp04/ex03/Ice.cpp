#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called!" << std::endl;
}

Ice::Ice(Ice const &ice) : AMateria(ice)
{
	*this = ice;
	std::cout << "Ice copy constructor called!" << std::endl;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	this->type = rhs.getType();
	return (*this);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	AMateria::clone() const
{
	return (new Ice(*this));
}

Ice::~Ice()
{
	std::cout << "Ice destructor called!" << std::endl;
}