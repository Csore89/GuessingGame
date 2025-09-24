// Utils.h
#ifndef UTILS_H
#define UTILS_H

#include <string>

// Function prototypes
void setColor(int color);
void typeWriter(const std::string& text, int delay = 50, int color = 7);
void say(const std::string& message, int rate = 0);
void sayAndScroll(const std::string& voiceText, const std::string& scrollText, int voiceRepeat = 1, int scrollDelay = 50);

#endif
