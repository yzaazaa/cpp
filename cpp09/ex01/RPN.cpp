#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const &) {}
RPN &RPN::operator=(RPN const &) { return *this; }
RPN::~RPN() {}

const char*	RPN::RPNException::what() const throw()
{
	return "Error";
}

void	RPN::process(char c)
{
	int	val1;
	int	val2;

	if (this->data.size() < 2)
		throw RPN::RPNException();
	val1 = this->data.top();
	this->data.pop();
	val2 = this->data.top();
	this->data.pop();
	switch (c)
	{
		case '*':
			this->data.push(val1 * val2);
			break;
		case '+':
			this->data.push(val1 + val2);
			break;
		case '-':
			this->data.push(val2 - val1);
			break;
		case '/':
			if (val1 == 0)
				throw RPN::RPNException();
			this->data.push(val2 / val1);
			break;
		default:
			throw RPN::RPNException();
	}
}

void	RPN::calc(std::string const &expression)
{
	std::string	operations = "*/-+";

	for (size_t i = 0; i < expression.size(); i++)
	{
		size_t	pos = operations.find(expression[i], 0);
		if (!isdigit(expression[i]) && pos == std::string::npos && expression[i] != ' ')
			throw	RPN::RPNException();
		else if (isdigit(expression[i]) && expression[i + 1] == ' ')
			this->data.push(expression[i] - '0');
		else if (isdigit(expression[i]))
			throw	RPN::RPNException();
		else if (expression[i] == ' ')
			continue ;
		else if (expression[i + 1] == ' ' || !expression[i + 1])
			this->process(expression[i]);
		else
			throw RPN::RPNException();
	}
	if (this->data.size() != 1)
		throw RPN::RPNException();
	std::cout << this->data.top() << std::endl;
}

void	RPN::calculate(std::string const &expression)
{
	RPN	rpn;

	try
	{
		rpn.calc(expression);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}