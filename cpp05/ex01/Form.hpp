#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
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
	int					verifyGrade(int const grade);

	Form();
	Form(std::string const name, int const gradeToSign, int const gradeToExecute);
	Form(Form const &form);
	Form	&operator=(Form const &rhs);
	~Form();

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
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);