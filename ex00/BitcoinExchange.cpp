#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(std::string data)
{
	std::ifstream	readData(data);
	std::string		line;
	size_t			count = 0;
	Data 			*start = &this->_data;

	while (getline(readData, line))
	{
		std::stringstream	data(line);
		std::string part;
		Data	newNode;

		if (line.find_first_of('|') != line.find_last_of('|')
			|| line.find_first_of('|') == std::string::npos)
		{
			start->date = "Error: bad input => " + line;
			start->value = -1;
			start->next = &newNode;
		}
		while (getline(data, part, '|'))
		{

		}
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange const	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void)copy;
	return (*this);
}

int err(std::string error)
{
	std::cerr << error << std::endl;
	return 1;
}