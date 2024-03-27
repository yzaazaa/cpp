#include "Character.hpp"

Character::Character()
{
	return ;
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	std::cout << "Character constructor called!" << std::endl;
}

Character::Character(Character const &character)
{
	*this = character;
	std::cout << "Character copy constructor called!" << std::endl;
}

Character	&Character::operator=(Character const &rhs)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = new AMateria(rhs);
}

std::string const	&ICharacter::getName() const
{
	return this->name;
}


std::ostream	&operator<<(std::ostream &o, Character const &rhs)
{
	return o << rhs.getName();
}

Character::~Character()
{
	std::cout << "Character destructor called!" << std::endl;
}