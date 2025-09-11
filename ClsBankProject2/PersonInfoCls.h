#pragma once
#include <iostream>
#include<string>
using namespace std;
class PersonInfoCls
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _PhoneNumber;
public:
	PersonInfoCls(string name, string lastName, string Email, string PhoneNumber) {
		_FirstName = name;
		_LastName = lastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
	}
	// setter
	void SetFirstName(string name) { _FirstName = name; }
	void SetLastName(string lastName) { _LastName = lastName; }
	void SetEmail(string Email) { _Email = Email; }
	void SetPhoneNumber(long phone) {
		string new_str = to_string(phone);
		_PhoneNumber = new_str;
	}
	void SetPhoneNumber(string PhoneNumber) { _PhoneNumber = PhoneNumber; }
	//getter
	string PhoneNumber() { return _PhoneNumber; }
	string FirstName() { return _FirstName; }
	string LastName() { return _LastName; }
	string Email() { return _Email; }
	__declspec(property(get = PhoneNumber, put = SetPhoneNumber)) string Phone;
	__declspec(property(get = FirstName, put = SetFirstName)) string Name;
	__declspec(property(get = LastName, put = SetLastName)) string Last_Name;
	__declspec(property(get = Email, put = SetEmail)) string email;

};

