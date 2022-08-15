#include "rps.h"

#include <iostream>
#include <cmath>

#include "constants.h"

RPS::RPS(Player* computer, Player* human)
    : computer_{computer}
    , human_{human}
{

}

void RPS::fight()
{
    setHumanWeapon();
    setComputerWeapon();
    setWinner();
}

void RPS::setWinner()
{
    Player* winner;

    const auto computer_weapon = static_cast<int>(computer_->getWeapon());
    const auto human_weapon = static_cast<int>(human_->getWeapon());
    const auto abs_diff = std::abs(computer_weapon - human_weapon);

    if(abs_diff == 0) {
        winner = nullptr;
    } else if(abs_diff == 1) {
        winner = human_weapon > computer_weapon ? human_ : computer_;
    } else {
        winner = computer_weapon < human_weapon ? computer_ : human_;
    }

    if(winner) {
        winner->win();
    } else {
        std::cout << NO_WINNER_MSG << "\n\n\n";
    }
}

void RPS::setComputerWeapon()
{
    computer_->pickWeapon();
}

void RPS::setHumanWeapon()
{
    human_->pickWeapon();
}