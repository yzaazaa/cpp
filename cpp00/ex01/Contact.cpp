#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "EMPTY";
	this->last_name = "EMPTY";
	this->nickname = "EMPTY";
	this->phone_number = "EMPTY";
	this->darkest_secret = "EMPTY";
}

Contact::Contact(std::string first, std::string last, std::string nickname
			, std::string phone, std::string secret) : first_name(first)
			, last_name(last), nickname(nickname), phone_number(phone)
			, darkest_secret(secret)
{
	return ;
}

std::string	Contact::getFirstName()
{
	return this->first_name;
}

std::string	Contact::getLastName()
{
	return this->last_name;
}

std::string	Contact::getNickname()
{
	return this->nickname;
}

std::string	Contact::getPhoneNumber()
{
	return this->phone_number;
}

std::string	Contact::getDarkestSecret()
{
	return this->darkest_secret;
}