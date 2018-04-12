#include <fstream>
#include <string>
#include "Dictionary.h"
#include "FileReading.h"
#include "gtest/gtest.h"

class FileReadingTests : public ::testing::Test {
 protected:
  std::string path = "test-words.txt";

  virtual void SetUp() {}

  virtual void TearDown() {}
};

TEST_F(FileReadingTests, testRead) {
  Dictionary dict = FileReading::read(path);

  EXPECT_EQ("hello", dict.findWord("hello"));
  EXPECT_EQ("cat", dict.findWord("act"));
  EXPECT_EQ("dog", dict.findWord("odg"));
  EXPECT_EQ("goodbye", dict.findWord("byegood"));
}

TEST_F(FileReadingTests, testReadWithWordsTxt) {
  Dictionary dict = FileReading::read("english-words/words.txt");

  EXPECT_EQ("aardvark", dict.findWord("varkaard"));
  EXPECT_EQ("queen", dict.findWord("ueeqn"));
  EXPECT_EQ("ace", dict.findWord("cea"));
}
