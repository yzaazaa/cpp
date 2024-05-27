#include "BitcoinExchange.hpp"

int	main()
{
	try
	{
		BitcoinExchange::putPrices("test");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}