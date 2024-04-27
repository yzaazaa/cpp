#pragma once

#include <iostream>
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
private:
	std::string	const	target;
public:
	virtual void		execute(Bureaucrat const &executor) const;
	std::string const	&getTarget() const;

	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &form);
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
	~PresidentialPardonForm();
};