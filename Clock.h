/* 
 * Author: Sean Sperry
 * Header File: Clock.h
 * Contains Clock class definition for time tracking.
 */

#ifndef CLOCK_H
#define CLOCK_H

#include <string>

class Clock {
private:
    int hour;   // 24-hour format (0–23)
    int minute; // 0–59
    int second; // 0–59

public:
    Clock(int h, int m, int s);

    // Methods to increment time values
    void addHour();
    void addMinute();
    void addSecond();

    // Return formatted time strings
    std::string get12Hour() const;
    std::string get24Hour() const;
};

#endif
