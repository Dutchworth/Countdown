#include "ArgUtils.h"
#include "FileReading.h"
#include "Dictionary.h"
#include "Solver.h"
#include <string>
#include <iostream>

int main(int argc, char **argv) {
  if (ArgUtils::helpRequested(argc, argv)) {
    ArgUtils::printHelp(std::cout);
    return 0;
  }

  std::cout << "Countdown Solver" << '\n';
  std::cout << " ======== " << '\n';

  if (ArgUtils::lettersGiven(argc, argv)) {
    std::cout << "Searching with given letters: ";
    std::string letters = ArgUtils::getLetters(argc, argv);
    std::cout << letters << '\n';

    Dictionary  dict;
    std::string path;

    if (ArgUtils::newDictPathGiven(argc, argv)) {
      path = ArgUtils::newDictPath(argc, argv);
      std::cout << "Using new Dictionary: " << path << '\n';
    } else {
      path = "english-words/words.txt";
    }

    dict = FileReading::read(path);

    std::string word;

    if (Solver::findWord(dict, letters, word)) {
      std::cout << "Solution found: " << word << '\n';
    } else {
      std::cout << "No Solution found" << '\n';
    }
  } else {
    std::cout <<
      "Bad input. Please try again or use help command for more info." << '\n';
    return 1;
  }

  return 0;
}
