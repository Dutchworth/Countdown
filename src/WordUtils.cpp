#include "WordUtils.h"
#include <string>
#include <algorithm>

std::string WordUtils::alphabetise(const std::string word) {
  std::string toReturn = word;
  std::sort(toReturn.begin(), toReturn.end());
  return toReturn;
}
