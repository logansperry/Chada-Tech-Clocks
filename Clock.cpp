/* 
 * Author: Sean Sperry
 * Source File: Clock.cpp
 * Implements Clock class behavior and formatting.
 */

#include "Clock.h"
#include <string>
using namespace std;

// Format function declared in main.cpp
string twoDigit(int num);

// Initialize clock, ensuring values wrap correctly
Clock::Clock(int h, int m, int s) {
    hour = h % 24;
    minute = m % 60;
    second = s % 60;
}

void Clock::addHour() {
    hour = (hour + 1) % 24;  // Wraps after 23 -> 0
}

void Clock::addMinute() {
    minute = (minute + 1) % 60;
    if (minute == 0)
        addHour();           // Wrap minute rollover into hour
}

void Clock::addSecond() {
    second = (second + 1) % 60;
    if (second == 0)
        addMinute();         // Wrap second rollover into minute
}

// Format and return 12-hour time with AM/PM
string Clock::get12Hour() const {
    int displayHour = hour % 12;
    if (displayHour == 0) displayHour = 12;

    string period = (hour >= 12) ? " PM" : " AM";

    return twoDigit(displayHour) + ":" +
           twoDigit(minute) + ":" +
           twoDigit(second) + period;
}

// Format and return 24-hour time
string Clock::get24Hour() const {
    return twoDigit(hour) + ":" +
           twoDigit(minute) + ":" +
           twoDigit(second);
}
