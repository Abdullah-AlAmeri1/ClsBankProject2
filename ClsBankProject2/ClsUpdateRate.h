#pragma once
#include<iostream>
#include "ClsCurrency.h"
#include "ClsHeaderScreen.h"
#include"InputValidLib.h"
class ClsUpdateRate : protected ClsHeaderScreen
{
	static string _ReadCurrencyCode() {
		string CurrencyCode;
		cout << "Please enter the currency code: ";
		CurrencyCode = InputValidLib::ReadString();
		return CurrencyCode;
	}
	static float _ReadNewRate() {
		float NewRate;
		cout << "Please enter the new rate: ";
		NewRate = InputValidLib::ReadFloatNumber("Invalid input. Please enter a valid number: ");
		return NewRate;
	}
	static void _PrintCurrencyCard(clsCurrency obj) {
		if (obj.IsEmpty()) {
			std::cout << "Currency not found for the specified currency code." << std::endl;
			return;
		}
		cout << "Currency Information:" << endl;
		std::cout << "-----------------------------------------------" << std::endl;
		std::cout << "Country       : " << obj.Country() << std::endl;
		std::cout << "Currency Code: " << obj.CurrencyCode() << std::endl;
		std::cout << "Currency Name: " << obj.CurrencyName() << std::endl;
		std::cout << "Exchange Rate to USD: " << obj.Rate() << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
	}
	static void _ChangeRate() {
		string CurrencyCode = _ReadCurrencyCode();
		clsCurrency obj = clsCurrency::FindByCode(CurrencyCode);
		while (obj.IsEmpty())
		{
			cout << "Currency not found for the specified currency code. Please try again." << endl;
			CurrencyCode = _ReadCurrencyCode();
			obj = clsCurrency::FindByCode(CurrencyCode);

		}
		_PrintCurrencyCard(obj);
		
		float NewRate = _ReadNewRate();
		cout << "Are you sure you want to update the rate? (Y/N): ";
		char answer = InputValidLib::ReadCharYesOrNo();
		if (tolower(answer) != 'y') {
			cout << "Operation cancelled. Rate not updated." << endl;
			return;
		}
		obj.UpdateRate(NewRate);
		cout << "Rate updated successfully." << endl;
		_PrintCurrencyCard(obj);
		
	}
public:
	static void UpdateRate() {
		_HeaderScreen("Update Currency Rate");
		_ChangeRate();
	}

};

