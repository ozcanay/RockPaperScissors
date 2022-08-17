#include "rps/computer.h"
#include "utility.h"
#include "constants.h"

std::string Computer::getDescription() const
{
    return COMPUTER;
}

Weapon Computer::pickWeapon()
{
    const int num = getUniformRandomNumber(static_cast<int>(Weapon::Rock), static_cast<int>(Weapon::Scissors));
    weapon_ = static_cast<Weapon>(num);
    std::cout << "computer picked " << enumToString(weapon_) << '\n';

    return weapon_;
}