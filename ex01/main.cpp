#include "RPN.hpp"
#include <iostream>

static void standardizeInput(std::string &input, char **av)
{
    for (size_t i = 1; av[i] != NULL; i++)
    {
        std::string tmp(av[i]);
        for (size_t i = 0; i < tmp.size(); ++i)
        {
            if (tmp[i] == ' ')
                continue;
            input += tmp[i];
        }
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    std::string input;
    try
    {
        standardizeInput(input, av);
        RPN rpn(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
