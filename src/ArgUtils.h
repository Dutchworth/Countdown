#ifndef ARGUTILS_H
#define ARGUTILS_H
#include <ostream>
#include <string>
#include <vector>

namespace ArgUtils {
std::vector<std::string> getArgs(int argc, char** argv);

bool helpRequested(int argc, char** argv);

bool newDictPathGiven(int argc, char** argv);

std::string newDictPath(int argc, char** argv);

bool lettersGiven(int argc, char** argv);

std::string getLetters(int argc, char** argv);

void printHelp(std::ostream& out);
}
#endif  // ifndef ARGUTILS_H
