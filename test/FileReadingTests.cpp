#include "gtest/gtest.h"
#include "FileReading.h"
#include "Dictionary.h"
#include <string>
#include <fstream>

class FileReadingTests : public ::testing::Test {
protected:

  std::string path = "test-words.txt";

  virtual void SetUp() {
    std::ofstream testFile;
    testFile.open(path);

    testFile << "hello\n";
    testFile << "cat\n";
    testFile << "dog\n";
    testFile << "goodbye\n";

    testFile.close();
  }

  virtual void TearDown() {
    std::remove(path.c_str());
  }
};

TEST_F(FileReadingTests, testRead) {
  Dictionary dict = FileReading::read(path);

  EXPECT_EQ("hello",   dict.findWord("hello"));
  EXPECT_EQ("cat",     dict.findWord("act"));
  EXPECT_EQ("dog",     dict.findWord("odg"));
  EXPECT_EQ("goodbye", dict.findWord("byegood"));
}

TEST_F(FileReadingTests, testReadWithWordsTxt) {
  Dictionary dict = FileReading::read("english-words/words.txt");

  EXPECT_EQ("aardvark", dict.findWord("varkaard"));
  EXPECT_EQ("queen",    dict.findWord("ueeqn"));
  EXPECT_EQ("knave",    dict.findWord("avnke"));
  EXPECT_EQ("ace",      dict.findWord("cea"));
}
