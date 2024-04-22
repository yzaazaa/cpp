#pragma once
#ifndef __CAT_H__
# define __CAT_H__

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{

private:
	Brain	*brain;

public:
	virtual void	makeSound() const;
	Cat();
	Cat(Cat const &cat);
	Cat	&operator=(Cat const &rhs);
	~Cat();
};


#endif