#pragma once

#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &scalarConverter);
	ScalarConverter	&operator=(const ScalarConverter &rhs);
	~ScalarConverter();

public:
	static void	convert(std::string &str);
};

enum e_type
{
	STRING,
	DOUBLE
};
