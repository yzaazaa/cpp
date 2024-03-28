#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &ice) : AMateria(ice)
{
	*this = ice;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	this->type = rhs.getType();
	return (*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

Ice::~Ice() {}