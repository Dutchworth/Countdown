#include "gtest/gtest.h"
#include "StatsUtils.h"
#include <string>
#include <vector>
#include <iostream>

TEST(StatsUtilsTests, testGetCombinations) {
  std::string input = "abcd";

  std::vector<std::string> combs4to4 { { "abcd" } };
  std::vector<std::string> combs4to3 { { "abc" },
                                       { "abd" },
                                       { "acd" },
                                       { "bcd" } };
  std::vector<std::string> combs4to2 { { "ab" },
                                       { "ac" },
                                       { "ad" },
                                       { "bc" },
                                       { "bd" },
                                       { "cd" } };
  std::vector<std::string> combs4to1 { { "a" }, { "b" }, { "c" }, { "d" } };

  std::vector<std::string> actual4to4 = StatsUtils::getCombinations(input, 4);
  EXPECT_EQ(combs4to4, actual4to4);

  std::vector<std::string> actual4to3 = StatsUtils::getCombinations(input, 3);
  EXPECT_EQ(combs4to3, actual4to3);

  std::vector<std::string> actual4to2 = StatsUtils::getCombinations(input, 2);
  EXPECT_EQ(combs4to2, actual4to2);

  std::vector<std::string> actual4to1 = StatsUtils::getCombinations(input, 1);
  EXPECT_EQ(combs4to1, actual4to1);
}
