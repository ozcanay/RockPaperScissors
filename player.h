#pragma once

#include <string>

enum class Weapon {
    Rock,
    Paper,
    Scissors
};

class Player {
public:
    [[nodiscard]] int getScore() const;
    [[nodiscard]] Weapon getWeapon() const;

    virtual void win();
    virtual ~Player() = default;
    [[nodiscard]] virtual std::string getDescription() const = 0;
    virtual void pickWeapon() = 0;

protected:
    Weapon weapon_ = Weapon::Rock;
    int score_ = 0;
    std::string description_;
};

std::string enumToString(Weapon weapon);

