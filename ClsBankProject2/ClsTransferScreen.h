#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"InputValidLib.h"
#include"bankSys.h"
using namespace std;
class ClsTransferScreen : protected ClsHeaderScreen
{
	private:
		static int _ReadAmount() {
			cout << "Enter Amount to Transfer :\n";
			int amount = InputValidLib::ReadIntNumber("Try Again with number please: ");
			return amount;
		}
		static string ReadAccountNumber(string message) {
			cout << message;
			string accountnumber = InputValidLib::ReadString();
			while (!bankSys::IsClientExist(accountnumber)) {
				cout << "Account Number does not exist, please enter a valid Account Number: ";
				accountnumber = InputValidLib::ReadString();
			}
			return accountnumber;
		}
		static bool _IsAmountValid(bankSys fromObj, long amount) {
			if (amount > stol(fromObj.balance)) {
				cout << "Insufficient balance in the account. Please enter a smaller amount.\n";
				return false;
			}
			return true;
		}
		static void PrintCard(bankSys obj) {
			cout << "Client Information:" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Name          : " << obj.Name << endl;
			cout << "Account Number: " << obj.AccountNumber() << endl;
			cout << "Balance       : " << obj.balance << endl;
			cout << "-----------------------------------------------" << endl;
		}
	static void _Transfer() {
		string fromAccount = ReadAccountNumber("Enter Client Account Number to Transfer From :\n");
		
		bankSys fromObj = bankSys::Find(fromAccount);
		PrintCard(fromObj);
		cout << "Enter Client Account Number to Transfer To :\n";
		string toAccount = InputValidLib::ReadString();
		while (!bankSys::IsClientExist(toAccount) || toAccount == fromAccount) {
			if (toAccount == fromAccount) {
				cout << "Cannot transfer to the same account. Please enter a different Account Number: ";
			} else {
				cout << "Account Number does not exist, please enter a valid Account Number: ";
			}
			toAccount = InputValidLib::ReadString();
		}
		bankSys toObj = bankSys::Find(toAccount);
		PrintCard(toObj);
		int amount =  _ReadAmount();
		while (!_IsAmountValid(fromObj, amount)) {
			if(amount <= 0) {
				long amount = InputValidLib::ReadIntNumber("Try Again can not be Negative");
			}
			amount = InputValidLib::ReadIntNumber("Try With sufficient Balance...");
		}

		if (!fromObj.Transfer(amount, toObj)) {
			cout << "Transfer failed!" << endl;
			return;
		}
		if(fromObj.save() == bankSys::SaveFailed || toObj.save() == bankSys::SaveFailed) {
			cout << "Error: Transfer could not be completed due to a saving error." << endl;
			return;
		}
		system("cls");
		_HeaderScreen("Transfer Successful");
		cout << "Transfer successful!" << endl;
		cout << "Sender Account After Transfer:\n";
		PrintCard(fromObj);
		cout << "Destination Account After Transfer:\n";
		PrintCard(toObj);
	}
public:
	static void ShowTransferScreen() {
		_HeaderScreen("Transfer Screen");
		_Transfer();
	}
};

