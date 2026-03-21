#include "../header_files/user_info.h"
#include "../header_files/functions.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// SETTERS & GETTERS
void UserInfo::setFirstName(const string firstName) {
  string capitalizedFirstName =
      capitalizeFirstLetter(firstName); // capitalizing first letter of the name
  FirstName = capitalizedFirstName;
}
string UserInfo::getFirstName() const { return FirstName; }
void UserInfo::setLastName(const string lastName) {
  string capitalizedLastName = capitalizeFirstLetter(lastName);
  LastName = capitalizedLastName;
}
string UserInfo::getLastName() const { return LastName; }
void UserInfo::setBirthDay(const int birthDay) { BirthDay = birthDay; }
int UserInfo::getBirthDay() const { return BirthDay; }
void UserInfo::setBirthMonth(const string birthMonth) {
  // capitalizing first letter of the name
  string capitalizedBirthMonth = birthMonth;
  if (!birthMonth.empty()) {
    if (islower(capitalizedBirthMonth[0])) {
      capitalizedBirthMonth[0] = toupper(capitalizedBirthMonth[0]);
    }
  }
  BirthMonth = capitalizedBirthMonth;

  // getting birth month as a number
  if (BirthMonth == "January") {
    numericalBirthMonth = 1;
  } else if (BirthMonth == "February") {
    numericalBirthMonth = 2;
  } else if (BirthMonth == "March") {
    numericalBirthMonth = 3;
  } else if (BirthMonth == "April") {
    numericalBirthMonth = 4;
  } else if (BirthMonth == "May") {
    numericalBirthMonth = 5;
  } else if (BirthMonth == "June") {
    numericalBirthMonth = 6;
  } else if (BirthMonth == "July") {
    numericalBirthMonth = 7;
  } else if (BirthMonth == "August") {
    numericalBirthMonth = 8;
  } else if (BirthMonth == "September") {
    numericalBirthMonth = 9;
  } else if (BirthMonth == "October") {
    numericalBirthMonth = 10;
  } else if (BirthMonth == "November") {
    numericalBirthMonth = 11;
  } else if (BirthMonth == "December") {
    numericalBirthMonth = 12;
  }
}
int UserInfo::getBirthMonth() const { return numericalBirthMonth; }
void UserInfo::setBirthYear(const int birthYear) { BirthYear = birthYear; }
int UserInfo::getBirthYear() const { return BirthYear; }
int UserInfo::getAge() {
  int age;
  // get current date
  int currentYear = getCurrentYear();
  int currentMonth = getCurrentMonth();
  int currentDay = getCurrentDay();

  // if birthday has not yet occured
  if ((numericalBirthMonth > currentMonth) ||
      (numericalBirthMonth == currentMonth && BirthDay > currentDay)) {
    age = currentYear - BirthYear;
    age--;
    return age;
  } else {
    age = currentYear - BirthYear;
    return age;
  }
}
string UserInfo::getUsername() {
  string username;
  // reset first letter of first name to small
  string smallFirstName = getFirstName();
  if (!getFirstName().empty()) {
    if (isupper(smallFirstName[0])) {
      smallFirstName[0] = tolower(smallFirstName[0]);
    }
  }

  // reset first letter of last name to small
  string smallLastName = getLastName();
  if (!getLastName().empty()) {
    if (isupper(smallLastName[0])) {
      smallLastName[0] = tolower(smallLastName[0]);
    }
  }

  // print small-lettered username
  username = smallFirstName + "." + smallLastName;
  Username = username;
  return Username;
}
void UserInfo::setPassword(const string password) { Password = password; }
string UserInfo::getPassword() const { return Password; }

// CONSTRUCTORS
// default constructor
UserInfo::UserInfo() {
  FirstName = "";
  LastName = "";
  BirthDay = 0;
  BirthMonth = "";
  BirthYear = 0;
  Password = "";
  Username = "";
}

// user info constructor
UserInfo::UserInfo(const string cFirstName, const string cLastName,
                   const int cBirthDay, const string cBirthMonth,
                   const int cBirthYear, const string cUsername,
                   const string cPassword) {
  FirstName = cFirstName;
  LastName = cLastName;
  BirthDay = cBirthDay;
  BirthMonth = cBirthMonth;
  BirthYear = cBirthYear;
  Password = cPassword;
  Username = cUsername;
}

// METHODS
// print date of log in
void UserInfo::getCurrentDate() {
  // current date
  int currentYear = getCurrentYear();
  int currentMonth = getCurrentMonth();
  int currentDay = getCurrentDay();

  // print date info
  cout << currentDay << "/" << currentMonth << "/" << currentYear;
}

// print time of log in
void UserInfo::getCurrentTime() {
  int currentHour = getCurrentHour();
  int currentMinute = getCurrentMinute();
  int currentSecond = getCurrentSecond();

  // print time info
  cout << currentHour << ":" << currentMinute << ":" << currentSecond << endl;
}

// user profile
void UserInfo::displayUserProfile() {
  cout << "---------------------------------------" << endl;
  cout << "Welcome, " << getFirstName() << "!" << endl;

  // display date and time
  cout << "Last log in on ";
  getCurrentDate();
  cout << " at ";
  getCurrentTime();
  cout << endl;

  // display personal info
  cout << "< YOUR INFO >" << endl;
  cout << "- First Name: " << getFirstName() << endl;
  cout << "- Last Name: " << getLastName() << endl;

  cout << "- Birth Date: " << getBirthDay() << "/" << getBirthMonth() << "/"
       << getBirthYear() << endl;
  cout << "- Age: " << getAge() << " years" << endl << endl;

  // display username
  cout << "< LOGIN INFO >" << endl;
  cout << "- Username: " << getUsername() << endl;

  // hide password as stars
  string hiddenPassword(Password.size(), '*');
  cout << "- Password: " << hiddenPassword << endl;
}
