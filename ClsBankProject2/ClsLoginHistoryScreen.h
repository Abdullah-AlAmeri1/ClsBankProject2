#pragma once
#include<iostream>
#include<vector>
#include"UserSys.h"
#include"ClsHeaderScreen.h"
#include"GlobalObj.h"
#include<iomanip>
using namespace std;
class ClsLoginHistoryScreen : protected ClsHeaderScreen
{
	private:
		static void _PrintLoginHistory() {
			cout << "\t\t|-------------------------------------------------------------------------------------\n";
			cout << "\t\t|" << left << setw(15) <<"Date" << "|" << left << setw(15) << "Time" << "|" << left << setw(20) << "User Name" << "|" << left << setw(20) << "Permission" << endl;
			cout << "\t\t|-------------------------------------------------------------------------------------\n";
		}
public:
	static void ShowLoginHistory() {
		if(!CurrentObj.CheckPermission(UserSys::EnLoginHistory)) {
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			cout << "\t\t\t\t\tAccess Denied! Contact Your Admin.......\n\n";
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			return;
		}
		_HeaderScreen("Login History");
		_PrintLoginHistory();
		vector<UserSys::LoginHistory> list = UserSys::_LoadLoginDataFromFile();
		for (UserSys::LoginHistory obj : list) {
			cout << "\t\t|" << left << setw(15) << obj.Date << "|" << left << setw(15) << obj.Time << "|" << left << setw(20) << obj.UserName << "|" << left << setw(20) << obj.Permission << endl;
			
		}
		cout << "\t\t|-------------------------------------------------------------------------------------\n";
	}
};
