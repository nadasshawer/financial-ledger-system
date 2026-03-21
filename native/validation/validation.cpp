// File Imports
#include "../../include/validation/validation.h"
#include "../../include/utils/datetime.h"

// Library Imports
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

// --- Check user name input ---
bool checkNameInput(std::string name) {
  bool goodInput = true;

  if (name.empty()) {
    goodInput = false;
  }

  for (char c : name) {
    // If it's invalid input (not a letter AND not a space)
    if (!std::isalpha(static_cast<unsigned char>(c)) && !std::isspace (static_cast<unsigned char>(c))) {
      goodInput = false;
      break;
    }
  }
  return goodInput;
}

// --- Map month info together ---
MonthInfo mapMonthInfo(int month, int year) {
  // February days (leap years)
  int febDays =
      ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;

  // Vector storing structs of month data (name, numerical value, max days)
  std::vector<MonthInfo> calendar = {
      {"January", 1, 31},  {"February", 2, febDays}, {"March", 3, 31},
      {"April", 4, 30},    {"May", 5, 31},           {"June", 6, 30},
      {"July", 7, 31},     {"August", 8, 31},        {"September", 9, 30},
      {"October", 10, 31}, {"November", 11, 30},     {"December", 12, 31}};

  for (const auto &m : calendar) {
    if (m.monthNum == month) {
      return m;
    }
  }
  return {"", 0, 0};
}

// --- Check day input ---
bool checkDayInput(int day, const MonthInfo &monthStruct) {
  if (day >= 1 && day <= monthStruct.maxDays) {
    return true; // day is valid
  }
  return false; // day is invalid
}

// -- Check month integer input ---
bool checkNumMonthInput(int month) {
  if (month >= 1 && month <= 12) {
    return true;
  }
  return false;
}

// --- Check year input ---
bool checkYearInput(int year) {
  tm* timeNowPtr = getCurrentDateAndTime();
  int currentYear = getCurrentYear(*timeNowPtr);
  return (year <= currentYear && year >= 2020);
}

// --- Check source input is a valid source ---
bool checkSourceInput(std::string source) {
  if (!source.empty() && source.length() <= 50) {
    bool hasContent = false;
    for (char c : source) {
      if (!std::isspace(c)) {
        hasContent = true;
        break;
      }
    }
    if (!hasContent) {
      return false;
    }
    for (char c : source) {
      if (!std::isalnum(c) && c != '&' && c != '.' && c != '-') {
        return false;
      }
    }
  }
  return true;
}

// --- Check gross amount is a valid monetary amount ---
bool checkGrossAmount(double amount) {
  if (std::isfinite(amount)) {
    if (amount > 0.0 && amount <= 1000000) {
      return true;
    }
  }
  return false;
}
