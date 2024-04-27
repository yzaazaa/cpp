#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		Intern	random;
		AForm	*form;

		form = random.makeForm("shrubbery creation", "Bender");
		delete form;
		form = random.makeForm("robotomy request", "Bender");
		delete form;
		form = random.makeForm("presidential pardon", "Bender");
		delete form;
		form = random.makeForm("bad form", "Bender");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}