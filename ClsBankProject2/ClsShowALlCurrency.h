#pragma once
#include <iostream>
#include"ClsCurrency.h"
#include"ClsHeaderScreen.h"
#include<iomanip>
using namespace std;
class ClsShowAllCurrency : protected ClsHeaderScreen
{
private:
	static void _Header() {
		cout << "____________________________________________________________________________________________\n";
		cout << "|" << left << setw(30) << "Country Name " << "|" << left << setw(8) << "CurrCode" << "|" << left << setw(30) << "Curr Name" << "|" << left << setw(15) << "Currency Rate" << endl;
		cout << "____________________________________________________________________________________________\n";
	}
	static void AllCurrency() {
		_HeaderScreen("All Currencies");
		_Header();
		vector <clsCurrency> list = clsCurrency::GetCurrenciesList();
		if (list.size() == 0) {
			cout << "Currency List is Empty\n";
			return;
		}
		for (clsCurrency& obj : list) {
			cout << "|" << left << setw(30) << obj.Country() << "|" << left << setw(8) << obj.CurrencyCode() << "|" 
				<< left << setw(30) << obj.CurrencyName() << "|" << left << setw(15) << obj.Rate() << endl;
			
			
		}
		cout << "____________________________________________________________________________________________\n";
	}

public :
	static void ShowAllCurrency() {
		AllCurrency();
	}


};

