#pragma once

#include "CryptoUtilities.h"

// The ChallengeSolution struct of ChallengeSolutions.h holds the primary methods that are used to solve all eight Cryptopal 
// challenges. Each method can be called via a ChallengeSolution struct variable.
struct ChallengeSolution
{
    // Prototypes for the eight challenge methods
    string HexToBase64(string);
    string FixedXOR(string, string);
    string SingleByteXORCipher(string);
    string DetectSingleCharXOR(vector<string>);
    string RepeatingKeyXOR(const string&, const string);
    string BreakRepeatingKeyXOR(Block);
    string AES_ECBMode(Block);
    string DetectAES_ECBMode(vector<Block>);
};

/*************************************************** Method for Challenge 1 ***************************************************/
inline string ChallengeSolution::HexToBase64(string hexString)
{
    try 
    {
        // Input validation
        if (hexString.length() < 4 && hexString.length() > 0)
            return "Must enter at least 4 characters";
        if (!IsHexadecimalString(hexString))
            return "Data is not in hexadecimal form";

        vector<unsigned char> hexBytes = HexToBytes(hexString);
        string base64String;
        size_t i = 0;

         //Takes Hex and Converts it into base64
        while (i < hexBytes.size())
        {
            unsigned char byte1 = hexBytes[i++];
            unsigned char byte2 = (i < hexBytes.size()) ? hexBytes[i++] : 0;
            unsigned char byte3 = (i < hexBytes.size()) ? hexBytes[i++] : 0;

            unsigned int threeBytes = (byte1 << 16) | (byte2 << 8) | byte3;

            base64String.push_back(BASE64_TABLE[(threeBytes >> 18) & 0b0011'1111]);
            base64String.push_back(BASE64_TABLE[(threeBytes >> 12) & 0b0011'1111]);
            base64String.push_back(BASE64_TABLE[(threeBytes >> 6) & 0b0011'1111]);
            base64String.push_back(BASE64_TABLE[threeBytes & 0b0011'1111]);
        }

        // Add padding characters if necessary
        int hexStrLength = hexString.length();
        do
        {
            // If hexStrLength is 4, the last two charaters of the base64 encoded string will be '='
            if (hexStrLength == 4)
            {
                base64String.at(base64String.length() - 1) = '=';
                break;
            }

            // If hexStrLength is 8, the last two characters of the base64 encoded string will be '='
            if (hexStrLength == 8)
            {
                base64String.at(base64String.length() - 1) = '=';
                base64String.at(base64String.length() - 2) = '=';
                break;
            }

            // Keep substracting 6 from hexStrLength until it equals 4 or 8
            hexStrLength -= 6;
        } while (hexStrLength >= 4);

        return base64String;
    }
    catch (const std::exception& e)
    {
        return e.what();
    }
}

/*************************************************** Method for Challenge 2 ***************************************************/
inline string ChallengeSolution::FixedXOR(string hexString1, string hexString2)
{
    // Feeds a Hex string then decodes the Hex string. Finally it the decoded Hex goes against XOR'd
    try 
    {
        // Input validation
        if (hexString1.length() != hexString2.length())
            return "Strings are not the same length.";
        if (!IsHexadecimalString(hexString1))
            return "Data is not in hexadecimal form";
        if (!IsHexadecimalString(hexString2))
            return "Data is not in hexadecimal form";

        string result;

        for (size_t i = 0; i < hexString1.length(); i++)
        {
            unsigned char byte1 = HexToBytes(hexString1.substr(i, 1))[0];
            unsigned char byte2 = HexToBytes(hexString2.substr(i, 1))[0];
            unsigned char xorResult = byte1 ^ byte2;
            result += "0123456789abcdef"[xorResult];
        }

        return result;
    }
    catch (const std::exception& e) 
    {
        return e.what();
    }
}

/*************************************************** Method for Challenge 3 ***************************************************/
inline string ChallengeSolution::SingleByteXORCipher(string hexString)
{
    try
    {
        // Input validation
        if (!IsHexadecimalString(hexString))
            return "Data is not in hexadecimal form";

        vector<float> plaintextScores;
        vector<unsigned char> hexBytes = HexToBytes(hexString);
    
        // Generate plaintext with every possible character key with ASCII value 0 through 255
        for (int i = 0; i < 256; i++)
        {
            string plaintext = "";
    
            for (size_t j = 0; j < hexBytes.size(); j++)
            {
                unsigned char xorResult = hexBytes[j] ^ i;
                plaintext += xorResult;
            }
    
            plaintextScores.push_back(ScoreString(plaintext));
        }
    
        float highestScore = *max_element(plaintextScores.begin(), plaintextScores.end());
        char key = distance(plaintextScores.begin(), max_element(plaintextScores.begin(), plaintextScores.end()));
    
        string message = "Key: ";
        message += key;
        message += "\r\nMessage:\r\n";
    
        // Decrypt the message and then displays the message
        for (size_t i = 0; i < hexBytes.size(); i++)
        {
            unsigned char xorResult = hexBytes[i] ^ key;
            message += xorResult;
        }
    
        return message;
    }
    catch (const std::exception& e)
    {
        return e.what();
    }
}

/*************************************************** Method for Challenge 4 ***************************************************/
inline string ChallengeSolution::DetectSingleCharXOR(vector<string> hexCiphertexts)
{
    try
    {
        // Input validation
        for (string hexText : hexCiphertexts)
        {
            if (!IsHexadecimalString(hexText))
                return "Data is not in hexadecimal form";
        }

        vector<float> highPlaintextScores;
        vector<unsigned char> candidateBytes;
        string bestCandidate;
        string ciphertext;
        char possibleKey = '\0';

        for (size_t i = 0; i < hexCiphertexts.size(); i++)
        {
            vector<unsigned char> hexBytes = HexToBytes(hexCiphertexts[i]);
            vector<float> plaintextScores;
            string plaintext;

            // Calculates the high scores of the Plain texts
            for (int i = 0; i < 256; i++)
            {
                plaintext = "";

                for (size_t j = 0; j < hexBytes.size(); j++)
                {
                    unsigned char xorResult = hexBytes[j] ^ i;
                    plaintext += xorResult;
                }

                plaintextScores.push_back(ScoreString(plaintext));
            }

            float highScore = *max_element(plaintextScores.begin(), plaintextScores.end());
            highPlaintextScores.push_back(highScore);

            // If current high score is the highest of the high scores, it is the new best candidate for being the encrypted string
            if (highScore == *max_element(highPlaintextScores.begin(), highPlaintextScores.end()))
            {
                possibleKey = distance(plaintextScores.begin(), max_element(plaintextScores.begin(), plaintextScores.end()));
                bestCandidate = hexCiphertexts[i];
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
    catch (const std::exception& e)
    {
        return e.what();
    }
}

/*************************************************** Method for Challenge 5 ***************************************************/
inline string ChallengeSolution::RepeatingKeyXOR(const string& plain_text, const string key)
{
    try
    {
        //Converts plain text to cipher_text
        string cipher_text;
        for (size_t i = 0; i < plain_text.length(); i++) 
        {
            char xor_result = plain_text[i] ^ key[i % key.length()];
            cipher_text += xor_result;
        }
    
        // Convert the binary cipher_text to hexadecimal
        std::ostringstream hex_stream;
        hex_stream << std::hex << std::setfill('0');
        for (unsigned char c : cipher_text)
            hex_stream << std::setw(2) << static_cast<int>(c);
    
        return hex_stream.str();
    }
    catch (const std::exception& e)
    {
        return e.what();
    }

}

/*************************************************** Method for Challenge 6 ***************************************************/
inline string ChallengeSolution::BreakRepeatingKeyXOR(Block base64Text)
{
    try
    {
        // Input validation
        if (!IsBase64Block(base64Text))
            return "Data is not in base64 form";

        int maxSize = base64Text.len * 3 / 4;
    
        Block hexBuffer;
        hexBuffer.Alloc(maxSize);
        hexBuffer.len = DecodeBase64(base64Text.data, base64Text.len, hexBuffer.data, maxSize);
    
        Block key;
        key.Alloc(FindLikelyKeySize(hexBuffer.data, hexBuffer.len));
    
        for (unsigned i = 0; i < key.len; i++)
            key.data[i] = FindKeyByte(hexBuffer.data, hexBuffer.len, i, key.len);
    
        Block plaintext;
        plaintext.Alloc(hexBuffer.len);
    
        string message = "Key: ";
        for (int i = 0; i < key.len; i++)
            message += key.data[i];

        message += "\r\nMessage:\r\n";

        for (int i = 0; i < hexBuffer.len; i++)
        {
            char byte = key.data[i % key.len];
            plaintext.data[i] = hexBuffer.data[i] ^ byte;
            message += plaintext.data[i];
        }
    
        return message;
    }
    catch (const std::exception& e)
    {
        return e.what();
    }
   
}

/*************************************************** Method for Challenge 7 ***************************************************/
inline string ChallengeSolution::AES_ECBMode(Block base64Text)
{
    try
    {
        // Input validation
        if (!IsBase64Block(base64Text))
            return "Data is not in base64 form";

        // YELLOW SUBMARINE in hexadecimal form; YELLOW SUBMARINE is the default key?
        unsigned char strKey[16] = { 0x59, 0x45, 0x4C, 0x4C, 0x4F, 0x57, 0x20, 0x53, 0x55, 0x42, 0x4D, 0x41, 0x52, 0x49, 0x4E, 0x45 };
    
        // Base64 decode the input
        int iMaximumSize = base64Text.len * 3 / 4;
    
        Block ciphertext;
        ciphertext.Alloc(iMaximumSize);
        ciphertext.len = DecodeBase64(base64Text.data, base64Text.len, ciphertext.data, iMaximumSize);
        Block plaintext;
        plaintext.Alloc(ciphertext.len);
    
        AES_ECB_Decrypt(ciphertext.data, ciphertext.len, plaintext.data, &plaintext.len, strKey, true);
    
        string message;
        //Displays message
        for (int i = 0; i < plaintext.len; i++)
            message += plaintext.data[i];
    
        return message;
    }
    catch (const std::exception& e)
    {
        return e.what();
    }
}

/*************************************************** Method for Challenge 8 ***************************************************/
inline string ChallengeSolution::DetectAES_ECBMode(vector<Block> hexCiphertexts)
{
    try
    {
        // Input validation
        for (Block hexText : hexCiphertexts)
        {
            if (!IsHexadecimalBlock(hexText))
                return "Data is not in hexadecimal form";
        }
        string message;
    
        int lineNum = 0;
    
        for (Block const& line : hexCiphertexts)
        {
            lineNum++;
    
            Block lineHex = StringToHex(line.data, line.len);
            if (lineHex.len < 0)
                return "Failed to convert string to hex";
    
            int detected = DetectECBMode(lineHex.data, lineHex.len, 16);
    
            if (ECBMode == detected)
            {
                message = "Line ";
                message += std::to_string(lineNum);
                message += " is encrypted with ECB.";
            }
        }
    
        return message;
    }
    catch (const std::exception& e)
    {
        return e.what();
    }
}
