#include <iostream>
#include "PmergeMe.hpp"
#include <cstdlib>

bool isValidInteger(const char* str)
{
    if (!str || *str == '\0')
        return false;
        
    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        i = 1;
        
    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    
    return (i > (str[0] == '-' || str[0] == '+' ? 1 : 0));
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <list of integers>" << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;

    for (int i = 1; i < argc; ++i)
    {
        if (!isValidInteger(argv[i]))
        {
            std::cerr << "Error: Invalid integer '" << argv[i] << "'." << std::endl;
            return 1;
        }
        
        int value = std::atoi(argv[i]);
        pmergeMe.add(value);
    }
    pmergeMe.sort();
    
}