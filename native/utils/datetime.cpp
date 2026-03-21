// File Imports
#include "../../include/utils/datetime.h"

// Library Imports
#include <ctime>

// --- Get Current Date & Time ---
tm *getCurrentDateAndTime() {
  time_t currentTime = time(0);   // get current time
  // timeNow is a pointer to the current time struct (huge int)
  tm *timeNow = localtime(&currentTime);      // convert it to local time
  return timeNow;
}

// --- Get Current Year ---
int getCurrentYear(const tm &timeNow) {
  return timeNow.tm_year + 1900;    // added 1900 for year accuracy (count starts at 1900)
}

// --- Get Current Month ---
int getCurrentMonth(const tm &timeNow) {
  return timeNow.tm_mon + 1;      // added 1 to the month cuz index starts at 0 for January
}

// --- Get Current Day ---
int getCurrentDay(const tm &timeNow) { return timeNow.tm_mday; }

// --- Get Current Hour ---
int getCurrentHour(const tm &timeNow) { return timeNow.tm_hour; }

// --- Get Current Minute ---
int getCurrentMinute(const tm &timeNow) { return timeNow.tm_min; }

// --- Get Current Second ---
int getCurrentSecond(const tm &timeNow) { return timeNow.tm_sec; }
