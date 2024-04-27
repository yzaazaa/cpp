#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robotomy", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &form) : AForm("Robotomy", 72, 45), target(form.getTarget()) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (&rhs != this)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string const	&RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkExecution(executor);
	std::srand(std::time(NULL));
	std::cout << "Drilling noises." << std::endl;
	std::cout << this->target << " has " << (std::rand() % 2 ? "" : "not ") << "been robotomized " << "successfully." << std::endl;
}