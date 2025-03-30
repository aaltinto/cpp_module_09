#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> _db;

	public:
		/* Constructors & Destructors */
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange(void);

		/* Basic Operators */
		BitcoinExchange const	&operator=(BitcoinExchange const &copy);
};

int err(std::string error);