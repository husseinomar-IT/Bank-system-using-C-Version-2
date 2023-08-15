#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsUsersListScreen.h"
#include"clsAddUserScreen.h"
#include"clsDeleteUser.h"
#include"clsUpdateUser.h"
#include"clsFindUser.h"
class clsMangeUserScreen:protected clsScreen
{
private:
	enum enMangeOptions{ ListUser = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, MainMenueScreen = 6 };



	static  short _ReadMangeUserOption()
	{
		short num = 0;
		cout << setw(37) << left << "" << "Choose what do you want to do?[1 to 6]?";
		num = clsInputValidate::ReadshortNumberBetween(1, 6, "Enter number between 1 and 4 ");
		return num;
	}



	static void _ShowUsersListScreen()
	{
		clsUsersListScreen::ShowUsersListScreen();

	}



	static void _ShowAddUserScreen()
	{
		clsAddUserScreen::ShowAddUserScreen();
	}


	static void _ShowDeleteUserScreen()
	{
		clsDeleteUser::ShowDeleteUserScreen();
	}



	static void _ShowUpdateUserScreen()
	{
		clsUpdateUser::ShowUpdateUserScreen();
	}









	static void _ShowFindUserScreen()
	{
		clsFindUser::ShowFindUserScreen();
	}




	static void  _BacktoManagUsereMenue()
	{
		cout << "\n\tpress any key to  go back tho Mange Users Menue...\n";
		system("pause>0");
		ShowMangeUserScreen();
	}



	static  void _PerforimManageUserOption(enMangeOptions MangeOption)
	{
		switch (MangeOption)
		{
		case enMangeOptions::ListUser:
			system("cls");
			_ShowUsersListScreen();
			_BacktoManagUsereMenue();

			break;
		case enMangeOptions::AddUser:

			system("cls");
			_ShowAddUserScreen();
			_BacktoManagUsereMenue();
			break;

		case enMangeOptions::DeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_BacktoManagUsereMenue();
			break;

		case enMangeOptions::UpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_BacktoManagUsereMenue();
			break;

		case enMangeOptions::FindUser:
			system("cls");
			_ShowFindUserScreen();
			_BacktoManagUsereMenue();
			break;

		case enMangeOptions::MainMenueScreen:

			break;
		}

	}
public:

	static void ShowMangeUserScreen()
	{
		system("cls");
		if (!CheckAccessRight(clsUser::enUserPerimission::eManageUser))
		{
			return;
		}
		_DrawHeaderScreen("Manage User Menue Screen");
		cout<<setw(37)<<left<<""<< "=====================================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Munue Screen           \n";
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t\t[6] Main Menue.\n";

		cout << setw(37) << left << "" << "=====================================================\n";
		_PerforimManageUserOption((enMangeOptions)_ReadMangeUserOption());

	}
};

