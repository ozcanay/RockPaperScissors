#include <iostream>
#include <string>

#include "rps.h"

void printUsage(const std::string& executable_name)
{
    std::cerr << "Usage: " << executable_name << " <GAME COUNT>\n";
}

int main(int argc, char** argv)
{
    if(argc != 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const auto N = std::stoi(argv[1]);
    if(N <= 0) {
        std::cerr << "N has to be greater than 0.\n";
        return EXIT_FAILURE;
    }

    RPS rps(N);

    return EXIT_SUCCESS;
}