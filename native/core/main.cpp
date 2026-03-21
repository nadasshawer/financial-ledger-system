#include "../header_files/classes.h"
#include "../header_files/data_display.h"
#include "../header_files/functions.h"
#include "../header_files/registration.h"
#include <iostream>
using namespace std;

int main() {
  // PROGRAM WELCOME MSG
  cout << "WELCOME TO PERSONAL FINANCE MANAGER" << endl
       << endl
       << "Please enter your information to register." << endl
       << endl;

  // REGISTER USER
  registerUser();

  // TRACKER CHOICE
  chooseTracker();

  return 0;
}