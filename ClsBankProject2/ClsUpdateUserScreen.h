#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"InputValidLib.h"
#include "UserSys.h"
#include"ClsAddUser.h"
using namespace std;

class ClsUpdateUserScreen : protected ClsHeaderScreen
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
		if (tolower(answer) == 'y')
			total += UserSys::_PermissionAccess::EnLoginHistory;
		if (total == 255) {
			return -1;
		}
		return total;

	}

public:
	static void UpdateUser() {
		_HeaderScreen("Update User Screen  ");
		cout << "Enter UserName to update:\n";
		string user = InputValidLib::ReadString();
		while (!UserSys::IsUSerExist(user)) {
			cout << "Please Try again This one is already exist ...\nEnter UserName to update:\n";
			string user = InputValidLib::ReadString();
		}
		UserSys obj = UserSys::FindUser(user);
		UserSys::PrintCard(obj);
		cout << "Are you Sure do you want to update this User?\n";
		char ans = InputValidLib::ReadCharYesOrNo();
		if (tolower(ans) == 'y') {
			ClsUpdateUserScreen::_ReadUserInfo(obj);
			UserSys::enSaveResults result;
			result = obj.Save();
			switch (result) {
			case UserSys::enSaveResults::svFaildEmptyObject:
				cout << "Error , Update user failed.......\n";
				break;
			case UserSys::enSaveResults::svSucceeded:
				system("cls");
				cout << "User Updated Successfully ....\n";
				UserSys::PrintCard(obj);
			case UserSys::enSaveResults::svFaildUserExists:
				break;
			}

		}
		else
		{
			cout << "Update Cancelled ......\n";
			UserSys::PrintCard(obj);
		}
	}

};


