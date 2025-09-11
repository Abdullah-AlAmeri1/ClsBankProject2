#pragma once
#include<iostream>
#include "bankSys.h"
using namespace std;
#include"InputValidLib.h"
#include"ClsHeaderScreen.h"
class ClsDepositScreen : protected ClsHeaderScreen
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
	static void _Deposit() {
		_HeaderScreen("Deposit Screen ");
		string account_number = _ReadAccountNumber();
		bankSys obj = bankSys::Find(account_number);
		bankSys::_PrintCard(obj);
		long amount = _ReadInt();
		cout << "Do you want to Deposit This amount " << amount << " To this account " << account_number << endl;
		char answer;
		cin >> answer;
		if (tolower(answer) == 'y') {
			obj.Deposit(amount);
			cout << "Successfully Deposit " << endl;
			cout << "\nNew Balance is : " << obj.balance << endl;

		}
		else
		{
			cout << "Deposit Canceled ...";
		}
	}
public:
	static void DepositScreen() {
		_Deposit();
	}
};


