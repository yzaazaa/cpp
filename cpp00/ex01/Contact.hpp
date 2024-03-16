#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
public:
	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	Contact();
	Contact(std::string first, std::string last, std::string nickname
			, std::string phone, std::string secret);
};

#endif