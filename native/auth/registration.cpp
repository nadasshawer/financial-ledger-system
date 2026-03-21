#include "../header_files/registration.h"
#include "../header_files/functions.h"
#include "../header_files/user_info.h"
#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_set>
using namespace std;

/*STEPS:
    done: ask user for registration info
    done: save info for future log in
    done: create user profile using info
*/

// VARIABLES
string firstName;
string lastName;
int birthDay;
string birthMonth;
int birthYear;
string firstPassword;
string secondPassword;
char viewPassChoice;

// CLASS CALLS
UserInfo newUser;

/*FUNCTIONS*/
// CHECK BIRTH MONTH AS LETTERS
bool checkLetterMonthInput(string letterMonth) {
  unordered_set<string> monthsOfYear = {
      "january", "february", "march",     "april",   "may",      "june",
      "july",    "august",   "september", "october", "november", "december"};

  transform(letterMonth.begin(), letterMonth.end(), letterMonth.begin(),
            [](char c) { return tolower(c); });

  if (monthsOfYear.find(letterMonth) != monthsOfYear.end()) {
    return true;
  } else {
    return false;
  }
}

// CHECK BIRTH YEAR AND AGE OF USER
bool checkYearAgeInput(int year) {
  // get current year
  int currentYear = getCurrentYear();
  // get year digit number
  int count = digitCount(year);

  // calc age and check validity
  int userAge = currentYear - year;
  if (userAge < 18 && count == 4) {
    cout << "Sorry you aren't old enough! Retry --> ";
    return false;
  } else if (year >= currentYear || year < 1900 || count != 4) {
    cout << "Please enter a valid year! Retry --> ";
    return false;
  }
  return true;
}

// CHECK PASSWORD VALIDATION
bool checkPassword() {
  bool hasLetter = false;
  bool hasCapLetter = false;
  bool hasSmallLetter = false;
  bool hasSpecialChar = false;
  bool hasNum = false;

  unordered_set<char> specialChar = {
      '!', '@', '#', '$', '%',  '^', '&', '*', '(', ')', '_', '+', '=', '-',
      '{', '}', ':', ';', '\'', '/', '|', '~', '<', '>', '.', ',', '?'};

  for (char ch : firstPassword) {
    if (isalpha(ch)) {
      hasLetter = true;
      if (isupper(ch)) {
        hasCapLetter = true;
      } else if (islower(ch)) {
        hasSmallLetter = true;
      }
    } else if (isdigit(ch)) {
      hasNum = true;
    } else if (specialChar.find(ch) != specialChar.end()) {
      hasSpecialChar = true;
    }
  }

  // checking if password satisfies all requirments
  if (firstPassword.size() >= 8) {
    if (hasCapLetter && hasSmallLetter && hasSpecialChar && hasNum) {
      cout << "Please confirm your password below." << endl << endl;
      return true;
    } else if (hasCapLetter && hasSmallLetter && hasSpecialChar) {
      cout << "Password has to include at least one number. Retry -->  ";
      return false;
    } else if (hasCapLetter && hasSmallLetter && hasNum) {
      cout << "Password has to include at least one special character. Retry "
              "-->  ";
      return false;
    } else if (hasCapLetter && hasSpecialChar && hasNum) {
      cout << "Password has to include at least one small letter. Retry -->  ";
      return false;
    } else if (hasSmallLetter && hasSpecialChar && hasNum) {
      cout
          << "Password has to include at least one capital letter. Retry -->  ";
      return false;
    } else {
      cout << "This isn't strong enough. Please enter a strong password! Retry "
              "-->  ";
      return false;
    }
  } else {
    cout << "Password has to be at least 8 characters. Retry -->  ";
    return false;
  }
}

// CONFIRM BOTH PASSWORDS MATCH
bool confirmPassword() {
  if (secondPassword == firstPassword) {
    cout << endl << "Yay! Password confimred :)" << endl;
    return true;
  } else {
    return false;
  }
}

/*PASSWORD ENCRIPTION
size_t hashPassword (string passwordToBeEncrypted) {
        return hash<string> {}(passwordToBeEncrypted);
}*/

// VIEW HIDDEN PASSWORD
bool showPassword(char userPassShowingChoice) {
  cout << "View Password? (Y/N) -->  ";
  while (true) {
    cin >> userPassShowingChoice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (cin.good()) {
      if (userPassShowingChoice == 'Y' || userPassShowingChoice == 'y') {
        cout << "- Password: ";
        cout << newUser.getPassword();
        return true;
      } else if (userPassShowingChoice == 'N' || userPassShowingChoice == 'n') {
        // no action needed - password remains hidden
        return false;
      } else {
        cout << "Please enter a valid Y/N option! Retry --> ";
      }
    }
  }
}

// REGISTER USER
void registerUser() {
  // naming info
  cout << "<[ NAME INFORMATION ]>" << endl << "- First Name: ";
  while (true) {
    getline(cin, firstName);
    if (checkNameInput(firstName)) {
      newUser.setFirstName(firstName);
      break;
    } else {
      cout << "Please enter a valid name! Retry --> ";
    }
  }

  cout << "- Last Name: ";
  while (true) {
    getline(cin, lastName);
    if (checkNameInput(lastName)) {
      newUser.setLastName(lastName);
      break;
    } else {
      cout << "Please enter a valid name! Retry --> ";
    }
  }

  cout << endl;

  // brith info
  cout << "<[ BIRTH INFORMATION ]>" << endl << "- Day: ";
  while (true) {
    cin >> birthDay;
    if (cin.good() && checkDayInput(birthDay)) {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      newUser.setBirthDay(birthDay);
      break;
    } else {
      cout << "Please enter a valid day! Retry --> ";
      cin.clear();
      cin.ignore();
    }
  }

  cout << "- Month (in letters): ";
  while (true) {
    getline(cin, birthMonth);
    if (checkLetterMonthInput(birthMonth)) {
      newUser.setBirthMonth(birthMonth);
      break;
    } else {
      cout << "Please enter a valid month! Retry --> ";
    }
  }

  cout << "- Year: ";
  while (true) {
    cin >> birthYear;
    if (cin.good() && checkYearAgeInput(birthYear)) {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      newUser.setBirthYear(birthYear);
      break;
    } else {
      cin.clear();
      cin.ignore();
    }
  }

  cout << endl;

  // password info
  cout << "<[ SET A STRONG PASSWORD ]>" << endl << "- Password: ";
  while (true) {
    getline(cin, firstPassword);
    if (checkPassword()) {
      break;
    }
  }

  cout << "- Confirm password: ";
  while (true) {
    getline(cin, secondPassword);
    if (confirmPassword()) {
      /*password encryption
      size_t hiddenPassword = hashPassword(firstPassword);
      newUser.setPassword(to_string (hiddenPassword));*/
      newUser.setPassword(firstPassword);
      break;
    } else {
      cout << "Passwords do not match. Retry --> ";
    }
  }

  // display user profile
  newUser.displayUserProfile();

  // display hidden password
  showPassword(viewPassChoice);
  cout << endl << "---------------------------------------" << endl;
}
