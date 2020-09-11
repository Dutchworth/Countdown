#include "Dictionary.h"

#include <exception>
#include <map>
#include <string>

#include "WordUtils.h"

Dictionary::Dictionary() {
  // do nothing, words will be added later
}

Dictionary::Dictionary(const Dictionary &other)
    : mappingDict(other.mappingDict) {
  // do nothing, using member initialisation list
}

Dictionary &Dictionary::operator=(const Dictionary &other) {
  mappingDict = other.mappingDict;

  return *this;
}

Dictionary::~Dictionary() {
  // do nothing, resources will destruct themselves
}

bool Dictionary::addWord(const std::string word) {
  std::string wordCleaned = WordUtils::lowercase(word);

  if (WordUtils::isUsable(wordCleaned)) {
    mappingDict.emplace(WordUtils::alphabetise(wordCleaned), wordCleaned);
    return true;
  }

  return false;
}

std::string Dictionary::findWord(const std::string letters) {
  std::string lettersCleaned =
      WordUtils::alphabetise(WordUtils::lowercase(letters));

  try {
    return mappingDict.at(lettersCleaned);
  } catch (std::out_of_range &except) {
    return "";
  }
}
