#include "PmergeMe.hpp"
#include <limits>
#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>
#include <sstream>

void printSequence(const std::vector<int>& seq)
{
    if (seq.size() > 5)
    {
        for (size_t i = 0; i < 5; ++i)
        {
            std::cout << seq[i] << " ";
        }
        std::cout << "[...]";
    }
    else
    {
        for (std::vector<int>::const_iterator it = seq.begin(); it != seq.end(); ++it)
        {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;
}

void printSequence(const std::deque<int>& seq)
{
    if (seq.size() > 5)
    {
        for (size_t i = 0; i < 5; ++i)
        {
            std::cout << seq[i] << " ";
        }
        std::cout << "[...]";
    }
    else
    {
        for (std::deque<int>::const_iterator it = seq.begin(); it != seq.end(); ++it)
        {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;
}

void	parseInput(int argc, char **argv, std::vector<int>& vec, std::deque<int>& deq)
{
	if (argc < 2)
		throw std::invalid_argument("Invalid number of arguments");
	for (int i = 1; i < argc; ++i)
	{
		std::stringstream ss(argv[i]);
		long n;
		ss >> n;
		if (ss.fail() || !ss.eof() || n < 0 || n > std::numeric_limits<int>::max())
			throw std::invalid_argument("Invalid argument");
		vec.push_back(static_cast<int>(n));
		deq.push_back(static_cast<int>(n));
	}
}

int main(int argc, char **argv)
{
	std::vector<int> vec;
	std::deque<int> deq;

	try
	{
		parseInput(argc, argv, vec, deq);
		std::cout << "Before: ";
		printSequence(vec);
		std::clock_t start = std::clock();
		PmergeMe<std::vector<int> >::merge(vec);
		std::clock_t end = std::clock();
		double duration = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000);

		std::cout << "After: ";
		printSequence(vec);

		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << duration << " us" << std::endl;

		start = std::clock();
		PmergeMe<std::deque<int> >::merge(deq);
		end = std::clock();
		duration = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000);

		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << duration << " us" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
