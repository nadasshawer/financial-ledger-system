/**
 - @file user_info.cpp
 - @brief Implementation of the UserInfo class for managing profile and auth data.
 - @details Refactored to remove namespace std and prepare for TUI integration.
 */

#include "../../include/auth/user_info.h"
#include "../../include/utils/datetime.h"
#include "../../include/utils/text_utils.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>

// --- Constructors ---

/**
 - @brief Default constructor for UserInfo.
 - @details Initializes all strings to empty and numerical values to zero.
 */
UserInfo::UserInfo() {
    FirstName = "";
    LastName = "";
    BirthDay = 0;
    BirthMonth = "";
    numericalBirthMonth = 0;
    BirthYear = 0;
    Age = 0;
    Password = "";
    Username = "";
}

/**
 - @brief Parameterized constructor for UserInfo.
 - @param cFirstName First name of the user.
 - @param cLastName Last name of the user.
 - @param cBirthDay Day of birth.
 - @param cBirthMonth Month of birth as a string.
 - @param cBirthYear Year of birth.
 - @param cUsername Chosen username.
 - @param cPassword User password.
 */
UserInfo::UserInfo(const std::string cFirstName, const std::string cLastName,
                   const int cBirthDay, const std::string cBirthMonth,
                   const int cBirthYear, const std::string cUsername,
                   const std::string cPassword) {
    FirstName = cFirstName;
    LastName = cLastName;
    BirthDay = cBirthDay;
    BirthMonth = cBirthMonth;
    BirthYear = cBirthYear;
    Username = cUsername;
    Password = cPassword;
}

// --- Setters ---

void UserInfo::setFirstName(const std::string firstName) {
    FirstName = capitalizeFirstLetter(firstName);
}

void UserInfo::setLastName(const std::string lastName) {
    LastName = capitalizeFirstLetter(lastName);
}

void UserInfo::setBirthDay(const int birthDay) {
    BirthDay = birthDay;
}

void UserInfo::setBirthMonth(const std::string birthMonth) {
    std::string capitalizedBirthMonth = birthMonth;
    if (!birthMonth.empty()) {
        if (std::islower(static_cast<unsigned char>(capitalizedBirthMonth[0]))) {
            capitalizedBirthMonth[0] = std::toupper(static_cast<unsigned char>(capitalizedBirthMonth[0]));
        }
    }
    BirthMonth = capitalizedBirthMonth;

    // Mapping month string to numerical value for age calculations
    std::map<std::string, int> months = {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
        {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
        {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };

    if (months.find(BirthMonth) != months.end()) {
        numericalBirthMonth = months[BirthMonth];
    }
}

void UserInfo::setBirthYear(const int birthYear) {
    BirthYear = birthYear;
}

void UserInfo::setPassword(const std::string password) {
    Password = password;
}

void UserInfo::setUsername(const std::string username) {
    Username = username;
}

void UserInfo::setAge() {
    tm* timePtr = getCurrentDateAndTime();
    int currentYear = getCurrentYear(*timePtr);
    int currentMonth = getCurrentMonth(*timePtr);
    int currentDay = getCurrentDay(*timePtr);

    Age = currentYear - BirthYear;

    // Adjustment if the birthday hasn't occurred yet in the current year
    if (numericalBirthMonth > currentMonth || 
       (numericalBirthMonth == currentMonth && BirthDay > currentDay)) {
        Age--;
    }
}

// --- Getters ---

std::string UserInfo::getFirstName() const {
    return FirstName;
}

std::string UserInfo::getLastName() const {
    return LastName;
}

int UserInfo::getBirthDay() const {
    return BirthDay;
}

std::string UserInfo::getBirthMonth() const {
    return BirthMonth;
}

int UserInfo::getBirthYear() const {
    return BirthYear;
}

int UserInfo::getAge() const {
    return Age;
}

std::string UserInfo::getUsername() const {
    return Username;
}

std::string UserInfo::getPassword() const {
    return Password;
}

// --- Display Methods ---

/**
 - @brief Prints the current system date.
 */
void UserInfo::getCurrentDate() {
    tm* timePtr = getCurrentDateAndTime();
    std::cout << getCurrentDay(*timePtr) << "/" 
              << getCurrentMonth(*timePtr) << "/" 
              << getCurrentYear(*timePtr);
}

/**
 - @brief Prints the current system time.
 */
void UserInfo::getCurrentTime() {
    tm* timePtr = getCurrentDateAndTime();
    std::cout << getCurrentHour(*timePtr) << ":" 
              << getCurrentMinute(*timePtr) << ":" 
              << getCurrentSecond(*timePtr) << std::endl;
}

/**
 - @brief Displays the formatted user profile to the console.
 */
void UserInfo::displayUserProfile() {
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Welcome, " << getFirstName() << "!" << std::endl;

    std::cout << "Last log in on ";
    getCurrentDate();
    std::cout << " at ";
    getCurrentTime();
    std::cout << std::endl;

    std::cout << "< YOUR INFO >" << std::endl;
    std::cout << "- Name: " << getFirstName() << " " << getLastName() << std::endl;
    std::cout << "- Birth Date: " << getBirthDay() << "/" << getBirthMonth() << "/" << getBirthYear() << std::endl;
    std::cout << "- Age: " << getAge() << " years" << std::endl << std::endl;

    std::cout << "< LOGIN INFO >" << std::endl;
    std::cout << "- Username: " << getUsername() << std::endl;
    std::cout << "---------------------------------------" << std::endl;
}