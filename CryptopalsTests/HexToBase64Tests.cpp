#include "gtest/gtest.h"
#include "ChallengeSolutions.h"

ChallengeSolution HexSolutions;

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
        {"4927", "SSc="},  // 2 characters (1 byte) 
        {"49276d20", "SSdtIA=="},  // 8 characters (4 bytes)
        {"49276d206b", "SSdtIGs="},  // 10 characters (5 bytes)
    };

    for (const auto& testCase : testCases) {
        EXPECT_EQ(HexSolutions.HexToBase64(testCase.input_hex), testCase.expected_base64);
    }
}