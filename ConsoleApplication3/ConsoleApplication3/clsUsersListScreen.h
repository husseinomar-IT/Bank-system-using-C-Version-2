#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
class clsUsersListScreen:protected clsScreen
{


private:
	static void _PrintClient(clsUser User)
	{


		cout << setw(8) << left << "" << "| " << setw(8) << left << User.Username;
		cout << "| " << setw(22) << left << User.Fullname();
		cout << "| " << setw(12) << left << User.Phoen;
		cout << "| " << setw(20) << left << User.email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Perimission;


	}


public:


	static void ShowUsersListScreen()
	{
		vector<clsUser>vUsers = clsUser::GetUserList();
		string title = "User List Screen";
		string Subtile = "(" + to_string(vUsers.size()) + ") Client(s) ";

		_DrawHeaderScreen(title, Subtile);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(8) << "Username";
		cout << "| " << left << setw(22) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;



		if (vUsers.size() == 0)
			cout << "\t\t No Clients Available in the System\n";
		else
		for (clsUser &U : vUsers)
		{
			_PrintClient(U);
			cout << endl;
		}
		cout << setw(20) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
	
};

