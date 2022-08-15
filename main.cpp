#include <iostream>
#include <string>
#include <memory>

#include "utility.h"

#include "rps.h"
#include "Human.h"
#include "Computer.h"

void printSummary(long long round_count, Player* computer, Player* human);

int main(int argc, char** argv)
{
    if(argc != 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    long long round_count = 0;
    try {
        round_count = std::stoll(argv[1]);
    } catch(const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
    } catch(const std::out_of_range& e) {
        std::cerr << e.what() << '\n';
    }

    if(round_count <= 0) {
        std::cerr << "Round count has to be greater than 0.\n";
        return EXIT_FAILURE;
    }

    std::unique_ptr<Player> human = std::make_unique<Human>();
    std::unique_ptr<Player> computer = std::make_unique<Computer>();

    long long round = 0;
    while(round_count--) {
        std::cout << "Round #" << round++ << '\n';
        RPS rps(computer.get(), human.get());
        rps.fight();
    }

    printSummary(round, computer.get(), human.get());

    return EXIT_SUCCESS;
}

void printSummary(long long round_count, Player* computer, Player* human)
{
    const auto human_score = human->getScore();
    const auto computer_score = computer->getScore();

    std::cout << "Game Summary:\n";
    std::cout << "\t\tHuman: " << human_score << '\n';
    std::cout << "\t\tComputer: " << computer_score << '\n';
    std::cout << "\t\tTie: " << round_count - human_score - computer_score << std::endl;
}