#pragma once
#ifndef __ANIMAL_H__
# define __ANIMAL_H__

# include <iostream>

class Animal
{

protected:
	std::string	type;
	Animal();
	Animal(Animal const &animal);

public:
	virtual void	makeSound() const;
	std::string		getType() const;

	Animal	&operator=(Animal const &rhs);
	virtual ~Animal();
};


#endif