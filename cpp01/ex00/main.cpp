#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie_allocated;

	zombie_allocated = newZombie("zombie_allocated");
	zombie_allocated->announce();
	randomChump("randomChump");
	delete zombie_allocated;
	return (0);
}