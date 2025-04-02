#include "RPN.hpp"
#include <iostream>

int checkInput(std::string input)
{
    int nums = 0;
    int operators = 0;
    std::cout << "=>" << input << "<=" << std::endl;
    if (input.size() < 3)
        return 0;
    for (size_t i = 0; i < input.size(); i++)
    {

        if (input[i] == ' ')
            continue;
        if (operators > 0 && nums < 2)
            return 0;
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
        return 0;
    }
    if (nums - 1 != operators)
        return 0;
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
    if (!checkInput(input))
    {
        std::cerr << "ERROR" << std::endl;
        return 1;
    }
    RPN rpn(input);
    return 0;
}