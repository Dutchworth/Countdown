#include "ArgUtils.h"
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string>ArgUtils::getArgs(int argc, char **argv) {
  std::vector<std::string> args;

  for (int i = 0; i < argc; ++i) {
    args.push_back(std::string(argv[i]));
  }

  return args;
}

bool ArgUtils::helpRequested(int argc, char **argv) {
  std::vector<std::string> args = getArgs(argc, argv);
  std::vector<std::string> helpCommands { { "help", "h", "--help", "--h", "-help", "-h" } };

  for (auto each : args) {
    if (std::find(helpCommands.begin(), helpCommands.end(), each) != helpCommands.end()) {
      return true;
    }
  }

  return false;
}

bool ArgUtils::newDictPathGiven(int argc, char **argv) {
  return argc == 3;
}

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
