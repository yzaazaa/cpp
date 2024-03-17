#include "Weapon.hpp"

Weapon::Weapon() : type("")
{
	return ;
}

Weapon::Weapon(std::string type) : type(type)
{
	return ;
}

const std::string	&Weapon::getType(void)
{
	std::string	&ref = this->type;
	return ref;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}