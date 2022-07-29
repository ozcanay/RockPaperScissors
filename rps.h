#pragma once

#include <string>

class RPS {
    /// order of items inside enum is important for algorithm to work!
    enum class Weapon {
        Rock,
        Paper,
        Scissors
    };

public:
    explicit RPS(int N);

private:
    void startGameLoop();
    Weapon pickWinner();
    void setItsWeapon();
    void setMyWeapon(int choice);
    static std::string enumToString(Weapon weapon);
private:
    int N_ = 0;
    Weapon my_weapon_;
    Weapon its_weapon_;

    int my_score_  = 0;
    int its_score_ = 0;
    int tie_count_ = 0;
};

