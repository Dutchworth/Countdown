#include "gtest/gtest.h"
#include "WordUtils.h"
#include <string>

class WordUtilsTests : public ::testing::Test {
protected:

  std::string orig1   = "fedcba";
  std::string sorted1 = "abcdef";

  virtual void SetUp()    {}

  virtual void TearDown() {}
};

TEST_F(WordUtilsTests, testAlphabetise) {
  std::string actual1 = WordUtils::alphabetise(orig1);
  EXPECT_EQ(sorted1, actual1);
}
