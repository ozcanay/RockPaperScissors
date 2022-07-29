#include "rps.h"

#include <iostream>
#include <cmath>
#include <random>
#include <cassert>

RPS::RPS(int N)
    : N_{N}
    , my_weapon_{Weapon::Rock}
    , its_weapon_{Weapon::Rock}
{
    startGameLoop();
}

void RPS::startGameLoop()
{
    for(int i = 0; i < N_; ++i) {
        std::cout << "Game #" << i + 1 << '\n';
        std::cout << "\tPick: 1) Rock, 2) Paper, 3) Scissors" << std::endl;

        int my_choice = -1;
        std::cin >> my_choice;

        if(my_choice < 1 || my_choice > 3) {
            std::cerr << "Your choice is not valid. Please pick one of the choices displayed in the terminal.\n";
            --i;
            continue;
        }

        setMyWeapon(my_choice - 1);
        setItsWeapon();

        if(my_weapon_ == its_weapon_) {
            std::cout << "None could beat the other!\n";
            ++tie_count_;
            continue;
        } else {
            const auto winner_weapon = pickWinner();
            const std::string winner = (winner_weapon == my_weapon_ ? (++my_score_, "Me") : (++its_score_, "Computer"));

            std::cout << "Winner is " << winner << '\n';
            std::cout << "-----------------------------------------------------------------------------------\n";
        }
    }

    std::cout << "Game ended. Scores:\n";
    std::cout << "\tMy score: " << my_score_ << '\n';
    std::cout << "\tComputer's score: " << its_score_ << '\n';
    std::cout << "\tTie count: " << tie_count_ << '\n';
}

RPS::Weapon RPS::pickWinner()
{
    assert(my_weapon_ != its_weapon_);

    const auto w1 = static_cast<int>(my_weapon_);
    const auto w2 = static_cast<int>(its_weapon_);

    const auto abs_diff = std::abs(w1 - w2);

    if(abs_diff == 1) {
        return w2 > w1 ? its_weapon_ : my_weapon_;
    } else {
        return w1 < w2 ? my_weapon_ : its_weapon_;
    }
}

void RPS::setItsWeapon()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uni_distribution(static_cast<int>(Weapon::Rock), static_cast<int>(Weapon::Scissors));
    its_weapon_ = static_cast<Weapon>(uni_distribution(gen));

    std::cout << "Computer picked " << enumToString(its_weapon_) << '\n';
}

void RPS::setMyWeapon(int choice)
{
    my_weapon_ = static_cast<Weapon>(choice);
    std::cout << "I picked " << enumToString(my_weapon_) << '\n';
}

std::string RPS::enumToString(RPS::Weapon weapon) {
    std::string res;

    switch (weapon) {
        case Weapon::Rock:
            res = "Rock";
            break;
        case Weapon::Paper:
            res = "Paper";
            break;
        case Weapon::Scissors:
            res = "Scissors";
            break;
        default:
            res = "Unknown";
            std::cerr << "Unexpected weapon!\n";
    }

    return res;
}
