#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Bot"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clap) : name(clap.name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap copy constructor called!" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called!" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints && this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints)
	{
		if ((int)amount < 0)
		{
			std::cout << "Amount cannot be negative." << std::endl;
			return ;
		}
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
		if (this->hitPoints < (int)amount)
			amount = hitPoints;
		this->hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints && this->energyPoints)
	{
		if ((int)amount < 0)
		{
			std::cout << "Amount cannot be negative." << std::endl;
			return ;
		}
		std::cout << "ClapTrap " << this->name << " gets " << amount << " hit points back!" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
}