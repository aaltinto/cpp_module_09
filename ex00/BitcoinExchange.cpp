#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange(void)
{

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
	return (*this);
}

int err(std::string error)
{
	std::cerr << error << std::endl;
	return 1;
}