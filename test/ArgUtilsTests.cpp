#include "gtest/gtest.h"
#include "ArgUtils.h"
#include <vector>
#include <string>


class ArgUtilsTests : public ::testing::Test {
protected:

  int argc1    = 3;
  char **argv1 = new char *[argc1];

  std::vector<std::string>expected1 { "path/to/file",
                                      "abcdefghi",
                                      "path/to/dict.txt" };

  int argc2    = 2;
  char **argv2 = new char *[argc2];

  std::vector<std::string>expected2 { "path/to/file",
                                      "abcdefghi"  };

  int argc3    = 2;
  char **argv3 = new char *[argc3];

  virtual void SetUp()    {
    argv1[0] = (char *)"path/to/file";
    argv1[1] = (char *)"abcdefghi";
    argv1[2] = (char *)"path/to/dict.txt";

    argv2[0] = (char *)"path/to/file";
    argv2[1] = (char *)"abcdefghi";

    argv3[0] = (char *)"path/to/file";
    argv3[1] = (char *)"help";
  }

  virtual void TearDown() {
    delete[] argv1;
    delete[] argv2;
    delete[] argv3;
  }
};

TEST_F(ArgUtilsTests, testGetArgs) {
  std::vector<std::string> actual1 = ArgUtils::getArgs(argc1, argv1);
  EXPECT_EQ(expected1, actual1);

  std::vector<std::string> actual2 = ArgUtils::getArgs(argc2, argv2);
  EXPECT_EQ(expected2, actual2);
}

TEST_F(ArgUtilsTests, testHelpRequested) {
  EXPECT_TRUE(ArgUtils::helpRequested(argc3, argv3));
}

TEST_F(ArgUtilsTests, testNewDictPathGiven) {
  EXPECT_TRUE(ArgUtils::newDictPathGiven(argc1, argv1));
}

TEST_F(ArgUtilsTests, testGetNewPath) {
  EXPECT_EQ("path/to/dict.txt", ArgUtils::newDictPath(argc1, argv1));
}

TEST_F(ArgUtilsTests, testLettersGiven) {
  EXPECT_TRUE(ArgUtils::lettersGiven(argc1, argv1));
  EXPECT_TRUE(ArgUtils::lettersGiven(argc2, argv2));
  EXPECT_FALSE(ArgUtils::lettersGiven(argc3, argv3));
}

TEST_F(ArgUtilsTests, testGetLetters) {
  EXPECT_EQ("abcdefghi", ArgUtils::getLetters(argc1, argv1));
  EXPECT_EQ("abcdefghi", ArgUtils::getLetters(argc2, argv2));
}
