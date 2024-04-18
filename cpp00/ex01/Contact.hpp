#pragma once
#ifndef __CONTACT_H__
# define __CONTACT_H__

# include <iostream>

class Contact {
private:
	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	Contact(std::string first, std::string last, std::string nickname
			, std::string phone, std::string secret);
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
};

#endif