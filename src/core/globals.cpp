/**
 - @file globals.cpp
 - @brief Definitions for global variables used across the Flux Engine.
 */

#include "../../include/auth/user_info.h"
#include "../../include/core/globals.h"
#include "../../include/models/classes.h"

#include <vector>
#include <string>

// Global Data Initialization
std::vector<Expense> allExpenses;
std::vector<Income> allIncome;
std::string currency = "$"; // default currency

// Define the global user objects
UserInfo newUser; 
UserInfo currentUser;