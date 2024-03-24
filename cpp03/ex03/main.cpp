#include "DiamondTrap.hpp"

int	main( void )
{
	ClapTrap	clap("clap");
	ScavTrap	scav("scav");
	FragTrap	frag("frag");
	DiamondTrap	diam("diam");

	clap.attack("target");
	scav.attack("clap");
	clap.takeDamage(20);
	scav.guardGate();
	frag.attack("target");
	frag.highFiveGuys();
	diam.attack("target");
	diam.whoAmI();
	return (0);
}