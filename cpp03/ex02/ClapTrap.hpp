#pragma once
#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include <iostream>

class ClapTrap
{

protected:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

public:
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &clap);
	ClapTrap	&operator=(ClapTrap const &rhs);
	~ClapTrap();
};

#endif