#pragma once

#include <iostream>
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
private:
	std::string	const	target;
public:
	virtual void		execute(Bureaucrat const &executor);
	std::string const	&getTarget();

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &form);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
	~ShrubberyCreationForm();
};