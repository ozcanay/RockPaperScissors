#pragma once

#include <string>

#include "player.h"

class RPS {
public:
    explicit RPS(Player* computer, Player* human);
    void fight();

private:
    void setWinner();
    void setComputerWeapon();
    void setHumanWeapon();

private:
    Player* computer_ = nullptr;
    Player* human_ = nullptr;
};

