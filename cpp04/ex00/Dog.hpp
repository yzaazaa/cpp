#pragma once
#ifndef __DOG_H__
# define __DOG_H__

# include "Animal.hpp"

class Dog : public Animal
{

public:
	void	makeSound() const;
	Dog();
	Dog(Dog const &dog);
	Dog	&operator=(Dog const &rhs);
	~Dog();
};


#endif