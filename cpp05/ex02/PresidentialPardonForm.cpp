#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("Presidential", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &form) : AForm("Presidential", 25, 5), target(form.getTarget()) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (&rhs != this)
		return *this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string const	&PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkExecution(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}