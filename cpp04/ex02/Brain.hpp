#pragma once
#ifndef __BRAIN_H__
# define __BRAIN_H__

# include <iostream>

class	Brain
{

private:
	std::string	ideas[100];

public:
	Brain();
	Brain(Brain const &brain);
	Brain	&operator=(Brain const &rhs);
	~Brain();
};

#endif