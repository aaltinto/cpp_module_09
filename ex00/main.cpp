#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <iterator>

int checkInputFile(std::string file)
{
    if (file[file.size() -1] != 't'
        && file[file.size() - 2] != 'x' 
        && file[file.size() -3] != 't'
        && file[file.size() -4] != '.')
    {
        std::cerr << "Input file need to be '.txt' file" << file[file.size()] << std::endl;
        return 0;
    }
    return 1;
}

std::multimap<std::string, std::string> readFile(std::string file)
{
    std::ifstream readFile(file);
    std::string stream;
    std::multimap<std::string, std::string> multimap;

    while (std::getline(readFile, stream))
    {
        if (stream.find_first_of('|') != stream.find_last_of('|') || stream.find_first_of('|') == std::string::npos)
        {
            multimap.insert(std::make_pair("Error: bad input =>", stream));
            continue;
        }

        std::string line;
        std::stringstream ss(stream);
        size_t dlm = 2;
        std::string index;
        while (std::getline(ss, line, '|'))
        {
            if (dlm % 2 == 0)
            {
                index = line;
            }
            else
                multimap.insert(std::make_pair(index, line));
            dlm++;
        }

    }
    std::multimap<std::string, std::string>::iterator it;
    std::cout << "multimap:" << std::endl;
    for (it = multimap.begin(); it != multimap.end(); it++)
    {
        std::cout << it->first << " | " << it->second << std::endl; 
    }
    return multimap;
}

int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cout << "Need an input file" << std::endl;
        return 1;
    }
    std::string file(argv[1]);
    if (!checkInputFile(file))
        return 1;
    try
    {
        BitcoinExchange btc(file);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
