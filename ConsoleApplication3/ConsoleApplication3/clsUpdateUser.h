#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
class clsUpdateUser:protected clsScreen
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

	static void ShowUpdateUserScreen()
	{
		_DrawHeaderScreen("Update User Screen");
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
		cout << "\n Do you Want to Update this User?? y/n ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			cout << "\n\nUpdate User Info:\n";
			cout << "_________________________________\n";


			_ReadUserInfo(User);
			clsUser::enSaveResult SaveResult;
			SaveResult = User.Save();
			switch (SaveResult)
			{
			case clsUser::svFalidEmptyObject:
				cout << "\nError user was not saved because it's Empty :-(\n";
				break;
			case clsUser::svSucceeded:
				cout << "\nuser Update Successfuly :-)\n";
				_PrintUser(User);
				break;

			}
		}

	}
};

