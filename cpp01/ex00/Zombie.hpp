#pragma once
#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <iostream>

class Zombie
{

private:
	std::string name;

public:
	void	announce( void );

	Zombie();
	Zombie(std::string zombieName);
	~Zombie();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif