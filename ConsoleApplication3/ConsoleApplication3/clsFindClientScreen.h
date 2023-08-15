#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsFindClientScreen:protected clsScreen
{

private:

	static 	void _PrintClient(clsBankClient Client)
	{
		cout << "client Card\n";
		cout << "__________________________________\n";
		cout << "\nFiratName      : " << Client.Firstname;
		cout << "\nLastName       : " << Client.Lastname;
		cout << "\nFullName       : " << Client.Fullname();
		cout << "\nEmail          : " << Client.email;
		cout << "\nPhone          : " << Client.Phoen;
		cout << "\nAccountNumber  : " << Client.GetAccountNumber();
		cout << "\nPinCode        : " << Client.PinCode;
		cout << "\nAccountBalance : " << Client.AccountBalance << endl;
		cout << "__________________________________\n";
	}

public:


	static void FindClientScreen()


	{


		if (!CheckAccessRight(clsUser::enUserPerimission::eFindClient))
		{
			return;
		}
		_DrawHeaderScreen("Find Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::ISClientExist(AccountNumber))
		{
			cout << "Account number is not found,choose another one:\n";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (!Client.IsEmpty())
		{
			cout << "\nFound Client :-)\n\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n\n";
		}
	
		_PrintClient(Client);
	}

};

