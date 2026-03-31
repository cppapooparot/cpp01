#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments!" << std::endl;
        return 0;
    }
    Harl h;
    h.complain(std::string(argv[1]));
    return 0;
}