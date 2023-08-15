#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include<iomanip>
#include"clsTransferLogScreen.h"

class clsTransactionScreen:protected clsScreen
{
private:
	enum enTransactionMenueScreeen{ Deposit = 1, Withdraw = 2, TotalBlances = 3, Transfer=4,TransferLog=5, MainMenue = 6 };

	static short _ReadTransActionOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ?[1 to 6]?";
		short choice = clsInputValidate::ReadshortNumberBetween(1, 6, "Enter number between 1 and 4 ");
		return choice;
	}



	static void _ShowDepositeScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}



	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();

	}

	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalanceScreen::ShowTotalBalaneScreen();

	}

	   
	
	 
	static void _GoBackToTransactionScreen()
	{
		 cout<< "\n\tpress any key to  go back tho Transaction Menue...\n";
		system("pause>0");
		ShowTransactionScreen();
	}




	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}




	static void _ShowTransFerLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerforimTransactionOption(enTransactionMenueScreeen  Options)
	{
		switch (Options)
		{
		case enTransactionMenueScreeen::Deposit:
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTransactionScreen();
			break;
		case enTransactionMenueScreeen::Withdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionScreen();
			break;
			case enTransactionMenueScreeen::TotalBlances:
				system("cls");
				_ShowTotalBalanceScreen();
				_GoBackToTransactionScreen();
			break;

			case enTransactionMenueScreeen::Transfer:
				system("cls");
				_ShowTransferScreen();
				_GoBackToTransactionScreen();
				break;


			case enTransactionMenueScreeen::TransferLog:
				system("cls");
				_ShowTransFerLogScreen();
				_GoBackToTransactionScreen();
				break;


		case 	enTransactionMenueScreeen::MainMenue:
			break;
		}

	}
public:

	static void ShowTransactionScreen()
	{


		system("cls");
		if (!CheckAccessRight(clsUser::enUserPerimission::eTransaction))
		{
			return;
		}
		_DrawHeaderScreen("Transaction Menue Screen");
		
		cout<<setw(37)<<left<<""<<"=====================================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Munue Screen           \n";
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t\t[2] Withdrae.\n";
		cout << setw(37) << left << "" << "\t\t[3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=====================================================\n";
		_PerforimTransactionOption((enTransactionMenueScreeen)_ReadTransActionOption());

	}

	
};

