// File Imports
#include "../../include/utils/math_utils.h"
#include "../../include/models/classes.h"
#include "../../include/core/globals.h"

// Library Imports
#include <cmath>
#include <string>
#include <vector>

// --- Count digits in a number ---
int digitCount(int num) {
  int count = 0;
  if (num == 0) {
    return 1;
  } else if (num < 0) {
    num = std::abs(num); // get absolute value of -ve nums
  }
  while (num > 0) {
    num /= 10; // remove last digit with each iteration
    count++;
  }
  return count;
}

// --- Round number to 2 decimal places ---
double roundTo2Digits(double num) {
  double roundedNum = std::round(num * 100.0) / 100.0;
  return roundedNum;
}

// --- Calculate total of all expenses ---
double calcExpenseTotal() {
  double total = 0.0;
  for (Expense expense : allExpenses) {
    total += expense.getAmount();
  }
  return total;
}

// --- Calculate the net income from all sources ---
double calcIncomeTotal() {
  double total = 0.0;
  for (Income income : allIncome) {
    double decimalTax = income.getTaxRate() / 100.0;
    double netIncome = (income.getAmount() * income.getFrequency()) * (1.0 - decimalTax);
    total += netIncome;
  }
  return roundTo2Digits(total);
}
