/**
 - @file menu_handler.cpp
 - @brief implementation of the flux systems engine visual menu.
 */

#include "../../include/core/menu_handler.h"
#include "../../include/core/tui_palette.h"
#include <iostream>

void chooseTracker() {
    // clears the terminal for a clean start
    std::cout << CLEAR_SCREEN;

    // header section
    std::cout << FLUX_PINK << "========================================" << RESET << std::endl;
    std::cout << FLUX_PURPLE << BOLD << "       FLUX SYSTEMS ENGINE v1.0        " << RESET << std::endl;
    std::cout << FLUX_PINK << "========================================" << RESET << std::endl;

    std::cout << "\nHi! What do you want to track today?\n" << std::endl;

    // menu options with mint accents
    std::cout << FLUX_MINT << " [A] " << RESET << "Expense Tracker" << std::endl;
    std::cout << FLUX_MINT << " [B] " << RESET << "Income Tracker" << std::endl;
    std::cout << FLUX_MINT << " [C] " << RESET << "Budget Tracker" << std::endl;
    std::cout << FLUX_ORANGE << " [X] " << RESET << "Exit Engine" << std::endl;

    std::cout << "\n" << FLUX_PINK << "Your Selection --> " << RESET;
}