#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
class clsTotalBalanceScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{


		cout << setw(8) << left << "" << "| " << setw(30) << left << Client.GetAccountNumber();
		cout << "| " << setw(30) << left << Client.Fullname();
		cout << "| " << setw(30) << left << Client.AccountBalance;


	}

public:

	static void ShowTotalBalaneScreen()
		{
			vector<clsBankClient>vClicents = clsBankClient::GetClientList();
			string title = "Total Balance Screen";
			string Subtile = "(" + to_string(vClicents.size()) + ") Client(s) ";
			_DrawHeaderScreen(title, Subtile);
			
			cout << setw(8) << left << "" << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;

			cout << setw(8) << left << "" << "| " << left << setw(30) << "Accout Number";
			cout << "| " << left << setw(30) << "Client Name";
			cout << "| " << left << setw(30) << "Balance";
			cout << setw(8) << left << "" << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;
			if (vClicents.size() == 0)
				cout << "\t\t No Clients Available in the System\n";
			else
			for (clsBankClient Client : vClicents)
			{
				_PrintClient(Client);
				cout << endl;
			}
			cout << setw(8) << left << "" << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;
			double totalbalnce = clsBankClient::GetTotalBalnce();
			cout << "\t\t\t\tTotalBalance=" << totalbalnce << endl;
			cout << "\t\t\t\t( " << clsUtil::NumberToString(totalbalnce) <<")" << endl;
		}
};

