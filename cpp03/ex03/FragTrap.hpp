#pragma once
#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

public:
	void	highFiveGuys(void) const;

	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const &frag);
	FragTrap	&operator=(FragTrap const &rhs);
	~FragTrap();
};


#endif