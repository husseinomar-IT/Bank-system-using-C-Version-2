#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"
class clsCurrency
{


private:
	enum enMode{ EmptyMode = 0, UpdateMode = 1 };;
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string  _CurrencyName;
	float _Rate;



	static clsCurrency _ConvertLineCurrencyToObject(string line)
	{
		vector<string>vCurrency = clsString::Split(line, "#//#");
		clsCurrency Currency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
		return Currency;
	}



	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}




	static 	vector<clsCurrency>_LoadDataFromFileToVector()
	{
		vector<clsCurrency>vCurrency;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsCurrency Currency = _ConvertLineCurrencyToObject(line);
				vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrency;
	}



	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Spletor = "#//#")
	{
		string Line = "";
		Line += Currency.Country() + Spletor;
		Line += Currency.CurrencyCode() + Spletor;
		Line += Currency.CurrencyName() + Spletor;
		Line +=to_string(Currency.Rate());
		return Line;
	}


	static	void _SaveCurrencyDateToFile(vector<clsCurrency> vCurrency)
	{
		string line = "";
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsCurrency &C : vCurrency)
			{
			
				
				line = _ConvertCurrencyObjectToLine(C);
					MyFile << line << endl;
				

			}
			MyFile.close();
		}

	}


	 void _Update()
	{
		vector<clsCurrency>vCurrency = _LoadDataFromFileToVector();
		for (clsCurrency &C : vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDateToFile(vCurrency);

	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}

	static vector<clsCurrency>GetAllUSDRates()
	{
		return _LoadDataFromFileToVector();
	}


	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}


	string Country()
	{
		return _Country;
	}



	string CurrencyCode()
	{
		return _CurrencyCode;
	}


	string CurrencyName()
	{
		return _CurrencyName;
	}


	

	void UpdateRate(float NewRate)
	{
		
		_Rate = NewRate;
		_Update();
		
	}

	float Rate()
	{
		return _Rate;
	}



	static clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		vector<clsCurrency>vCurrency;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{

				clsCurrency Currency = _ConvertLineCurrencyToObject(line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
				vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{

		Country = clsString::UpperAllString(Country);
		vector<clsCurrency>vCurrency;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{

				clsCurrency Currency = _ConvertLineCurrencyToObject(line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
				vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}


	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return(!C1.IsEmpty());
	}

	static vector<clsCurrency>GetCurrencisdList()
	{
		return _LoadDataFromFileToVector();
	}




	 float ConvertToUSD(float amount)
	{
		 return (float)(amount / Rate());
	}


	 float ConvertToanotherCurrencies(float amount, clsCurrency Currency2)
	 {
		 float AmountInUSD = ConvertToUSD(amount);
		 if (Currency2.CurrencyCode() == "USD")
		 {
			 return AmountInUSD;
		 }
		 return  (float)(AmountInUSD*Currency2.Rate());
	 }


	

};

