#include "span.hpp"

Span::Span(unsigned int n) : _n(n), _tab() {
	
}

Span::Span(const Span &tocopy) {
	*this = tocopy;
}

Span &Span::operator=(const Span &tocopy) {
	this->_n = tocopy._n;
	this->_tab = tocopy._tab;
    return *this;
}

char const *Span::FullException::what() const throw()
{
    return "Number could not be added.";
}

char const *Span::NoSpanException::what() const throw()
{
    return "Span cannot be calculated.";
}

void Span::addNumber(int number) {
	if (_tab.size() >= _n)
        throw Span::FullException();
    _tab.push_back(number);
}

int Span::shortestSpan() const {
	if (_tab.size() <= 1)
        throw Span::NoSpanException();

	std::vector<int> sp(_tab);
	std::vector<int>::iterator first = sp.begin();
	std::vector<int>::iterator next = sp.begin() + 1;
	size_t min_span = std::abs(*next - *first);
	while (next != sp.end())
	{
		size_t tmp = std::abs(*next - *first);
		if (tmp < min_span)
			min_span = tmp;
		first++;
		next++;
	}
	return (min_span);
}

int Span::longestSpan() const {
	if (_tab.size() <= 1)
        throw Span::NoSpanException();
	int max = *std::max_element(_tab.begin(), _tab.end());
    int min = *std::min_element(_tab.begin(), _tab.end());
	return max - min;
}
