#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
class clsFindCurrencyScreen :protected clsScreen
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







	 static void _ShowResult(clsCurrency Currency)
	 {
		 if (!Currency.IsEmpty())
		 {

			 cout << "\nCurrency  found :-)";
			 _PrintCurrency(Currency);
		 }
		 else
		 {
			 cout << "\nCurrency not found :-(";
		 }

	 }



	

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawHeaderScreen(" Find Currancy Screen");


		cout << "\nFind By [1] Code or [2] Country? ";
		short Answer = 1;
		cin >> Answer;
		if (Answer == 1)
		{
			string CuurencyCode = "";
			cout << "\nPlease Enter Currency Code: ";
			CuurencyCode = clsInputValidate::ReadString();
			clsCurrency C1 = clsCurrency::FindByCode(CuurencyCode);
			_ShowResult(C1);
		}
		else
		{
			string Country = "";
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency C1 = clsCurrency::FindByCountry(Country);
			_ShowResult(C1);
		}
	
	}




	
};

