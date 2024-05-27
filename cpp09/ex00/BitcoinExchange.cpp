#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &) {}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &) { return *this; }

BitcoinExchange::~BitcoinExchange() {}

const char*	BitcoinExchange::DBFormatException::what() const throw()
{
	return "Database not formatted correctly!";
}

const char*	BitcoinExchange::DBEmptyException::what() const throw()
{
	return "Database is empty!";
}

bool	checkDate(const std::string &dateStr)
{
	std::tm tm = {};
	std::istringstream	ss(dateStr);

	ss >> std::get_time(&tm, "%Y-%m-%d");

	if (ss.fail() || !ss.eof())
		return false;
	if (tm.tm_year < 0 || tm.tm_mon < 0 || tm.tm_mon > 11 || tm.tm_mday < 1 || tm.tm_mday > 31)
		return false;
	return true;
}

bool	checkValue(const std::string &valueStr)
{
	std::istringstream	ss(valueStr);
	double				value;

	ss >> value;
	if (ss.fail() || !ss.eof() || value < 0)
		return false;
	return true;
}

void	BitcoinExchange::parseDB()
{
	std::ifstream	dataFile("data.csv");
	std::string		line;
	std::string		date;
	std::string		value;

	if (!dataFile.is_open())
		throw std::runtime_error("Error: Couldn't open file.");
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		date = line.substr(0, line.find(',', 0));
		value = line.substr(line.find(',', 0) + 1, line.size());
		if (!checkDate(date) || !checkValue(value))
			throw BitcoinExchange::DBFormatException();
		this->data[date] = std::stod(value, 0);
	}
	dataFile.close();
	if (this->data.size() == 0)
		throw BitcoinExchange::DBEmptyException();
}

void	BitcoinExchange::printDB()
{
	for (std::map<std::string, double>::iterator i = this->data.begin(); i != this->data.end(); i++)
		std::cout << i->first << "," << i->second << std::endl;
}

void	BitcoinExchange::putPrice(std::string const &date, double const value)
{
	std::map<std::string, double>::iterator it;
	double 									price;

	for (it = this->data.begin(); it != this->data.end(); it++)
	{
		if (it->first == date)
		{
			price = it->second * value;
			break ;
		}
		if (it != this->data.begin() && it->first > date)
		{
			price = (--it++)->second * value;
			break ;
		}
	}
	if (it == this->data.end())
		price = --it->second * value;
	std::cout << date << " => " << value << " = " << price << std::endl;
}

void	BitcoinExchange::parseInput(std::string const &fileName)
{
	std::ifstream	inputFile(fileName);
	std::string		line;
	std::string		date;
	std::string		value;
	double			value_nb;

	if (!inputFile.is_open())
		throw std::runtime_error("Error: Couldn't open file.");
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		size_t	pos = line.find(" | ", 0);
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input ==> " << line << std::endl;
			continue ;
		}
		date = line.substr(0, pos);
		if (!checkDate(date))
		{
			std::cerr << "Error: bad input ==> " << date << std::endl;
			continue ;
		}
		value = line.substr(pos + 3, line.size());
		if (!checkValue(value))
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		value_nb = std::stod(value);
		if (value_nb > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		this->putPrice(date, value_nb);
	}
	inputFile.close();
}

void	BitcoinExchange::putPrices(std::string const &fileName)
{
	BitcoinExchange	btc;

	try
	{
		btc.parseDB();
		btc.parseInput(fileName);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
