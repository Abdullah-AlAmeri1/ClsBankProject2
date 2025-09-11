#pragma once
#include<iostream>
#include "ClsHeaderScreen.h"
#include"InputValidLib.h"
#include"ClsDepositScreen.h"
#include"ClsWithdraw.h"
#include"ClsTotalBalance.h"
#include"GlobalObj.h"
#include"ClsTransferScreen.h"
#include"ClsTransferRegisterShowScreen.h"

class ClsTransMenu : protected ClsHeaderScreen
{
private:
	static short _ReadNum() {
		cout << "Please Select Option to Perform  :";
		int number = InputValidLib::ReadIntNumberInRange(" Try again with number please:  ", 1, 6);
		return number;
	}
	enum TransOption { EnDeposit = 1, EnWithdraw, EnTotalBalances,EnTransfer,EnTransferReg ,MainMenu };
	static void _Deposit() {
		ClsDepositScreen::DepositScreen();
	}
	static void TransferRegister() {
		ClsTransferRegisterShowScreen::ShowTransferRegisterScreen();
	}
	static void _Withdraw()
	{
		ClsWithdraw::Withdraw();

	}
	static void _TotalBalance() {
		ClsTotalBalance::AllBalancesShow();
	}
	static void _Transfer() {
		ClsTransferScreen::ShowTransferScreen();
	}

	static void _GoToTransScreen() {
		cout << "Press any Key To Go To Transaction Main Menu...........\n";
		system("pause>0");
		system("cls");
		_MainScreen();
	}
	static void _PerformOptions(TransOption option) {
		switch (option) {

		case TransOption::EnDeposit: {
			system("cls");
			_Deposit();
			_GoToTransScreen();
			break;
		}
		case TransOption::EnWithdraw:
		{
			system("cls");
			_Withdraw();
			_GoToTransScreen();
			break;
		}
		case TransOption::EnTotalBalances:
		{
			system("cls");
			_TotalBalance();
			_GoToTransScreen();
			break;
		}
		case TransOption::EnTransfer:
		{
			system("cls");
			_Transfer();
			_GoToTransScreen();
			break;
		}
		case TransOption::EnTransferReg:
		{
			system("cls");
			TransferRegister();
			_GoToTransScreen();
			break;
		}
		case TransOption::MainMenu:
		{

		}

		}
	}
	static void _MainScreen() {
		_HeaderScreen("Transaction  Screen");
		cout << "\t\t|-----------------------------------------------------------------------" << endl;
		cout << "\t\t|\t\t\t[1]. Deposit\t\t\t\t" << endl;
		cout << "\t\t|\t\t\t[2]. Withdraw\t\t\t\t" << endl;
		cout << "\t\t|\t\t\t[3]. Total Balances \t\t\t\t" << endl;
		cout << "\t\t|\t\t\t[4]. Transfer \t\t\t\t" << endl;
		cout << "\t\t|\t\t\t[5]. Transfer Register \t\t\t\t" << endl;
		cout << "\t\t|\t\t\t[6]. Main Menu \t\t\t\t" << endl;
		cout << "\t\t|-----------------------------------------------------------------------" << endl;
		_PerformOptions((TransOption)_ReadNum());
	}


public:
	static void _TransScreen() {
			if (!CurrentObj.CheckPermission(CurrentObj.EnTrans)) {
				cout << "\t\t\t\t-----------------------------------------------------\n\n";
				cout << "\t\t\t\t\tAccess Denied! Contact Your Admin.......\n\n";
				cout << "\t\t\t\t-----------------------------------------------------\n\n";
				return;

			}
		_MainScreen();
	}



};


