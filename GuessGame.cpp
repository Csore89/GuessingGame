// main.cpp
#include "Game.h"
#include "Utils.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));
    int easter = 69;
    bool playAgain = true;
    string playerName;


	// Introduction
    sayAndScroll("Hello player! Let's begin.", "HELLO PLAYER! LET'S BEGIN!\n", 3, 35);
    sayAndScroll("Welcome to the Guessing Game!", "WELCOME TO THE GUESSING GAME!\n", 3, 35);


	// Get player name
    typeWriter("BTW, What is your name?\n", 20);
    getline(cin, playerName);
    typeWriter("WHY HELLO THERE, " + playerName + "! GET READY TO LOSE! >:O\n", 10);

	// Choose range and difficulty
    Range range = chooseRange();
    int attempts = chooseDifficulty();


	// Game loop
    while (playAgain) {
        int target = rand() % (range.maxNum - range.minNum + 1) + range.minNum;
        guessingGame(target, easter, playerName, attempts, range.minNum, range.maxNum);

        typeWriter("Play again? (yes/no)\n", 20);
        string response;
        cin >> response;

        if (response == "yes" || response == "YES") {
            typeWriter("Choose a new range for the next game!\n", 10);
            range = chooseRange();
            attempts = chooseDifficulty();
            typeWriter("HELL YEAH! LET’S GO AGAIN! >:)\n", 10);
        }
        else {
            playAgain = false;
            typeWriter("Thanks for playing, " + playerName + "! Goodbye!\n", 20);
        }
    }

    return 0;
}
