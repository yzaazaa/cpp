#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

static void	allocate(const Animal *animals[], int nb_animals)
{
	for (int i = 0; i < nb_animals; i++)
	{
		if (i < nb_animals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
}

static void	make_sound(const Animal *animals[], int nb_animals)
{
	for (int i = 0; i < nb_animals; i++)
		animals[i]->makeSound();
}

static void	deallocate(const Animal *animals[], int nb_animals)
{
	for (int i = 0; i < nb_animals; i++)
		delete animals[i];
}

int	main()
{
	const int		nb_animals = 4;
	const Animal	*animals[nb_animals];

	allocate(animals, nb_animals);
	make_sound(animals, nb_animals);
	deallocate(animals, nb_animals);
	Dog basic;
	{
	Dog tmp = basic;
	}
	return 0;
}