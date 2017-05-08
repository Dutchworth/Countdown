#include "gtest/gtest.h"
#include "WordUtils.h"
#include <string>

TEST(WordUtilsTests, testAlphabetise) {
  std::string input    = "fedcbaaa";
  std::string expected = "aaabcdef";

  std::string actual = WordUtils::alphabetise(input);
  EXPECT_EQ(expected, actual);
}

TEST(WordUtilsTests, testLowercase) {
  std::string input    = "AbCdEf";
  std::string expected = "abcdef";

  std::string actual = WordUtils::lowercase(input);
  EXPECT_EQ(expected, actual);
}

TEST(WordUtilsTests, testIsUsable) {
  std::string input1 = "abcdef";
  EXPECT_TRUE(WordUtils::isUsable(input1));

  std::string input2 = "abcd^ef";
  EXPECT_FALSE(WordUtils::isUsable(input2));

  std::string input3 = "AbCdEf";
  EXPECT_FALSE(WordUtils::isUsable(input3));
}
