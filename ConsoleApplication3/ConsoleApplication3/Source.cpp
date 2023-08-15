#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsLoginScreen.h"

using namespace std;









int main(){


	

	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	

	}





	system("pause>0");
	return 0;

}