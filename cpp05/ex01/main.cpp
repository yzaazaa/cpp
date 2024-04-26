#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	b1("bot", 50);
		Form		form1("good form", 60, 60);
		Form		form2("bad form", 49, 49);
		b1.signForm(form1);
		b1.signForm(form1);
		b1.signForm(form2);
		Form		form3("bad form 2", 0, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}