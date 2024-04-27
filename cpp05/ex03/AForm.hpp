#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
private:
	std::string const	name;
	bool				isSigned;
	int const			gradeToSign;
	int const			gradeToExecute;

public:
	std::string const	&getName() const;
	bool				getSignStatus() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(Bureaucrat &bureaucrat);
	int					verifyGrade(int const grade) const;
	void				checkExecution(Bureaucrat const &executor) const;
	virtual void		execute(Bureaucrat const &executor) const = 0;

	AForm();
	AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
	AForm(AForm const &aform);
	AForm	&operator=(AForm const &rhs);
	virtual ~AForm();

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class FormSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);