#include "RPN.hpp"
#include <iostream>

int checkInput(std::string input)
{
    int nums = 0;
    int operators = 0;
    if (input.size() < 3)
        return 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ')
            continue;
        if (nums >= 2 && operators > nums - 1)
            throw std::runtime_error("Not enough numbers");
        if (std::isdigit(input[i]))
        {
            nums++;
            continue;
        }
        if (input[i] == '+' || input[i] == '-'
            || input[i] == '*' || input[i] == '/')
            {
            operators++;
            continue;
        }
        throw std::runtime_error("Invalid character");
        return 0;
    }
    if (operators != nums - 1)
        throw std::runtime_error("Not enough operators");
    return 1;
}

int main(int ac, char **av)
{
    (void)ac;
    std::string input;
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
    try
    {
        checkInput(input);
        RPN rpn(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
