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
	if (ss.fail() || !ss.eof())
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
}

void	BitcoinExchange::printDB()
{
	for (std::map<std::string, double>::iterator i = this->data.begin(); i != this->data.end(); i++)
		std::cout << i->first << "," << i->second << std::endl;
}

void	BitcoinExchange::putPrices(std::string const &fileName)
{
	BitcoinExchange	btc;

	btc.parseDB();
	btc.printDB();
}
