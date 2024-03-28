#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(AMateria const &materia) : type(materia.type) {}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	this->type = rhs.getType();
	return (*this);
}

std::string	const	&AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria used at " << target.getName() << " *" << std::endl;
}


AMateria::~AMateria() {}