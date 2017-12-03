#include "FileReading.h"
#include <fstream>
#include <string>
#include "Dictionary.h"

Dictionary FileReading::read(std::string path) {
  Dictionary myDict;

  std::ifstream infile(path);
  std::string line;

  while (std::getline(infile, line)) {
    myDict.addWord(line);
  }

  return myDict;
}
