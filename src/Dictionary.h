#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <map>
#include <string>

class Dictionary {
 private:
  // a map of words in the dictionary to be used stored against a key which is
  // the word put into alphabetical order
  std::map<std::string, std::string> mappingDict;

 public:
  // Constructors & Destructor
  Dictionary();
  Dictionary(const Dictionary& other);
  Dictionary& operator=(const Dictionary& other);
  ~Dictionary();

  // add given word to the Dictionary, returns true is word could be added
  bool addWord(const std::string word);

  // find word that has the given letters
  std::string findWord(const std::string letters);
};

#endif  // ifndef DICTIONARY_H
