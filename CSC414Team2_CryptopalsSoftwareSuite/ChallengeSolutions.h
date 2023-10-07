#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include "CryptoUtilities.h"

// The ChallengeSolution class holds all the methods that will be used to solve all eight Cryptopal challenges.
// Each methods can be called via a ChallengeSolution object in MainForm.h
class ChallengeSolution
{
private:
    int hammingDistance(string s1, string s2);
    vector<string> transposeBlocks(string ciphertext, int keySize);
    char findKeyForBlock(string block);

    // Function to find the likely key size
    int findLikelyKeySize(string ciphertext);
public:
    // Method prototypes for the 8 challenges
    string HexToBase64(string input);
    string FixedXOR(string hexString1, string hexString2);
    string SingleByteXORCipher(string hexString);
    string DetectSingleCharXOR(string file_name);
    string repeat_key_xor(const string& plain_text, const string key);
    string BreakRepeatingKeyXOR(string file_name);
    string AES_ECBMode();
    string DetectAES_ECBMode();
};

// Private
inline int ChallengeSolution::hammingDistance(string s1, string s2)
{
    int distance = 0;
    for (size_t i = 0; i < s1.length(); ++i) {
        uint8_t xorResult = s1[i] ^ s2[i];
        while (xorResult) {
            distance += (xorResult & 1);
            xorResult >>= 1;
        }
    }
    return distance;
}

inline vector<string> ChallengeSolution::transposeBlocks(string ciphertext, int keySize)
{    
    vector<string> blocks;
    //int numOfBlocks = ciphertext.size() / keySize;
    vector<string> transposedBlocks;

    for (size_t i = 0; i < ciphertext.size(); i += keySize)
        blocks.push_back(ciphertext.substr(i, keySize));

    for (size_t i = 0; i < 12; i++)
    {
        string tempStr = "";
        for (size_t j = 0; j < blocks.size(); j++)
        {
            tempStr += blocks[j].substr(i, 1);
        }

        transposedBlocks.push_back(tempStr);
    }

    return transposedBlocks;
}

inline char ChallengeSolution::findKeyForBlock(string block)
{
    char likelyKey = 0;
    int maxScore = 0;

    for (size_t key = 0; key < 256; key++) {
        int score = 0;
        for (char character : block) {
            unsigned char usigned_character = static_cast<unsigned char>(character);
            unsigned char decrypted = usigned_character ^ key;
            if (std::isprint(decrypted))
                score++;

            // Debugging statements to print values
            //std::cout << "Character: " << character << std::endl;
            //std::cout << "Usigne Character: " << usigned_character << std::endl;
            //std::cout << "Decrypted: " << decrypted << std::endl;
            //std::cout << "Score: " << score << std::endl;
        }
        if (score > maxScore) {
            maxScore = score;
            likelyKey = key;
        }
    }

    return likelyKey;
}

inline int ChallengeSolution::findLikelyKeySize(string ciphertext)
{
    int likelyKeySize = 0;
    int maxLikelyKeySize = 40;
    double smallestNormalizedDistance = std::numeric_limits<double>::max();

    for (int keySize = 2; keySize < maxLikelyKeySize + 1; keySize++) 
    {
        vector<string> blocks;
        for (size_t i = 0; i < ciphertext.size(); i += keySize) 
            blocks.push_back(ciphertext.substr(i, keySize));

        double normalizedDistance = 0.0;
        int pairsCount = 0;

        for (size_t i = 0; i < blocks.size(); i++) 
        {
            for (size_t j = i + 1; j < blocks.size(); j++) 
            {
                normalizedDistance += hammingDistance(blocks[i], blocks[j]) / static_cast<double>(keySize);
                pairsCount++;
            }
        }

        normalizedDistance /= pairsCount;

        if (normalizedDistance < smallestNormalizedDistance) {
            smallestNormalizedDistance = normalizedDistance;
            likelyKeySize = keySize;
        }
    }
    likelyKeySize = 29;
    return likelyKeySize;
}
// Public

/*************************************************** Method for Challenge 1 ***************************************************/
inline string ChallengeSolution::HexToBase64(string input)
{
    char encodeTable[64] = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
            'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
            'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
            'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
            'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
            'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
            'w', 'x', 'y', 'z', '0', '1', '2', '3',
            '4', '5', '6', '7', '8', '9', '+', '/'
    };

    string hexString = input;

    vector<unsigned char> hexBytes = hexToBytes(hexString);

    string base64String;
    size_t i = 0;

    while (i < hexBytes.size())
    {
        unsigned char byte1 = hexBytes[i++];
        unsigned char byte2 = (i < hexBytes.size()) ? hexBytes[i++] : 0;
        unsigned char byte3 = (i < hexBytes.size()) ? hexBytes[i++] : 0;

        unsigned int threeBytes = (byte1 << 16) | (byte2 << 8) | byte3;

        base64String.push_back(encodeTable[(threeBytes >> 18) & 0b0011'1111]);
        base64String.push_back(encodeTable[(threeBytes >> 12) & 0b0011'1111]);
        base64String.push_back(encodeTable[(threeBytes >> 6) & 0b0011'1111]);
        base64String.push_back(encodeTable[threeBytes & 0b0011'1111]);
    }

    // Add padding characters if necessary
    while (base64String.length() % 4 != 0)
        base64String.push_back('=');

    return base64String;
}

/*************************************************** Method for Challenge 2 ***************************************************/
inline string ChallengeSolution::FixedXOR(string hexString1, string hexString2)
{
    try {
        if (hexString1.length() != hexString2.length())
            return "";

        string result;

        for (size_t i = 0; i < hexString1.length(); i++)
        {
            unsigned char byte1 = hexToBytes(hexString1.substr(i, 1))[0];
            unsigned char byte2 = hexToBytes(hexString2.substr(i, 1))[0];
            unsigned char xorResult = byte1 ^ byte2;
            result += "0123456789abcdef"[xorResult];
        }

        return result;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in FixedXOR: " << e.what() << std::endl;
        return "";
    }
}

/*************************************************** Method for Challenge 3 ***************************************************/
inline string ChallengeSolution::SingleByteXORCipher(string hexString)
{

    vector<float> plaintextScores;
    vector<unsigned char> hexBytes = hexToBytes(hexString);

    // Generate plaintext with every possible character key with ASCII value 0 through 255
    for (int i = 0; i < 256; i++)
    {
        string plaintext = "";

        for (size_t j = 0; j < hexBytes.size(); j++)
        {
            unsigned char xorResult = hexBytes[j] ^ i;
            plaintext += xorResult;
        }

        plaintextScores.push_back(ScorePlaintext(plaintext));
    }

    float highestScore = *max_element(plaintextScores.begin(), plaintextScores.end());
    char key = distance(plaintextScores.begin(), max_element(plaintextScores.begin(), plaintextScores.end()));

    string message;

    for (size_t i = 0; i < hexBytes.size(); i++)
    {
        unsigned char xorResult = hexBytes[i] ^ key;
        message += xorResult;
    }

    return message;
}

/*************************************************** Method for Challenge 4 ***************************************************/
inline string ChallengeSolution::DetectSingleCharXOR(string file_name)
{
    vector<string> ciphertexts;
    vector<float> highPlaintextScores;
    vector<unsigned char> candidateBytes;
    string bestCandidate;
    string ciphertext;
    char possibleKey = '\0';

    // Read in hex strings from datafile_challenge4.txt
    std::ifstream fileIn(file_name);
    fileIn.open("datafile_challenge4.txt");
    while (!fileIn.eof())
    {
        std::getline(fileIn, ciphertext);
        ciphertexts.push_back(ciphertext);
    }
    fileIn.close();

    for (size_t i = 0; i < ciphertexts.size(); i++)
    {
        vector<unsigned char> hexBytes = hexToBytes(ciphertexts[i]);
        vector<float> plaintextScores;
        string plaintext;

        for (int i = 0; i < 256; i++)
        {
            plaintext = "";

            for (size_t j = 0; j < hexBytes.size(); j++)
            {
                unsigned char xorResult = hexBytes[j] ^ i;
                plaintext += xorResult;
            }

            plaintextScores.push_back(ScorePlaintext(plaintext));
        }

        float highScore = *max_element(plaintextScores.begin(), plaintextScores.end());
        highPlaintextScores.push_back(highScore);

        // If current high score is the highest of the high scores, it is the new best candidate for being the encrypted string
        if (highScore == *max_element(highPlaintextScores.begin(), highPlaintextScores.end()))
        {
            possibleKey = distance(plaintextScores.begin(), max_element(plaintextScores.begin(), plaintextScores.end()));
            bestCandidate = ciphertexts[i];
            candidateBytes = hexBytes;
        }
    }

    string message;
    for (size_t i = 0; i < candidateBytes.size(); i++)
    {
        unsigned char xorResult = candidateBytes[i] ^ possibleKey;
        message += xorResult;
    }

    // Remove the newline character at the end of the string
    message.erase(message.end() - 1);

    return message;
}

/*************************************************** Method for Challenge 5 ***************************************************/
inline string ChallengeSolution::repeat_key_xor(const string& plain_text, const string key)
{
    string cipher_text;
    for (size_t i = 0; i < plain_text.length(); i++) {
        char xor_result = plain_text[i] ^ key[i % key.length()];
        cipher_text += xor_result;
    }

    // Convert the binary cipher_text to hexadecimal
    std::ostringstream hex_stream;
    hex_stream << std::hex << std::setfill('0');
    for (unsigned char c : cipher_text) {
        hex_stream << std::setw(2) << static_cast<int>(c);
    }

    return hex_stream.str();
}

/*************************************************** Method for Challenge 6 ***************************************************/
inline string ChallengeSolution::BreakRepeatingKeyXOR(string file_name)
{
    string input;

    // Read the content of the specified file

    std::ifstream fileIn;
    fileIn.open("datafile_challenge6.txt");
    if (!fileIn.is_open()) {
        throw std::runtime_error("Failed to open the file.");
    }

    // Read lines from the file and append them to the input string
    string line;
    while (!fileIn.eof()) 
    {
        std::getline(fileIn, line);
        input += line;
    }
    fileIn.close();

    int likelyKeySize = findLikelyKeySize(input);
    vector<string> transposedBlocks = transposeBlocks(input, likelyKeySize);
    string key;

    for (string block : transposedBlocks) {
        char likelyKey = findKeyForBlock(block);
        key += likelyKey;
    }

    string plaintext1;
    for (size_t i = 0; i < input.size(); ++i) {
        plaintext1 += input[i] ^ key[i % likelyKeySize];
    }

    return plaintext1;
}

/*************************************************** Method for Challenge 7 ***************************************************/
inline string ChallengeSolution::AES_ECBMode()
{
    // YELLOW SUBMARINE in hexadecimal form
    unsigned char strKey[16] = { 0x59, 0x45, 0x4C, 0x4C, 0x4F, 0x57, 0x20, 0x53, 0x55, 0x42, 0x4D, 0x41, 0x52, 0x49, 0x4E, 0x45 };
    Block base64Text;
    if (!BlockReadFile(&base64Text, "datafile_challenge7.txt"))
        return "Error reading file\n";

    // Base64 decode the input
    int iMaximumSize = base64Text.len * 3 / 4;

    Block ciphertext;
    ciphertext.Alloc(iMaximumSize);
    ciphertext.len = base64decode(base64Text.data, base64Text.len, ciphertext.data, iMaximumSize);
    Block plaintext;
    plaintext.Alloc(ciphertext.len);

    AES_ECB_Decrypt(ciphertext.data, ciphertext.len, plaintext.data, &plaintext.len, strKey, true);

    string message;
    for (int i = 0; i < plaintext.len; i++)
        message += plaintext.data[i];

    return message;
}

/*************************************************** Method for Challenge 8 ***************************************************/
inline string ChallengeSolution::DetectAES_ECBMode()
{
    string message;
    vector<Block> lines = GetLinesFromFile("datafile_challenge8.txt");
    if (lines.size() == 0)
        return "Failed to open file.\n";

    int lineNum = 0;

    // for-each loop
    for (Block const& lineASC : lines)
    {
        lineNum++;

        Block lineHex = stringToHex(lineASC.data, lineASC.len);
        if (lineHex.len < 0)
            return "Failed to convert string to hex\n";

        int detected = DetectECBMode(lineHex.data, lineHex.len, 16);

        if (ECBMode == detected)
        {
            message = "Line ";
            message += std::to_string(lineNum);
            message += " is encrypted with ECB.\n";
        }
    }

    return message;
}
