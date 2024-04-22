#include	"Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "\0";
	std::cout << "Brain constructor called!" << std::endl;
}

Brain::Brain(Brain const &brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain copy constructor called!" << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}