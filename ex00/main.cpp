#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <iterator>

int main(int ac, char **argv)
{
    if (ac < 2)
    {
        std::cout << "Need an input file" << std::endl;
        return 1;
    }
    std::string file(argv[1]);
    try
    {
        if (ac == 2)
            BitcoinExchange btc(file);
        else
        {
            std::string data(argv[2]);
            BitcoinExchange btc(file, data);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}
