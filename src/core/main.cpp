/**
 - @file main.cpp
 - @brief Entry point for the Flux Systems Engine.
 - @details Initializes the FTXUI screen and manages the high-level application flow.
 */

#include "../include/core/registration.h"
#include "../include/core/login.h"
#include "../include/core/menu_handler.h"
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

/**
 - @brief Main application loop.
 - @return int Execution status code.
 */
int main() {
    using namespace ftxui;

    // The ScreenInteractive class manages the terminal rendering loop
    auto screen = ScreenInteractive::TerminalOutput();

    // Start with the registration sequence
    registerUser();

    // Loop for authentication
    bool authenticated = false;
    authenticated = loginUser(); 

    if (authenticated) {
        chooseTracker();
    }

    return 0;
}