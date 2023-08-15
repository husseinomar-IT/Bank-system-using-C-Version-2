#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
class clsFindUser:protected clsScreen
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
	static void ShowFindUserScreen()
	{
		_DrawHeaderScreen("Find User Screen");
		string Username = "";
		cout << "\nPlease Enter Username: ";
		Username = clsInputValidate::ReadString();
		while (!clsUser::ISUserExist(Username))
		{
			cout << "Username  is not found,choose another one: ";
			Username = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(Username);
		if (!User.IsEmpty())
		{
			cout << "\nFound user :-)\n\n";

		
		}
		else
		{
			cout << "\nUser Was not Found :-(\n\n";
		}
		_PrintUser(User);

	}
	
};

