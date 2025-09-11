#pragma once
#include<iostream>
#include"UserSys.h"
#include "ClsHeaderScreen.h"
#include "Cls_String_Library.h"
#include"InputValidLib.h"
//#include"ClsGlobal.h"
class ClsAddUser :protected ClsHeaderScreen
{
private:
	static void _ReadUserInfo(UserSys& obj) {
		cout << "Enter First Name :\n";
		obj.Name = InputValidLib::ReadString();
		cout << "Enter LastName:\n";
		obj.Last_Name = InputValidLib::ReadString();
		cout << "Enter Email :\n";
		obj.email = InputValidLib::ReadString();
		cout << "Enter Phone number :\n";
		obj.Phone = InputValidLib::ReadString();
		cout << "Enter Password :\n";
		obj.password = InputValidLib::ReadString();
		cout << "Do you want to give it full Permission :\n";
		char ans;
		cin >> ans;
		if (tolower(ans) == 'y') {
			obj.Permission = "-1";

		}
		else
		{

			int va = _ReadPerm();
			obj.Permission = to_string(va);

		}
	}
	static int _ReadPerm() {
		int total = 0;
		char answer;
		cout << "Do you want to give access to :\nShow All Clients :\n";
		answer = InputValidLib::ReadCharYesOrNo();
		if (tolower(answer) == 'y')
			total += UserSys::_PermissionAccess::EnShowALL;
		cout << "Add Client :\n";
		answer = InputValidLib::ReadCharYesOrNo();
		if (tolower(answer) == 'y')
			total += UserSys::_PermissionAccess::EnAddClient;
		cout << "Update Client :\n";
		answer = InputValidLib::ReadCharYesOrNo();
		if (tolower(answer) == 'y')
			total += UserSys::_PermissionAccess::EnUpdate;
		cout << "Find Client :\n";
		answer = InputValidLib::ReadCharYesOrNo();
		if (tolower(answer) == 'y')
			total += UserSys::_PermissionAccess::EnFind;
		cout << "Delete Client :\n";
		answer = InputValidLib::ReadCharYesOrNo();
		if (tolower(answer) == 'y')
			total += UserSys::_PermissionAccess::EnDelet;
		cout << "Transaction :\n";
		answer = InputValidLib::ReadCharYesOrNo();
		if (tolower(answer) == 'y')
			total += UserSys::_PermissionAccess::EnTrans;
		cout << "Manage User :\n";
		answer = InputValidLib::ReadCharYesOrNo();
		if (tolower(answer) == 'y')
			total += UserSys::_PermissionAccess::EnManag;
		cout << "Login History :\n";
		answer = InputValidLib::ReadCharYesOrNo();
		if (tolower(answer) == 'y') {
			total += UserSys::_PermissionAccess::EnLoginHistory;
		}
		cout << "Currency Exchange :\n";
		answer = InputValidLib::ReadCharYesOrNo();
		if(tolower(answer) == 'y') {
			total += UserSys::_PermissionAccess::EnCurrencyExchange;
		}
		if (total == 511) {
			return -1;
		}
		return total;

	}
public:
	static void AddUser() {
		_HeaderScreen("Add New User Screen");
		cout << "Enter UserName :\n";
		string username = InputValidLib::ReadString();
		while (UserSys::IsUSerExist(username)) {
			cout << "This user name already exist ,\nTry another one please:\n";
			username = InputValidLib::ReadString();
		}
		UserSys obj = UserSys::GetAddNewUserObject(username);
		_ReadUserInfo(obj);
		UserSys::enSaveResults result;
		result = obj.Save();
		switch (result) {
		case UserSys::enSaveResults::svFaildEmptyObject:
			cout << "\nError User was not saved because it's Empty";
			break;
		case UserSys::enSaveResults::svFaildUserExists:
			cout << "Error User is Already Exist....\n";
			break;
		case UserSys::enSaveResults::svSucceeded:
			cout << "User Added Successfully ....\n";
			UserSys::PrintCard(obj);

		}




	}
	/*friend class ClsUpdateUserScreen;*/
};



