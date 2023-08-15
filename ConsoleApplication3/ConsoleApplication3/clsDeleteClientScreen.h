#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsDeleteClientScreen:protected clsScreen
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

	static void ShowDeleteClientScreen()
		{

		if (!CheckAccessRight(clsUser::enUserPerimission::eDeleteClient))
		{
			return;
		}

		_DrawHeaderScreen("Delete Cleint Screen");
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
			cout << "\n Do you Want to Delete this Client?? y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				if (Client.Delete())
				{
					cout << "\n Client Deleted  Successfuly :-)\n"; 
					_PrintClient(Client);
				}
				else
				{
					cout << "Error Client was not Deleted\n";
				}
				
			}
			
		}
};

