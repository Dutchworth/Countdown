#include "StatsUtils.h"
#include <vector>
#include <string>
#include <iostream>

std::string charToString(char letter) {
  std::string toReturn = "";
  toReturn += letter;
  return toReturn;
}

std::vector<std::string>StatsUtils::getCombinations(std::string set,
                                                    int         subSetSize) {
  std::vector<std::string> returnVect;

  if (subSetSize <= 1) {
    for (int i = 0; i < set.size(); ++i) {
      returnVect.push_back(charToString(set.at(i)));
    }
  } else {
    std::string setCopy = set;

    for (int i = 0; i < set.size(); ++i) {
      char item = set.at(i);

      setCopy.erase(setCopy.begin());

      std::vector<std::string> combs = getCombinations(setCopy, subSetSize - 1);

      for (int j = 0; j < combs.size(); ++j) {
        std::string subCombo = charToString(item) + combs[i];
        returnVect.push_back(subCombo);
      }
    }
  }

  return returnVect;
}
