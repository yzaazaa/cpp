#pragma once
#ifndef __AMATERIA_H__
# define __AMATERIA_H__

# include <iostream>

class ICharacter;

class AMateria
{

private:
	AMateria();

protected:
	std::string	type;

public:
	AMateria(std::string const &type);
	AMateria(AMateria const &materia);
	AMateria	&operator=(AMateria const &rhs);
	virtual ~AMateria();

	std::string	const	&getType() const;

	virtual	AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};


#endif