#pragma once
#include <iostream>
#include"bankSys.h"
#include<iomanip>
#include"ClsHeaderScreen.h"
#include"GlobalObj.h"
using namespace std;

class ClsScreenList : protected ClsHeaderScreen
{
private:
	static void _Header() {
		string subtitle = to_string(bankSys::getAllClients().size()) + " Clients";
		ClsHeaderScreen::_HeaderScreen("All Client List", subtitle);
		cout << "    |--------------------------------------------------------------------------------------------------" << endl;
		cout << setw(5) << "|" << left << setw(15) << "AccountNumber" << "|" << left << setw(15)
			<< "Name" << "|" << left << setw(15) << "Last Name" << "|" << left << setw(20) << "Email"
			<< "|" << left << setw(10) << "Phone" << "|" << left << setw(10) << "PinCode" << "|" << left << setw(10) << "Balance" << endl;
		cout << "    |--------------------------------------------------------------------------------------------------" << endl;

	}
public:
	static void ShowAllClients() {
		if (!CurrentObj.CheckPermission(CurrentObj.EnShowALL)) {
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			cout << "\t\t\t\t\tAccess Denied! Contact Your Admin.......\n\n";
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			return;

		}

		_Header();
		vector<bankSys> list = bankSys::getAllClients();
		if (list.size() == 0) {
			cout << "     |\n|\t\t\t\tNo clients found" << endl;
			cout << "     |\n|--------------------------------------------------------------------------------------------------" << endl;


			return;
		}

		for (bankSys obj : list) {
			cout << setw(5) << "    |" << left << setw(15) << obj.AccountNumber() << "|" << left << setw(15)
				<< obj.FirstName() << "|" << left << setw(15) << obj.LastName() << "|" << left << setw(20) << obj.Email()
				<< "|" << left << setw(10) << obj.PhoneNumber() << "|" << left << setw(10) << obj.PinCode() << "|" << left << setw(10) << obj.balance << endl;


		}
		cout << "      \n    |--------------------------------------------------------------------------------------------------" << endl;
	}
};


