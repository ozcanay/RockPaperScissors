#include "Human.h"
#include "utility.h"
#include "constants.h"

std::string Human::getDescription() const
{
    return HUMAN;
}

void Human::pickWeapon()
{
    std::cout << OPTIONS_MSG << std::endl;

    int my_choice;
    std::cin >> my_choice;

    while(my_choice < 1 || my_choice > 3) {
        resetStdin();
        std::cerr << INVALID_INPUT_MSG << '\n';
        std::cout << OPTIONS_MSG << std::endl;

        std::cin >> my_choice;
    }

    weapon_ = static_cast<Weapon>(my_choice - 1);
    std::cout << "I picked " << enumToString(weapon_) << '\n';
}

void Human::win()
{
    std::cout << "Winner: " << getDescription() << "\n\n\n";
    ++score_;
}