/**
 - @file user_info.h
 - @brief Header for the UserInfo class managing profile and authentication data.
 */

#ifndef USER_INFO_H
#define USER_INFO_H

#include <string>

class UserInfo {
private:
    std::string FirstName;
    std::string LastName;
    int BirthDay;
    std::string BirthMonth;
    int BirthYear;
    int Age;
    std::string Username;
    std::string Password;
    int numericalBirthMonth;

public:
    // Setters
    void setFirstName(const std::string firstName);
    void setLastName(const std::string lastName);
    void setBirthDay(const int birthDay);
    void setBirthMonth(const std::string birthMonth);
    void setBirthYear(const int birthYear);
    void setAge();
    void setPassword(const std::string password);
    void setUsername(const std::string username);
	void getCurrentDate();
    void getCurrentTime();

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    int getBirthDay() const;
    std::string getBirthMonth() const;
    int getBirthYear() const;
    int getAge() const;
    std::string getUsername() const;
    std::string getPassword() const;

    // Constructors
    UserInfo();
    UserInfo(const std::string cFirstName, const std::string cLastName, 
             int cBirthDay, const std::string cBirthMonth, 
             int cBirthYear, const std::string cUsername, 
             const std::string cPassword);

    // Methods
    void displayUserProfile();
};

#endif