#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

using std::string;
using std::vector;

std::vector<std::string> transposeBlocks(const std::string& ciphertext, int keySize);
int hammingDistance(const std::string& s1, const std::string& s2);
char findKeyForBlock(const std::string& block);
int findLikelyKeySize(const std::string& ciphertext);

// The ChallengeSolution class holds all the methods that will be used to solve all eight Cryptopal challenges.
// Each methods can be called via a ChallengeSolution object in MainForm.h
class ChallengeSolution
{
private:
    // Method for scoring plaintext according to letter frequency
    float ScorePlaintext(string plaintxt)
    {
        float score = 0;
        int asciiCount = 0;

        for (int i = 0; i < plaintxt.length(); i++)
            plaintxt[i] = tolower(plaintxt[i]);

        for (int i = 0; i < plaintxt.length(); i++)
        {

            switch (tolower(plaintxt[i]))
            {
                case 'a': score += 8.12; break;
                case 'b': score += 1.49; break;
                case 'c': score += 2.71; break;
                case 'd': score += 4.32; break;
                case 'e': score += 12.02; break;
                case 'f': score += 2.30; break;
                case 'g': score += 2.03; break;
                case 'h': score += 5.92; break;
                case 'i': score += 7.31; break;
                case 'j': score += 0.10; break;
                case 'k': score += 0.69; break;
                case 'l': score += 3.98; break;
                case 'm': score += 2, 61; break;
                case 'n': score += 6.95; break;
                case 'o': score += 7.68; break;
                case 'p': score += 1.82; break;
                case 'q': score += 0.11; break;
                case 'r': score += 6.02; break;
                case 's': score += 6.28; break;
                case 't': score += 9.10; break;
                case 'u': score += 2.88; break;
                case 'v': score += 1.11; break;
                case 'w': score += 2.09; break;
                case 'x': score += 0.17; break;
                case 'y': score += 2.11; break;
                case 'z': score += 0.07; break;
                case ' ': score += 15; break;
                default:
                    break;
            }
        }

        return score;
    }

    // Create method for generating plaintext w/ XOR

    // Method for converting hexadecimal values into bytes
    vector<unsigned char> hexToBytes(const string& hex)
    {
        vector<unsigned char> bytes;

        for (size_t i = 0; i < hex.length(); i += 2)
        {
            string byteString = hex.substr(i, 2);
            unsigned char byte = static_cast<unsigned char>(std::stoi(byteString, nullptr, 16));
            bytes.push_back(byte);
        }

        return bytes;
    }

public:
    char currentEncryptKey;
    // Constructor
    ChallengeSolution()
    {
        currentEncryptKey = 0;
    }

    /*************************************************** Method for Challenge 1 ***************************************************/
    string HexToBase64(string input)
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
    string FixedXOR(string hexString1, string hexString2)
    {
        // Both strings must be the same length
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
    string SingleByteXORCipher()
    {
        string hexString = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
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
        // Key is 88
        char key = distance(plaintextScores.begin(), max_element(plaintextScores.begin(), plaintextScores.end()));
        currentEncryptKey = key;

        string message;

        for (size_t i = 0; i < hexBytes.size(); i++)
        {
            unsigned char xorResult = hexBytes[i] ^ key;
            message += xorResult;
        }

        return message;
    }

    /*************************************************** Method for Challenge 4 ***************************************************/
    string DetectSingleCharXOR(string file_name)
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
        currentEncryptKey = possibleKey;
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
    string repeat_key_xor(const string& plain_text, const string key) {
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
    string BreakRepeatingKeyXOR(const string& input)
    {

        //static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

        int likelyKeySize = findLikelyKeySize(input);
        std::vector<std::string> transposedBlocks = transposeBlocks(input, likelyKeySize);
        std::string key;

        for (const std::string& block : transposedBlocks) {
            char likelyKey = findKeyForBlock(block);
            key += likelyKey;
        }

        std::string plaintext;
        for (size_t i = 0; i < input.size(); ++i) {
            plaintext += input[i] ^ key[i % likelyKeySize];
        }

        return plaintext;
    }

    /*************************************************** Method for Challenge 7 ***************************************************/
    string AES_ECBMode()
    {
        return "";
    }

    /*************************************************** Method for Challenge 8 ***************************************************/
    string DetectAES_ECBMode()
    {
        return "";
    }

    int hammingDistance(const std::string& s1, const std::string& s2) {
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


    std::vector<std::string> transposeBlocks(const std::string& ciphertext, int keySize) {
        std::vector<std::string> transposedBlocks(keySize, "");

        for (size_t i = 0; i < ciphertext.size(); ++i) {
            transposedBlocks[i % keySize] += ciphertext[i];
        }

        return transposedBlocks;
    }

    char findKeyForBlock(const std::string& block) {
        char likelyKey = 0;
        int maxScore = 0;

        for (char key = 0; key < 256; ++key) {
            int score = 0;
            for (char c : block) {
                char decrypted = c ^ key;
                if (std::isprint(decrypted)) {
                    score++;
                }
            }
            if (score > maxScore) {
                maxScore = score;
                likelyKey = key;
            }
        }

        return likelyKey;


    }


    // Function to find the likely key size
    int findLikelyKeySize(const std::string& ciphertext) {
        int likelyKeySize = 0;

        //cant solve error
        double smallestNormalizedDistance = std::numeric_limits<double>::max();

        for (int keySize = 2; keySize <= 40; ++keySize) {
            std::vector<std::string> blocks;
            for (size_t i = 0; i < ciphertext.size(); i += keySize) {
                blocks.push_back(ciphertext.substr(i, keySize));
            }

            double normalizedDistance = 0.0;
            int pairsCount = 0;

            for (size_t i = 0; i < blocks.size() - 1; ++i) {
                for (size_t j = i + 1; j < blocks.size(); ++j) {
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

        return likelyKeySize;
    }

};
