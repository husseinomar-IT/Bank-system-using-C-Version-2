#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
class clsLoginRegister:protected clsScreen
{


	static void _PrintLoginRegister(clsUser::stLoginRegisterRecord Login)
	{


		cout << setw(8) << left << "" << "| " << setw(32) << left << Login.DateTime;
		cout << "| " << setw(20) << left << Login.Username;
		cout << "| " << setw(20) << left << Login.Password;
		cout << "| " << setw(20) << left << Login.Perimission;


	}








private:

public:
	static void ShowLoginRegisterListScreen()

	{

		if (!CheckAccessRight(clsUser::eShowLoginRegister))
		{
			return;
		}
		vector<clsUser::stLoginRegisterRecord>vLogin = clsUser::GetLoginRegisterList();
		string title = "Login Register List Screen";
		string Subtile = "(" + to_string(vLogin.size()) + ") Client(s) ";

		_DrawHeaderScreen(title, Subtile);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(32) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(20) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;



		if (vLogin.size() == 0)
			cout << "\t\t No Clients Available in the System\n";
		else
			
		for (clsUser::stLoginRegisterRecord &R : vLogin)
		{
			_PrintLoginRegister(R);
			cout << endl;
		}
		cout << setw(20) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

