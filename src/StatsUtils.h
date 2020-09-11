#ifndef STATSUTILS_H
#define STATSUTILS_H

#include <string>
#include <vector>

namespace StatsUtils {
// get combinations of given subSetSize from the given set of inputs
std::vector<std::string> getCombinations(std::string set, int subSetSize);
}  // namespace StatsUtils
#endif  // ifndef STATSUTILS_H
