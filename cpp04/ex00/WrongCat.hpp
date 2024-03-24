#pragma once
#ifndef __WRONGCAT_H__
# define __WRONGCAT_H__

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	void	makeSound() const;
	WrongCat();
	WrongCat(WrongCat const &wrongCat);
	WrongCat	&operator=(WrongCat const &rhs);
	~WrongCat();
};


#endif