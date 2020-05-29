#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>
# include <iostream>
# include <algorithm>

class Span {

    private:
        unsigned int _n;
        std::vector<int> _tab;

        Span() {};

    public:
        Span(unsigned int n);
		~Span() {};
        Span(const Span &tocopy);
        Span &operator=(const Span &tocopy);

        class FullException: public std::exception
        {
            public:
                char const *what() const throw();
        };

        class NoSpanException: public std::exception
        {
            public:
                char const *what() const throw();
        };

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
};

#endif