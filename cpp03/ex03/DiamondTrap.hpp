#pragma once
#ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap: public FragTrap, public ScavTrap
{

private:
	std::string	name;

public:
	void	whoAmI() const;
	void	attack(const std::string &target);

	DiamondTrap();	
	DiamondTrap(std::string name);	
	DiamondTrap(DiamondTrap const &diam);
	DiamondTrap	&operator=(DiamondTrap const &rhs);
	~DiamondTrap();	
};

#endif