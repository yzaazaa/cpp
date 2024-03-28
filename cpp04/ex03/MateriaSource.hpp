#pragma once
#ifndef __MATERIASOURCE_H__
# define __MATERIASOURCE_H__

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

private:
	AMateria	*inventory[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &materiaSource);
	MateriaSource	&operator=(MateriaSource const &rhs);
	~MateriaSource();
	void learnMateria(AMateria *);
	AMateria* createMateria(std::string const &type);
};

#endif