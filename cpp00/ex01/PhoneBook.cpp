#include "PhoneBook.hpp"
#include <iomanip>
#include <string>
#include <limits>
#include <sstream>

PhoneBook::PhoneBook()
{
	this->index = 0;
}

std::string	truncate(std::string str)
{
	if(str.length() > 10)
		return str.substr(0, 9) + '.';
	return str;
}

void	PhoneBook::print()
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::left << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::left << std::setw(10) << truncate(contacts[i].first_name);
		std::cout << "|";
		std::cout << std::left << std::setw(10) << truncate(contacts[i].last_name);
		std::cout << "|";
		std::cout << std::left << std::setw(10) << truncate(contacts[i].nickname);
		std::cout << "\0";
		std::cout << std::endl;
	}
}

void	PhoneBook::add()
{
	std::cout << "First Name: ";
	std::string	firstName;
	if (getline(std::cin, firstName).eof())
		puterr();
	std::cout << "Last Name: ";
	std::string	lastName;
	if (getline(std::cin, lastName).eof())
		puterr();
	std::cout << "Nickname: ";
	std::string	nickname;
	if (getline(std::cin, nickname).eof())
		puterr();
	std::cout << "Phone Number: ";
	std::string	phoneNumber;
	if (getline(std::cin, phoneNumber).eof())
		puterr();
	while (!check_phone_number(phoneNumber))
	{
		std::cout << "Phone number not valid!" << std::endl << "Phone Number: ";
		if (getline(std::cin, phoneNumber).eof())
			puterr();
	}

	std::cout << "Darkest Secret: ";
	std::string	darkestSecret;
	if (getline(std::cin, darkestSecret).eof())
		puterr();
	if (this->index == 8)
		this->index = 0;
	this->contacts[this->index++] = Contact(firstName, lastName
											,nickname, phoneNumber
											, darkestSecret);
}

void	PhoneBook::search()
{
	std::string	index;
	int i;

	this->print();
	std::cout << "Enter the index of the entry to display: ";
	if (getline(std::cin, index).eof())
		puterr();
	std::stringstream o(index);
	if (!(o >> i) || i  < 0 || i > 7)
	{
		std::cout << "Wrong index." << std::endl;
		return ;
	}
	if (check_empty(contacts[i]))
	{
		std::cout << "Index empty." << std::endl;
		return ;
	}
	std::cout << std::left << std::setw(14) << "First name";
	std::cout << ": " << contacts[i].first_name << std::endl;
	std::cout << std::left << std::setw(14) << "Last name";
	std::cout << ": " << contacts[i].last_name << std::endl;
	std::cout << std::left << std::setw(14) << "Nickname";
	std::cout << ": " << contacts[i].nickname << std::endl;
	std::cout << std::left << std::setw(14) << "Phone number";
	std::cout << ": " << contacts[i].phone_number << std::endl;
	std::cout << std::left << std::setw(14) << "Darkest secret";
	std::cout << ": " << contacts[i].phone_number << std::endl;
}