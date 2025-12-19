/* 
 * Author: Sean Sperry
 * Course: CS 210
 * Project: Chada Tech Clocks
 * Description:
 * Simulates two clocks (12-hour and 24-hour) displayed simultaneously.
 * User can add hours, minutes, or seconds via a menu.
 * Includes helper functions for formatting output.
 */

#include <iostream>
#include <string>
#include "Clock.h"
using namespace std;

// Format integers as 2-digit strings (e.g., 05, 09)
string twoDigit(int num) {
    return (num < 10 ? "0" + to_string(num) : to_string(num));
}

// Repeat a character (used for formatting clock borders)
string repeatChar(char c, int count) {
    return string(count, c);
}

// Display both 12-hour and 24-hour clocks
void displayClocks(const Clock& clock) {
    cout << repeatChar('*', 26) << " " << repeatChar('*', 26) << endl;
    cout << "*     12-Hour Clock      * *     24-Hour Clock      *" << endl;

    // Print each time format side by side
    cout << "*     " << clock.get12Hour() << "        * *        "
         << clock.get24Hour() << "        *" << endl;

    cout << repeatChar('*', 26) << " " << repeatChar('*', 26) << endl;
}

// Display menu options for user interaction
void displayMenu() {
    cout << endl;
    cout << "*************** Menu ***************" << endl;
    cout << "1 - Add One Hour" << endl;
    cout << "2 - Add One Minute" << endl;
    cout << "3 - Add One Second" << endl;
    cout << "4 - Exit Program" << endl;
    cout << "************************************" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int hour, minute, second;

    // Get initial time values from the user
    cout << "Enter initial hour: ";
    cin >> hour;
    cout << "Enter initial minute: ";
    cin >> minute;
    cout << "Enter initial second: ";
    cin >> second;

    // Create a clock object (values normalize automatically)
    Clock clock(hour, minute, second);

    int choice = 0;

    // Main program loop
    while (choice != 4) {
        displayClocks(clock);
        displayMenu();
        cin >> choice;

        // Process user menu selection
        switch (choice) {
        case 1:
            clock.addHour();     // Increment hour
            break;
        case 2:
            clock.addMinute();   // Increment minute
            break;
        case 3:
            clock.addSecond();   // Increment second
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}
