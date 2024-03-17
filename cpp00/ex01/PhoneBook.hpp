#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:
	int		index;
	Contact	contacts[8];
	void	print();

public:
	PhoneBook();

	void	add();
	void	search();
};

void	puterr();
int		check_empty(Contact contact);
int		check_phone_number(std::string phoneNumber);
int		is_full_spaces(std::string str);
void	get_line(std::string &str, std::string name);

#endif