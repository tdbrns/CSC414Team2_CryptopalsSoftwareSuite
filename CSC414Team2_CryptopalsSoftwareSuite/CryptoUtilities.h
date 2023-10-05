#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <openssl/aes.h>

using std::string;
using std::vector;
using namespace std;

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
    CBCMode,
    CTRMode
};

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
    Block& operator=(const Block& other)
    {
        // copy the data
        Alloc(other.len);
        memcpy(data, other.data, other.len);

        return *this;
    }
};

// Method for scoring plaintext according to letter frequency
inline float ScorePlaintext(string plaintxt)
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

// Method for converting hexadecimal values into bytes
inline vector<unsigned char> hexToBytes(const string& hex)
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

inline Block stringToHex(unsigned char* inputASCII, int inputLength)
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

inline vector<Block> GetLinesFromFile(const char* file)
{
    vector<Block> out;

    // Create an ifstream
    std::ifstream inStream(file, std::ifstream::binary);
    if (!inStream)
        return out;

    // Add every line to the vector
    std::string line;

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

inline int FindIndex(char ch)
{
    int i;
    for (i = 0; i < 64; i++)
        if (ch == base64Table[i])
            break;

    return i;
}

inline int base64decode(unsigned char* encodedBuffer, int encodedSize, unsigned char* hexBuffer, int hexMaxSize)
{
    char achFour[4] = { 0 };
    int iHexSize = 0;

    if (NULL == hexBuffer || NULL == encodedBuffer || encodedSize <= 0)
        return 0;

    if (hexMaxSize < encodedSize * 3 / 4)
        return 0;

    if (encodedSize % 4 != 0)
        return 0;

    while (encodedSize > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            achFour[i] = FindIndex(*(encodedBuffer++));
        }

        hexBuffer[iHexSize++] = (achFour[0] << 2) | (achFour[1] >> 4);
        if (achFour[2] < 64)
        {
            hexBuffer[iHexSize++] = (achFour[1] << 4) | (achFour[2] >> 2);
            if (achFour[3] < 64)
                hexBuffer[iHexSize++] = (achFour[2] << 6) | (achFour[3] >> 0);
            else
                iHexSize = iHexSize;
        }
        else
            iHexSize = iHexSize;

        encodedSize -= 4;
    }

    return iHexSize;
}


inline bool ValidPKCS7Padding(unsigned char* plaintext, unsigned int ciphertextLen, unsigned int* newLength)
{
    bool bValid = true;
    *newLength = ciphertextLen;
    unsigned int uiPaddingSize = plaintext[ciphertextLen - 1]; // this is the last byte of the plaintext [0 to uiLen-1]

    // Padding must be smaller than the actual size
    if (uiPaddingSize >= ciphertextLen || uiPaddingSize == 0)
    {
        bValid = false;
    }
    else
    {
        *newLength -= uiPaddingSize;

        // Determine if it has valid PKCS#7 padding
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

inline unsigned int RemovePKCS7Padding(unsigned char* plaintext, unsigned int ciphertextLen, bool useExceptions = false)
{
    bool bValid = false;
    unsigned int uiNewSize = 0;

    bValid = ValidPKCS7Padding(plaintext, ciphertextLen, &uiNewSize);

    if (false == bValid)
    {
        if (useExceptions)
        {
            throw("Invalid PKCS#7 padding");
        }
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
