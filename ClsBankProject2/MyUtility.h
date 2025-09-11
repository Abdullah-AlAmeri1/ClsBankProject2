#pragma once
#include <string>
#include<iostream>
using namespace std;
class MyUtility
{
public:
	enum Type_of_oparetion {
		Capitale_letter = 1,
		Small_letter = 2,
		Number = 3,
		Mix = 4,
	};
	static void Srand() {
		srand((unsigned)time(NULL));
	}
	static int GetRandomNumber(int From, int To) {
		return rand() % (To - From + 1) + From;
	}
	static char GetRandomChar(Type_of_oparetion type) {
		switch (type)
		{
		case MyUtility::Capitale_letter:
			return (char)GetRandomNumber(65, 90);
			break;
		case MyUtility::Small_letter:
			return (char)GetRandomNumber(97, 122);
			break;
		case MyUtility::Number:
			return (char)GetRandomNumber(48, 57);
			break;
		case MyUtility::Mix:
		{
			int random = GetRandomNumber(1, 3);
			if (random == 1)
				return (char)GetRandomNumber(65, 90);
			else if (random == 2)
				return (char)GetRandomNumber(97, 122);
			else
				return (char)GetRandomNumber(48, 57);
			break;
		}
		default:
			break;
		}
	}
	static string GenerateWord(int length, Type_of_oparetion type){
		string word = "";
		for (int i = 0; i < length; i++) {
			word += GetRandomChar(type);
		}
		return word;
	}
	static string GenerateWord(int length) {
		return GenerateWord(length, Mix);
	}
	static string GenerateKey(Type_of_oparetion type) {
		string key = "";
		for (int i = 0; i < 4; i++) {
			key += GenerateWord(4, type);
			if (i != 3)
				key += "-";
		}
		return key;
	}
	static string GenerateKey() {
		return GenerateKey(Mix);
	}
	static void GenerateKeys(int number_of_keys, Type_of_oparetion type) {
		for (int i = 0; i < number_of_keys; i++) {
			cout << "Key ["<< i + 1 <<"] : "<< GenerateKey(type) << endl;
		}

	}
	static void  Swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
			}
	static void Swap(char& a, char& b) {
		char temp = a;
		a = b;
		b = temp;
	}
	static void Swap(string& a, string& b) {
		string temp = a;
		a = b;
		b = temp;
	}
	static void Swap(double& a, double& b) {
		double temp = a;
		a = b;
		b = temp;
	}
	static string   Shuffle(string& str) {
		int n = str.length();
		string new_str = str;
		for (int i = 0; i < n; i++) {
			int random_index = GetRandomNumber(0, n - 1);
			Swap(str[i], str[random_index]);
			new_str = str;
		}
		return new_str;
	}
	static void Shuffle(int arr[100], int length) {
		for (int i = 0; i < length; i++) {
			int random_index = GetRandomNumber(0, length - 1);
			Swap(arr[i], arr[random_index]);
		}



	}
	static void Shuffle(char arr[100], int length) {
		for (int i = 0; i < length; i++) {
			int random_index = GetRandomNumber(0, length - 1);
			Swap(arr[i], arr[random_index]);
		}
	}
	static void Shuffle(string arr[100], int length) {
		for (int i = 0; i < length; i++) {
			int random_index = GetRandomNumber(0, length - 1);
			Swap(arr[i], arr[random_index]);
		}
	}

	static void FillArrayWithRandNum(int arr[100], int length, int from, int to) {
		for (int i = 0; i < length; i++) {
			arr[i] = GetRandomNumber(from, to);
		}
	}
	static void DisplayArray(int arr[100], int length,bool  WithNewLine = true) {
		for (int i = 0; i < length; i++) {
			cout << arr[i] << " ";
			if (WithNewLine)
				cout << endl;
		}
		
	}
	static void DisplayArray(string arr[100], int length, bool  WithNewLine = true) {
		for (int i = 0; i < length; i++) {
			cout << arr[i] << " ";
			if (WithNewLine)
				cout << endl;
		}
	}
	static string Encrypt(string text, int Key) {
		string encrypted_text = "";
		for (int i = 0; i < text.length(); i++) {
			encrypted_text += (char)(text[i] + Key);
		}
		return encrypted_text;
	}
	static string Decrypt(string &text, int Key) {
		string decrypted_text = "";
		for (int i = 0; i < text.length(); i++) {
			decrypted_text += (char)(text[i] - Key);
		}
		return decrypted_text;
	}
	static string NumberToString(long number) {
		if (number == 0) return "0";
		string str = "";
		int num = number;
		if (number < 0) {
			str += "Positive ";
			num *= -1;
		}
		if (num >= 1 && num <= 19) {
			string units[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
				"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
			return str + units[num - 1];
		}
		if (num >= 20 && num <= 99) {
			string tens[] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
			return str + tens[num / 10 - 2] + (num % 10 != 0 ? " " + NumberToString(num % 10) : "");
		}
		if (num >= 100 && num <= 999) {
			return str + NumberToString(num / 100) + " Hundred" + (num % 100 != 0 ? " and " + NumberToString(num % 100) : "");
		}
		if (num >= 1000 && num <= 999999) {
			return str + NumberToString(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + NumberToString(num % 1000) : "");
		}
		if (num >= 1000000 && num <= 999999999) {
			return str + NumberToString(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + NumberToString(num % 1000000) : "");
		}
	}
	//static string NumberToString(const double number) {
	//	long int_part = (long)number;
	//	long frac_part = (long)((number - int_part) * 100); // Get two decimal places
	//	if (frac_part < 0) frac_part *= -1; // Handle negative numbers
	//	return NumberToString(int_part) + " Point " + NumberToString(frac_part);
	//}

	static void Decryption(string& text, const string& key) {
		unsigned short keyPos = 0;

		for (char& C : text) {
			if (keyPos == key.length())
				keyPos = 0;

			C = (C - key[keyPos] + 95) % 95 + 32;

			keyPos++;
		}
	}
	static void Encryption(string& text, const string& key) {
		unsigned short keyPos = 0;
		for (char& C : text) {
			if (keyPos == key.length())
				keyPos = 0;
			// Encryption algorithm
			C = (C + key[keyPos] - 64) % 95 + 32;
			keyPos++;
		}
	}
	

};
