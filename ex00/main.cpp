#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int checkInputFile(std::string file)
{
    std::string input;

    size_t i = file.find_last_of(".txt");
    if (i != file.size())
    {
        std::cerr << "Input file need to be '.txt' file" << std::endl;
        return 0;
    }
    return 1;
}

std::map<std::string, std::string> readFile(std::string file)
{
    std::string stream;
    std::ifstream readFile(file);
    std::map<std::string, std::string> map;

    while (std::getline(readFile, stream))
    {
        if (stream.find_first_of('|') != stream.find_last_of('|'))

        std::stringstream ss(stream);
    }

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
    std::map<std::string, std::string> input = readFile(file);
    return 0;
}
