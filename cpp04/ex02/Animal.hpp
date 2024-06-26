#pragma once
#ifndef __ANIMAL_H__
# define __ANIMAL_H__

# include <iostream>

class Animal
{

protected:
	std::string	type;
	
public:
	virtual void	makeSound() const = 0;
	std::string		getType() const;

	Animal();
	Animal(Animal const &animal);
	Animal	&operator=(Animal const &rhs);
	virtual ~Animal();
};


#endif