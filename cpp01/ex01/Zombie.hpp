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
	void	setName(std::string name);

	Zombie();
	Zombie(std::string zombieName);
	~Zombie();
};

Zombie	*zombieHorde(int N, std::string name);

#endif