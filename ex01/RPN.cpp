#include "RPN.hpp"
#include <iostream>
#include <ctype.h>
#include <cstdlib>

RPN::RPN(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (std::isdigit(input[i]))
		{
			std::string num = "";
			num += input[i];
			this->_nums.push(std::atoi(num.c_str()));
		}
		else
		{
			switch (input[i])
			{
			case '+':
			{
				int after = this->_nums.top();
				this->_nums.pop();
				int pre = this->_nums.top();
				this->_nums.pop();
				this->_nums.push(pre + after);
				break;
			}
			case '-':
			{
				int after = this->_nums.top();
				this->_nums.pop();
				int pre = this->_nums.top();
				this->_nums.pop();
				this->_nums.push(pre - after);
				break;
			}
			case '*':
			{
				int after = this->_nums.top();
				this->_nums.pop();
				int pre = this->_nums.top();
				this->_nums.pop();
				this->_nums.push(pre * after);
				break;
			}
			case '/':
			{
				int after = this->_nums.top();
				this->_nums.pop();
				if (after == 0)
					throw std::runtime_error("division by zero");
				int pre = this->_nums.top();
				this->_nums.pop();
				this->_nums.push(pre / after);
				break;
			}
			
			default:
				break;
			}

		}

	}
	std::cout << this->_nums.top() << std::endl;
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

