#pragma once
#include <iostream>
#include"ClsHeaderScreen.h"
#include"InputValidLib.h"
#include"bankSys.h"
#include"GlobalObj.h"
using namespace std;

class ClsUpdateClient :protected ClsHeaderScreen
{
private:
	static void _readUpdateData(bankSys& obj) {
		cout << "Enter Name: ";
		obj.Name = InputValidLib::ReadString();
		cout << "Enter Last Name: ";
		obj.Last_Name = InputValidLib::ReadString();
		cout << "Enter Email: ";
		obj.email = InputValidLib::ReadString();
		cout << "Enter Phone Number: ";
		obj.Phone = InputValidLib::ReadString();
		cout << "Enter Pin Code: ";
		obj.Pincode = InputValidLib::ReadString();
		cout << "Enter Balance: ";
		obj.balance = InputValidLib::ReadString();
	}
	/*static void _PrintCard(bankSys obj) {
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
	}*/
public:
	static void ShowUpdateClientScreen() {
		if (!CurrentObj.CheckPermission(CurrentObj.EnUpdate)) {
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			cout << "\t\t\t\t\tAccess Denied! Contact Your Admin.......\n\n";
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			return;

		}
		_HeaderScreen("Update Client Screen ");
		cout << "Enter Account Number: ";
		string accountnumber = InputValidLib::ReadString();
		while (!bankSys::IsClientExist(accountnumber)) {
			cout << "Account Number not found, please enter a valid Account Number: ";
			accountnumber = InputValidLib::ReadString();
		}
		bankSys obj = bankSys::Find(accountnumber);
		_readUpdateData(obj);
		bankSys::EnSaveResult result = obj.save();
		switch (result)
		{
		case bankSys::SaveFailed:
			cout << "Error: Client data could not be saved." << endl;
			break;
		case bankSys::SaveOk:
			cout << "Client data saved successfully." << endl;
			bankSys::_PrintCard(obj);
			break;
		default:
			break;
		}
	}
};


