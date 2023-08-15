#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include"Global.h"

class clsLoginScreen:protected clsScreen
{


private:


	static bool CounterLogin(short counter)
	{
		return (counter == 3);
	}

	static bool _Login()
	{
		string username = "", Password = ""; 
		bool Falidlogin = false; 
		short FalidLogincounter = 0;
		
		do{
			
			
			if (Falidlogin)
			{
				FalidLogincounter++;
				cout << "\nInvlaid Username/Password!\n";
				cout << "You have " << (3 - FalidLogincounter);
				cout << " Trial(s) to login\n\n";
			}
			if (FalidLogincounter == 3)
			{
				cout << "\n Your are Loked after 3 falid trails\n\n";
				return false;
			}
			cout << "\nEnter Username? ";
			cin >> username;

			cout << "Enter Password? ";
			cin >> Password; 
			
				CurrentUser = clsUser::Find(username, Password);
				Falidlogin = CurrentUser.IsEmpty();
			
			
		} while (Falidlogin);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenuScreen();

		return true;

	}
public:

	static bool ShowLoginScreen()
	{
		_DrawHeaderScreen("Login Screen");
	
			return _Login();
		
	

	}
	
};

