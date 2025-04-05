#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;
		void	readCSV(void);
		float	findClosestDate(std::string date);

	public:
		/* Constructors & Destructors */
		BitcoinExchange(std::string data);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange(void);

		/* Basic Operators */
		BitcoinExchange const	&operator=(BitcoinExchange const &copy);
};

int err(std::string error);