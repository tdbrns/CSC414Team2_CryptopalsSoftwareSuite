#include "gtest/gtest.h"

TEST(AESTests, DecryptAESInECB) {
    struct TestCase {
        std::string input_encrypted;
        std::string input_key;
        std::string expected_decrypted;
    };

    std::vector<TestCase> testCases = {
        {"3ad77bb40d7a3660a89ecaf32466ef97", "2b7e151628aed2a6abf7158809cf4f3c", "6bc1bee22e409f96e93d7e117393172a"},
        {"f5d3d58503b9699de785895a96fdbaaf", "2b7e151628aed2a6abf7158809cf4f3c", "ae2d8a571e03ac9c9eb76fac45af8e51"},
        {"43b1cd7f598ece23881b00e3ed030688", "2b7e151628aed2a6abf7158809cf4f3c", "30c81c46a35ce411e5fbc1191a0a52ef"},
    };

    for (const auto& testCase : testCases) {
        FAIL() << "Pending impl.";
    }
}