#include "gtest/gtest.h"
#include "ChallengeSolutions.h"

ChallengeSolution AESSolutions;

// -- ECB 128 Decrypt

TEST(AESTests, DecryptAESInECB) {
    struct TestCase {
        std::string input_encrypted;
        std::string expected_decrypted;
    };

    std::vector<TestCase> testCases = {
        {"401gyzJgpJNkouYaQRZZRg==", "Hello, World!"}, // padded
    };

    for (const auto& testCase : testCases) {
        Block testBlock;
        BlockFromString(&testBlock, testCase.input_encrypted);
        EXPECT_EQ(AESSolutions.AES_ECBMode(testBlock), testCase.expected_decrypted);
    }
}

TEST(AESTests, DecryptAESInECBInvalid) {
    struct TestCase {
        std::string input_encrypted;
        std::string expected_decrypted;
    };

    std::vector<TestCase> testCases = {
        {"", "n/a"}, // null
         {"--wads", "n/a"}, // bad base64
    };

    for (const auto& testCase : testCases) {
        Block testBlock;
        BlockFromString(&testBlock, testCase.input_encrypted);
        //EXPECT_TRUE(AESSolutions.AES_ECBMode(testBlock).rfind("Exception:", 0) == 0);
    }
}

// -- Detect AES in ECB 

TEST(AESTests, DetectAESInECB) {
    struct TestCase {
        std::vector<std::string> input_encrypted;
        std::string ECB_str;
    };

    std::vector<TestCase> testCases = {
        {{"401gyzJgpJNkouYaQRZZRg=="}, "401gyzJgpJNkouYaQRZZRg=="}, // 1
    };

    for (const auto& testCase : testCases) {
        std::vector<Block> blockTestVector;
        for (const auto& str : testCase.input_encrypted) {
            Block testBlock;
            BlockFromString(&testBlock, str);

            blockTestVector.push_back(testBlock);
        }

        EXPECT_EQ(AESSolutions.DetectAES_ECBMode(blockTestVector), testCase.ECB_str);
    }
}

TEST(AESTests, DetectAESInECBInvalid) {
    struct TestCase {
        std::vector<std::string> input_encrypted;
        std::string ECB_str;
    };

    std::vector<TestCase> testCases = {
        {{"401gyzJgpJNkouYaQRZZRg=="}, "401gyzJgpJNkouYaQRZZRg=="}, // padded
    };

    for (const auto& testCase : testCases) {
        std::vector<Block> blockTestVector;
        for (const auto& str : testCase.input_encrypted) {
            Block testBlock;
            BlockFromString(&testBlock, str);

            blockTestVector.push_back(testBlock);
        }

        EXPECT_EQ(AESSolutions.DetectAES_ECBMode(blockTestVector), testCase.ECB_str);
    }
}