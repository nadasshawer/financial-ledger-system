/**
 - @file validation.cpp
 - @brief Implementation of validation logic using explicit std:: scoping.
 */

#include "../../include/validation/validation.h"
#include "../../include/models/classes.h"
#include "../../include/utils/datetime.h"
#include <string>
#include <algorithm>
#include <cctype>

// Name Validation
bool checkNameInput(std::string name) {
    if (name.empty()) return false;
    
    // Using std::all_of and explicit std::isalpha
    return std::all_of(name.begin(), name.end(), [](char c) {
        return std::isalpha(static_cast<unsigned char>(c)) || std::isspace(static_cast<unsigned char>(c));
    });
}

// Map Month Info (Handling Leap Years)
MonthInfo mapMonthInfo(int month, int year) {
    MonthInfo info;
    info.monthNum = month;

    switch (month) {
        case 1:  info.name = "January";   info.maxDays = 31; break;
        case 2: 
            info.name = "February";
            // Leap year logic
            info.maxDays = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
            break;
        case 3:  info.name = "March";     info.maxDays = 31; break;
        case 4:  info.name = "April";     info.maxDays = 30; break;
        case 5:  info.name = "May";       info.maxDays = 31; break;
        case 6:  info.name = "June";      info.maxDays = 30; break;
        case 7:  info.name = "July";      info.maxDays = 31; break;
        case 8:  info.name = "August";    info.maxDays = 31; break;
        case 9:  info.name = "September"; info.maxDays = 30; break;
        case 10: info.name = "October";   info.maxDays = 31; break;
        case 11: info.name = "November";  info.maxDays = 30; break;
        case 12: info.name = "December";  info.maxDays = 31; break;
        default: info.name = "Invalid";   info.maxDays = 0;  break;
    }
    return info;
}

// Year Input (2005 friendly!)
bool checkYearInput(int year) {
    tm* timePtr = getCurrentDateAndTime();
    int currentYear = getCurrentYear(*timePtr);
    
    return (year >= 1900 && year <= currentYear);
}

// Password Strength (Mechanical 8-char rule)
bool checkPasswordStrength(std::string pass) {
    return (pass.length() >= 8);
}

// Day Input Validation
bool checkDayInput(int day, const MonthInfo &monthStruct) {
    return (day >= 1 && day <= monthStruct.maxDays);
}

// Month Number Validation
bool checkNumMonthInput(int month) {
    return (month >= 1 && month <= 12);
}

/**
 - @brief Validates if the income/expense source string is not empty.
 - @param source The string to check.
 - @return true if valid, false otherwise.
 */
bool checkSourceInput(std::string source) {
    return !source.empty();
}