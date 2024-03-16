#include "PhoneBook.hpp"

int	check_phone_number(std::string phoneNumber)
{
	int	i = 0;

	if (phoneNumber[i] == '+')
		i++;
	while (isdigit(phoneNumber[i]))
		i++;
	if (phoneNumber[i])
		return (0);
	return (1);
}

void	puterr()
{
	std::cout << "ERROR!" << std::endl;
	exit(1);
}

int	check_empty(Contact contact)
{
	if (contact.darkest_secret == "EMPTY" && contact.first_name == "EMPTY"
		&& contact.last_name == "EMPTY" && contact.nickname == "EMPTY"
		&& contact.phone_number == "EMPTY")
		return (1);
	return (0);
}