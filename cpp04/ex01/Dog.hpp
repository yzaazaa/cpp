#pragma once
#ifndef __DOG_H__
# define __DOG_H__

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{

private:
	Brain	*brain;

public:
	virtual void	makeSound() const;
	Dog();
	Dog(Dog const &dog);
	Dog	&operator=(Dog const &rhs);
	~Dog();
};


#endif