#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

static int checkValidDate(int year, int month, int day)
{
	const int daysInMonths[] = {
		31, 28, 31, 30, 31, 30, 
        31, 31, 30, 31, 30, 31 
	};
	if (year < 2000)
	{
		std::cerr << "Year should be bigger than 2000" << std::endl;
		return 0;
	}
	int isLeapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);

	if (isLeapYear && month == 2 && day < 30)
		return 1;
	if (day <= daysInMonths[month -1])
		return 1;
	return 0;
}

static int inputChecker(std::string input, int date, int csv)
{
	std::stringstream	ss(input);
	int					count = 0;
	std::string			line;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
			continue;
		if ((date && input[i] == '-') || (!date && input[i] == '.'))
		{
			count++;
			continue;
		}
		if (!std::isdigit(input[i]))
		{
			if (!date && !csv)
				return -1;
			return 0;
		}
	}
	if ((date && count > 2) || (!date && count > 1))
		return 0;
	if (date)
	{
		int year;
		int month;
		int day;
		int	j = 0;
		while (std::getline(ss, line, '-'))
		{
			++j;
			switch (j)
			{
			case 1:
				year = std::atoi(line.c_str());
				break;
			case 2:
				month = std::atoi(line.c_str());
				break;
			case 3:
				day = std::atoi(line.c_str());
				break;	
			default:
				return 0;
			}
		}
		if (!checkValidDate(year, month, day))
			return 0;
	}
	if (!csv && !date)
	{
		char *end;
		float f = std::strtod(input.c_str(), &end);
		if (f > 1000)
			return 2;
	}
	
	return 1;
}

float BitcoinExchange::findClosestDate(std::string date)
{
	std::map<std::string, float>::iterator it = this->_db.lower_bound(date);

	if (it != this->_db.end() && it->first == date)
		return it->second;
	if (it != this->_db.begin())
	{
		it--;
		return it->second;
	}
	return -1;
}

BitcoinExchange::BitcoinExchange(std::string data)
{
	std::ifstream	readData(data);
	std::string		line;
	std::string		date;
	size_t			count = 1;
	
	this->readCSV();
	
	while (getline(readData, line))
	{
		std::stringstream ss(line);
		std::string	part;

		if (line.find_first_of('|') != line.find_last_of('|') || line.find_first_of('|') == std::string::npos)
		{
			std::cerr << "Error: Bad input => " << line << std::endl;
			continue;
		}
		while (std::getline(ss, part, '|'))
		{
			count++;
			if (count % 2 == 0)
			{
				if (count == 2 && 1 != inputChecker(part, 1, 0))
					continue;
				if (!inputChecker(part, 1, 0))
					std::cerr << "Error: Bad input => " << part << std::endl;
				date = part;
				continue;
			}
			
			if (count == 3 && 1 != inputChecker(part, 0, 0))
			continue;
			int err = inputChecker(part, 0, 0);
			if (err == -1)
			{
				std::cerr << "Error: Bad input => value should be a positive number" << std::endl;
				continue;
			}
			if (err == 2)
			{
				std::cerr << "Error: value too large" << std::endl;
				continue;
			}
			char *end;
			float value = std::strtod(part.c_str(), &end);
			float rate = this->findClosestDate(date);
			if (rate < 0)
			{
				std::cerr << "Error: No avaible date on given date" << std::endl;
				continue;
			}
			std::cout << date << "=>" << part << " = " << rate * value << std::endl;
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

void	BitcoinExchange::readCSV(void)
{
	std::ifstream	fs("data.csv");
	std::string		line;
	std::string		part;
	std::string		date;
	size_t			del = 1;

	while (std::getline(fs, line))
	{

		if (line.find_first_of(',') != line.find_last_of(','))
			throw std::runtime_error("More than one delimiter => " + line);
		std::stringstream	ss(line);
		while (std::getline(ss, part, ','))
		{
			del++;
			if (del % 2 == 0)
			{
				if (del == 2 && !inputChecker(part, 1, 1))
					continue;
				if (!inputChecker(part, 1, 1))
					throw std::runtime_error("Bad input in csv => " + line);
					date = part;
					this->_db[part];
					continue;
				}
				if (del == 3 && !inputChecker(part, 0, 1))
					continue;
				if (!inputChecker(part, 0, 1))
					throw std::runtime_error("Bad input in csv => " + line);
				char *end;
			this->_db[date] = std::strtod(part.c_str(), &end);
		}
	}
}

int err(std::string error)
{
	std::cerr << error << std::endl;
	return 1;
}