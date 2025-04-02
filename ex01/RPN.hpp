#pragma once

#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<char> _rpn;


	public:
		/* Constructors & Destructors */
		RPN(std::string input);
		RPN(RPN const &copy);
		~RPN(void);

		/* Basic Operators */
		RPN const	&operator=(RPN const &copy);
};

