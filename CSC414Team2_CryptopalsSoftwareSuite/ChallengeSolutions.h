#pragma once

#include <array>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::vector;

// The ChallengeSolution class holds all the methods that will be used to solve all eight Cryptopal challenges.
// Each methods can be called via a ChallengeSolution object in MainForm.h
class ChallengeSolution
{
private:

	vector<uint8_t> hexToBytes(const string& hex) 
	{
		vector<unsigned char> bytes;

		for (size_t i = 0; i < hex.length(); i += 2) {
			string byteString = hex.substr(i, 2);
			uint8_t byte = static_cast<uint8_t>(std::stoi(byteString, nullptr, 16));
			bytes.push_back(byte);
		}

		return bytes;
	}

public:

	// Constructor
	ChallengeSolution() {}

	string HexToBase64()
	{
		array<char, 64> constexpr encodeTable{
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
		'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
		'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
		'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
		'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
		'w', 'x', 'y', 'z', '0', '1', '2', '3',
		'4', '5', '6', '7', '8', '9', '+', '/'
		};

		string hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
		vector<uint8_t> hexToDecValues = {};
		int temp = 0;

		// Use ASCII to convert each character to its hexadecimal value in decimal form
		// Example: hex value 'd' has decimal value 13; 13 is stored in hexToDecValues vector
		for (size_t i = 0; i < hexString.length(); i++)
		{
			if (hexString[i] >= 48 && hexString[i] <= 57)
				temp = hexString[i] - 48;
			else if (hexString[i] >= 97 && hexString[i] <= 102)
				temp = hexString[i] - 87;

			hexToDecValues.push_back(temp);
		}

		string base64String;

		for (size_t i = 0; i < hexString.length(); i += 3)
		{
			uint32_t const concatBits = (hexToDecValues[i] << 8) | (hexToDecValues[i + 1] << 4) | hexToDecValues[i + 2];

			auto base64Char1 = encodeTable[(concatBits >> 6) & 0b0011'1111];
			auto base64Char2 = encodeTable[concatBits & 0b0011'1111];

			base64String += base64Char1;
			base64String += base64Char2;
		}

		// Add padding characters if necessary
		while (base64String.length() % 4 != 0)
			base64String.push_back('=');

		return base64String;
	}

	string FixedXOR()
	{
		string hexString1 = "1c0111001f010100061a024b53535009181c";
		string hexString2 = "686974207468652062756c6c277320657965";

		if (hexString1.length() != hexString2.length())
			return "";

		string result;

		for (size_t i = 0; i < hexString1.length(); i++)
		{
			uint8_t byte1 = hexToBytes(hexString1.substr(i, 2))[0];
			uint8_t byte2 = hexToBytes(hexString2.substr(i, 2))[0];
			uint8_t xorResult = byte1 ^ byte2;
			result += "0123456789ABCDEF"[xorResult];
		}

		return result;
	}
};