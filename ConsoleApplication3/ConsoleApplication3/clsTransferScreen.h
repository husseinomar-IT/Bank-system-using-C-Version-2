#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsTransferScreen:protected clsScreen
{
	static string _ReadAccountNumber()

	{
		string	AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::ISClientExist(AccountNumber))
		{
			cout << "\n\nAccount number is not found,choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		
		 return AccountNumber;
	}



	static 	void _PrintClient(clsBankClient Client)
	{
		cout << "\n\nclient Card\n";
		cout << "__________________________________\n";
		cout << "\nFiratName       : " << Client.Firstname;
		cout << "\nAcc.Number      : " << Client.GetAccountNumber();
		cout << "\nBalance         : " << Client.AccountBalance << endl;
		cout << "__________________________________\n";
	}



	static double _ReadAmount(clsBankClient SourceClient)
	{
		double amount;
		cout << "\n\nEnter Transfer amount? ";
		amount = clsInputValidate::ReadDblNumber();
		while (amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds available,Enter another Amount ? ";
			amount = clsInputValidate::ReadDblNumber();
		}
	
		return amount;
	}





public:
	static void ShowTransferScreen()
	{


		_DrawHeaderScreen("Transfer Screen");
		cout << "\nPlease Enter Account Number to Transfer from : ";

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

			_PrintClient(SourceClient);
		
		cout << "\nPlease Enter Account Number to Transfer to : ";
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		
		
		_PrintClient(DestinationClient);
		

		double amount = _ReadAmount(SourceClient);

		

		char answer = 'n';
		cout << "\nAre you sure you want to perform this transaction? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{ 
			if (SourceClient.Transfer(amount, DestinationClient,CurrentUser.Username))
			{
				cout << "\nTransfer done successfully\n";
				
			}

			else
			{
				cout << "\n Falid Transfer \n";

			}
			_PrintClient(SourceClient);
			_PrintClient(DestinationClient);
			
		

			
		}

	}
	
};

