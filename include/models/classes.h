/**
 - @file classes.h
 - @brief Defines the core financial data structures for the ledger system.
 */

#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>

/**
 - @struct MonthInfo
 */
struct MonthInfo {
    std::string name;
    int monthNum;
    int maxDays;
};

/**
 - @class Transaction
 */
class Transaction {
protected:
    std::string Name;
    int Day;
    int Month;
    int Year;
    std::string Category;
    std::string Description;
    double Amount;

public:
    // --- Setters ---
    bool setName(const std::string& name);
    bool setDay(int day);
    bool setMonth(int month);
    bool setYear(int year);
    bool setCategory(const std::string& category);
    bool setDescription(const std::string& description);
    bool setAmount(double amount);

    // --- Getters ---
    std::string getName() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    std::string getCategory() const;
    std::string getDescription() const;
    double getAmount() const;

    // --- Constructors ---
    Transaction();
    Transaction(const std::string& cName, int cDay, int cMonth,
                int cYear, const std::string& cCategory,
                const std::string& cDescription, double cAmount);
};

/**
 - @class Expense
 */
class Expense : public Transaction {
public:
    Expense();
    Expense(const std::string& cName, int cDay, int cMonth,
            int cYear, const std::string& cCategory,
            const std::string& cDescription, double cAmount);
};

/**
 - @class Income
 */
class Income : public Transaction {
private:
    std::string Source;
    double GrossAmount;
    int Frequency;
    std::string Mode;
    double TaxRate;
    std::string TaxCategory;
    std::string Status;
    std::string BudgetAllocation;

public:
    // --- Setters ---
    bool setSource(const std::string& source);
    bool setGrossAmount(double grossAmount);
    bool setFrequency(int frequency);
    bool setMode(const std::string& mode);
    bool setTaxRate(double taxRate);
    bool setTaxCategory(const std::string& taxCategory);
    bool setStatus(const std::string& status);
    bool setBudgetAllocation(const std::string& budgetAllocation);

    // --- Getters ---
    std::string getSource() const;
    double getGrossAmount() const;
    int getFrequency() const;
    std::string getMode() const;
    double getTaxRate() const;
    std::string getTaxCategory() const;
    std::string getStatus() const;
    std::string getBudgetAllocation() const;

    // --- Constructors ---
    Income();

    Income(const std::string& cName, int cDay, int cMonth,
           int cYear, const std::string& cSource, double cGrossAmount,
           const std::string& cCategory, const std::string& cDescription,
           double cAmount, int cFrequency, const std::string& cMode,
           double cTaxRate, const std::string& cTaxCategory,
           const std::string& cStatus, const std::string& cBudgetAllocation);
};

#endif