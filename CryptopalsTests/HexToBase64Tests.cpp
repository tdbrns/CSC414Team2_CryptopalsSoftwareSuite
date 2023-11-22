#include "gtest/gtest.h"
#include "ChallengeSolvers.h"

ChallengeSolver HexSolutions;

TEST(HexToBase64Tests, HexToBase64Basic) {
    struct TestCase {
        std::string input_hex;
        std::string expected_base64;
    };

    std::vector<TestCase> testCases = {
        {"", ""},  // Empty input
        {"49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d", "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"}  // Long
    };

    for (const auto& testCase : testCases) {
        EXPECT_EQ(HexSolutions.HexToBase64(testCase.input_hex), testCase.expected_base64);
    }
}

TEST(HexToBase64Tests, HexToBase64Padded) {
    struct TestCase {
        std::string input_hex;
        std::string expected_base64;
    };

    std::vector<TestCase> testCases = {
        {"4927", "SSc="},  // 4 characters (4 bytes) 
        {"49276d20", "SSdtIA=="},  // 8 characters (8 bytes)
        {"49276d206b", "SSdtIGs="},  // 10 characters (10 bytes)
    };

    for (const auto& testCase : testCases) {
        EXPECT_EQ(HexSolutions.HexToBase64(testCase.input_hex), testCase.expected_base64);
    }
}

TEST(HexToBase64Tests, HexToBase64Invalid) {
    struct TestCase {
        std::string input_hex;
        std::string expected_base64;
    };

    std::vector<TestCase> testCases = {
        {"zbzefa", "n/a"},  // invalid hexadecimal
        {"ccc", "n/a"},  // not enough characters
    };

    for (const auto& testCase : testCases) {
        EXPECT_TRUE(HexSolutions.HexToBase64(testCase.input_hex).rfind("Exception:", 0) == 0);
    }
}