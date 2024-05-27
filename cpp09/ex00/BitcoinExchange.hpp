#pragma once

#include <iostream>
#include <stdexcept>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	data;
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &);
		BitcoinExchange	&operator=(BitcoinExchange const &);
		~BitcoinExchange();
	public:
		void	parseDB();
		void	printDB();
		void	putPrice(std::string const &date, double const value);
		void	parseInput(std::string const &fileName);
		static void	putPrices(std::string const &fileName);

		class DBFormatException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class DBEmptyException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};