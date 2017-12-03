#ifndef SOLVER_H
#define SOLVER_H

#include <string>
#include "Dictionary.h"

namespace Solver {
// takes in the given dictionary and letters, then tries to find the largest
// word that fits those letters.
// The found word is output by reference.
bool findWord(Dictionary& map, std::string letters, std::string& foundWord);
}

#endif  // ifndef SOLVER_H
