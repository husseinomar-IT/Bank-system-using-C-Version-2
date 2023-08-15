#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
class clsTransferLogScreen :protected clsScreen
{
private:
	static void _PrintTransferLogRegister(clsBankClient::stTransferLogRecord Transfer)
	{


		cout << setw(8) << left << "" << "| " << setw(25) << left << Transfer.DateTime;
		cout << "| " << setw(10) << left << Transfer.SouAccountNumber;
		cout << "| " << setw(10) << left << Transfer.DesAccountNumber;
		cout << "| " << setw(10) << left << Transfer.Amount;
		cout << "| " << setw(10) << left << Transfer.SouBalance;
		cout << "| " << setw(10) << left << Transfer.DesBalance;
		cout << "| " << setw(10) << left << Transfer.User;



	}
public:

	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord>vTransfer = clsBankClient::GetTransferRegisterList();
		string title = "Transfer Log List Screen";
		string Subtile = "(" + to_string(vTransfer.size()) + ") Client(s) ";

		_DrawHeaderScreen(title, Subtile);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;



		if (vTransfer.size() == 0)
			cout << "\t\t No Transfer Available in the System\n";
		else

		for (clsBankClient::stTransferLogRecord &T : vTransfer)
		{
			_PrintTransferLogRegister(T);
			cout << endl;
		}
		cout << setw(20) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

