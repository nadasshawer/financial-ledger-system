// File Imports
#include "../../include/utils/text_utils.h"

// Library Imports
#include <string>

// --- Capitalize first letter of a name ---
std::string capitalizeFirstLetter(std::string name) {
  if(name.empty()){
    return name;
  }
  // If the first letter is lowercase
  if (std::islower(static_cast<unsigned char>(name[0]))) {
    // Make it uppercase
    name[0] = std::toupper(static_cast<unsigned char>(name[0]));
  }
  // Returns name after its first letter has been capitalized
  return name;
}
