#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form) : AForm("Shrubbery", 145, 137), target(form.getTarget()) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (&rhs != this)
		return *this;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string const	&ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	file_stream;

	this->checkExecution(executor);
	file_stream.open(this->target + "_shrubbery");
	if (!file_stream.is_open())
		throw std::runtime_error("Couldn't open file");
	file_stream << "      _-_        " << std::endl;
	file_stream << "    /~~   ~~\\   " << std::endl;
	file_stream << " /~~         ~~\\" << std::endl;
	file_stream << "{               }" << std::endl;
	file_stream << " \\  _-     -_  /" << std::endl;
	file_stream << "   ~  \\\\ //  ~ " << std::endl;
	file_stream << "_- -   | | _- _  " << std::endl;
	file_stream << "  _ -  | |   -_  " << std::endl;
	file_stream << "      // \\\\    " << std::endl;
	file_stream.close();
}