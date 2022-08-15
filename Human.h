#pragma once

#include "player.h"

class Human : public Player {
public:
    ~Human() override = default;
    [[nodiscard]] std::string getDescription() const override;
    void pickWeapon() override;
    void win() override;
};
