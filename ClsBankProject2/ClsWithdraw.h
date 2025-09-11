#pragma once
#include<iostream>
#include"bankSys.h"
#include"ClsHeaderScreen.h"
#include"InputValidLib.h"

class ClsWithdraw :protected ClsHeaderScreen
{
private:
	static long _ReadInt() {
		cout << "Enter The Amount That you Want to Deposit :\n";
		long num = InputValidLib::ReadIntNumber("Try Again with Positive Number");
		return num;
	}
	static string _ReadAccountNumber() {
		string nm;
		do {
			cout << "Please enter the Account number to deposit :\n";
			nm = InputValidLib::ReadString();
		} while (!bankSys::IsClientExist(nm));
		return nm;
	}
	static void _Withdraw() {
		_HeaderScreen("Withdraw Screen ");
		string account_number = _ReadAccountNumber();
		bankSys obj = bankSys::Find(account_number);
		bankSys::_PrintCard(obj);
		long amount = _ReadInt();
		if (obj.Withdraw(amount)) {
			cout << "Do you want to Deposit This amount " << amount << " To this account " << account_number << endl;
			char answer;
			cin >> answer;
			if (tolower(answer) == 'y') {
				bankSys::_PrintCard(obj);
				cout << "Successfully withdraw  " << endl;
				cout << "\nNew Balance is : " << obj.balance << endl;

			}
			else
			{
				cout << "Deposit Canceled ...\n";
			}

		}
		else
		{
			cout << "\n\nOps , Insufficient Balance\n";
			cout << "Do you want ot try again ?\n";
			char an;
			cin >> an;
			if (tolower(an) == 'y') {
				_Withdraw();
			}

		}

	}
public:
	static void Withdraw() {
		_Withdraw();
	}
};


