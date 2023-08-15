#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsWithdrawScreen :protected clsScreen
{

private:


	static 	void _PrintClient(clsBankClient Client)
	{
		cout << "\n\nclient Card\n";
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
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number: ";
		cin >> AccountNumber;
		return AccountNumber;
	}
public:

	static void ShowWithdrawScreen()
	{
		_DrawHeaderScreen("Withdraw Screen");
		string	AccountNumber = "";

		AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::ISClientExist(AccountNumber))
		{
			cout << "Client with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);
		double amount = 0;
		cout << "\nPlease enter Withdraw amount? ";
		amount = clsInputValidate::ReadDblNumber();

		char answer = 'n';
		cout << "\nAre you sure you want to perform this transaction? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			if (Client.Withdraw(amount))
			{
				cout << "\nAmount withdraw Successfuly";
				cout << "\nNew Balance is: " << Client.AccountBalance << endl;
			}
			else
			{
				cout << "\nCan not withdraw,Insuffecient Balance!\n";
				cout << "\nAmount to withdraw is:" << amount;
				cout << "\nYour Balance is: " << Client.AccountBalance << endl;
			}
		}


	}


};

