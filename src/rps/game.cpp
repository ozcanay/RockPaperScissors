#include "game.h"
#include "constants.h"

#include <iostream>

Game::Game(Human& human, Computer& computer)
    : human_{human}
    , computer_{computer}
{

}

void Game::armPlayers()
{
    std::cout << "Round #" << round_count_++ << '\n';

    human_.pickWeapon();
    computer_.pickWeapon();
}

Player* Game::pickWinner(Player& player1, Player& player2)
{
    Player* winner = nullptr;
    const auto player1_weapon = player1.getWeapon();

    if(player1_weapon == Weapon::Rock) {
        const auto player2_weapon = player2.getWeapon();
        if(player2_weapon == Weapon::Rock) {
            winner = nullptr;
        } else if(player2_weapon == Weapon::Paper) {
            winner = &player2;
        } else if(player2_weapon == Weapon::Scissors) {
            winner = &player1;
        } else {
            std::cout << UNEXPECTED_WEAPON_MSG << " on " << player2.getDescription() << "\n";
        }
    } else if(player1_weapon == Weapon::Paper) {
        const auto player2_weapon = player2.getWeapon();
        if(player2_weapon == Weapon::Rock) {
            winner = &player1;
        } else if(player2_weapon == Weapon::Paper) {
            winner = nullptr;
        } else if(player2_weapon == Weapon::Scissors) {
            winner = &player2;
        } else {
            std::cout << UNEXPECTED_WEAPON_MSG << " on " << player2.getDescription() << "\n";
        }
    } else if(player1_weapon == Weapon::Scissors) {
        const auto player2_weapon = player2.getWeapon();
        if(player2_weapon == Weapon::Rock) {
            winner = &player2;
        } else if(player2_weapon == Weapon::Paper) {
            winner = &player1;
        } else if(player2_weapon == Weapon::Scissors) {
            winner = nullptr;
        } else {
            std::cout << UNEXPECTED_WEAPON_MSG << " on " << player2.getDescription() << "\n";
        }
    } else {
        std::cout << UNEXPECTED_WEAPON_MSG << " on " << player1.getDescription() << "\n";
    }

    return winner;
}

void Game::printSummary()
{
    const auto human_score = human_.getScore();
    const auto computer_score = computer_.getScore();

    std::cout << "Game Summary:\n";
    std::cout << "\t\tRound count: " << round_count_ << '\n';
    std::cout << "\t\tHuman: " << human_score << '\n';
    std::cout << "\t\tComputer: " << computer_score << '\n';
    std::cout << "\t\tTie: " << round_count_ - human_score - computer_score << std::endl;
}