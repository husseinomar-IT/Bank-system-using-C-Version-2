#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
class CurrenciesListScreen:protected clsScreen
{



private:


	static void _PrintCurrency(clsCurrency Currency)
	{


		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(22) << left << Currency.CurrencyCode();
		cout << "| " << setw(25) << left << Currency.CurrencyName();
		cout << "| " << setw(20) << left << Currency.Rate();


	}


public:



	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency>vCurrencies = clsCurrency::GetCurrencisdList();
		string title = "Carrencies List Screen";
		string Subtile = "(" + to_string(vCurrencies.size()) + ") Currency ";

		_DrawHeaderScreen(title, Subtile);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(22) << "Code";
		cout << "| " << left << setw(25) << "Name";
		cout << "| " << left << setw(20) << "Rate/(1$)";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;



		if (vCurrencies.size() == 0)
			cout << "\t\t No Currency Available in the System\n";
		else
		for (clsCurrency &C : vCurrencies)
		{
			_PrintCurrency(C);
			cout << endl;
		}
		cout << setw(20) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}




};

