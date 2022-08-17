#include "rps/human.h"
#include "utility.h"
#include "constants.h"

std::string Human::getDescription() const
{
    return HUMAN;
}

Weapon Human::pickWeapon()
{
    std::cout << "\tPick: ";

    for(int i = 0; i < weapons.size(); ++i) {
        std::cout << i + 1 << ") " << weapons[i] << ' ';
    }

    const auto my_choice = readStream(std::cin, 1, weapons.size());
    weapon_ = static_cast<Weapon>(my_choice);

    std::cout << "I picked " << enumToString(weapon_) << '\n';

    return weapon_;
}