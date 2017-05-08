#ifndef STATSUTILS_H
#define STATSUTILS_H

#include <vector>
#include <string>

namespace StatsUtils {
// get combinations of given subSetSize from the given set of inputs
std::vector<std::string>getCombinations(std::string set,
                                        int         subSetSize);
}
#endif // ifndef STATSUTILS_H
