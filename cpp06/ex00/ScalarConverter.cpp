#include <iostream>
#include <string>
#include <sstream>
#include "ScalarConverter.hpp"

void	getValueType(const std::string &str, double *value, std::string *value_str, e_type *type)
{
	if (str.length() == 1 && std::isalpha(str[0]))
	{
		*value = static_cast<int>(str[0]);
		*type = DOUBLE;
		return ;
	}
	if (std::isalpha(str[0]))
		throw std::out_of_range("Invalid value");
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan")
	{
		*value_str = str;
		*type = STRING;
		return ;
	}
	*value = std::stod(str);
	*type = DOUBLE;
}

void	toChar(const e_type type, const double value)
{
	char	c;

	if (type == STRING)
	{
		std::cout << "impossible";
		return ;
	}
	c = static_cast<char>(value);
	if (!std::isprint(c))
	{
		std::cout << "Non displayable";
		return ;
	}
	std::cout << "'" << c << "'";
}

void	toInt(const e_type type, const double value)
{
	int	i;

	if (type == STRING)
	{
		std::cout << "impossible";
		return ;
	}
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::lowest())
	{
		std::cout << "impossible";
		return ;
	}
	i = static_cast<int>(value);
	std::cout << i;
}

void	toFloat(const e_type type, const double value, const std::string value_str)
{
	float	f;
	int		i;

	if (type == STRING)
	{
		if (value_str == "-inf")
			std::cout << "-inff";
		else if (value_str == "+inf")
			std::cout << "+inff";
		else if (value_str == "nan")
			std::cout << "nanf";
		else
			std::cout << value_str;
		return ;
	}
	if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::lowest())
	{
		std::cout << "impossible";
		return ;
	}
	f = static_cast<float>(value);
	i = static_cast<int>(value);
	std::cout << f << (f - i ? "f" : ".0f");
}

void	toDouble(const e_type type, const double value, const std::string value_str)
{
	int		i;

	if (type == STRING)
	{
		if (value_str == "-inff")
			std::cout << "-inf";
		else if (value_str == "+inff")
			std::cout << "+inf";
		else if (value_str == "nanf")
			std::cout << "nan";
		else
			std::cout << value_str;
		return ;
	}
	i = static_cast<int>(value);
	std::cout << value << (value - i ? "" : ".0");
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string &str)
{
	double		value;
	std::string	value_str;
	e_type		type;

	getValueType(str, &value, &value_str, &type);
	std::cout << "char: "; toChar(type, value); std::cout << std::endl;
	std::cout << "int: "; toInt(type, value); std::cout << std::endl;
	std::cout << "float: "; toFloat(type, value, value_str); std::cout << std::endl;
	std::cout << "double: "; toDouble(type, value, value_str); std::cout << std::endl;
}