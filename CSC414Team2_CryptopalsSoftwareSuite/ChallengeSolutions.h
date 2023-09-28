#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

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

	// Private method for converting hexadecimal values into bytes
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
	int currentEncryptKey;
	// Constructor
	ChallengeSolution()
	{
		currentEncryptKey = 0;
	}

	// Method for challenge 1
	string HexToBase64()
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

		string hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

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

	// Method for challenge 2
	string FixedXOR()
	{
		string hexString1 = "1c0111001f010100061a024b53535009181c";
		string hexString2 = "686974207468652062756c6c277320657965";

		// Both strings must be the same length
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

	// Method for challenge 3
	string SingleByteXORCipher()
	{
		string hexString = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
		vector<float> plaintextScores;

		vector<unsigned char> hexBytes = hexToBytes(hexString);

		string plaintext;

		// Generate plaintext with every possible character key with ASCII value 0 through 255
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

		float highestScore = *max_element(plaintextScores.begin(), plaintextScores.end());
		// Key is 88
		auto key = distance(plaintextScores.begin(), max_element(plaintextScores.begin(), plaintextScores.end()));
		currentEncryptKey = key;

		string message;

		for (int i = 0; i < hexBytes.size(); i++)
		{
			unsigned char xorResult = hexBytes[i] ^ key;
			message += xorResult;
		}

		return message;
	}
};
