#include "Computer.h"
#include "utility.h"
#include "constants.h"

std::string Computer::getDescription() const
{
    return COMPUTER;
}

void Computer::pickWeapon()
{
    const int num = getUniformRandomNumber(static_cast<int>(Weapon::Rock), static_cast<int>(Weapon::Scissors));
    weapon_ = static_cast<Weapon>(num);
    std::cout << "Computer picked " << enumToString(weapon_) << '\n';
}

void Computer::win()
{
    std::cout << "Winner: " << getDescription() << "\n\n\n";
    ++score_;
}
