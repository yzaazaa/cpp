#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);

	try
	{
		std::cout << "Filling span ..." << std::endl;
		sp.addNumber(6);
		std::cout << "Added 6 to the span." << std::endl;
		sp.addNumber(3);
		std::cout << "Added 3 to the span." << std::endl;
		sp.addNumber(17);
		std::cout << "Added 17 to the span." << std::endl;
		sp.addNumber(9);
		std::cout << "Added 9 to the span." << std::endl;
		sp.addNumber(11);
		std::cout << "Added 11 to the span." << std::endl;
		sp.addNumber(100);
		std::cout << "Added 100 to the span." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "Finished fillin span.\nShortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	std::srand(time(NULL));
	std::vector<int> range1;
	for (int i = 0; i < 5; i++)
		range1.push_back(std::rand());
	try
	{
		std::cout << "Filling span with a range of 5 values." << std::endl;
		sp.fillSpanRange(range1.begin(), range1.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "Finished Filling span with range.\nAfter fillSpanRange:" << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    Span sp2 = Span(10001);
    std::vector<int> range2;
	for (int i = 0; i < 10001; ++i)
	{
		range2.push_back(std::rand());
	}
	try
	{
		std::cout << "Filling new span with 10001 values." << std::endl;
		sp2.fillSpanRange(range2.begin(), range2.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "After filling span of more than 10000 range:" << std::endl;
    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;

    return 0;
}
