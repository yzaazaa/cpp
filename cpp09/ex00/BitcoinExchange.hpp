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
		static void	putPrices(std::string const &fileName);

		class DBFormatException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};