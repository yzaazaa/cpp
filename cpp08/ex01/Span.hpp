#pragma once

#include <stdexcept>
#include <vector>

class Span
{
	private:
		unsigned int		n;
		std::vector<int>	span;
	public:
		void	addNumber(int nb);
		int		shortestSpan();
		int		longestSpan();
		void	fillSpanRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		Span();
		Span(unsigned int n);
		Span(Span const &span);
		Span	&operator=(Span const &rhs);
		~Span();

		class SpanFullException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
