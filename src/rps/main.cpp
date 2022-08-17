#include <iostream>
#include <string>

#include "constants.h"

#include "rps/rps.h"
#include "rps/human.h"
#include "rps/computer.h"
#include "rps/utility.h"

void printSummary(long long round_count, const Player& computer, const Player& human);

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
        std::cerr << e.what() << ", Invalid argument." << '\n';
        return EXIT_FAILURE;
    } catch(const std::out_of_range& e) {
        std::cerr << e.what() << ", Out of range." << '\n';
        return EXIT_FAILURE;
    }

    if(round_count <= 0) {
        std::cerr << "Round count has to be greater than 0.\n";
        return EXIT_FAILURE;
    }

    Human human;
    Computer computer;

    long long round = 0;
    while(round_count--) {
        std::cout << "Round #" << round++ << '\n';
        human.pickWeapon();
        computer.pickWeapon();

        const auto winner = pickWinner(computer, human);
        if(winner) {
            winner->win();
            std::cout << "Winner: " << winner->getDescription() << "\n\n\n";
        } else {
            std::cout << NO_WINNER_MSG << "\n\n\n";
        }
    }

    printSummary(round, computer, human);

    return EXIT_SUCCESS;
}

void printSummary(long long round_count, const Player& computer, const Player& human)
{
    const auto human_score = human.getScore();
    const auto computer_score = computer.getScore();

    std::cout << "Game Summary:\n";
    std::cout << "\t\tRound count: " << round_count << '\n';
    std::cout << "\t\tHuman: " << human_score << '\n';
    std::cout << "\t\tComputer: " << computer_score << '\n';
    std::cout << "\t\tTie: " << round_count - human_score - computer_score << std::endl;
}