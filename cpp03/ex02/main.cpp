#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	ClapTrap	clap("clap");
	ScavTrap	scav("scav");
	FragTrap	frag("frag");

	clap.attack("target");
	scav.attack("clap");
	clap.takeDamage(20);
	scav.guardGate();
	frag.attack("target");
	frag.highFiveGuys();
	return (0);
}