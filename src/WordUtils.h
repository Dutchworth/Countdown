#ifndef WORDUTILS_H
#define WORDUTILS_H

#include <string>

namespace WordUtils {
// returns the given word in alphabetical order
std::string alphabetise(const std::string word);

// returns the given word formatted to lowercase
std::string lowercase(const std::string word);

// returns if the given word is good use in this program.
// ie. lowercase, only alphbetic chars, <= 9 chars long
bool isUsable(const std::string word);
}  // namespace WordUtils
#endif  // ifndef WORDUTILS_H
