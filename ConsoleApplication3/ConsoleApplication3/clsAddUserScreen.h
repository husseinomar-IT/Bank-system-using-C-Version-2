#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
class clsAddUserScreen:protected clsScreen
{


private:

	static void _ReadUserInfo(clsUser &User)
	{


		cout << "\n_________________________________\n";
		cout << "\nFirstname      : ";
		User.Firstname = clsInputValidate::ReadString();
		cout << "\nLastname       : ";
		User.Lastname = clsInputValidate::ReadString();
		cout << "\nEmail          : ";
		User.email = clsInputValidate::ReadString();
		cout << "\nPhone          : ";
		User.Phoen = clsInputValidate::ReadString();
		cout << "\nPassword       : ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nPermission     : ";
		User.Perimission = _ReadPerimission();
		cout << "_________________________________\n";




	}


	static int _ReadPerimission()
	{

		int perimission = 0;
		char Answer = 'n';
		cout << "Do you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			return -1;
		}

		cout << "\n Do you want to give access to : \n";

		cout << "\n show Client List? y/n:? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			perimission += clsUser::eShoeListClient;
		}


		cout << "\n Add new Client? y/n:? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			perimission += clsUser::eAddNewClient;
		}


		cout << "\n Delete Client? y/n:? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			perimission += clsUser::eDeleteClient;
		}




		cout << "\n Update Client? y/n:? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			perimission += clsUser::eUpdateClient;
		}




		cout << "\n Find Client? y/n:? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			perimission += clsUser::eFindClient;
		}



		cout << "\n Transactions? y/n:? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			perimission += clsUser::eTransaction;
		}

		cout << "\n Manage Users? y/n:? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			perimission += clsUser::eManageUser;
		}


		cout << "\n LoginRegister Screen? y/n:? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			perimission += clsUser::eShowLoginRegister;
		}






		cout << "\n Currency Exchange Screen? y/n:? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			perimission += clsUser::eCurrencyEXchang;
		}


		return perimission;






	}


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

	void static ShowAddUserScreen()
	{
		_DrawHeaderScreen("Add User Screen");
		string username = "";
		cout << "\nPlease Enter Username: ";
		username = clsInputValidate::ReadString();

		while (clsUser::ISUserExist(username))
		{
			cout << "Username is Exsit ,choose another one:\n";
			username = clsInputValidate::ReadString();
		}


		clsUser NewUser = clsUser::GetNewUsers(username);

		_ReadUserInfo(NewUser);
		clsUser::enSaveResult SaveResult;
		SaveResult = NewUser.Save();
		switch (SaveResult)
		{
		case clsUser::svFalidEmptyObject:
			cout << "\nError User was not saved because it's Empty :-(\n";
			break;
		case clsUser::svSucceeded:
			cout << "\nUser Added Successfuly :-)\n";

			_PrintUser(NewUser);
			break;
		case clsUser::svFalidAccountExist:
			cout << "\nError User was not saved because  Username  is Exist  :-(\n";
			break;
		}
	}
};

