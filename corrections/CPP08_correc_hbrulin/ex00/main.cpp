#include "easyfind.hpp"

char const *NotFoundException::what() const throw()
{
    return "Element wasn't found!";
}

int main()
{
    std::vector<int> tab;
    tab.push_back(5);
    tab.push_back(4);
    tab.push_back(3);
    tab.push_back(2);
    tab.push_back(1);
    try
    {
        std::cout << easyfind(tab, 5) << std::endl;
    }
   	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    try
    {
        std::cout << easyfind(tab, 7) << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    return 0;
}
