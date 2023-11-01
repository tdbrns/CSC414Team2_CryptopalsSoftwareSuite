#pragma once
// CryptoUtilities.h holds all of the supplementary functions and header files that are utilized within MainForm.h and
// ChallengeSolutions.h

#include <string>
#include <iomanip>
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
using std::ifstream;

const int BASE64_TABLE_SIZE = 64;
const char BASE64_TABLE[] = {
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
'w', 'x', 'y', 'z', '0', '1', '2', '3',
'4', '5', '6', '7', '8', '9', '+', '/'
};

const int HEX_TABLE_SIZE = 22;
const char HEX_TABLE[] = {
    '0', '1', '2','3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f',
    'A', 'B', 'C', 'D', 'E', 'F'
};

enum OperationMode
{
    ECBMode = 0,
    CBCMode
};

// The Block struct is used to identify a block of data of any given size for a block cipher
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
        if (data != 0)
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

// Scores a character (byte) according to letter frequency (the average number of times letters of the alphabet appear in the English
// language). Reference: https://pi.math.cornell.edu/~mec/2003-2004/cryptography/subs/frequencies.html
inline float ScoreByte(unsigned char ch)
{
    float letterScore = 0;

    switch (tolower(ch))
    {
    case 'a': letterScore = 8.12f; break;
    case 'b': letterScore = 1.49f; break;
    case 'c': letterScore = 2.71f; break;
    case 'd': letterScore = 4.32f; break;
    case 'e': letterScore = 12.02f; break;
    case 'f': letterScore = 2.30f; break;
    case 'g': letterScore = 2.03f; break;
    case 'h': letterScore = 5.92f; break;
    case 'i': letterScore = 7.31f; break;
    case 'j': letterScore = 0.10f; break;
    case 'k': letterScore = 0.69f; break;
    case 'l': letterScore = 3.98f; break;
    case 'm': letterScore = 2.61f; break;
    case 'n': letterScore = 6.95f; break;
    case 'o': letterScore = 7.68f; break;
    case 'p': letterScore = 1.82f; break;
    case 'q': letterScore = 0.11f; break;
    case 'r': letterScore = 6.02f; break;
    case 's': letterScore = 6.28f; break;
    case 't': letterScore = 9.10f; break;
    case 'u': letterScore = 2.88f; break;
    case 'v': letterScore = 1.11f; break;
    case 'w': letterScore = 2.09f; break;
    case 'x': letterScore = 0.17f; break;
    case 'y': letterScore = 2.11f; break;
    case 'z': letterScore = 0.07f; break;
    case ' ': letterScore = 15.0f; break;
    default:
        break;
    }

    return letterScore;
}

// Scores a string of plaintext according to letter frequency
inline float ScoreString(string plaintext)
{
    float score = 0;

    for (int i = 0; i < plaintext.length(); i++)
        score += ScoreByte(plaintext[i]);

    return score;
}

// Scores a block of plaintext according to letter frequency
inline float ScoreBlock(unsigned char* block, int blockLen)
{
    float score = 0;

    for (int i = 0; i < blockLen; i++)
        score += ScoreByte(block[i]);

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

// Calculate the edit/hamming distance between two unsigned char arrays (strings)
inline int HammingDistance(unsigned char* buffer1, unsigned char* buffer2, int bufferLen)
{
    int distance = 0;

    // For every byte (character) in buffer1 and buffer2, compare the bits of buffer1's byte to the bits of buffer2's byte
    for (int i = 0; i < bufferLen; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (((buffer1[i] >> j) & 0x01) != ((buffer2[i] >> j) & 0x01))
                distance++;
        }
    }

    return distance;
}

// Find a single byte of the key for repeating-key XOR cipher
inline unsigned char FindKeyByte(unsigned char* ciphertext, int ciphertextLen, int targetByte, int keyLen)
{
    // Divide the ciphertext into key length-sized blocks.
    // Because the ciphertext may not divide evenly into key length-sized blocks, the length of the block will either be 
    // (ciphertextLen / keyLen) or (ciphertextLen / keyLen) + 1.
    int blockLen = (ciphertextLen / keyLen) + ((targetByte < ciphertextLen % keyLen) ? 1 : 0);

    Block candidateBlock(blockLen);
    Block testBlock(blockLen);

    int indexOffset = 0;
    for (int i = targetByte; i < ciphertextLen; i += keyLen)
        candidateBlock.data[indexOffset++] = ciphertext[i];

    unsigned char bestByte = 0;
    float bestScore = 0;
    for (int i = 0; i < 256; i++)
    {
        unsigned char* temp = (unsigned char*)&i;
        for (int j = 0; j < candidateBlock.len; j++)
        {
            unsigned char byte = temp[j % 1];
            testBlock.data[j] = candidateBlock.data[j] ^ byte;
        }

        float blockScore = ScoreBlock(testBlock.data, testBlock.len);

        if (blockScore > bestScore)
        {
            bestScore = blockScore;
            bestByte = i;
        }
    }

    return bestByte;
}

// Determines the likely size of a key used to encrypt a given ciphertext
inline int FindLikelyKeySize(unsigned char* ciphertext, int ciphertextLen)
{
    int numOfSamples = 3;
    int likelyKeySize = 0;
    int MAX_KEYSIZE = 40;
    float smallestDistance = 100;

    for (int i = 3; i <= MAX_KEYSIZE; i++)
    {
        int distance = 0;
        for (int j = 0; j < numOfSamples; j++)
            distance = HammingDistance(&ciphertext[j * i], &ciphertext[(j + 1) * i], i);

        float normalizedDistance = static_cast<float>(distance) / numOfSamples / i;
        if (normalizedDistance < smallestDistance)
        {
            smallestDistance = normalizedDistance;
            likelyKeySize = i;
        }
    }

    return likelyKeySize;
}

// Trim from the beginning of a string
static inline string& leftTrim(string& str)
{
    // lambda expression
    str.erase(str.begin(), find_if(str.begin(), str.end(), [](unsigned char c) {return !isspace(c); }));
    return str;
}

// Trim from the end of a string
static inline string& rightTrim(string& str)
{
    str.erase(find_if(str.rbegin(), str.rend(), [](unsigned char ch) {return !isspace(ch); }).base(), str.end());
    return str;
}

// Trim from beggining and end of string
static inline string& trim(string& str)
{
    return leftTrim(rightTrim(str));
}

// Read the contents of a file into a Block struct
inline bool BlockReadFile(Block* out, const char* file)
{
    ifstream inStream(file, ifstream::binary);
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
    ifstream inStream(file, ifstream::binary);
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
        if (ch == BASE64_TABLE[i])
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