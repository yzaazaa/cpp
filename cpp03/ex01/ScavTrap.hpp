#pragma once
#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include "ClapTrap.hpp" 

class ScavTrap : public ClapTrap
{

public:
	void	guardGate() const;

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &scav);
	ScavTrap	&operator=(ScavTrap const &rhs);
	~ScavTrap();
};

#endif