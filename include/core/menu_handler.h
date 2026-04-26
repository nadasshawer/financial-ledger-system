#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

/**
 - @file menu_handler.h
 - @brief Primary navigation hub for the application.
          Contains the main menu logic that allows users to toggle 
          between Expense, Income, and Budget tracking modules.
 */

/**
 - @brief Displays the main tracker selection menu and routes the user to their choice.
 - @details Runs an infinite loop until a valid choice (A, B, or C) is made. 
            Integrates with data_display functions to launch specific trackers.
 - @note This is the primary entry point for the application's main logic loop.
 */
void chooseTracker();

#endif