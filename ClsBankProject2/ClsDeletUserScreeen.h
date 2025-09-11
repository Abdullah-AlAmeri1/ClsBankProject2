#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"InputValidLib.h"
#include "UserSys.h"
using namespace std;

class ClsDeletUserScreeen : protected ClsHeaderScreen
{
private:

public:
	static void DeleteUserScreen() {
		_HeaderScreen("Delete User Screen");
		cout << "\nEnter UserName to delete:\n";
		string name = InputValidLib::ReadString();
		while (!UserSys::IsUSerExist(name)) {
			cout << "Ops, There is no such this user .\nPlease Enter UserName to delete:\n";
			string name = InputValidLib::ReadString();
		}
		UserSys obj = UserSys::FindUser(name);
		UserSys::PrintCard(obj);
		cout << "\nAre you sure do you want to delete this account ?\n";
		char ans = InputValidLib::ReadCharYesOrNo();
		if (tolower(ans) == 'y') {
			if (obj.DeleteUSer()) {
				cout << "User Delete Successfully .....\n";
				UserSys::PrintCard(obj);
			}
			else
			{
				cout << "Error happened , Try again  ";
				return;
			}
		}
		else
		{
			cout << "Delete User Canceled....";
			return;
		}

	}

};

