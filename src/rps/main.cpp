#include <iostream>
#include <string>

#include "game.h"
#include "constants.h"
#include "utility.h"

int main(int argc, char** argv)
{
    if(argc != 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    int round_count;
    try {
        round_count = std::stoi(argv[1]);
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
    Game game(human, computer);

    while(round_count--) {
        game.armPlayers();

        const auto winner = Game::pickWinner(human, computer);
        if(winner) {
            winner->win();
            std::cout << "Winner: " << winner->getDescription() << "\n\n\n";
        } else {
            std::cout << NO_WINNER_MSG << "\n\n\n";
        }
    }

    game.printSummary();

    return EXIT_SUCCESS;
}