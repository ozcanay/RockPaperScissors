#pragma once

#include <string>

enum class Weapon {
    Unarmed = 0,
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

class Player {
public:
    [[nodiscard]] int getScore() const;
    [[nodiscard]] Weapon getWeapon() const;

    virtual ~Player() = default;
    [[nodiscard]] virtual std::string getDescription() const = 0;
    virtual Weapon pickWeapon() = 0;
    void setWeapon(Weapon weapon);
    void win();

protected:
    Weapon weapon_ = Weapon::Unarmed;
    int score_ = 0;
    std::string description_;
};

std::string enumToString(Weapon weapon);

