#pragma once#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"CurrenciesListScreen.h"
#include"clsCurrency.h"
class clsUpdateCurrencyScreen:protected clsScreen
{


private:

	static void _PrintCurrency(clsCurrency Currency)
	{

		cout << "\n\ncurrency Card:";
		cout << "\n_____________________________\n";
		cout << "Countery : " << Currency.Country() << endl;
		cout << "Code     : " << Currency.CurrencyCode() << endl;
		cout << "Name     : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) : " << Currency.Rate() << endl;
		cout << "_____________________________\n";
	}












	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float Rate = clsInputValidate::ReadFloatlNumber();
		return Rate;
	}



public:


	static void UpdateCurrencyScreen()
	{
		_DrawHeaderScreen("Update Currency Screen");
		string CuurencyCode = "";
		cout << "\nPlease Enter Currency Code: ";
		CuurencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CuurencyCode))
		{
			cout << "CuurencyCode is not found,choose another one: ";
			CuurencyCode = clsInputValidate::ReadString();
		}
		clsCurrency C1 = clsCurrency::FindByCode(CuurencyCode);
		_PrintCurrency(C1);

		char answer = 'n';
		cout << "\n Are You sure you want to update the rate of this Currency y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{

			cout << "\n\nUpdate Currency Rate: \n";
			cout << "____________________________\n";
			
		
			C1.UpdateRate(_ReadRate());
			
				cout << "\n Currency Rate Update Successfully :-)";
				_PrintCurrency(C1);
			


		}

	}
	
	
};

