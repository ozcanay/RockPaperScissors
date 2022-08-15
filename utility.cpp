#include "utility.h"

#include <limits>
#include <random>

void printUsage(const std::string& executable_name)
{
    std::cerr << "Usage: " << executable_name << " <ROUND COUNT>\n";
}

void resetStdin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getUniformRandomNumber(int low, int high)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uni_distribution(low, high);
    return uni_distribution(gen);
}
