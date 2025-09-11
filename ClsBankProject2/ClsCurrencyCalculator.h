#pragma once
#include<iostream>
#include"ClsCurrency.h"
#include"ClsHeaderScreen.h"
#include"InputValidLib.h"
class ClsCurrencyCalculator : protected ClsHeaderScreen
{
private:
	static float _Convert(float Amount, float FromRate, float ToRate) {
		return (Amount / FromRate) * ToRate;
	}
	static clsCurrency _ReadCurrencyCode(string number) {
		cout << "Please enter the currency code that you want to  " << number << " :\n";
		string CurrencyCode = InputValidLib::ReadString();
		while (clsCurrency::FindByCode(CurrencyCode).IsEmpty())
		{
			cout << "Currency not found for the specified currency code. Please try again." << endl;
			CurrencyCode = InputValidLib::ReadString();

		}
		return clsCurrency::FindByCode(CurrencyCode);
	}
	static float _ReadAmount() {
		cout << "Please enter the amount: ";
		float Amount = InputValidLib::ReadFloatNumber("Invalid input. Please enter a valid number: ");
		return Amount;
	}

public:
	static void Calculate() {
		
		char choice = 'y';
		while(tolower(choice) == 'y') {
			system("cls");
			_HeaderScreen("Currency Calculator");
			clsCurrency FromCurrency = _ReadCurrencyCode("convert from ");
			clsCurrency ToCurrency = _ReadCurrencyCode("convert to");
			float Amount = _ReadAmount();
			float ConvertedAmount = _Convert(Amount, FromCurrency.Rate(), ToCurrency.Rate());
			cout <<endl<<  Amount << " " << FromCurrency.CurrencyCode() << " = " << ConvertedAmount << " " << ToCurrency.CurrencyCode() << endl;
			cout << "\nDo you want to perform another conversion? (Y/N): ";
			choice = InputValidLib::ReadCharYesOrNo();

		}
		
	}
};

