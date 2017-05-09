#include "Solver.h"
#include "Dictionary.h"
#include "StatsUtils.h"
#include <string>
#include <iostream>

bool Solver::findWord(Dictionary & map,
                      std::string  letters,
                      std::string& foundWord) {
  std::string word = map.findWord(letters);

  if (word != std::string("")) {
    foundWord = word;
    return true;
  } else {
    for (int i = letters.size() - 1; i > 0; --i) {
      for (std::string each : StatsUtils::getCombinations(letters, i)) {
        word = map.findWord(each);

        if (word != std::string("")) {
          foundWord = word;
          return true;
        }
      }
    }
  }

  return false;
}
