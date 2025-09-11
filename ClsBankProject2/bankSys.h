#pragma once
#include <iostream>
#include<string>
#include "PersonInfoCls.h"
#include<vector>
#include<fstream>
#include"Cls_String_Library.h"
#include"MyUtility.h"
#include"clsDate.h"
#include"GlobalObj.h"
using namespace std;
class bankSys : public PersonInfoCls
{
private:
	string _PinCode;
	string _AccountNumber;
	string _balance;
	bool _MarkedForDelete = false;
	enum AccountMod { EmptyMod = 0, UpdateMod = 1, AddNew = 2 };
	AccountMod _accountMod;
	string  _filename  = "bankSys.txt";
	//string _TransferFilename = "Transfer.txt";

	static bankSys _convertLineToObj(string line) {
		vector<string> data = Cls_String_Library::Split(line, "/##/");
		return bankSys(AccountMod::UpdateMod, data[0], data[1], data[2], data[3], data[4], data[5], data[6]);
	}
	static bankSys _EmptyConvertLineToObj() {
		return bankSys(AccountMod::EmptyMod, "", "", "", "", "", "", "0");
	}
	static string _ConvertObjToLine(bankSys obj) {
		string line = obj.Name + "/##/" + obj.Last_Name + "/##/" + obj.email + "/##/" + obj.Phone + "/##/" + obj._AccountNumber + "/##/" + obj._PinCode + "/##/" + obj._balance;
		return line;
	}
	static vector<bankSys> _LoadDataFromFile() {
		vector<bankSys> list;
		fstream file;
		file.open("bankSys.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				bankSys obj = _convertLineToObj(line);
				list.push_back(obj);
			}
			file.close();
		}
		return list;
	}
	static void _SaveDataToFile(vector<bankSys> list) {
		fstream file;
		file.open("bankSys.txt", ios::out); // this overwriten ::out it truncate the all file content and then add a new ones
		if (file.is_open()) {
			for (bankSys obj : list) {
				if (obj._MarkedForDelete) {
					continue;
				}
				string line = _ConvertObjToLine(obj);
				file << line << endl;
			}
			file.close();
		}
	}
	void _Update() {
		vector<bankSys> list = _LoadDataFromFile();
		for (bankSys& obj : list) {
			if (obj.AccountNumber() == AccountNumber()) {
				obj = *this;
				break;
			}
		}
		_SaveDataToFile(list);
	}
	// Add this public assignment operator to the bankSys class if needed
	////bankSys& operator=(const bankSys& other) {
	////	if (this != &other) {
	////		// Assign base class part
	////		PersonInfoCls::operator=(other);
	////		// Assign bankSys members
	////		_PinCode = other._PinCode;
	////		_AccountNumber = other._AccountNumber;
	////		_balance = other._balance;
	////		_accountMod = other._accountMod;
	////		// _filename is const, no need to assign
	////	}
	////	return *this;
	////}
	static void _AddDateLineToFile(string line) {
		fstream file;
		file.open("bankSys.txt", ios::app);
		if (file.is_open()) {
			file << line << endl;
			file.close();
		}
	}
	void _AddClient() {
		string line = _ConvertObjToLine(*this);
		_AddDateLineToFile(line);
	}

	//void _SaveDataToFile(vector<bankSys> list) {
	//	fstream file;
	//	file.open("bankSys.txt", ios::out); // this overwriten ::out it truncate the all file content and then add a new ones
	//	if (file.is_open()) {
	//		for (bankSys obj : list) {
	//			if (!obj._MarkedForDelete) {
	//				string line = _ConvertObjToLine(obj);
	//				file << line << endl;
	//			}
	//		}
	//		file.close();}}
	
	static void _AddTransInfo(string line) {
		fstream file;
		file.open("Transfer.txt", ios::out| ios::app);
		if (file.is_open()) {
			file << line << endl;
			file.close();
		}
	}
	string ConvertToLineTransfer(int amount, bankSys Destobj, string username) {
		string line = clsDate::SystemDate() + "/##/" + clsDate::CurrentTime() + "/##/" + AccountNumber() + "/##/" + Destobj.AccountNumber() + "/##/" + to_string(amount) + "/##/" + Balance() + "/##/" + Destobj.Balance() + "/##/" + username;
		return line;

	}
	void _AddTransferToFile(int amount, bankSys Destobj, string username) {
		string line = ConvertToLineTransfer(amount, Destobj, username);
		_AddTransInfo(line);
	}
	


public:
	static struct _TransferInfo {
		string Date;
		string Time;
		string SenderAccNumber;
		string DestAccNumber;
		string Amount;
		string SenderBalance;
		string DesBalance;
		string UserName;
	};
	bankSys(AccountMod mod, string name, string lastname, string email, string phonenumber, string accountnumber, string pincode, string balance)
		:PersonInfoCls(name, lastname, email, phonenumber) {
		_accountMod = mod;
		_AccountNumber = accountnumber;
		_PinCode = pincode;
		_balance = balance;
	}
	// setter
	void SetPinCode(string pincode) { _PinCode = pincode; }
	void SetBalance(string balance) { _balance = balance; }
	void SetBalance(double balance) {
		string new_str = to_string(balance);
		_balance = new_str;
	}
	// getter
	string PinCode() { return _PinCode; }
	string AccountNumber() { return _AccountNumber; }
	string Balance() { return _balance; }
	bool MarkedForDelete() { return _MarkedForDelete; }
	__declspec(property(get = PinCode, put = SetPinCode)) string Pincode;
	__declspec(property(get = AccountNumber)) string AccountNumber_;
	__declspec(property(get = Balance, put = SetBalance)) string balance;
	// open file and add data
	void AddDataToFile() {
		fstream file;
		file.open(_filename, ios::app);
		if (file.is_open()) {
			file << Name + "/##/" + Last_Name + "/##/" + email + "/##/" + Phone + "/##/" + _AccountNumber + "/##/" + _PinCode + "/##/" + _balance << endl;
			file.close();
		}
		else {
			cout << "Error opening file" << endl;
		}
	}
	static bankSys Find(string accountnumber) {
		fstream file;
		file.open("bankSys.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				bankSys obj = _convertLineToObj(line);
				if (obj._AccountNumber == accountnumber) {
					file.close();
					return obj;
				}

			}
			file.close();
		}
		return _EmptyConvertLineToObj();

	}
	static bankSys Find(string accountnumber, string pincode) {
		fstream file;
		file.open("bankSys.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				bankSys obj = _convertLineToObj(line);
				if (obj._AccountNumber == accountnumber && obj._PinCode == pincode) {
					file.close();
					return obj;
				}
			}
			file.close();
		}
		return _EmptyConvertLineToObj();
	}
	bool IsEmpty() {
		return (_accountMod == AccountMod::EmptyMod);
	}
	static bool IsClientExist(string accountnumber) {
		return !Find(accountnumber).IsEmpty();
	}
	static bankSys AddNewClient(string AccountNumber) {
		return bankSys(AccountMod::AddNew, "", "", "", "", AccountNumber, "", "0");
	}
	bool Delete() {
		vector<bankSys> list = _LoadDataFromFile();
		for (bankSys& obj : list) {
			if (obj.AccountNumber() == _AccountNumber) {
				obj._MarkedForDelete = true;
				break;
			}
		}
		_SaveDataToFile(list);
		*this = _EmptyConvertLineToObj();
		return true;

	}

	void print() {
		cout << "Client Information:" << endl;
		cout << "------------------" << endl;
		cout << "Name: " << Name << endl;
		cout << "Last Name: " << Last_Name << endl;
		cout << "Email: " << email << endl;
		cout << "Phone Number: " << Phone << endl;
		cout << "Account Number: " << _AccountNumber << endl;
		cout << "Pin Code: " << _PinCode << endl;
		cout << "Balance: " << _balance << endl;
		cout << "------------------" << endl;
	}
	static void _PrintCard(bankSys obj) {
		cout << "Client Information:" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Name          : " << obj.Name << endl;
		cout << "Last Name     : " << obj.Last_Name << endl;
		cout << "Full Name     : " << obj.Name + " " + obj.Last_Name << endl;
		cout << "Email         : " << obj.email << endl;
		cout << "Phone Number  : " << obj.Phone << endl;
		cout << "Account Number: " << obj.AccountNumber() << endl;
		cout << "Pin Code      : " << obj.PinCode() << endl;
		cout << "Balance       : " << obj.balance << endl;
		cout << "-----------------------------------------------" << endl;
	}
	static vector<bankSys> getAllClients() {
		return _LoadDataFromFile();
	}
	static double GetTotalBalance() {
		vector<bankSys> list = _LoadDataFromFile();
		double total = 0.0;
		for (bankSys obj : list) {
			total += stod(obj.Balance());
		}
		return total;
	}
	enum EnSaveResult {
		SaveFailed = 0, SaveOk = 1, ClientAlreadyExists = 2
	};
	EnSaveResult save() {
		switch (_accountMod)
		{
		case AccountMod::EmptyMod:
			if (IsEmpty()) {
				return EnSaveResult::SaveFailed;
			}
		case AccountMod::UpdateMod:
			_Update();
			return EnSaveResult::SaveOk;
			break;
		case AccountMod::AddNew:
			if (IsClientExist(_AccountNumber)) {
				return EnSaveResult::ClientAlreadyExists;
			}
			else {
				_AddClient();
				_accountMod = AccountMod::UpdateMod;
				return EnSaveResult::SaveOk;
			}
			break;

		default:
			break;
		}
	}
	int ConvertToInt(string num) {
		return stoi(num);
	}
	void Deposit(int number) {
		int account = ConvertToInt(Balance());
		number += account;
		string newstr = to_string(number);
		_balance = newstr;
		save();
	}
	bool Withdraw(int number) {
		int account = ConvertToInt(Balance());
		if (account >= number) {
			account -= number;
			string newstr = to_string(account);
			_balance = newstr;
			save();
			return true;

		}
		return false;

	}
	
	bool Transfer(int amount , bankSys& DestObj) {
		int account = ConvertToInt(Balance());
		if (account >= amount) {
			Withdraw(amount);
			DestObj.Deposit(amount);
			_AddTransferToFile(amount, DestObj, CurrentObj.UserName());
			return true;
		}
		return false;
	}
	static _TransferInfo _ConvertLineToTransferObj(string line) {
		vector<string> data = Cls_String_Library::Split(line, "/##/");
		_TransferInfo obj;
		obj.Date = data[0];
		obj.Time = data[1];
		obj.SenderAccNumber = data[2];
		obj.DestAccNumber = data[3];
		obj.Amount = data[4];
		obj.SenderBalance = data[5];
		obj.DesBalance = data[6];
		obj.UserName = data[7];
		return obj;
	}
	static vector<_TransferInfo> _LoadTransferDataFromFile() {
		vector<_TransferInfo> list;
		fstream file;
		file.open("Transfer.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				list.push_back(_ConvertLineToTransferObj(line));
			}
			file.close();
		}
		return list;
	}
	
};
