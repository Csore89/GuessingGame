// Game.h
#ifndef GAME_H
#define GAME_H

#include <string>

// Struct to hold the number range
struct Range {
    int minNum;
    int maxNum;
};

// Game functions
Range chooseRange();
int chooseDifficulty();
void guessingGame(int target, int easter, std::string playerName, int attempts, int minNum, int maxNum);

#endif
