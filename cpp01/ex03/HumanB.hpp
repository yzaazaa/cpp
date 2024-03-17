#pragma once
# ifndef __HUMANB_H__
# define __HUMANB_H__

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
private:
	std::string	name;
	Weapon	*weapon;

public:
	void	setWeapon(Weapon &weapon);
	void	attack();
	HumanB();
	HumanB(std::string name);
};

#endif
