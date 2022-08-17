#include "rps/rps.h"
#include "rps/human.h"
#include "rps/computer.h"
#include "rps/utility.h"

#include <gtest/gtest.h>

class RockPaperScissorsTests : public ::testing::Test {
protected:
    Human human;
    Computer computer;
    ~RockPaperScissorsTests() override = default;
};

TEST_F(RockPaperScissorsTests, PaperBeatsRock)
{
    human.setWeapon(Weapon::Rock);
    computer.setWeapon(Weapon::Paper);
    const auto winner = pickWinner(human, computer);
    ASSERT_EQ(winner->getWeapon(), Weapon::Paper);
}

TEST_F(RockPaperScissorsTests, RockBeatsScissors)
{
    human.setWeapon(Weapon::Rock);
    computer.setWeapon(Weapon::Scissors);
    const auto winner = pickWinner(human, computer);
    ASSERT_EQ(winner->getWeapon(), Weapon::Rock);
}

TEST_F(RockPaperScissorsTests, ScissorsBeatsPaper)
{
    human.setWeapon(Weapon::Scissors);
    computer.setWeapon(Weapon::Paper);
    const auto winner = pickWinner(human, computer);
    ASSERT_EQ(winner->getWeapon(), Weapon::Scissors);
}

TEST_F(RockPaperScissorsTests, RockTiesWithRock)
{
    human.setWeapon(Weapon::Rock);
    computer.setWeapon(Weapon::Rock);

    const auto winner = pickWinner(human, computer);
    ASSERT_EQ(winner, nullptr);
}

TEST_F(RockPaperScissorsTests, PaperTiesWithPaper)
{
    human.setWeapon(Weapon::Paper);
    computer.setWeapon(Weapon::Paper);

    const auto winner = pickWinner(human, computer);
    ASSERT_EQ(winner, nullptr);
}

TEST_F(RockPaperScissorsTests, ScissorsTiesWithScissors)
{
    human.setWeapon(Weapon::Scissors);
    computer.setWeapon(Weapon::Scissors);

    const auto winner = pickWinner(human, computer);
    ASSERT_EQ(winner, nullptr);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
