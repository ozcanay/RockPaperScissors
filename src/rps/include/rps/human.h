#pragma once

#include "player.h"

class Human : public Player {
public:
    ~Human() override = default;
    [[nodiscard]] std::string getDescription() const override;
    Weapon pickWeapon() override;
};
