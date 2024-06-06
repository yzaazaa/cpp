#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(this->verifyGrade(gradeToSign)), gradeToExecute(this->verifyGrade(gradeToExecute)) {}

AForm::AForm(AForm const &aform) : name(aform.getName()), gradeToSign(aform.getGradeToSign()), gradeToExecute(aform.getGradeToExecute())
{
	*this = aform;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	this->isSigned = rhs.isSigned;
	return *this;
}

AForm::~AForm() {}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	AForm::FormSignedException::what() const throw()
{
	return "Form already signed!";
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed yet!";
}

std::string	const	&AForm::getName() const
{
	return this->name;
}

bool	AForm::getSignStatus() const
{
	return this->isSigned;
}

int	AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int	AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	int	const	grade = bureaucrat.getGrade();
	if (this->isSigned)
		throw AForm::FormSignedException();
	if (this->gradeToSign < grade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

int	AForm::verifyGrade(int const grade) const
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
	if (grade < 1)
		throw AForm::GradeTooHighException();
	return grade;
}

void	AForm::checkExecution(Bureaucrat const &executor) const
{
	if (!this->getSignStatus())
		throw AForm::FormNotSignedException();
	if (this->gradeToExecute < executor.getGrade())
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	return o << rhs.getName() << " signed: " << rhs.getSignStatus() << ", grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExecute();
}