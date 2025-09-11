#pragma once
#include<iostream>
#include<vector>
#include"PersonInfoCls.h"
#include<fstream>
#include"Cls_String_Library.h"
#include <charconv>
#include"ClsDate.h"
#include"MyUtility.h"
using namespace std;
class UserSys :public PersonInfoCls

{
private:
	string _UserNameFile = "user.txt";
	//	enum _PermissionAccess {
	//	EnShowALL = 1, EnAddClient = 2, EnUpdate = 4, EnFind = 8, EnDelet = 16 , EnTrans = 32, EnManag = 64
	//};

	enum _Mod { EnEmptyMod = 0, EnUpdateMod = 1, EnAddMod = 2 };
	_Mod _ModStatus;
	string _UserName;
	string _Password;
	string _Permission;
	bool _MarkForDelete = false;
	static void _AddUser(string line) {
		fstream file;
		file.open("user.txt", ios::out | ios::app);
		if (file.is_open()) {
			file << line << endl;
			file.close();
		}
		else
		{
			cout << "Error happened" << endl;
		}


	}
	void _AddUser() {
		string line = _ConvertToLine(*this);
		_AddUser(line);
	}
	static UserSys _ConvertLineToUserObj(string line) {
		
		vector<string> list = Cls_String_Library::Split(line, "/##/");
		string decrypted = list[5];
		MyUtility::Decryption(decrypted,"KEY");
		return UserSys(_Mod::EnUpdateMod, list[0], list[1], list[2], list[3], list[4], decrypted, list[6]);


	}
	static UserSys _ConvertLineToUserObjEmpty() {
		return UserSys(_Mod::EnEmptyMod, "", "", "", "", "", "", "0");
	}
	static string _ConvertToLine(UserSys obj) {
		string encrypted = obj._Password;
		MyUtility::Encryption(encrypted, "KEY");
		string line = obj.FirstName() + "/##/" + obj.LastName() + "/##/" + obj.Email() + "/##/" + obj.Phone + "/##/" + obj._UserName + "/##/" + encrypted + "/##/" + obj._Permission;
		return line;
	}
	static vector<UserSys> _LoadDataFromFile() {
		vector<UserSys> list;
		fstream file;
		file.open("user.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				UserSys obj = _ConvertLineToUserObj(line);
				list.push_back(obj);
			}
			file.close();
		}
		return list;
	}
	static void _SaveDataToFile(vector<UserSys> list) {
		fstream file;
		file.open("user.txt", ios::out); // this overwriten ::out it truncate the all file content and then add a new ones
		if (file.is_open()) {
			for (UserSys obj : list) {
				if (obj._MarkForDelete) {
					continue;
				}
				string line = _ConvertToLine(obj);
				file << line << endl;
			}
			file.close();
		}
	}
	void Update() {
		vector<UserSys> list = _LoadDataFromFile();
		for (UserSys& obj : list) {
			if (obj.UserName() == UserName()) {
				obj = *this;
				break;
			}
		}
		_SaveDataToFile(list);
	}
	
	string _RegisterLogin() {
		string newuser = clsDate::SystemDate() + "/##/" + clsDate::CurrentTime() + "/##/" + _UserName + "/##/" + _Permission;
		return newuser;
	}
	
	

public:

	UserSys(_Mod mod, string FirstName, string LastName, string Email, string PhoneNumber, string UserName, string Password, string Permissions) :
		PersonInfoCls(FirstName, LastName, Email, PhoneNumber) {
		_ModStatus = mod;
		_UserName = UserName;
		_Password = Password;
		_Permission = Permissions;
	}
	//setter
	void SetUserName(string user) {
		_UserName = user;
	}
	void SetPassword(string Pass) {
		_Password = Pass;
	}
	void SetPermission(string perm) {
		_Permission = perm;
	}
	///*void SetPermission(string Permis) {
	//	_Permission = Permis;
	//}*/
	//getter
	string UserName() {
		return _UserName;
	}
	string PassWord() {
		return _Password;
	}
	string Permissions() {
		return _Permission;
	}
	__declspec(property(get = UserName, put = SetUserName)) string username;
	__declspec(property(get = PassWord, put = SetPassword)) string password;
	__declspec(property(get = Permissions, put = SetPermission)) string Permission;

	static UserSys FindUser(string user) {
		fstream file;
		file.open("user.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				UserSys obj = _ConvertLineToUserObj(line);
				if (obj._UserName == user) {
					file.close();
					return obj;
				}
			}file.close();
		}
		return _ConvertLineToUserObjEmpty();
	}
	static struct LoginHistory {
		string Date;
		string Time;
		string UserName;
		string Permission;
	};
	static UserSys FindUser(string user, string Password) {
		fstream file;
		file.open("user.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				UserSys obj = _ConvertLineToUserObj(line);
				if (obj._UserName == user && obj._Password == Password) {
					file.close();
					return obj;
				}
			}file.close();
		}
		return _ConvertLineToUserObjEmpty();
	}
	bool IsEmpty() {
		return (_Mod::EnEmptyMod == _ModStatus);
	}
	static bool IsUSerExist(string user) {
		return !FindUser(user).IsEmpty();
	}
	bool DeleteUSer() {
		vector <UserSys> list = _LoadDataFromFile();
		for (UserSys& obj : list) {
			if (obj.UserName() == _UserName) {
				obj._MarkForDelete = true;
				break;
			}
		}
		_SaveDataToFile(list);
		*this = _ConvertLineToUserObjEmpty();
		return true;
	}
	static vector<UserSys> AllUsers() {
		return _LoadDataFromFile();
	}
	enum _PermissionAccess {
		EnShowALL = 1, EnAddClient = 2, EnUpdate = 4, EnFind = 8, EnDelet = 16, EnTrans = 32, EnManag = 64, EnLoginHistory = 128, EnCurrencyExchange = 256
	};
	static UserSys GetAddNewUserObject(string UserName)
	{
		return UserSys(_Mod::EnAddMod, "", "", "", "", UserName, "", "0");
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	enSaveResults Save()
	{

		switch (_ModStatus)
		{
		case _Mod::EnEmptyMod:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case _Mod::EnUpdateMod:
		{
			Update();
			return enSaveResults::svSucceeded;

			break;
		}

		case _Mod::EnAddMod:
		{
			//This will add new record to file or database
			if (UserSys::IsUSerExist(_UserName))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddUser();
				//We need to set the mode to update after add new
				_ModStatus = _Mod::EnUpdateMod;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}

	}
	static void PrintCard(UserSys obj) {
		cout << "------------------------------------------------\n";
		cout << "First Name       :" << obj.FirstName() << endl;
		cout << "Last Name        :" << obj.LastName() << endl;
		cout << "Phone Number     :" << obj.PhoneNumber() << endl;
		cout << "Email            :" << obj.Email() << endl;
		cout << "User Name        :" << obj.UserName() << endl;
		cout << "Password         :" << obj.PassWord() << endl;
		cout << "Permission       :" << obj.Permissions() << endl;
		cout << "------------------------------------------------\n";
	}
	/*bool CheckPermission(_PermissionAccess perm) {
		int ToNumber = stoi(this->Permission);
		if (ToNumber == -1) {
			return true;
		}
		else if ((ToNumber & perm) == perm) {
			return true;
		}
		else
		{
			return false;
		}
	}*/
	bool CheckPermission(_PermissionAccess perm) {
		int ToNumber = 0;
		try {
			ToNumber = std::stoi(this->Permission);
		}
		catch (const std::invalid_argument& e) {
			cerr << "Invalid permission value: not a number (" << this->Permission << ")\n";
			return false;  // or maybe deny access
		}
		catch (const std::out_of_range& e) {
			cerr << "Invalid permission value: out of range (" << this->Permission << ")\n";
			return false;  // or maybe deny access
		}

		if (ToNumber == -1) return true;

		return (ToNumber & perm) == perm;
	}
	void RegisterLoginUser() {
		string line = _RegisterLogin();
		fstream file;
		file.open("RegisterLogin.txt", ios::out | ios::app);
		if (file.is_open()) {
			file << line << endl;
			file.close();
		}
		else
		{
			cout << "Error , File Close.......\n";

		}
	}
	static vector<LoginHistory> _LoadLoginDataFromFile() {
		vector<LoginHistory> list;
		fstream file;
		file.open("RegisterLogin.txt", ios::in);
		if (file.is_open()) {
			string line;
			string split;
			while (getline(file, line)) {
				list.push_back(_ConvertLineToLoginObj(line));

			}
			file.close();
		}
		return list;
	}
	static LoginHistory _ConvertLineToLoginObj(string line) {
		vector<string> list = Cls_String_Library::Split(line, "/##/");
		LoginHistory obj;
		obj.Date = list[0];
		obj.Time = list[1];
		obj.UserName = list[2];
		obj.Permission = list[3];
		return obj;
	}
	static vector<LoginHistory> GetLoginHistory() {
		return _LoadLoginDataFromFile();
	}
};


