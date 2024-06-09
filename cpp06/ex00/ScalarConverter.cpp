#include <iostream>
#include <string>
#include <sstream>
#include "ScalarConverter.hpp"

bool checkSpecialValues(const std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan")
		return true;
	return false;
}

bool	checkFloatingPoint(const std::string &str)
{
	std::istringstream	iss(str);
	double	value;
	iss >> value;
	if (iss.fail() || !iss.eof())
	{
		if (str[str.size() - 1] == 'f')
		{
			std::istringstream	iss(str.substr(0, str.size() - 1));
			double	value;
			iss >> value;
			if (iss.fail() || !iss.eof())
				return false;
			return true;
		}
		return false;
	}
	return true;
}

void	getValueType(const std::string &str, double *value, std::string *value_str, e_type *type)
{
	if (checkSpecialValues(str))
	{
		*value_str = str;
		*type = STRING;
		return ;
	}
	if (str.length() == 1 && !(str[0] >= '0' && str[0] <= '9'))
	{
		*value = static_cast<double>(str[0]);
		*type = DOUBLE;
		return ;
	}
	if (!checkFloatingPoint(str))
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
	if (!(c >= ' ' && c < 127))
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

bool	fractionalPartZero(const std::string &str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] != '.' && str[i] != 'f')
		i++;
	if (!str[i] || str[i] == 'f')
		return true;
	i++;
	while (str[i] == '0')
		i++;
	if (!str[i] || str[i] == 'f')
		return true;
	return false;
}

void	toFloat(const std::string str, const e_type type, const double value, const std::string &value_str)
{
	float	f;

	if (type == STRING)
	{
		if (value_str == "-inf")
			std::cout << "-inff";
		else if (value_str == "+inf")
			std::cout << "+inff";
		else if (value_str == "nan")
			std::cout << "nanf";
		else if (value_str == "nanf" || value_str == "+inff" || value_str == "-inff")
			std::cout << value_str;
		else
			std::cout << "impossible";
		return ;
	}
	if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::lowest())
	{
		std::cout << "impossible";
		return ;
	}
	f = static_cast<float>(value);
	std::cout << f;
	if (fractionalPartZero(str))
		std::cout << ".0f";
	else
		std::cout << "f";
}

void	toDouble(const std::string str, const e_type type, const double value, const std::string value_str)
{
	if (type == STRING)
	{
		if (value_str == "-inff")
			std::cout << "-inf";
		else if (value_str == "+inff")
			std::cout << "+inf";
		else if (value_str == "nanf")
			std::cout << "nan";
		else if (value_str == "nan" || value_str == "+inf" || value_str == "-inf")
			std::cout << value_str;
		else
			std::cout << "impossible";
		return ;
	}
	std::cout << value;
	if (fractionalPartZero(str))
		std::cout << ".0";
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
	std::cout << "float: "; toFloat(str, type, value, value_str); std::cout << std::endl;
	std::cout << "double: "; toDouble(str, type, value, value_str); std::cout << std::endl;
}
