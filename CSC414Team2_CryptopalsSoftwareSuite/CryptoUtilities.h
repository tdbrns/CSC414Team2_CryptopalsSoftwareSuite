#pragma once
// CryptoUtilities.h holds all of the supplementary functions and header files that are utilized within MainForm.h and
// ChallengeSolutions.h

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <new>
#include <limits>
#include <openssl/aes.h>

using std::string;
using std::vector;

const char base64Table[64] = {
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
'w', 'x', 'y', 'z', '0', '1', '2', '3',
'4', '5', '6', '7', '8', '9', '+', '/'
};

enum OperationMode
{
    ECBMode = 0,
    CBCMode
};

// The Block struct is used to identify blocks of data of any given size for a block cipher.
struct Block
{
    unsigned char* data = NULL;
    unsigned int len;

    void Alloc(int iSize)
    {
        if (data)
            Free();

        try
        {
            data = new unsigned char[iSize];
            len = iSize;
        }
        catch (std::bad_alloc& e)
        {
            len = 0;
        }
    }

    void Free()
    {
        len = 0;
        if (data)
        {
            delete[] data;
            data = NULL;
        }
    }

    void SetTo(int iValue)
    {
        memset(data, iValue, len);
    }

    void SetData(const char* newData, unsigned int newDataLen)
    {
        memcpy(data, newData, newDataLen);
    }

    Block()
    {
        data = NULL;
        len = 0;
    }

    Block(int iSize)
    {
        Alloc(iSize);
    }

    ~Block()
    {
        Free();
    }

    // Copy constructor
    Block(const Block& other)
    {
        Alloc(other.len);
        memcpy(data, other.data, other.len);
    }

    // Copy assignment operator
    Block& operator=(const Block& rightSide)
    {
        // copy the data
        Alloc(rightSide.len);
        memcpy(data, rightSide.data, rightSide.len);
        return *this;
    }
};

// Scores plaintext according to letter frequency (the average number of times letters of the alphabet appear in the English
//  language). Reference: https://pi.math.cornell.edu/~mec/2003-2004/cryptography/subs/frequencies.html
inline float ScorePlaintext(string plaintxt)
{
    float score = 0.0f;
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
        default: break;
        }
    }

    return score;
}

// Converts hexadecimal values into bytes
inline vector<unsigned char> HexToBytes(const string& hex)
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

// Converts a string into hexadecimal form
inline Block StringToHex(unsigned char* inputASCII, int inputLength)
{
    // Create a Block object to be returned.
    Block out(inputLength / 2);

    for (int i = 0; i < inputLength / 2; i++)
    {
        if (inputASCII[2 * i] >= '0' && inputASCII[2 * i] <= '9')
            out.data[i] = 16 * (inputASCII[2 * i] - '0');

        else if (inputASCII[2 * i] >= 'A' && inputASCII[2 * i] <= 'F')
            out.data[i] = 16 * (10 + (inputASCII[2 * i] - 'A'));

        else if (inputASCII[2 * i] >= 'a' && inputASCII[2 * i] <= 'f')
            out.data[i] = 16 * (10 + (inputASCII[2 * i] - 'a'));

        else
            return -1;


        if (inputASCII[2 * i + 1] >= '0' && inputASCII[2 * i + 1] <= '9')
            out.data[i] += (inputASCII[2 * i + 1] - '0');

        else if (inputASCII[2 * i + 1] >= 'A' && inputASCII[2 * i + 1] <= 'F')
            out.data[i] += 10 + (inputASCII[2 * i + 1] - 'A');

        else if (inputASCII[2 * i + 1] >= 'a' && inputASCII[2 * i + 1] <= 'f')
            out.data[i] += 10 + (inputASCII[2 * i + 1] - 'a');

        else
            return -1;
    }

    return out;
}

// Calculates the edit/hamming distance between to strings
inline int HammingDistance(string s1, string s2)
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

// Transposes blocks of data according to the method described in Challenge 6, Set 1 
inline vector<string> TransposeBlocks(string ciphertext, int keySize)
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
            tempStr += blocks[j].substr(i, 1);

        transposedBlocks.push_back(tempStr);
    }

    return transposedBlocks;
}

// 
inline char FindKeyForBlock(string block)
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

// Determines the likely size of a key used to encrypt a given ciphertext
inline int FindLikelyKeySize(string ciphertext)
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
                normalizedDistance += HammingDistance(blocks[i], blocks[j]) / static_cast<double>(keySize);
                pairsCount++;
            }
        }

        normalizedDistance /= pairsCount;

        if (normalizedDistance < smallestNormalizedDistance) 
        {
            smallestNormalizedDistance = normalizedDistance;
            likelyKeySize = keySize;
        }
    }
    
    return likelyKeySize;
}

// Trim from the beginning of a string
static inline string& leftTrim(string& str)
{
    // lambda expression
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char c) {return !std::isspace(c); }));
    return str;
}

// Trim from the end of a string
static inline string& rightTrim(string& str)
{
    str.erase(find_if(str.rbegin(), str.rend(), [](unsigned char ch) {return !isspace(ch); }).base(), str.end());
    return str;
}

// Trim from beggining and end of string
static inline std::string& trim(std::string& str)
{
    return leftTrim(rightTrim(str));
}

// Read the contents of a file into a Block struct
inline bool BlockReadFile(Block* out, const char* file)
{
    std::ifstream inStream(file, std::ifstream::binary);
    if (!inStream)
        return false;

    // get length of file:
    inStream.seekg(0, inStream.end);
    int contentLength = (int)inStream.tellg();
    inStream.seekg(0, inStream.beg);

    if (contentLength <= 0)
        return false;

    out->Alloc(contentLength);

    inStream.read((char*)out->data, contentLength);
    inStream.close();

    return true;
}

// Read the contents of a file into a vector of Block structs
inline vector<Block> GetLinesFromFile(const char* file)
{
    vector<Block> out;

    // Create an ifstream
    std::ifstream inStream(file, std::ifstream::binary);
    if (!inStream)
        return out;

    // Add every line to the vector
    string line;

    while (std::getline(inStream, line))
    {
        // Trim
        line = trim(line);

        // Create a block
        Block temp(line.size());
        temp.SetData(line.c_str(), line.size());

        // Insert into vector
        out.push_back(temp);
    }

    inStream.close();

    return out;
}

// Accept a base64 character and find its index in the base64 encode table
inline int FindIndexBase64(char ch)
{
    int i;
    for (i = 0; i < 64; i++)
        if (ch == base64Table[i])
            break;

    return i;
}

// Decode a base64 string and determine the size of the decoded hexadecimal value
inline int DecodeBase64(unsigned char* encodedBuffer, int encodedSize, unsigned char* hexBuffer, int hexMaxSize)
{
    char achFour[4] = { 0 };
    int hexSize = 0;

    if (NULL == hexBuffer || NULL == encodedBuffer || encodedSize <= 0)
        return 0;

    if (hexMaxSize < encodedSize * 3 / 4)
        return 0;

    if (encodedSize % 4 != 0)
        return 0;

    while (encodedSize > 0)
    {
        for (int i = 0; i < 4; i++)
            achFour[i] = FindIndexBase64(*(encodedBuffer++));

        hexBuffer[hexSize++] = (achFour[0] << 2) | (achFour[1] >> 4);
        if (achFour[2] < 64)
        {
            hexBuffer[hexSize++] = (achFour[1] << 4) | (achFour[2] >> 2);
            if (achFour[3] < 64)
                hexBuffer[hexSize++] = (achFour[2] << 6) | (achFour[3] >> 0);
            else
                hexSize = hexSize;
        }
        else
            hexSize = hexSize;

        encodedSize -= 4;
    }

    return hexSize;
}

// Determine if the plaintext had any PKCS #7 padding added to it when it was encrypted
inline bool ValidPKCS7Padding(unsigned char* plaintext, unsigned int ciphertextLen, unsigned int* newLength)
{
    bool bValid = true;
    *newLength = ciphertextLen;
    unsigned int uiPaddingSize = plaintext[ciphertextLen - 1]; // this is the last byte of the plaintext [0 to uiLen-1]

    // Padding must be smaller than the actual size
    if (uiPaddingSize >= ciphertextLen || uiPaddingSize == 0)
        bValid = false;
    else
    {
        *newLength -= uiPaddingSize;

        // Determine if it has valid PKCS #7 padding
        for (unsigned int i = ciphertextLen - 1; i >= *newLength; i--)
        {
            if (plaintext[i] != uiPaddingSize)
            {
                bValid = false;
                break;
            }
        }
    }

    return bValid;
}

// Remove PKCS #7 padding from plaintext if needed
inline unsigned int RemovePKCS7Padding(unsigned char* plaintext, unsigned int ciphertextLen, bool useExceptions = false)
{
    bool bValid = false;
    unsigned int uiNewSize = 0;

    bValid = ValidPKCS7Padding(plaintext, ciphertextLen, &uiNewSize);

    if (false == bValid)
    {
        if (useExceptions)
            throw("Invalid PKCS#7 padding");
        else
        {
            // Return the exact same size
            return ciphertextLen;
        }
    }

    // Just to be sure, fill it with 0xFF
    for (unsigned int i = ciphertextLen - 1; i >= uiNewSize; i--)
        plaintext[i] = 0xFF;

    return uiNewSize;
}

// Decrypt AES-encrypted ciphertext with a given key
inline void AES_ECB_Decrypt(unsigned char* ciphertext, unsigned int ciphertextLen, unsigned char* plaintext, unsigned int* pPlaintextLen, unsigned char* strKey, bool removePadding = true)
{
    AES_KEY key;
    AES_set_decrypt_key(strKey, 8 * AES_BLOCK_SIZE, &key);

    for (unsigned i = 0; i < ciphertextLen; i += 16)
        AES_ecb_encrypt(&ciphertext[i], &plaintext[i], &key, AES_DECRYPT);

    // Remove padding
    if (removePadding)
        *pPlaintextLen = RemovePKCS7Padding(plaintext, ciphertextLen);
}

// Detect a line of ciphertext encrypted with AES in ECB mode by locating identical AES-sized blocks
inline int DetectECBMode(unsigned char* ciphertext, unsigned int ciphertextLen, unsigned int blockSize)
{
    int currMode = CBCMode;
    int numBlocks = ciphertextLen / blockSize;

    for (int i = 0; i < numBlocks; i++)
    {
        for (int j = i + 1; j < numBlocks; j++)
        {
            // Get an AES-sized block
            if (0 == memcmp(&ciphertext[i * blockSize], &ciphertext[j * blockSize], blockSize))
                currMode = ECBMode;
        }
    }

    return currMode;
}
