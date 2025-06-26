#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <iterator>

int main(int ac, char **argv)
{
    if (ac < 2)
        return err("Need an input file");
    std::string file(argv[1]);
    try
    {
        if (ac > 3)
            return err("Too many arguments");
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
