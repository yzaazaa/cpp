#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	Animal* animal = new Animal();
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	WrongAnimal* wrongAnimal = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;
	return 0;
}