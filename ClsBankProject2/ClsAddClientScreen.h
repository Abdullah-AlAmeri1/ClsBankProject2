#pragma once
#include <iostream>
#include"bankSys.h"
#include"InputValidLib.h"
#include"ClsHeaderScreen.h"
#include"GlobalObj.h"
using namespace std;
class ClsAddClientScreen : protected ClsHeaderScreen
{

private:
	static void _ReadClientData(bankSys& obj) {
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
	static void ShowAddNewClientScreen() {
		if (!CurrentObj.CheckPermission(CurrentObj.EnAddClient)) {
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			cout << "\t\t\t\t\tAccess Denied! Contact Your Admin.......\n\n";
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			return;

		}
		_HeaderScreen("Add New  Client ");
		cout << "Enter New Account Number: ";
		string accountnumber = InputValidLib::ReadString();
		while (bankSys::IsClientExist(accountnumber)) {
			cout << "Account Number already exists, please enter a different Account Number: ";
			accountnumber = InputValidLib::ReadString();
		}
		bankSys obj = bankSys::AddNewClient(accountnumber);
		_ReadClientData(obj);
		bankSys::EnSaveResult result = obj.save();
		switch (result) {
		case bankSys::SaveFailed:
			cout << "Error: Client data could not be saved." << endl;
			break;
		case bankSys::SaveOk:
			cout << "Client data saved successfully." << endl;
			_PrintCard(obj);
			break;
		case bankSys::ClientAlreadyExists:
			cout << "Error: Account Number already exists." << endl;
			break;
		default:
			break;
		}
	}
	friend class ClsDeleteClient;

};


