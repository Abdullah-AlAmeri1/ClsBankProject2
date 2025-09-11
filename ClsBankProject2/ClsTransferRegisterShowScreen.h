#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"bankSys.h"
#include<iomanip>
using namespace std;
class ClsTransferRegisterShowScreen : protected ClsHeaderScreen
{
private:
	static void _PrintHeader()
	{
		std::cout << "\t\t|=====================================================================================================\|\n";
		std::cout << "\t\t|" << left << setw(10) << "Date" << "|" << left << setw(7) << "Time" << "|" << left << setw(10) 
			<< "S.A.Number" << "|" << left << setw(10) << "D.A.Number" << "|" << left << setw(10) << "Amount" << "|" 
			<< left << setw(10) << "S.Balance" << "|" << left << setw(10) << "D.Balance" << "|" << left << setw(10) << "UserName" << "                 |\n";
		std::cout << "\t\t|=====================================================================================================\|\n";
	}
	static void Trans() {
		vector<bankSys::_TransferInfo> list = bankSys::_LoadTransferDataFromFile();
		_PrintHeader();
		for(bankSys::_TransferInfo obj : list) {
			std::cout << "\t\t|" << left << setw(10) << obj.Date << "|" << left << setw(7) << obj.Time << "|" << left << setw(10)
				<< obj.SenderAccNumber << "|" << left << setw(10) << obj.DestAccNumber << "|" << left << setw(10) << obj.Amount << "|" 
				<< left << setw(10) << obj.SenderBalance << "|" << left << setw(10) << obj.DesBalance << "|" << left << setw(10) << obj.UserName << "\n";
		}
		std::cout << "\t\t|=====================================================================================================\|\n";
	}
		
public:
	static void ShowTransferRegisterScreen() {
		int number = bankSys::_LoadTransferDataFromFile().size();
		string title = "Transfer Register Screen";
		string subtitle = "Transfer " + to_string(number) + " Times";
		_HeaderScreen(title, subtitle);
		Trans();
	}

};

