#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &clap)
{
	std::cout << "ScavTrap copy constructor called!" << std::endl;
	*this = clap;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called!" << std::endl;
}

void	ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << this->name << " is in Gate keeper mode!" << std::endl;
}