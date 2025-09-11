#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"UserSys.h"
#include"ClsMainScreen.h"
#include "InputValidLib.h"
#include"GlobalObj.h"
//#include"ClsGlobal.h"
class ClsLoginScreen :protected ClsHeaderScreen
{
private:
	static bool _Login() {
		bool LoginFailed = false;
		int count = 3;
		do {

			
			if (LoginFailed) {
				
				cout << "Invalid UserName/Password\n";
				cout << "You have " << count << " trials \n";
				count--;

			}
			if (count == 0) {
				system("cls");
				cout << "\n\nYour Locked......\n";
				return false;
			}
			cout << "Enter User Name :\n";
			string name = InputValidLib::ReadString();
			cout << "Enter Password :\n";
			string Password = InputValidLib::ReadString();
			CurrentObj = UserSys::FindUser(name, Password);
			LoginFailed = CurrentObj.IsEmpty();
			
		} while (LoginFailed);
		CurrentObj.RegisterLoginUser();
		ClsMainScreen::Show();
		return true;

	}
public:
	static bool LoginScreen() {
		_HeaderScreen("Login Screen");
		return _Login();
	}
};

