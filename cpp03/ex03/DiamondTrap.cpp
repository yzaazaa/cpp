#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap()
{
	ClapTrap::name = "Bot_clap_name";
	this->name = "Bot";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &clap)
{
	*this = clap;
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs)
{
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called!" << std::endl;
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "name: " << this->name << ", claptrap name: " << ClapTrap::name << std::endl;
}