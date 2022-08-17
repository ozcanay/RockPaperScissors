#include "utility.h"
#include "constants.h"

#include <limits>
#include <random>

void printUsage(const std::string& executable_name)
{
    std::cerr << "Usage: " << executable_name << " <ROUND COUNT>\n";
}

void resetStream(std::istream& input_stream)
{
    input_stream.clear();
    input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readStream(std::istream& input_stream, int low, int high)
{
    int input;
    input_stream >> input;

    while(input < low || input > high) {
        resetStream(input_stream);
        std::cerr << INVALID_INPUT_MSG << '\n';

        input_stream >> input;
    }

    return input;
}

int getUniformRandomNumber(int low, int high)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uni_distribution(low, high);
    return uni_distribution(gen);
}
