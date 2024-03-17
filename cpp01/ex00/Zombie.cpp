#include "Zombie.hpp"

Zombie::Zombie()
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

Zombie::~Zombie()
{
	std::cout << this->name << ": died" << std::endl;
}
