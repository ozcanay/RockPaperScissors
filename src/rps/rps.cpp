#include "rps/rps.h"

#include <iostream>

#include "rps/player.h"
#include "constants.h"

Player* pickWinner(Player& player1, Player& player2)
{
    Player* winner;
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