#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		typedef struct Data
		{
			float		value;
			std::string	date;
			Data		*next;
		}	Data;
		Data _data;
		std::map<std::string, float> _db;

	public:
		/* Constructors & Destructors */
		BitcoinExchange(std::string data);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange(void);

		/* Basic Operators */
		BitcoinExchange const	&operator=(BitcoinExchange const &copy);
};

int err(std::string error);