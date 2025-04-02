#include "RPN.hpp"
#include <iostream>
#include <ctype.h>

RPN::RPN(std::string input)
{
	for (int i = input.size() -1; i >= 0; i--)
	{
		std::cout << input[i] << std::endl;
		this->_rpn.push(input[i]);
	}
	// std::stack<char> tmp(this->_rpn);
	// std::cout << "stack: " << std::endl;
	// while (!tmp.empty())
	// {
	// 	std::cout << tmp.top() << std::endl;
	// 	tmp.pop();
	// }
	
}

RPN::RPN(RPN const &copy)
{
	*this = copy;
}

RPN::~RPN(void)
{

}

RPN const	&RPN::operator=(const RPN &copy)
{
	(void)copy;
	return (*this);
}

