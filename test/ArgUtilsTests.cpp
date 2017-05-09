#include "gtest/gtest.h"
#include "ArgUtils.h"
#include <vector>
#include <string>


class ArgUtilsTests : public ::testing::Test {
protected:

  int argc1    = 3;
  char **argv1 = new char *[argc1];

  std::vector<std::string>expected1 { "path/to/file",
                                      "path/to/dict.txt",
                                      "abcdefghi"  };

  int argc2    = 2;
  char **argv2 = new char *[argc2];

  std::vector<std::string>expected2 { "path/to/file",
                                      "abcdefghi"  };

  char **argv3 = new char *[argc1];

  virtual void SetUp()    {
    argv1[0] = (char *)"path/to/file";
    argv1[1] = (char *)"path/to/dict.txt";
    argv1[2] = (char *)"abcdefghi";

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
