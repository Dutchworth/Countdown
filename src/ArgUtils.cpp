#include "ArgUtils.h"

#include <algorithm>
#include <ostream>
#include <string>
#include <vector>

std::vector<std::string> ArgUtils::getArgs(int argc, char **argv) {
  std::vector<std::string> args;

  for (int i = 0; i < argc; ++i) {
    args.push_back(std::string(argv[i]));
  }

  return args;
}

bool ArgUtils::helpRequested(int argc, char **argv) {
  std::vector<std::string> args = getArgs(argc, argv);
  std::vector<std::string> helpCommands{
      {"help", "h", "--help", "--h", "-help", "-h"}};

  for (auto each : args) {
    if (std::find(helpCommands.begin(), helpCommands.end(), each) !=
        helpCommands.end()) {
      return true;
    }
  }

  return false;
}

bool ArgUtils::newDictPathGiven(int argc, char **argv) { return argc == 3; }

std::string ArgUtils::newDictPath(int argc, char **argv) {
  std::vector<std::string> args = getArgs(argc, argv);
  return args.at(2);
}

bool ArgUtils::lettersGiven(int argc, char **argv) {
  return argc > 1 && !helpRequested(argc, argv);
}

std::string ArgUtils::getLetters(int argc, char **argv) {
  std::vector<std::string> args = getArgs(argc, argv);
  return args.at(1);
}

void ArgUtils::printHelp(std::ostream &out) {
  out << "Countdown Solver\n";
  out << " ========== \n";
  out << "This programs takes input of the 9 letters to be used to create the "
         "solution (as one block eg. abcdefghi).\n";
  out << "If you want to use another dictionary file then follow these letters "
         "with the path to said dictionary.\n";
  out << "Otherwise, a default dictionary of english words is used. Your own "
         "dictionary should consists of all the words you wich to be added, "
         "seperated by newlines\n";
  out << " ========== \n";
}
