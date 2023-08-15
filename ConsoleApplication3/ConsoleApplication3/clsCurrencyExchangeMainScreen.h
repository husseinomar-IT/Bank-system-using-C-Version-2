#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"CurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeMainScreen:protected clsScreen
{


private:

	enum enExchangeMenue{ ListCurrency = 1, FindCurrency, UpdateRate = 3, CurrencyCalulater=4,MainMenue=5 };



	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Cjoose what do you want to do ? [1 to 5]? ";
		short choice = clsInputValidate::ReadshortNumberBetween(1, 5, "Enter a number between 1 and 5? ");
		return choice;
	}




	





	static void _BackToExchangeMenue()
	{
		cout << setw(8) << left << "\n" << "press any key to  go back tho Main Menue...\n";
		system("pause>0");
		ShowCurrenciesMenue();
	}





	static void _ShowCurrencyListScreen()
	{
		CurrenciesListScreen::ShowCurrenciesListScreen();
	}


	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}




	static void _ShowUpdateCurrencyScreen()
	{
		clsUpdateCurrencyScreen::UpdateCurrencyScreen();
	}




	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerforimExchangeMainMenueOption(enExchangeMenue choice)

	{
		switch (choice)
		{
		case enExchangeMenue::ListCurrency:
			system("cls");
			_ShowCurrencyListScreen();
			_BackToExchangeMenue();
			break;

		case enExchangeMenue::FindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_BackToExchangeMenue();
			break;



		case enExchangeMenue::UpdateRate:
			system("cls");
			_ShowUpdateCurrencyScreen();
			_BackToExchangeMenue();
			break;




		case enExchangeMenue::CurrencyCalulater:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_BackToExchangeMenue();
			break;





		case enExchangeMenue::MainMenue:
			
			break;




		}
	}





public:

	static void ShowCurrenciesMenue()
	{
		system("cls");
		
		_DrawHeaderScreen("Currancy Exchange Main Screen");

		cout << "\n\n";
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue           \n";
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "=====================================================\n";
		_PerforimExchangeMainMenueOption((enExchangeMenue)_ReadMainMenueOption());
	}
};

