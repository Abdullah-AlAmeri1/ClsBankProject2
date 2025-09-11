#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"InputValidLib.h"
#include"bankSys.h"
#include "ClsAddClientScreen.h"
#include"GlobalObj.h"
using namespace std;


class ClsDeleteClient : protected ClsHeaderScreen
{
	static void _PrintCard(bankSys obj) {
		cout << "Client Information:" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Name          : " << obj.Name << endl;
		cout << "Last Name     : " << obj.Last_Name << endl;
		cout << "Full Name     : " << obj.Name + " " + obj.Last_Name << endl;
		cout << "Email         : " << obj.email << endl;
		cout << "Phone Number  : " << obj.Phone << endl;
		cout << "Account Number: " << obj.AccountNumber() << endl;
		cout << "Pin Code      : " << obj.PinCode() << endl;
		cout << "Balance       : " << obj.balance << endl;
		cout << "-----------------------------------------------" << endl;
	}
public:
	static void ShowDeleteClientScreen() {
		if (CurrentObj.CheckPermission(CurrentObj.EnDelet)) {


			_HeaderScreen("Delete Client Screen ");
			string accountnumber = "";
			cout << "Enter Account Number to Delete: ";
			accountnumber = InputValidLib::ReadString();
			while (!bankSys::IsClientExist(accountnumber)) {
				cout << "Account Number not found, please enter a valid Account Number: ";
				accountnumber = InputValidLib::ReadString();
			}
			bankSys obj = bankSys::Find(accountnumber);
			ClsDeleteClient::_PrintCard(obj);
			cout << "Are you sure you want to delete this client? (Y/N): ";
			char confirmation;
			cin >> confirmation;
			if (confirmation == 'Y' || confirmation == 'y') {
				if (obj.Delete()) {

					cout << "Client deleted successfully." << endl;
				}
				else {
					cout << "Error: Client could not be deleted." << endl;
				}
			}
			else {
				cout << "Deletion cancelled." << endl;
			}
		}
		else
		{
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			cout << "\t\t\t\t\tAccess Denies! Contact Your Admin.......\n\n";
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			return;

		}
	}
	

};
