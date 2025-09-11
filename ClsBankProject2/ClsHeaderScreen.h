#pragma once
#include <iostream>
#include<string>
#include"UserSys.h"
#include"GlobalObj.h"
#include"ClsDate.h"

using namespace std;
class ClsHeaderScreen
{
protected:
	static void _HeaderScreen(string title, string subtitle = "", string Username = CurrentObj.UserName()) {
		system("cls");
		std::cout << "\t\t|========================================================================\|\n";
		std::cout << "                                           " << title << "                    " << endl;
		
		
		if (subtitle != "") {
			std::cout << "                                               " << subtitle << "         " << endl;
		}
		std::cout << "\t\t|========================================================================\|\n";
		cout << "\t\t\t\t\t\t\t User :" << Username << endl;
		cout << "\t\t\t\t\t\t\t Date :" << clsDate::SystemDate();  cout << "\n";
		std::cout << "\t\t|========================================================================|\n\n" << endl;


	}
};



