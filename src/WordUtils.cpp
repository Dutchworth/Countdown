#include "WordUtils.h"
#include <string>
#include <algorithm>
#include <cctype>

std::string WordUtils::alphabetise(const std::string word) {
  std::string toReturn = word;
  std::sort(toReturn.begin(), toReturn.end());
  return toReturn;
}

std::string WordUtils::lowercase(const std::string word) {
  std::string toReturn = word;
  std::transform(toReturn.begin(), toReturn.end(), toReturn.begin(), ::tolower);
  return toReturn;
}

bool WordUtils::isUsable(const std::string word) {
  std::string toReturn = word;

  struct non_alpha {
    bool operator()(char c) {
      return !std::isalpha(c);
    }
  };

  return (toReturn.size() <= 9)
         && (std::find_if(toReturn.begin(),
                          toReturn.end(),
                          non_alpha()) == toReturn.end())
         && (std::find_if(toReturn.begin(),
                          toReturn.end(),
                          ::isupper) == toReturn.end());
}
