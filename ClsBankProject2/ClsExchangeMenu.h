#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsCurrency.h"
#include"InputValidLib.h"
#include"GlobalObj.h"
#include"ClsFindCurrencyByCountry.h"
#include"ClsShowALlCurrency.h"
#include"ClsFindbyCurrencyCode.h"
#include"ClsUpdateRate.h"
#include"ClsCurrencyCalculator.h"
using namespace std;
class ClsExchangeMenu : protected ClsHeaderScreen
{
private:
	enum _enOptions { EnShowAll = 1, EnFindByCode = 2, EnFindByCountry = 3, EnUpdateRate = 4, EnCalculateExchange = 5, EnMainMenu = 6 };
	static void _ShowAll() {
		ClsShowAllCurrency::ShowAllCurrency();
	}
	static void _FindByCode() {
		ClsFindbyCurrencyCode::FindCurrencyByCode();
	}
	static void _FindByCountry() {
		ClsFindCurrencyByCountry::FindCurrencyByCountry();
	}
	static void _UpdateRate() {
		ClsUpdateRate::UpdateRate();
	}
	static void _CalculateExchange() {
		ClsCurrencyCalculator::Calculate();
	}
	static void _GoBack() {
		cout << "\nPress any key to go back...";
		system("pause");
		_PrintMenu();
		system("cls");
	}
	static void _PerformOption(_enOptions option) {
		switch (option)
		{
		case _enOptions::EnShowAll:
			system("cls");
			_ShowAll();
			_GoBack();
			break;
		case _enOptions::EnFindByCode:
			system("cls");
			_FindByCode();
			_GoBack();
			break;
		case _enOptions::EnFindByCountry:
			system("cls");
			_FindByCountry();
			_GoBack();
			break;
		case _enOptions::EnUpdateRate:
			system("cls");
			_UpdateRate();
			_GoBack();
			break;
		case _enOptions::EnCalculateExchange:
			system("cls");
			_CalculateExchange();
			_GoBack();
			break;
		case EnMainMenu:
			break;
		default:
			break;
		}
	}
	static short _ReadOption() {
		cout << "\nChoose what do you want to do? [1 to 6] : ";
		int option = InputValidLib::ReadIntNumberInRange("Enter number between 1 and 6 only\n",1, 6);
		return option;
	}
	static void _PrintMenu() {
		string title = "Exchange Menu Screen";
		_HeaderScreen(title);
		cout << "\n\t\t__________________________________________"<< endl;
		cout << "\t\t\tExchange Menu Screen";
		cout << "\n\t\t__________________________________________";
		cout << "\n\n\t\t[1]. Show All Currencies.";
		cout << "\n\t\t[2]. Find Currency By Code.";
		cout << "\n\t\t[3]. Find Currency By Country.";
		cout << "\n\t\t[4]. Update Currency Exchange Rate.";
		cout << "\n\t\t[5]. Calculate Currency Exchange.";
		cout << "\n\t\t[6]. Main Menu.";
		cout << "\n\n\t\t__________________________________________\n\n";
		_PerformOption((_enOptions)_ReadOption());
		
	}
public:
	static void ShowExchangeMenu() {
		if(!CurrentObj.CheckPermission(UserSys::_PermissionAccess::EnCurrencyExchange)) {
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			cout << "\t\t\t\t\tAccess Denied! Contact Your Admin.......\n\n";
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			return;
		}
		_PrintMenu();
		
	}


};

