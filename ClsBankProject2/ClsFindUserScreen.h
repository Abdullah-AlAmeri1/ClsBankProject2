#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"InputValidLib.h"
#include "UserSys.h"
using namespace std;

class ClsFindUserScreen :protected ClsHeaderScreen
{
public:
	static void FindUserScreen() {
		_HeaderScreen("Find User Screen ");
		cout << "Enter UserName :\n";
		string username = InputValidLib::ReadString();
		while (!UserSys::IsUSerExist(username)) {
			cout << "This user name not  exist ,\nTry another one please:\n";
			username = InputValidLib::ReadString();
		}
		UserSys obj = UserSys::FindUser(username);
		if (UserSys::IsUSerExist(username)) {
			cout << "User Found Successfully.....\n";
			UserSys::PrintCard(obj);
		}
		else
		{
			cout << "User Not Found ......\n";
			return;
		}

	}
};
