#pragma once
#include<iostream>
#include"bankSys.h"
#include"MyUtility.h";
#include "ClsHeaderScreen.h"
#include <iomanip>
class ClsTotalBalance : protected ClsHeaderScreen
{
private:
	static void _Header_Balance() {
		_HeaderScreen("Total Balance Screen");
		cout << left << setw(16) << "" << "|---------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(16) << "" << "|" << left << setw(15) << "Name" << "|" << left << setw(20) << "AccountNumber" << "|" << left << setw(14) << "Balance" << endl;
		cout << left << setw(16) << "" << "|---------------------------------------------------------------------------------------------" << endl;
	}
	static void _ShowAllClients_Balance() {
		_Header_Balance();
		vector<bankSys> list = bankSys::getAllClients();
		if (list.size() == 0) {
			cout << left << setw(16) << "" << "|\n|\t\t\t\tNo clients found" << endl;
			cout << left << setw(16) << "" << "|\n|---------------------------------------------------------------------------------------" << endl;

		}
		for (bankSys obj : list) {
			cout << left << setw(16) << "" << "|" << left << setw(15) << obj.FirstName() << "|" << left << setw(20)
				<< obj.AccountNumber() << "|" << left << setw(15) << obj.balance << endl;
		}
		long totalBalance = bankSys::GetTotalBalance();
		cout << endl << left << setw(16) << "" << "|---------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(16) << "" << "\n\n\t\t Total Balance is " << totalBalance << endl;
		cout << left << setw(16) << "" << "\n\n\t\t Total Balance is " << MyUtility::NumberToString(totalBalance) << endl << endl;

	}
public:
	static void AllBalancesShow() {
		_ShowAllClients_Balance();
	}


};

