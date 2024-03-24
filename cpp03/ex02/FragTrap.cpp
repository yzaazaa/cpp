#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor called!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &clap)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
	*this = clap;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called!" << std::endl;
}

void	FragTrap::highFiveGuys(void) const
{
	std::cout << "FragTrap " << this->name << " asking for high fives!" << std::endl;
}