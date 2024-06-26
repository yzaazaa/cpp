#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

Character::Character()
{
	this->name = "Character";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(Character const &character)
{
	*this = character;
}

Character	&Character::operator=(Character const &rhs)
{
	this->name = rhs.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = 0;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (rhs.inventory[i])
			this->inventory[i] = rhs.inventory[i]->clone();
	}
	return (*this);
}

std::string const	&Character::getName() const
{
	return this->name;
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && this->inventory[idx])
		this->inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->inventory[idx])
		this->inventory[idx]->use(target);
}

std::ostream	&operator<<(std::ostream &o, Character const &rhs)
{
	return o << rhs.getName();
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}