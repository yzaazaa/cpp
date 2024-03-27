#pragma once
#ifndef __ICE_H__
# define __ICE_H__

# include "AMateria.hpp"

class Ice : public AMateria
{

public:
	Ice();
	Ice(Ice const &ice);
	Ice	&operator=(Ice const &rhs);
	virtual ~Ice();

	virtual	AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};

#endif