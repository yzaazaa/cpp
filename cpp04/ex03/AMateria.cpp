#include "AMateria.hpp"

AMateria::AMateria()
{
	return ;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria constructor called!" << std::endl;
}

AMateria::AMateria(AMateria const &materia) : type(materia.type)
{
	std::cout << "AMateria copy constructor called!" << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	this->type = rhs.getType();
	return (*this);
}

std::string	const	&AMateria::getType() const
{
	return this->type;
}


AMateria::~AMateria()
{
	std::cout << "AMateria destructor called!" << std::endl;
}