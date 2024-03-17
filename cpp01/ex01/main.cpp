#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		n;

	n = 10;
	horde = zombieHorde(n, "10clan");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	n = 3;
	horde = zombieHorde(n, "3clan");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}