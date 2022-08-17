#pragma once

#include "human.h"
#include "computer.h"

class Game {
public:
    Game(Human& human, Computer& computer);
    void armPlayers();
    static Player* pickWinner(Player& player1, Player& player2);
    void printSummary();
private:
    Human& human_;
    Computer& computer_;
    int round_count_ = 0;
};
