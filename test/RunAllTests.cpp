#include "gtest/gtest.h"
#include <string>
#include <fstream>

class TestEnv : public ::testing::Environment {
public:

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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::Environment *const test_env = ::testing::AddGlobalTestEnvironment(
    new TestEnv);

  return RUN_ALL_TESTS();
}
