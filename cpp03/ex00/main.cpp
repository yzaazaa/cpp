#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	clap;
	ClapTrap	named_clap("clap");
	ClapTrap	copied_clap(clap);
	ClapTrap	copy_assignment_clap;
	
	copy_assignment_clap = named_clap;
	clap.attack("clap");
	named_clap.takeDamage(0);
	copy_assignment_clap.takeDamage(0);
	copied_clap.beRepaired(-6);
	clap.beRepaired(6);
	copy_assignment_clap.attack("Bot");
	clap.takeDamage(0);
	copied_clap.takeDamage(0);
	return (0);
}