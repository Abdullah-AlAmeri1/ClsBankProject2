#pragma once
#include <iostream>
#include <string>
#include"ClsDate.h"
#include"Cls_String_Library.h"
#include <limits>
using namespace std;
class InputValidLib
{
public:
	static bool IsNumberBetween(int number, int From, int To)
	{
		return number >= From && number <= To;
	}
	static bool IsNumberBetween(float number, float From, float To)
	{
		return number >= From && number <= To;
	}
	static bool ISDateBetween(clsDate Date, clsDate From, clsDate To) {
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualToDate2(Date, From)) && (
			clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1AfterDate2(Date, To)))
			return true;
		else if((clsDate::IsDate1BeforeDate2(Date,From)|| clsDate::IsDate1EqualToDate2(Date,From))&&
			(clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualToDate2(Date, To)))
			return true;
		else

		return false;
	}
	static int ReadIntNumber(string message) {
		int number;
		while (!(cin >> number)) { // check if extraction fails
			cin.clear();             // clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
			cout << message;
		}
		return number;
	}
	static float ReadFloatNumber(string message) {
		float number;
		while (!(cin >> number)) { // check if extraction fails
			cout << message;
			cin.clear();             // clear error flag
			cin.ignore(10000, '\n'); // discard invalid input
		}
		return number;
	}
	static double ReadDoubleNumber(string message) {
		double number;
		while (!(cin >> number)) { // check if extraction fails
			cout << message;
			cin.clear();             // clear error flag
			cin.ignore(10000, '\n'); // discard invalid input
		}
		return number;
	}
	static int ReadIntNumberInRange(string message, int From, int To) {
		int number;
		do {
			number = ReadIntNumber(message);
			if (!IsNumberBetween(number, From, To)) {
				cout << "Number must be between " << From << " and " << To << ". Try again: " << endl;
			}
		} while (!IsNumberBetween(number, From, To));
		return number;
	}
	static float ReadFloatNumberInRange(string message, float From, float To) {
		float number;
		do {
			number = ReadFloatNumber(message);
		} while (!IsNumberBetween(number, From, To));
		return number;
	}
	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}
	static string ReadString() {
		string input = "";
		getline(cin >> ws, input);
		return input;
	}
	static char ReadCharYesOrNo() {
		char input;
		cin >> input;
		while (tolower(input) != 'y' && tolower(input) != 'n') {
				cout << "Please Enter Y or N\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> input;
		}
		return input;
	}
};

