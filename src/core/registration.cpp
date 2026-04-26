/**
 - @file registration.cpp
 - @brief Implementation of the registration flow.
 */

#include "../../include/core/registration.h"
#include "../../include/auth/user_info.h"
#include "../../include/validation/validation.h"
#include <iostream>
#include <string>
#include <limits>

extern UserInfo newUser;

void registerUser() {
    std::string inputStr;
    int inputInt;

    std::cout << "USER REGISTRATION" << std::endl;

    while (true) {
        std::cout << "- First Name: ";
        std::cin >> inputStr;
        if (checkNameInput(inputStr)) {
            newUser.setFirstName(inputStr);
            break;
        }
        std::cout << "Invalid input. Please use letters only." << std::endl;
    }

    while (true) {
        std::cout << "- Birth Year: ";
        if (!(std::cin >> inputInt)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (checkYearInput(inputInt)) {
            newUser.setBirthYear(inputInt);
            break;
        }
        std::cout << "Invalid year." << std::endl;
    }

    // This structure allows the TUI to eventually replace the 'while' loops
    // while keeping the 'newUser.set...' and 'check...Input' logic identical.
    
    newUser.setAge();
    std::cout << "Registration complete for " << newUser.getFirstName() << std::endl;
}