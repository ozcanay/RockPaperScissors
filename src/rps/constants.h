#pragma once

#include <string>
#include <array>

static const std::string ROCK = "Rock";
static const std::string PAPER = "Paper";
static const std::string SCISSORS = "Scissors";
static const std::string UNKNOWN = "Unknown";

static const std::string COMPUTER = "Computer";
static const std::string HUMAN = "Human";
static const std::string NO_WINNER_MSG = "No winner in this round!";
static const std::string UNEXPECTED_WEAPON_MSG = "Unexpected weapon!";
static const std::string INVALID_INPUT_MSG = "Your choice is not valid. Please pick one of the choices displayed in the terminal!";

static const std::array<std::string, 3> weapons{ROCK, PAPER, SCISSORS};
