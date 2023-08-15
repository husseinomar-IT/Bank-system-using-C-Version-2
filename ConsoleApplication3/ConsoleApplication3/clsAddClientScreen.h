#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsAddClientScreen :protected clsScreen

{

private:
	static void _ReadCleintInfo(clsBankClient &Client)
		{
		
		
			cout << "\n_________________________________\n";
			cout << "\nFirstname     : ";
			Client.Firstname = clsInputValidate::ReadString();
			cout << "\nLastname      : " ;
			Client.Lastname=clsInputValidate::ReadString();
			cout << "\nEmail         : " ; 
			Client.email=clsInputValidate::ReadString();
			cout << "\nPhone         : " ; 
			Client.Phoen=clsInputValidate::ReadString();
			cout << "\nPinCode       : " ; 
			Client.PinCode=	clsInputValidate::ReadString();
			cout << "\nAccountBalance: ";
			Client.AccountBalance = clsInputValidate::ReadDblNumber();
			cout << "_________________________________\n";
		
		
			
		
		}

static 	void _PrintClient(clsBankClient Client)
	{
		cout << "client Card\n";
		cout << "__________________________________\n";
		cout << "\nFiratName      : " << Client.Firstname;
		cout << "\nLastName       : " <<Client.Lastname;
		cout << "\nFullName       : " << Client.Fullname();
		cout << "\nEmail          : " << Client.email;
		cout << "\nPhone          : " << Client.Phoen;
		cout << "\nAccountNumber  : " << Client.GetAccountNumber();
		cout << "\nPinCode        : " << Client.PinCode;
		cout << "\nAccountBalance : " << Client.AccountBalance << endl;
		cout << "__________________________________\n";
	}


public:

	static void   ShowAddNewClientScreen()
	{
		if (!CheckAccessRight(clsUser::enUserPerimission::eAddNewClient))
		{
			return;
		}

		_DrawHeaderScreen("Add Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::ISClientExist(AccountNumber))
		{
			cout << "Account number is Exsit ,choose another one:\n";
			AccountNumber = clsInputValidate::ReadString();
		}


		clsBankClient NewClient = clsBankClient::GetNewClient(AccountNumber);

		_ReadCleintInfo(NewClient);
		clsBankClient::enSaveResult Result;
		Result = NewClient.Save();
		switch (Result)
		{
		case clsBankClient::svFalidEmptyObject:
			cout << "\nError account was not saved because it's Empty :-(\n";
			break;
		case clsBankClient::svSucceeded:
			cout << "\nAccount Added Successfuly :-)\n";

			_PrintClient(NewClient);


			break;
		case clsBankClient::svFalidAccountExist:
			cout << "\nError account was not saved because  Accout Number is Exist  :-(\n";
			break;
		default:
			break;
		}

	}

};

