#pragma once
#include <iostream>
#include<string>
#include "ClsHeaderScreen.h"
#include "InputValidLib.h"
#include"ClsScreenList.h"
#include"ClsAddClientScreen.h"
#include"ClsDeleteClient.h"
#include"ClsUpdateClient.h"
#include"ClsFindClientScreen.h"
#include"ClsTransMenu.h"
#include"ClsUserMang.h"
#include"GlobalObj.h"
#include"ClsLoginHistoryScreen.h"
#include"ClsExchangeMenu.h"
using namespace std;
class ClsMainScreen : protected ClsHeaderScreen
{
private:
	enum MainMenuOptions {
		ShowAllClients = 1, AddNewClient = 2, UpdateClient = 3, DeleteClient = 4, FindClient = 5, Transaction = 6, ManageUser = 7, LoginHistory = 8,ExchangeCurrency = 9,Exit = 10
	};
	static short _ReadMainMenuOption() {
		short option = 0;
		cout << "Please choose an option from the menu: ";
		option = InputValidLib::ReadIntNumberInRange("Try Again Please With number", 1, 10);
		return option;

	}
	static void _ShowAllClients() {
		ClsScreenList::ShowAllClients();
	}
	static void _AddNewClient() {
		ClsAddClientScreen::ShowAddNewClientScreen();
	}
	static void _UpdateClient() {
		ClsUpdateClient::ShowUpdateClientScreen();
	}
	static void _DeleteClient() {
		ClsDeleteClient::ShowDeleteClientScreen();
	}
	static void _Transaction() {
		ClsTransMenu::_TransScreen();
	}
	static void _FindClient() {
		ClsFindClientScreen::ShowFindClientScreen();

	}
	static void _ManageUser() {
		ClsUserManag::ShowUserManag();
	}
	static void LoginScreenHistory() {
		ClsLoginHistoryScreen::ShowLoginHistory();
		
	}
	static void ExchangeCurrencyScreen() {
		ClsExchangeMenu::ShowExchangeMenu();
	}
	static void  _GoToMain() {
		cout << "\n\nPress any key to go back to Main Menu...";
		system("pause>0");
		system("cls");
		_ShowMainScreen();
	}
	static void _LoginScreen() {
		CurrentObj = UserSys::FindUser("", "");
	}

	static void _PerformMainMenuOption(MainMenuOptions option) {
		switch (option)
		{
		case MainMenuOptions::ShowAllClients:
			system("cls");
			_ShowAllClients();
			_GoToMain();
			break;
		case MainMenuOptions::AddNewClient:
			system("cls");
			_AddNewClient();
			_GoToMain();
			break;
		case MainMenuOptions::UpdateClient:
			system("cls");
			_UpdateClient();
			_GoToMain();
			break;
		case MainMenuOptions::DeleteClient:
			system("cls");
			_DeleteClient();
			_GoToMain();
			break;
		case MainMenuOptions::FindClient:
			system("cls");
			_FindClient();
			_GoToMain();
			break;
		case MainMenuOptions::Transaction:
			system("cls");
			_Transaction();
			_GoToMain();
			break;
		case MainMenuOptions::ManageUser:
			system("cls");
			_ManageUser();
			_GoToMain();
			break;
		case MainMenuOptions::LoginHistory:
			system("cls");
			LoginScreenHistory();
			_GoToMain();
			break;
		case MainMenuOptions::ExchangeCurrency:
			system("cls");
			ExchangeCurrencyScreen();
			_GoToMain();
			break;
		case MainMenuOptions::Exit:
			_LoginScreen();
			break;
		default:
			break;
		}
	}
	static void _ShowMainScreen() {
		_HeaderScreen("Bank System Main Screen");
		cout << "\t\t|-----------------------------------------------------------------------|" << endl;
		cout << "\t\t|\t\t\t[1]. Show All Clients\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t[2]. Add New Client\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t[3]. Update Client\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t[4]. Delete Client\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t[5]. Find Client\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t[6]. Transaction\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t[7]. Manage User\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t[8]. Login History\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t[9]. Exchange Currency\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t[10]. Exit\t\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t\t\t\t\t\t\t|\n\t\t|-----------------------------------------------------------------------|\n\n\t\t";
		_PerformMainMenuOption((MainMenuOptions)_ReadMainMenuOption());



	}
public:
	static void Show() {
		_ShowMainScreen();
	}



};



