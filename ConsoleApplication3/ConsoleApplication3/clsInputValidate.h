#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
class clsInputValidate
{
public:

	static bool IsNumberBetween(int Num, int From, int To)
	{
		if (Num>=From && Num<=To)
			return true;
		else
	    	return false;
	}



	static bool IsNumberBetween(short Num, short From, short To)
	{
		if (Num >= From && Num <= To)
			return true;
		else
			return false;
	}




	static bool IsNumberBetween(float Num, float From, float To)
	{
		if (Num >= From && Num <= To)
			return true;
		else
			return false;
	}


	static bool IsNumberBetween(double Num, double From, double To)
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

	static int ReadIntNumber(string MassageError="Invalid Number, Enter again:\n")
	{
		
			int Num;
			
			while (!( cin >> Num))
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << MassageError;
				
			}
			return Num;
		}







	static double ReadDblNumber(string MassageError = "Invalid Number, Enter again:\n")
	{

		double Num;
		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << MassageError;

		}
		return Num;
	}



	static float ReadFloatlNumber(string MassageError = "Invalid Number, Enter again:\n")
	{

		float Num;
		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << MassageError;

		}
		return Num;
	}




	



	

	static int ReadIntNumberBetween(int from, int to, string MassageError="Number is not within range, Enter again:\n")
	{
		int Num = ReadIntNumber();
		while (!IsNumberBetween(Num, from, to))
		{
			cout << MassageError;
			Num = ReadIntNumber();
		}
		return Num;

	}


	static int ReadshortNumberBetween(short from, short to, string MassageError = "Number is not within range, Enter again:\n")
	{
		short Num = ReadIntNumber();
		while (!IsNumberBetween(Num, from, to))
		{
			cout << MassageError;
			Num = ReadIntNumber();
		}
		return Num;

	}


	static double ReadDblNumberBetween(double from, double to, string MassageError="Number is not within range, Enter again:\n")
	{
		double	Num = ReadDblNumber();
		while (!IsNumberBetween(Num, from, to))
		{
			cout << MassageError;
			Num = ReadDblNumber();
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
		getline(cin>>ws, txt);
		return txt;
	}


};

