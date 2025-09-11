#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"InputValidLib.h"
#include"ClsUserListSCreen.h"
#include"ClsAddUser.h"
#include "ClsDeletUserScreeen.h"
#include"ClsUpdateUserScreen.h"
#include "ClsFindUserScreen.h"
#include"GlobalObj.h"
using namespace std;
class ClsUserManag :protected ClsHeaderScreen
{
private:
	enum _UserOptions { ShowAllUsers = 1, AddNewUser, UpdateUser, FindUser, DeleteUser, MainMenu };
	static void _ShowAllUsers() {

		ClsUserListScreen::_ShowAllUser();

	}
	static void _AddNewUser() {
		ClsAddUser::AddUser();
	}
	static void _UpdateUser() {
		ClsUpdateUserScreen::UpdateUser();
	}
	static void _FindUser() {
		ClsFindUserScreen::FindUserScreen();
	}
	static void _DeleteUser() {
		ClsDeletUserScreeen::DeleteUserScreen();


	}
	static short _ReadNumber() {
		cout << "\n\t\tPlease choose an option from the menu: ";
		int  num = InputValidLib::ReadIntNumberInRange("Enter a Number please \n", 1, 6);
		return num;
	}
	static void _GoToMainScreen() {
		cout << "Press Any Key To go To Main Screen.....\n";
		system("Pause>0");
		_MainScreen();

	}

	static void _Perform(_UserOptions option) {
		switch (option) {
		case _UserOptions::ShowAllUsers:
		{
			system("cls");
			_ShowAllUsers();
			_GoToMainScreen();
			break;
		}
		case _UserOptions::AddNewUser:
		{
			system("cls");
			_AddNewUser();
			_GoToMainScreen();
			break;
		}
		case _UserOptions::UpdateUser:
		{
			system("cls");
			_UpdateUser();
			_GoToMainScreen();
			break;
		}
		case _UserOptions::FindUser:
		{
			system("cls");
			_FindUser();
			_GoToMainScreen();
			break;
		}
		case _UserOptions::DeleteUser:
		{
			system("cls");
			_DeleteUser();
			_GoToMainScreen();
			break;
		}
		case _UserOptions::MainMenu: {

		}
		default:
		{
			break;
		}
		}

	}
	static void _MainScreen() {
		_HeaderScreen("User Management Screen ");
		cout << "\t\t|-----------------------------------------------------------------------|" << endl;
		cout << "\t\t|\t\t\t[1]. Show All Users\t\t\t\t" << endl;
		cout << "\t\t|\t\t\t[2]. Add New User\t\t\t\t" << endl;
		cout << "\t\t|\t\t\t[3]. Update User\t\t\t\t" << endl;
		cout << "\t\t|\t\t\t[4]. Find User\t\t\t\t" << endl;
		cout << "\t\t|\t\t\t[5]. Delete User \t\t\t\t" << endl;
		cout << "\t\t|\t\t\t[6]. Main Menu\t\t\t\t" << endl;
		cout << "\t\t|-----------------------------------------------------------------------|" << endl;
		_Perform((_UserOptions)_ReadNumber());
	}
public:
	static void ShowUserManag() {
		if (!CurrentObj.CheckPermission(CurrentObj.EnManag)) {
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			cout << "\t\t\t\t\tAccess Denied! Contact Your Admin.......\n\n";
			cout << "\t\t\t\t-----------------------------------------------------\n\n";
			return;

		}
		_MainScreen();
	}
};


