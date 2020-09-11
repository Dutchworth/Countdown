#include "StatsUtils.h"

#include <iostream>
#include <string>
#include <vector>

std::string charToString(char letter) {
  std::string toReturn = "";
  toReturn += letter;
  return toReturn;
}

std::vector<std::string> StatsUtils::getCombinations(std::string set,
                                                     int subSetSize) {
  std::vector<std::string> returnVect;

  if (subSetSize <= 1) {
    for (char each : set) {
      returnVect.push_back(charToString(each));
    }
  } else {
    std::string setCopy = set;

    for (int i = 0; i < set.size(); ++i) {
      char item = set.at(i);

      setCopy.erase(setCopy.begin());

      std::vector<std::string> combs = getCombinations(setCopy, subSetSize - 1);

      for (std::string each : combs) {
        std::string subCombo = charToString(item) + each;
        returnVect.push_back(subCombo);
      }
    }
  }

  return returnVect;
}
