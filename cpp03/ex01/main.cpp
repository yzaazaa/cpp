#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	clap("clap");
	ScavTrap	scav("scav");

	clap.attack("target");
	scav.attack("clap");
	clap.takeDamage(20);
	scav.guardGate();
	return (0);
}