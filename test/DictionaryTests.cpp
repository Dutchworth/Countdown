#include "Dictionary.h"
#include "gtest/gtest.h"

class DictionaryTests : public ::testing::Test {
 protected:
  Dictionary dict1;

  virtual void SetUp() { dict1.addWord("hello"); }

  virtual void TearDown() { dict1 = Dictionary(); }
};

TEST_F(DictionaryTests, testCopyConstructor) {
  Dictionary newDict(dict1);

  EXPECT_EQ("hello", newDict.findWord("ehllo"));
}

TEST_F(DictionaryTests, testAssignmentOperator) {
  Dictionary newDict = dict1;

  EXPECT_EQ("hello", newDict.findWord("ehllo"));
}

TEST_F(DictionaryTests, testAddWordHappy) {
  EXPECT_TRUE(dict1.addWord("goodbye"));
  EXPECT_EQ("goodbye", dict1.findWord("bdegooy"));

  EXPECT_TRUE(dict1.addWord("cAt"));
  EXPECT_EQ("cat", dict1.findWord("act"));
}

TEST_F(DictionaryTests, testAddWordUnHappy) {
  EXPECT_FALSE(dict1.addWord("*&^*&^*&^"));

  EXPECT_FALSE(dict1.addWord("kjihgfedcba"));
  EXPECT_EQ("", dict1.findWord("abcdefghijk"));
}

TEST_F(DictionaryTests, testFindWordHappy) {
  EXPECT_EQ("hello", dict1.findWord("ehllo"));
  EXPECT_EQ("hello", dict1.findWord("ollhe"));
}

TEST_F(DictionaryTests, testFindWordUnHappy) {
  EXPECT_EQ("", dict1.findWord("sadvsadv"));
}
