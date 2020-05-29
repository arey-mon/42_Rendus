#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <iostream>

class NotFoundException: public std::exception
{
    public:
        virtual char const *what() const throw();
};

template <typename T>
int &easyfind(T tab, int i)
{
    typename T::iterator it = std::find(tab.begin(), tab.end(), i);
    if (it == tab.end())
        throw NotFoundException();
    return *it;
}

#endif
