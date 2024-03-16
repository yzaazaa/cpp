#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook 	book;
	std::string	input;
	while (420)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (getline(std::cin, input).eof())
			break ;
		if (input == "ADD")
			book.add();
		if (input == "SEARCH")
			book.search();
		if (input == "EXIT")
			break ;
	}
	return (0);
}