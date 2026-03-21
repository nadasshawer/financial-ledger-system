// File Imports
#include "../../include/models/classes.h"
#include "../../include/validation/validation.h"
#include "../../include/utils/text_utils.h"
#include "../../include/utils/math_utils.h"
#include "../../include/core/globals.h"

// Library Imports
#include <iostream>
#include <string>
#include <vector>

// Global Variables
char newExpChoice;

// --- Transactions Class (Base for Expense, Income) ---
// Setters & Getters
void Transaction::setName(std::string name) {
  bool validName = checkNameInput(name);
  if (validName == true) {
    std::string capitalizedName = capitalizeFirstLetter(name);
    this->Name = capitalizedName;
  } else {
    this->Name = "";
  }
}
std::string Transaction::getName() const { return Name; }

void Transaction::setMonth(int month) {
  bool checkedMonth = checkNumMonthInput(month);
  if (checkedMonth) {
    this->Month = month;
  } else {
    this->Month = 0;
  }
}
int Transaction::getMonth() const { return Month; }

void Transaction::setYear(int year) {
  bool checkedYear = checkYearInput(year);
  if (checkedYear) {
    this->Year = year;
  } else {
    this->Year = 0;
  }
}
int Transaction::getYear() const { return Year; }

void Transaction::setDay(int day) {
  MonthInfo monthDetails = mapMonthInfo(this->Month, this->Year);
  bool checkedDay = checkDayInput(day, monthDetails);
  if (checkedDay) {
    this->Day = day;
  } else {
    this->Day = 0;
  }
}
int Transaction::getDay() const { return Day; }

void Transaction::setCategory(std::string category) {
  bool validCategory = checkNameInput(category);
  if (validCategory == true) {
    std::string capitalizedCategory = capitalizeFirstLetter(category);
    this->Category = capitalizedCategory;
  } else {
    this->Category = "";
  }
}
std::string Transaction::getCategory() const { return Category; }

void Transaction::setDescription(std::string description) {
  std::string capitalizedDescription = capitalizeFirstLetter(description);
  this->Description = capitalizedDescription;
}
std::string Transaction::getDescription() const { return Description; }

void Transaction::setAmount(double amount) {
  double roundedAmount = roundTo2Digits(amount);
  this->Amount = roundedAmount;
}
double Transaction::getAmount() const { return Amount; }

// Default constructor
Transaction::Transaction() {
  Name = "";
  Day = 0;
  Month = 0;
  Year = 0;
  Category = "";
  Description = "";
  Amount = 0;
}

// Stored Transaction Info Constructor
Transaction::Transaction(const std::string cName, const int cDay,
                         const int cMonth, const int cYear,
                         const std::string cCategory,
                         const std::string cDescription, const double cAmount) {
  setName(cName);
  setMonth(cMonth);
  setYear(cYear);
  setDay(cDay);
  setCategory(cCategory);
  setDescription(cDescription);
  setAmount(cAmount);
}

// --- Expenses Class ---
// Default constructor
Expense::Expense() {
  Name = "";
  Day = 0;
  Month = 0;
  Year = 0;
  Category = "";
  Description = "";
  Amount = 0;
}

// Stored Expense Info Constructor
Expense::Expense(const std::string cName, const int cDay, const int cMonth,
                 const int cYear, const std::string cCategory,
                 const std::string cDescription, const double cAmount)
    : Transaction(cName, cDay, cMonth, cYear, cCategory, cDescription,
                  cAmount) {};

// --- Income Class ---
// Setters & Getters
void Income::setSource(const std::string source) {
  bool validSource = checkSourceInput(source);
  if (validSource) {
    std::string capitalizedSource = capitalizeFirstLetter(source);
    this->Source = capitalizedSource;
  } else {
    this->Source = "";
  }
}
std::string Income::getSource() const { return Source; }

void Income::setGrossAmount(const double grossAmount) {
  this->GrossAmount = grossAmount;
}
double Income::getGrossAmount() const { return GrossAmount; }

void Income::setFrequency(const int frequency) { this->Frequency = frequency; }
int Income::getFrequency() const { return Frequency; }

void Income::setMode(const std::string mode) {
  std::string capitalizedMode = capitalizeFirstLetter(mode);
  this->Mode = capitalizedMode;
}
std::string Income::getMode() const { return Mode; }

void Income::setTaxRate(const double taxRate) { this->TaxRate = taxRate; }
double Income::getTaxRate() const { return TaxRate; }

void Income::setTaxCategory(const std::string taxCategory) {
  std::string capitalizedTaxCategory = capitalizeFirstLetter(taxCategory);
  this->TaxCategory = capitalizedTaxCategory;
}
std::string Income::getTaxCategory() const { return TaxCategory; }

void Income::setStatus(const std::string status) { this->Status = status; }
std::string Income::getStatus() const { return Status; }

void Income::setBudgetAllocation(const std::string budgetAllocation) {
  this->BudgetAllocation = budgetAllocation;
}
std::string Income::getBudgetAllocation() const { return BudgetAllocation; }

// Default Constructor
Income::Income() {
  Name = "";
  Day = 0;
  Month = 0;
  Year = 0;
  Category = "";
  Description = "";
  Source = "";
  GrossAmount = 0;
  Frequency = 0;
  Mode = "";
  TaxRate = 0;
  TaxCategory = "";
  Status = "";
  BudgetAllocation = "";
}

// Stored Income Info Constructor
Income::Income(const std::string cName, const int cDay, const int cMonth,
               const int cYear, const std::string cSource,
               const double cGrossAmount, const std::string cCategory,
               const std::string cDescription, const double cAmount,
               const int cFrequency, const std::string cMode,
               const double cTaxRate, const std::string cTaxCategory,
               const std::string cStatus, const std::string cBudgetAllocation)
    : Transaction(cName, cDay, cMonth, cYear, cCategory, cDescription,
                  cAmount) {
  setSource(cSource);
  setGrossAmount(cGrossAmount);
  setFrequency(cFrequency);
  setMode(cMode);
  setTaxRate(cTaxRate);
  setTaxCategory(cTaxCategory);
  setStatus(cStatus);
  setBudgetAllocation(cBudgetAllocation);
};

// --- Budget Class ---
// Setters & Getters
void Budget::setBudgetedAmount(const double budgetedAmount) {
  BudgetedAmount = budgetedAmount;
}
double Budget::getBudgetedAmount() const { return BudgetedAmount; }
void Budget::setActualAmount(const double actualAmount) {
  ActualAmount = actualAmount;
}
double Budget::getActualAmount() const { return ActualAmount; }

// Default Constructor
Budget::Budget() {
  BudgetedAmount = 0;
  ActualAmount = 0;
}

// Stored Budget Info Constructor
Budget::Budget(const double cBudgetedAmount, const double cActualAmount) {
  BudgetedAmount = cBudgetedAmount;
  ActualAmount = cActualAmount;
}

// Methods
std::string Budget::calcDifference() {
  double difference;
  difference = BudgetedAmount - ActualAmount;
  if (difference < 0) {
    return "-ve cash flow";
  } else {
    return "+ve cash flow";
  }
}
