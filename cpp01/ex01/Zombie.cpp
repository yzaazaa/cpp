#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
	return ;
}

Zombie::Zombie(std::string zombieName) : name(zombieName)
{
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << ": died" << std::endl;
}
