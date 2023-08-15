#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
template<class T>
class clsTemplateInputValidate
{
public:

	static bool IsNumberBetween(T Num, T From, T To)
	{
		if (Num >= From && Num <= To)
			return true;
		else
			return false;
	}



	


	static bool IsDateBetween(clsDate Date1, clsDate from, clsDate to)
	{


		if (clsDate::IsDate1AfterDate2(Date1, from) || clsDate::IsEqualDate1Date2(Date1, from)
			&& clsDate::IsDate1BeforeDate2(Date1, to) || clsDate::IsEqualDate1Date2(Date1, to))
		{
			return true;
		}


		if (clsDate::IsDate1AfterDate2(Date1, to) || clsDate::IsEqualDate1Date2(Date1, to)
			&& clsDate::IsDate1BeforeDate2(Date1, from) || clsDate::IsEqualDate1Date2(Date1, from))
		{
			return true;
		}

		return false;


	}

	static T ReadNumber(string MassageError = "Invalid Number, Enter again:\n")
	{

		T Num;

		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << MassageError;

		}
		return Num;
	}















	static T ReadNumberBetween(T from, T to, string MassageError = "Number is not within range, Enter again:\n")
	{
		T Num = ReadIntNumber();
		while (!IsNumberBetween(Num, from, to))
		{
			cout << MassageError;
			Num = ReadIntNumber();
		}
		return Num;

	}




	




	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string txt;
		getline(cin >> ws, txt);
		return txt;
	}


};

