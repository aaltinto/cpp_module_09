#include "RPN.hpp"
#include <iostream>
#include <ctype.h>
#include <cstdlib>

void RPN::calculate(char op)
{
	switch (op)
	{
		case '+':
		{
			int after = _nums.top();
			_nums.pop();
			int pre = _nums.top();
			_nums.pop();
			_nums.push(pre + after);
			break;
		}
		case '-':
		{
			int after = _nums.top();
			_nums.pop();
			int pre = _nums.top();
			_nums.pop();
			_nums.push(pre - after);
			break;
		}
		case '*':
		{
			int after = _nums.top();
			_nums.pop();
			int pre = _nums.top();
			_nums.pop();
			_nums.push(pre * after);
			break;
		}
		case '/':
		{
			int after = _nums.top();
			_nums.pop();
			if (after == 0)
				throw std::runtime_error("division by zero");
			int pre = _nums.top();
			_nums.pop();
			_nums.push(pre / after);
			break;
		}
		default:
			throw std::runtime_error("invalid operator");
	}
}

void RPN::run(void)
{
	if (this->_input.empty())
		throw std::runtime_error("empty input");
	for (size_t i = 0; i < _input.size(); i++)
	{
		if (std::isdigit(_input[i]))
		{
			std::string num = "";
			num += _input[i];
			this->_nums.push(std::atoi(num.c_str()));
			continue;
		}
		if (this->_nums.size() < 2)
			throw std::runtime_error("not enough numbers to perform operation");
		
		calculate(_input[i]);
	}
	if (this->_nums.size() != 1)
		throw std::runtime_error("not enough operator to perform operation");
	std::cout << this->_nums.top() << std::endl;
}

void RPN::setInput(std::string input)
{
	this->_input = input;
}

RPN::RPN(std::string input): _input(input)
{
	run();
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
	this->_nums = copy._nums;
	return (*this);
}

