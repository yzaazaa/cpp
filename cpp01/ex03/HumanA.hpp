#pragma once
# ifndef __HUMANA_H__
# define __HUMANA_H__

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
private:
	std::string	name;
	Weapon	&weapon;

public:
	void	attack();
	HumanA(std::string name, Weapon &weapon);
};

#endif
