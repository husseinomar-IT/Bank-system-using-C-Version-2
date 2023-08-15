#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsMangeUserScreen.h"
#include"clsLoginRegister.h"
#include"clsCurrencyExchangeMainScreen.h"

#include"Global.h"
using namespace std;

class clsMainScreen:protected clsScreen
{
private:
	enum _enChooseWhatYouWan{ Show = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Transaction = 6, ManageUser = 7, LoginRegister = 8,CurrencyExchange=9,Logout=10 };
	static short _ReadMainMenueOption()
	{
	
		cout << setw(37) << left << ""<< "Choose what do you want to do ?[1 to 10]?";
		short choice = clsInputValidate::ReadshortNumberBetween(1, 10, "Enter number between 1 and 10 \n");
		return choice;
	}

	

	static void _BacktoMainMenueScreen()
	{
		cout << setw(8) << left << "\n" << "press any key to  go back to  Main Menue...\n";
		system("pause>0");
		ShowMainMenuScreen();

	}

		
	
	static 	void _ShowClientListScreen()
	{
	
		clsClientListScreen::ShowClientListScreen();
	
	}

	static 	void _ShowAddClientScreen()
	{

		clsAddClientScreen::ShowAddNewClientScreen();

	}



	static 	void _ShowDeletelientScreen()
	{

		clsDeleteClientScreen::ShowDeleteClientScreen();

	}

	static 	void _ShowUpdatelientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static 	void _ShowFindClientScreen()
	{

		clsFindClientScreen::FindClientScreen();

	}


	static 	void _ShowTranactionScreen()
	{

		clsTransactionScreen::ShowTransactionScreen();

	}



	static 	void _ShowMangeUserScreen()
	{
		clsMangeUserScreen::ShowMangeUserScreen();
	}




	static 	void _ShowLogoutScreen()
	{

		CurrentUser = clsUser::Find("", "");
	}


	static void _ShowLoginRegister()
	{
		clsLoginRegister::ShowLoginRegisterListScreen();
	}



	static void _showCurrencyExchangeMenue()
	{
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
	}

	static void _PerforimMainMenueOption(_enChooseWhatYouWan choice)
	{
	
	
		switch (choice)
		{
		case _enChooseWhatYouWan::Show:
			system("cls");
			_ShowClientListScreen();
			_BacktoMainMenueScreen();
			break;
		case _enChooseWhatYouWan::Add:
			system("cls");
			_ShowAddClientScreen();
			_BacktoMainMenueScreen();
			break;
		case _enChooseWhatYouWan::Delete:
			system("cls");
			_ShowDeletelientScreen();
			_BacktoMainMenueScreen();
			break;
		case _enChooseWhatYouWan::Update:
			system("cls");
			_ShowUpdatelientScreen();
			_BacktoMainMenueScreen();
			break;
		case _enChooseWhatYouWan::Find:
			system("cls");
			_ShowFindClientScreen();
			_BacktoMainMenueScreen();
			break;
		case _enChooseWhatYouWan::Transaction:
			system("cls");
			_ShowTranactionScreen();
			_BacktoMainMenueScreen();
			break;
		case _enChooseWhatYouWan::ManageUser:
			system("cls");
			_ShowMangeUserScreen();
			_BacktoMainMenueScreen();
			break;
		case _enChooseWhatYouWan::LoginRegister:
			system("cls");
			_ShowLoginRegister();
			_BacktoMainMenueScreen();
			break;
		case _enChooseWhatYouWan::CurrencyExchange:
			system("cls");
			_showCurrencyExchangeMenue();
			_BacktoMainMenueScreen();
			break;



		case _enChooseWhatYouWan::Logout:
			system("cls");
			_ShowLogoutScreen();
			break;
		}
	
	}



public:
	
	static void ShowMainMenuScreen()
	{
		system("cls");
		_DrawHeaderScreen("Main Menue Screen","");
		cout << "\n\n";
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Munue Screen           \n";
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t\t[10] Exit.\n";
		cout << setw(37) << left << "" << "=====================================================\n";
		_PerforimMainMenueOption((_enChooseWhatYouWan)_ReadMainMenueOption());

	}
	
	
};

