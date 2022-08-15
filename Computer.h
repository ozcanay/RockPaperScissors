#pragma once

#include "player.h"

class Computer : public Player {
public:
    ~Computer() override = default;
    [[nodiscard]] std::string getDescription() const override;
    void pickWeapon() override;
    void win() override;
};
