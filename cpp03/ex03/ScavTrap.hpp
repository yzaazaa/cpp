#pragma once
#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include "ClapTrap.hpp" 

class ScavTrap : virtual public ClapTrap
{

public:
	void	guardGate() const;
	void	attack(const std::string &target);

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &scav);
	ScavTrap	&operator=(ScavTrap const &rhs);
	~ScavTrap();
};

#endif