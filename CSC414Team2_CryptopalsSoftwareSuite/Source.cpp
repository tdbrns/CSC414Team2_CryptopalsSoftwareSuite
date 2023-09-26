#include <iostream>
#include <string>
#include <vector>

std::vector<unsigned char> hexToBytes(const std::string& hex);
std::string bytesToBase64(const std::vector<unsigned char>& bytes);
std::string hexXOR(const std::string& hex1, const std::string& hex2);

int main() {
    // Task 1: Convert hex to bytes
    std::string hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    std::vector<unsigned char> bytes = hexToBytes(hexString);

    // Task 2: Convert bytes to base64
    std::string base64String = bytesToBase64(bytes);
    std::cout << "Base64 Encoding: " << base64String << std::endl;

    // Task 3: Perform fixed XOR operation
    std::string hexString1 = "1c0111001f010100061a024b53535009181c";
    std::string hexString2 = "686974207468652062756c6c277320657965";
    std::string xorResult = hexXOR(hexString1, hexString2);
    std::cout << "XOR Result: " << xorResult << std::endl;

    return 0;
}

std::vector<unsigned char> hexToBytes(const std::string& hex) {
    std::vector<unsigned char> bytes;

    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(std::stoi(byteString, nullptr, 16));
        bytes.push_back(byte);
    }

    return bytes;
}



std::string bytesToBase64(const std::vector<unsigned char>& bytes) {
    static const std::string base64Chars =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789+/";

    std::string base64String;
    size_t i = 0;

    while (i < bytes.size()) {
        unsigned char byte1 = bytes[i++];
        unsigned char byte2 = (i < bytes.size()) ? bytes[i++] : 0;
        unsigned char byte3 = (i < bytes.size()) ? bytes[i++] : 0;

        unsigned int threeBytes = (byte1 << 16) | (byte2 << 8) | byte3;

        base64String.push_back(base64Chars[(threeBytes >> 18) & 0x3F]);
        base64String.push_back(base64Chars[(threeBytes >> 12) & 0x3F]);
        base64String.push_back(base64Chars[(threeBytes >> 6) & 0x3F]);
        base64String.push_back(base64Chars[threeBytes & 0x3F]);
    }

    // Add padding characters if necessary
    while (base64String.length() % 4 != 0) {
        base64String.push_back('=');
    }

    return base64String;
}

std::string hexXOR(const std::string& hex1, const std::string& hex2) {
    if (hex1.length() != hex2.length()) {
        return ""; // Buffers must be of equal length
    }

    std::string result;

    for (size_t i = 0; i < hex1.length(); i++) {
        unsigned char byte1 = hexToBytes(hex1.substr(i, 2))[0];
        unsigned char byte2 = hexToBytes(hex2.substr(i, 2))[0];
        unsigned char xorResult = byte1 ^ byte2;
        result += "0123456789ABCDEF"[xorResult];
    }

    return result;
}
