// Game.cpp
#include "Game.h"
#include "Utils.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;


// Function to choose the number range
Range chooseRange() {
    int rangeChoice;
    Range range;

    typeWriter("Now, would you be so kind to choose a range for the game?\n", 10);
    typeWriter("1. 1 to 100\n", 10);
    typeWriter("2. 1 to 1000\n", 10);
    typeWriter("3. 1 to 10000\n", 10);
    typeWriter("NOW FOLLOW THE RULES OR ELSE!\n", 10);
    cin >> rangeChoice;

	// Determine range based on user choice
    switch (rangeChoice) {
    case 1: range = { 1, 100 }; typeWriter("You chose a range of 1 to 100.\n", 10); break;
    case 2: range = { 1, 1000 }; typeWriter("You chose a range of 1 to 1000.\n", 10); break;
    case 3: range = { 1, 10000 }; typeWriter("You chose a range of 1 to 10000.\n", 10); break;
    default:
        typeWriter("YOU FOOL, YOU HAVE FALLEN INTO RANDOM MODE!\n", 10);
        range.minNum = rand() % 111 + 1;
        range.maxNum = range.minNum + rand() % 1000 + 100;
        break;
    }

    return range;
}


// Function to choose difficulty level
int chooseDifficulty() {
    int modeChoice, attempts;

    typeWriter("Now, would you be so kind to choose a mode :D.\n", 10);
    typeWriter("1. BABY MODE (Unlimited Attempts)\n", 10);
    typeWriter("2. WIMPY MODE (50 Attempts) >:P\n", 10);
    typeWriter("3. MAN MODE (30 Attempts) >:P\n", 10);
    typeWriter("4. GOD MODE!!! (10 Attempts) >:P\n", 10);
    typeWriter("Just type the number of the mode you want to play.\n", 10);
    cin >> modeChoice;

	// Determine attempts based on user choice
    switch (modeChoice) {
    case 1: attempts = -1; typeWriter("BABY MODE! Unlimited attempts.\n", 10); break;
    case 2: attempts = 50; typeWriter("WIMPY MODE! 50 attempts.\n", 10); break;
    case 3: attempts = 30; typeWriter("MAN MODE! 30 attempts.\n", 10); break;
    case 4: attempts = 10; typeWriter("GOD MODE!!! 10 attempts.\n", 10); break;
    default: attempts = -1; typeWriter("Defaulting to BABY MODE.\n", 10); break;
    }

    return attempts;
}


// Main guessing game function
void guessingGame(int target, int easter, string playerName, int attempts, int minNum, int maxNum) {
    int guess = 0;
    typeWriter("I have a number between " + to_string(minNum) + " and " + to_string(maxNum) + ". Can you guess it?\n", 35);

    while (guess != target) {
        cout << "---------------------------------------------------------------------\n";
        cout << "Enter your guess (" << minNum << " - " << maxNum << "): ";
        cin >> guess;

        if (guess == easter) {
            typeWriter("Excuse me? " + playerName + "!\n", 80);
            typeWriter("I don't have time for your perverted nonsense!\n", 5);
            continue;
        }
        else if (guess < minNum || guess > maxNum) {
            typeWriter("HEY, " + playerName + "! Didn't you read the range???\n", 25);
            continue;
        }

        if (guess < target) {
            cout << "Too low! Try Again!\n";
        }
        else if (guess > target) {
            cout << "Too high! Try Again!\n";
        }
        else {
            PlaySound(TEXT("assets/woo.wav"), NULL, SND_FILENAME | SND_ASYNC);
            typeWriter("Wow.....good job....you got it.... :(\n", 100);
            return;
        }

        if (attempts > 0) {
            attempts--;
            if (attempts == 0) {
                typeWriter("You have run out of attempts! YOU LOSE!!!\n", 20);
                return;
            }
            else {
                cout << "Attempts remaining: " << attempts << endl;
            }
        }
    }
}
