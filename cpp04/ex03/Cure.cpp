#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called!" << std::endl;
}

Cure::Cure(Cure const &cure) : AMateria(cure.getType())
{
	std::cout << "Cure copy constructor called!" << std::endl;
}

Cure	&Cure::operator=(Cure const &rhs)
{
	this->type = rhs.getType();
	return (*this);
}

AMateria*	AMateria::clone() const
{
	AMateria	*ret = new Cure(*this);
	return (ret);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called!" << std::endl;
}