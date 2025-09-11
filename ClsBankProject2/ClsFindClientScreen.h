#pragma once
#include <iostream>
#include"ClsHeaderScreen.h"
#include"InputValidLib.h"
#include"bankSys.h"
#include"GlobalObj.h"

class ClsFindClientScreen :protected ClsHeaderScreen
{
private:
	//static void _PrintCard(bankSys obj) {
	//	cout << "Client Information:" << endl;
	//	cout << "-----------------------------------------------" << endl;
	//	cout << "Name          : " << obj.Name << endl;
	//	cout << "Last Name     : " << obj.Last_Name << endl;
	//	cout << "Full Name     : " << obj.Name + " " + obj.Last_Name << endl;
	//	cout << "Email         : " << obj.email << endl;
	//	cout << "Phone Number  : " << obj.Phone << endl;
	//	cout << "Account Number: " << obj.AccountNumber() << endl;
	//	cout << "Pin Code      : " << obj.PinCode() << endl;
	//	cout << "Balance       : " << obj.balance << endl;
	//	cout << "-----------------------------------------------" << endl;
	//}
public:
	static void ShowFindClientScreen() {
		if (!CurrentObj.CheckPermission(CurrentObj.EnFind)) {
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			cout << "\t\t\t\t\tAccess Denied! Contact Your Admin.......\n\n";
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			return;

		}
		_HeaderScreen("Find Client Screen ");
		cout << "Enter Account Number: ";
		string accountnumber = InputValidLib::ReadString();
		while (!bankSys::IsClientExist(accountnumber)) {
			cout << "Account Number not found, please enter a valid Account Number: ";
			accountnumber = InputValidLib::ReadString();
		}
		bankSys obj = bankSys::Find(accountnumber);
		if (obj.IsEmpty())
			cout << "Client not found." << endl;
		else {
			cout << "Client found successfully." << endl;
			bankSys::_PrintCard(obj);

		}


	}


};

