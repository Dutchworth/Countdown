#include "ArgUtils.h"

#include <vector>
#include <string>

std::vector<std::string>ArgUtils::getArgs(int argc, char **argv) {
  std::vector<std::string> args;

  for (int i = 0; i < argc; ++i) {
    args.push_back(std::string(argv[i]));
  }

  return args;
}
