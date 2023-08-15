#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsUpdateClientScreen:protected clsScreen
{
private:
	static void _ReadCleintInfo(clsBankClient &Client)
	{


		cout << "\n_________________________________\n";
		cout << "\nFirstname     : ";
		Client.Firstname = clsInputValidate::ReadString();
		cout << "\nLastname      : ";
		Client.Lastname = clsInputValidate::ReadString();
		cout << "\nEmail         : ";
		Client.email = clsInputValidate::ReadString();
		cout << "\nPhone         : ";
		Client.Phoen = clsInputValidate::ReadString();
		cout << "\nPinCode       : ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nAccountBalance: ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
		cout << "_________________________________\n";




	}

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

	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRight(clsUser::enUserPerimission::eUpdateClient))
		{
			return;
		}
		_DrawHeaderScreen("Update Client Screen");
		string AccountNumber = "";
		char answer = 'n';
		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::ISClientExist(AccountNumber))
		{
			cout << "Account number is not found,choose another one:\n";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		cout << "\n Do you Want to Update this Client?? y/n ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			cout << "\n\nUpdate Client Info:\n";
			cout << "_________________________________\n";


			_ReadCleintInfo(Client);
			clsBankClient::enSaveResult Result;
			Result = Client.Save();
			switch (Result)
			{
			case clsBankClient::svFalidEmptyObject:
				cout << "\nError account was not saved because it's Empty :-(\n";
				break;
			case clsBankClient::svSucceeded:
				cout << "\nAccount Update Successfuly :-)\n";
				_PrintClient(Client);
				break;

			}
		}
		
	}
	
};

