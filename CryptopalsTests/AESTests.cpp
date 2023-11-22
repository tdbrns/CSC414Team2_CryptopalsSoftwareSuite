#include "gtest/gtest.h"
#include "ChallengeSolvers.h"

ChallengeSolver AESSolutions;

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
        {{"e34d60cb3260a49364a2e61a41165946"}, "e34d60cb3260a49364a2e61a41165946"}, // 1 ecb element
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
        {{"401gyzJgpJNkouYaQRZZRg=="}, "n/a"}, // not hex
        {{"ddada", "a03ffe"}, "n/a"}, // none
    };

    for (const auto& testCase : testCases) {
        std::vector<Block> blockTestVector;
        for (const auto& str : testCase.input_encrypted) {
            Block testBlock;
            BlockFromString(&testBlock, str);

            blockTestVector.push_back(testBlock);
        }

        EXPECT_TRUE(AESSolutions.DetectAES_ECBMode(blockTestVector).rfind("Exception:", 0) == 0);
    }
}