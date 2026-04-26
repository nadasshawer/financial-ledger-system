#ifndef VALIDATION_H
#define VALIDATION_H

/**
 - @file validation.h
 - @brief Functions and structures for data validation and mapping.
          This file ensures that user inputs for dates, names, and 
          amounts are logically correct before being processed.
 */

#include <string>
#include "../models/classes.h"

/**
 - @brief Validates if a string input is a valid name.
 - @param name: The string to be checked.
 - @return bool: True if the name contains only valid characters and length.
 */
bool checkNameInput(std::string name);

/**
 - @brief Maps date integers to a MonthInfo structure.
 - @param month: The month number.
 - @param year: The year (used to calculate leap year for February).
 - @return MonthInfo: A structure containing the month's name and limit.
 */
MonthInfo mapMonthInfo(int month, int year);

/**
 - @brief Validates if a day is within the correct range for a specific month.
 - @param day: The day to check.
 - @param monthStruct: The MonthInfo struct containing the maxDays limit.
 - @return bool: True if the day is valid for that specific month.
 */
bool checkDayInput(int day, const MonthInfo &monthStruct);

/**
 - @brief Validates if a month number is between 1 and 12.
 - @param month: The integer month input.
 - @return bool: True if the month is valid.
 */
bool checkNumMonthInput(int month);

/**
 - @brief Validates if a year is within a realistic range.
 - @param year: The integer year input.
 - @return bool: True if the year is valid (not in the far future/past).
 */
bool checkYearInput(int year);

/**
 - @brief Validates if a source input is a valid source.
 - @param source: The source string to be checked.
 - @return bool: True if the source contains only valid characters and length.
**/
bool checkSourceInput(std::string source);

/**
 - @brief Validates if a gross amount is a valid amount.
 - @param amount: The amount double to be checked.
 - @return bool: True if the amount is finite and within the valid range.
**/
bool checkGrossAmount(double amount);

/**
 - @brief Validates password and returns specific missing requirements.
 - @param pw The password string to check.
 - @return std::string "VALID" or a specific error message.
**/
std::string getPasswordFeedback(const std::string& pw);

#endif