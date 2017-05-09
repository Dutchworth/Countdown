#include "gtest/gtest.h"
#include "Solver.h"
#include "Dictionary.h"
#include "FileReading.h"

class SolverTests : public ::testing::Test {
protected:

  std::string path = "test-words.txt";
  Dictionary dict;

  virtual void SetUp() {
    dict = FileReading::read(path);
  }

  virtual void TearDown() {
    dict = Dictionary();
  }
};

TEST_F(SolverTests, testLongWordHappy) {
  std::string letters  = "aagoodbye";
  std::string expected = "goodbye";
  std::string actual;

  EXPECT_EQ(expected, dict.findWord("goodbye"));
  EXPECT_TRUE(Solver::findWord(dict, letters, actual));
  EXPECT_EQ(expected, actual);
}

TEST_F(SolverTests, testShortWordHappy) {
  std::string letters  = "cataaaaaa";
  std::string expected = "cat";
  std::string actual;

  EXPECT_EQ(expected, dict.findWord("cat"));
  EXPECT_TRUE(Solver::findWord(dict, letters, actual));
  EXPECT_EQ(expected, actual);
}

TEST_F(SolverTests, testNoWordExists) {
  std::string letters  = "zzzzzzzzz";
  std::string expected = "";
  std::string actual;

  EXPECT_FALSE(Solver::findWord(dict, letters, actual));
  EXPECT_EQ(expected, actual);
}

TEST_F(SolverTests, testWithEnglishWordsDictLongWord) {
  dict = FileReading::read("english-words/words.txt");

  std::string letters  = "zymophyte";
  std::string expected = "zymophyte";
  std::string actual;

  EXPECT_TRUE(Solver::findWord(dict, letters, actual));
  EXPECT_EQ(expected, actual);
}

TEST_F(SolverTests, testWithEnglishWordsDictShortWord) {
  dict = FileReading::read("english-words/words.txt");

  std::string letters  = "zymezzzzz";
  std::string expected = "zyme";
  std::string actual;

  EXPECT_TRUE(Solver::findWord(dict, letters, actual));
  EXPECT_EQ(expected, actual);
}
