#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &cure) : AMateria(cure.getType()) {}

Cure	&Cure::operator=(Cure const &rhs)
{
	this->type = rhs.getType();
	return (*this);
}

AMateria*	Cure::clone() const
{
	AMateria	*ret = new Cure(*this);
	return (ret);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure() {}