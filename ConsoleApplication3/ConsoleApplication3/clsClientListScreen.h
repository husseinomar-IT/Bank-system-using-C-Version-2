#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"

class clsClientListScreen:protected clsScreen
{


private:
	static void _PrintClient(clsBankClient Client)
	{
		

		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(20) << left << Client.Fullname();
		cout << "| " << setw(12) << left << Client.Phoen;
		cout << "| " << setw(20) << left << Client.email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;


	}
public:
	static void ShowClientListScreen()

	{

		if (!CheckAccessRight(clsUser::enUserPerimission::eShoeListClient))
		{
			return;
		}

		vector<clsBankClient>vClicents = clsBankClient::GetClientList();
		string title = "Client List Screen";
		string Subtile = "(" + to_string(vClicents.size()) + ") Client(s) ";
		_DrawHeaderScreen(title, Subtile);
	                           
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
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
		cout << setw(20) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

