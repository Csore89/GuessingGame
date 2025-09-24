// Utils.cpp
#include "Utils.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <cstdlib>

using namespace std;


// Set console text color
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
// Typewriter effect for displaying text
void typeWriter(const string& text, int delay, int color) {
    setColor(color);
    for (char c : text) {
        cout << c;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
    setColor(7); // reset
}


// Text-to-speech using SAPI
void say(const string& message, int rate) {
    string command = "mshta vbscript:Execute(\"Dim v:Set v=CreateObject(\"\"SAPI.SpVoice\"\"):v.Rate="
        + to_string(rate) + ":v.Speak(\"\"" + message + "\"\")(window.close)\")";
    system(command.c_str());
}


// Combine speech and typewriter effect
void sayAndScroll(const string& voiceText, const string& scrollText, int voiceRepeat, int scrollDelay) {
    thread t(say, voiceText, voiceRepeat);
    typeWriter(scrollText, scrollDelay);
    t.detach();
}
