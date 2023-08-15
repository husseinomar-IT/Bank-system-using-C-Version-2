#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
class clsDeleteUser:protected clsScreen
{


private:

	static 	void _PrintUser(clsUser User)
	{
		cout << "client Card\n";
		cout << "__________________________________\n";
		cout << "\nFiratName      : " << User.Firstname;
		cout << "\nLastName       : " << User.Lastname;
		cout << "\nFullName       : " << User.Fullname();
		cout << "\nEmail          : " << User.email;
		cout << "\nPhone          : " << User.Phoen;
		cout << "\nUsername       : " << User.Username;
		cout << "\nPassword       : " << User.Password;
		cout << "\nPermission     : " << User.Perimission << endl;
		cout << "__________________________________\n";
	}

public:
	static void ShowDeleteUserScreen()
	{
		_DrawHeaderScreen("Delete User Screen");
		string username = "";
		char answer = 'n';
		cout << "\nPlease Enter Username: ";
		username = clsInputValidate::ReadString();
		while (!clsUser::ISUserExist(username))
		{
			cout << "Username is not found,choose another one: ";
			username = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(username);
		_PrintUser(User);
		cout << "\n Do you Want to Delete this user?? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (User.Delete())
			{
				cout << "\n User Deleted  Successfuly :-)\n";
				_PrintUser(User);
			}
			else
			{
				cout << "Error User was not Deleted\n";
			}

		}
	}
	
};

