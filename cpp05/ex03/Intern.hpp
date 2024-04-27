#pragma once

#include "AForm.hpp"
#include <iostream>

class Intern
{
public:
	AForm	*makeForm(std::string const name, std::string const target);

	Intern();
	Intern(Intern const &intern);
	Intern	&operator=(Intern const &rhs);
	~Intern();

	class FormNotFound: public std::exception
	{
		public:
			const char* what() const throw();
	};
};
