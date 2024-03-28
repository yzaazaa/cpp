#pragma once
#ifndef __ICE_H__
# define __ICE_H__

# include "AMateria.hpp"

class Ice : public AMateria
{

public:
	Ice();
	Ice(Ice const &ice);
	Ice(AMateria const &amateria);
	Ice	&operator=(Ice const &rhs);
	~Ice();

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif