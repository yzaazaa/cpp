#pragma once
#ifndef __WRONGANIMAL_H__
# define __WRONGANIMAL_H__

# include <iostream>

class WrongAnimal
{

protected:
	std::string	type;

public:
	void	makeSound() const;
	std::string		getType() const;

	WrongAnimal();
	WrongAnimal(WrongAnimal const &wrongAnimal);
	WrongAnimal	&operator=(WrongAnimal const &rhs);
	virtual ~WrongAnimal();
};


#endif