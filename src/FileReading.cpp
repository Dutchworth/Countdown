#include "FileReading.h"
#include "Dictionary.h"
#include <fstream>
#include <string>

Dictionary FileReading::read(std::string path) {
  Dictionary myDict;

  std::ifstream infile(path);
  std::string   line;

  while (std::getline(infile, line)) {
    myDict.addWord(line);
  }

  return myDict;
}
