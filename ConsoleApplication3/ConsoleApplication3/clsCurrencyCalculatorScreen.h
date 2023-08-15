#pragma once
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"CurrenciesListScreen.h"
#include"clsCurrency.h"
class clsCurrencyCalculatorScreen:protected clsScreen
{


private:



	static clsCurrency _GetCurrency()
	{

		string	CurrencyCode = "";
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n\Currency Code  is not found,choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}


	static float _ReadAmount()
	{
		float amount;
		cout << "\n\nEnter  Amount to Exchange: ";
		amount = clsInputValidate::ReadFloatlNumber();
		return amount;
	}


	static void _PrintCurrency(clsCurrency Currency,string title="currency Card")
	{

		cout << "\n\n" << title;
		cout << "\n_____________________________\n";
		cout << "Countery : " << Currency.Country() << endl;
		cout << "Code     : " << Currency.CurrencyCode() << endl;
		cout << "Name     : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) : " << Currency.Rate() << endl;
		cout << "_____________________________\n";
	}

	static void  _PrintCalculationsResult(float amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrency(Currency1, "From:");

		float AmountInUSD = Currency1.ConvertToUSD(amount);

		cout << amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " " << Currency2.CurrencyCode() << endl;

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}


		cout << "\nConverting from USD to: \n ";
		_PrintCurrency(Currency2, "To:");
		float AmountInCurreny2 = Currency1.ConvertToanotherCurrencies(amount, Currency2);
		cout << amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurreny2 << " " << Currency2.CurrencyCode() << endl;
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{

		char answer = 'y';
		while (answer == 'Y' || answer == 'y')
		{
			system("cls");
			_DrawHeaderScreen("Currency Calculator Screen");
			cout << "\nPlease Enter Currency1 Code: ";
			clsCurrency Currency1 = _GetCurrency();
			cout << "\nPlease Enter Currency2 Code: ";
			clsCurrency Currency2 = _GetCurrency();

			float amount = _ReadAmount();
			_PrintCalculationsResult(amount, Currency1, Currency2);
			cout << "\n Do you want to do another  Calculation again ? y/n ? ";
			cin >> answer;
		}
		
		
	

		

	}
};

