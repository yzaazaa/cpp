#include "Span.hpp"

Span::Span() : n(0), span(0) {}

Span::Span(unsigned int n) : n(n), span(0) {}

Span::Span(Span const &span)
{
	*this = span;
}

Span	&Span::operator=(Span const &rhs)
{
	this->n = rhs.n;
	this->span = rhs.span;
	return *this;
}

Span::~Span() {}

const char*	Span::SpanFullException::what() const throw()
{
	return "Span is full.";
}

void	Span::addNumber(int nb)
{
	if (this->span.size() >= this->n)
		throw Span::SpanFullException();
	this->span.push_back(nb);
}

const char*	Span::NoSpanException::what() const throw()
{
	return "No span can be found.";
}

int	Span::shortestSpan()
{
	if (this->span.size() < 2)
		throw Span::NoSpanException();
	std::sort(this->span.begin(), this->span.end());
	int	shortest = this->span[1] - this->span[0];
	for (size_t i = 2; i < this->span.size(); i++)
	{
		int diff = this->span[i] - this->span[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int	Span::longestSpan()
{
	if (this->span.size() < 2)
		throw Span::NoSpanException();
	std::sort(this->span.begin(), this->span.end());
	return span.back() - span.front();
}

void	Span::fillSpanRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>	vec(begin, end);
	if (vec.size() + this->span.size() > this->n)
		throw Span::SpanFullException();
	span.insert(span.end(), vec.begin(), vec.end());
}
