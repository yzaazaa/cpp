#pragma once
#ifndef __CHARACTER_H__
# define __CHARACTER_H__

# include <iostream>
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

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

std::ostream	&operator<<(std::ostream &o, Character const &rhs);

#endif