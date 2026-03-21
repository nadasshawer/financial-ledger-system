// void chooseTracker() {
//   char choice;
//   std::cout << "Hi! What do you want to track today?" << endl << endl;
//   std::cout << "Choose Tracker (please select one):" << endl
//             << "a)Expense Tracker  b)Income Tracker  c)Budget Tracker" << endl
//             << endl;
//   std::cout << "Your Selection --> ";

//   while (true) {
//     std::cin >> choice;
//     if (choice == 'a' || choice == 'A') {
//       // call expense tracker
//       std::cout << endl
//                 << "<----------- EXPENSE TRACKER ----------->" << endl
//                 << "(Welcome to our program's Expense Tracker. Here you can "
//                    "track and manage all your expenses!)"
//                 << endl
//                 << endl;
//       currency = getSystemCurrency(); // get currency
//       std::cout << endl;
//       getExpenseInfo();
//     } else if (choice == 'b' || choice == 'B') {
//       // call income tracker
//       std::cout << endl
//                 << "<----------- INCOME TRACKER ----------->" << endl
//                 << "(Welcome to our program's Income Tracker. Here you can "
//                    "track and manage all your income streams!)"
//                 << endl
//                 << endl;
//       currency = getSystemCurrency(); // get currency
//       std::cout << endl;
//       getIncomeInfo();
//     } else if (choice == 'c' || choice == 'C') {
//       // call budget tracker
//       std::cout << endl
//                 << "<----------- BUDGET TRACKER ----------->" << endl
//                 << "(Welcome to our program's Budget Tracker. Here you can "
//                    "track and manage all your expenses, income, savings, "
//                    "transactions, and more!)"
//                 << endl
//                 << endl;
//       currency = getSystemCurrency(); // get currency
//       std::cout << endl;
//       getBudgetInfo();
//     } else {
//       std::cout << "Please enter a valid tracker option. Retry --> ";
//     }
//   }
// }
