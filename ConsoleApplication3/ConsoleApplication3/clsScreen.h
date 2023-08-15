#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"
using namespace std;
 class clsScreen
{
protected:
	static void _DrawHeaderScreen(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t------------------------------------------------------------";
		cout << "\n\n\t\t\t\t\t\t\t " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t\t\t " << SubTitle;
		}
		cout << "\n\n\t\t\t\t------------------------------------------------------------\n\n";
		cout << "\t\t\t\tUser:" << CurrentUser.Username;
		cout << "\n\t\t\t\tDate:" << clsDate::DateToString(clsDate()) << endl;
		//_SetUserAndDate();
	}




	/*static void _SetUserAndDate()
	{
		cout << setw(37) << left << "" << "User: " << CurrentUser.Username << endl;
		cout << setw(37) << left << "" << "Date: ";
		Date.Print();
	}*/


	static bool CheckAccessRight(clsUser::enUserPerimission Permission)
	{
		if (!CurrentUser.CheckAccessPerimission(Permission))
		{
			cout << "\t\t\t\t------------------------------------------------------------";
			cout << "\n\n\t\t\t\t\t\t" << "Access Denied Contact your Admin ";
			cout << "\n\n\t\t\t\t------------------------------------------------------------\n\n";
			return false;
		}
		else{


			return true;
		}
	}


};

