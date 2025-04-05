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
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}
