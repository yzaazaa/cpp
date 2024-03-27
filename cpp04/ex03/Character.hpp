#pragma once
#ifndef __ICHARACTER_H__
# define __ICHARACTER_H__

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{

private:
	AMateria	*inventory[4];
	std::string	name;
	Character();

public:
	Character(std::string const &name);
	Character(Character const &character);
	Character	&operator=(Character const &rhs);
	~Character();
};

std::ostream	&operator<<(std::ostream &o, Character const &rhs);

#endif