#include "gtest/gtest.h"

TEST(HexToBase64Tests, HexToBase64Basic) {
    struct TestCase {
        std::string input_hex;
        std::string expected_base64;
    };

    std::vector<TestCase> testCases = {
        {"49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d", "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"},
    };

    for (const auto& testCase : testCases) {
        FAIL() << "Pending impl.";
        // ASSERT_EQ(HexToBase64(testCase.input_hex), testCase.expected_base64);
    }
}