#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(this->verifyGrade(gradeToSign)), gradeToExecute(this->verifyGrade(gradeToExecute)) {}

Form::Form(Form const &form) : name(form.getName()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute())
{
	*this = form;
}

Form	&Form::operator=(Form const &rhs)
{
	this->isSigned = rhs.isSigned;
	return *this;
}

Form::~Form() {}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	Form::FormSignedException::what() const throw()
{
	return "Form already signed!";
}

std::string	const	&Form::getName() const
{
	return this->name;
}

bool	Form::getSignStatus() const
{
	return this->isSigned;
}

int	Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int	Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	int	const	grade = bureaucrat.getGrade();
	if (this->isSigned)
		throw Form::FormSignedException();
	if (this->gradeToSign < grade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

int	Form::verifyGrade(int const grade)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
	return grade;
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	return o << rhs.getName() << " signed: " << rhs.getSignStatus() << ", grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExecute();
}