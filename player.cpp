#include "player.h"
#include "constants.h"

#include <iostream>

int Player::getScore() const
{
    return score_;
}

Weapon Player::getWeapon() const
{
    return weapon_;
}

std::string Player::getDescription() const
{
    return description_;
}

void Player::win()
{
    ++score_;
}

std::string enumToString(Weapon weapon) {
    std::string res;

    switch (weapon) {
        case Weapon::Rock:
            res = ROCK;
            break;
        case Weapon::Paper:
            res = PAPER;
            break;
        case Weapon::Scissors:
            res = SCISSORS;
            break;
        default:
            res = UNKNOWN;
            std::cerr << UNEXPECTED_WEAPON_MSG << '\n';
    }

    return res;
}