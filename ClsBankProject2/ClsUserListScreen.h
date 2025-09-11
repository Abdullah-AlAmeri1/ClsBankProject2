
#pragma once
#include <iostream>
#include"ClsHeaderScreen.h"
#include"UserSys.h"
#include<iomanip>
class ClsUserListScreen : protected ClsHeaderScreen {
	static void _Header() {
		cout << "\t  |==========================================================================================================\n";
		cout << "\t\t" << left << setw(10) << "UserName " << "|" << left << setw(20) << "FullName" << "|"
			<< left << setw(25) << "Email " << "|" << left << setw(15) << "Phone Number" << "|" << left << setw(10) << "Password" << "|"
			<< left << setw(10) << "Permission" << endl;
		cout << "\t  |==========================================================================================================\n";
	}
public:
	static void _ShowAllUser() {
		string sub = to_string(UserSys::AllUsers().size()) + "Users";
		_HeaderScreen("Show Users List Screen ", sub);
		_Header();
		cout << "\t  |==========================================================================================================\n";
		if (UserSys::AllUsers().size() == 0) {
			cout << "\n\n\t\t\t\t Users List Empty\n\n\n";
			cout << "\t  |======================================================================================================\n";
			return;
		}
		vector <UserSys> list = UserSys::AllUsers();

		for (UserSys& l : list) {

			cout << "\t\t" << left << setw(10) << l.UserName() << "|" << left << setw(20) << l.FirstName() + " " + l.LastName() << "|"
				<< left << setw(25) << l.Email() << "|" << left << setw(15) << l.Phone << "|" <<

				left << setw(10) << l.PassWord() << "|" << left << setw(10) << l.Permissions() << endl;

		}
		cout << "\t  |==========================================================================================================\n";
	}
};