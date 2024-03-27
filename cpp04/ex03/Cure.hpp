#pragma once
#ifndef __CURE_H__
# define __CURE_H__

# include "AMateria.hpp"

class Cure : public AMateria
{

public:
	Cure();
	Cure(Cure const &cure);
	Cure	&operator=(Cure const &rhs);
	~Cure();
};

#endif