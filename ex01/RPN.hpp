#pragma once

#include <string>
#include <stack>

class RPN
{
	private:
		std::string _input;
		std::stack<int> _nums;
	public:
		/* Constructors & Destructors */
		RPN(std::string input = "");
		RPN(RPN const &copy);
		~RPN(void);

		/* Basic Operators */
		RPN const	&operator=(RPN const &copy);
		
		/* Member Functions */
		void setInput(std::string input);
		void calculate(char op);
		void run(void);
};

