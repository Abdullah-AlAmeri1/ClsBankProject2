#pragma once
#include<iostream>
#include"ClsCurrency.h"
#include"ClsHeaderScreen.h"
using namespace std;

class ClsFindCurrencyByCountry : protected ClsHeaderScreen
{
	private:
	static void _PrintCurrencyCard(clsCurrency obj) {
		if (obj.IsEmpty()) {
			std::cout << "Currency not found for the specified country." << std::endl;
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
	static string _ReadCountry() {
		string country;
		cout << "Please enter the country name: ";
		getline(cin >> ws, country); // Use getline to read the entire line including spaces
		return country;
	}


public:
	static void FindCurrencyByCountry() {
		_HeaderScreen("Find Currency by Currency Name ");
		string country = _ReadCountry();
		clsCurrency obj = clsCurrency::FindByCountry(country);
		_PrintCurrencyCard(obj);

	}
};

