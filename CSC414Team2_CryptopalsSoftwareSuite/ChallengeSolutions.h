#pragma once

#include <array>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::vector;

// 
struct ChallengeSolution
{
	// Constructor
	ChallengeSolution() {}

	void HexToBase64()
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

		// NOTE!!: This code will only work with strings whose length is a multiple of 3; code must be further modified to 
		// support string lengths that ar not a multiple of 3
		string hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
		vector<uint8_t> hexToDecValues = {};
		int temp = 0;

		// Use ASCII to convert each character to its hexadecimal value in decimal form
		// Example: hex value 'd' has decimal value 13; 13 is stored into hexToDecValues vector
		for (int i = 0; i < hexString.length(); i++)
		{
			if (hexString[i] >= 48 && hexString[i] <= 57)
				temp = hexString[i] - 48;
			else if (hexString[i] >= 97 && hexString[i] <= 102)
				temp = hexString[i] - 87;

			hexToDecValues.push_back(temp);
		}

		string base64String;

		for (int i = 0; i < hexString.length(); i += 3)
		{
			uint32_t const concatBits = (hexToDecValues[i] << 8) | (hexToDecValues[i + 1] << 4) | hexToDecValues[i + 2];

			auto base64Char1 = encodeTable[(concatBits >> 6) & 0b0011'1111];
			auto base64Char2 = encodeTable[concatBits & 0b0011'1111];

			base64String += base64Char1;
			base64String += base64Char2;
		}

		//cout << base64String << endl;
	}
};