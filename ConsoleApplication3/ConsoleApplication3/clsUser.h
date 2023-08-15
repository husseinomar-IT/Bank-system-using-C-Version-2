#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"clsPerson.h"
#include "clsString.h"
class clsUser:public clsPerson
{
private:

	enum enMode{ EmptyMode = 0, UpdateMode = 1, AddNewMode };
	


	enMode _Mode;
	string _Username;
	string _Password;

	int _Perimission;
	bool _MarkForDeleted = false;




	static	clsUser _ConvertLineUserToObject(string line, string Seperator = "#//#")
	{
		vector<string>vUser = clsString::Split(line,Seperator);
		clsUser User(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], clsUtil::DeEncyptiontxt(vUser[5]), stoi(vUser[6]));
		return User;
	}




	





	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}



	static 	vector<clsUser>_LoadDataFromFileToVector()
	{
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsUser User = _ConvertLineUserToObject(line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}



	
	




	static string _ConvertUserObjectToLine(clsUser User, string Spletor = "#//#")
	{
		string line = "";
		line += User.Firstname + Spletor;
		line += User.Lastname + Spletor;
		line += User.email + Spletor;
		line += User.Phoen  + Spletor;
		line += User.Username + Spletor;
		line += clsUtil::Encyptiontxt(User.Password) + Spletor;
		line += to_string(User.Perimission);
		return line;



	}

	

	

	  string _PrepareLoginInRecord( string Spletor = "#//#")
	{
		string line = "";

		line += clsDate::GetSystemDateTime() + Spletor;
		line +=Username + Spletor;
		line +=clsUtil::Encyptiontxt(Password) + Spletor;
		line += to_string(Perimission);
		return line;



	}



	static	void _SaveUserToFile(vector<clsUser> vUsers)
	{
		string line = "";
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsUser &U : vUsers)
			{
				if (U._MarkForDeleted == false)
				{
					line = _ConvertUserObjectToLine(U);
					MyFile << line << endl;
				}

			}
			MyFile.close();
		}

	}


	static  void _AddLineToFile(string line)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << line << endl;
			MyFile.close();


		}



	}

	


	void _Update()
	{
		vector<clsUser>vUsers = _LoadDataFromFileToVector();
		for (clsUser &U : vUsers)
		{
			if (U.Username == _Username)
			{
				U = *this;
				break;
			}
		}
		_SaveUserToFile(vUsers);
	}


	void _AddNewUser()
	{
		_AddLineToFile(_ConvertUserObjectToLine(*this));
	}
	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string delim = "#//#")
	{
		vector<string> LoginRegisterDateLine = clsString::Split(Line, delim);
		stLoginRegisterRecord LoginRegisterRecord;
		LoginRegisterRecord.DateTime = LoginRegisterDateLine[0];
		LoginRegisterRecord.Username = LoginRegisterDateLine[1];
		LoginRegisterRecord.Password = clsUtil::DeEncyptiontxt(LoginRegisterDateLine[2]);
		LoginRegisterRecord.Perimission = stoi(LoginRegisterDateLine[3]);
		return LoginRegisterRecord;
	}


public:
	enum enUserPerimission{ eAll = -1, eShoeListClient = 1, eAddNewClient = 2,
		eDeleteClient = 4, eUpdateClient = 8, eFindClient = 16, eTransaction = 32, eManageUser = 64,eShowLoginRegister=128,eCurrencyEXchang=256 };

	clsUser(enMode Mode, string Firatname, string Lastname, string email, string phone, string Username, string Password, int Perimission)
		:clsPerson(Firatname,Lastname,email,phone)
	{
		_Mode = Mode;
		_Username = Username;
		_Password = Password;
		_Perimission = Perimission;
	}



	struct stLoginRegisterRecord{
		string DateTime;
		string Username;
		string Password;
		int Perimission;
	};

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	void SetUsername(string Username)
	{
		_Username = Username;
	}



	string GetUsername()
	{
		return _Username;
	}





	__declspec(property(get = GetUsername, put = SetUsername)) string  Username;




	



	





	void SetPassword(string Password)
	{
		_Password = Password;
	}



	string GetPassword()
	{
		return _Password;
	}



	__declspec(property(get = GetPassword, put = SetPassword)) string  Password;




	void SetPerimission(int Perimission)
	{
		_Perimission = Perimission;
	}



	int GetPerimission()
	{
		return _Perimission;
	}



	__declspec(property(get = GetPerimission, put = SetPerimission)) int  Perimission;



	static clsUser Find(string Username)
	{
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{

				clsUser User = _ConvertLineUserToObject(line);
				if (User._Username == Username)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}





	static clsUser Find(string Username,string PassWord)
	{
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{

				clsUser User = _ConvertLineUserToObject(line);
				if (User._Username == Username && User._Password==PassWord)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}



	static bool ISUserExist(string Username)
	{
		clsUser User = clsUser::Find(Username);
		return (!User.IsEmpty());
	}



	enum enSaveResult{ svFalidEmptyObject = 0, svSucceeded = 1, svFalidAccountExist };




	enSaveResult Save()
	{


		switch (_Mode)
		{
		case clsUser::EmptyMode:

			if (IsEmpty())
				return enSaveResult::svFalidEmptyObject;

		case clsUser::UpdateMode:
			_Update();
			return enSaveResult::svSucceeded;

		case clsUser::AddNewMode:

			if (clsUser::ISUserExist(_Username))
			{
				return enSaveResult::svFalidAccountExist;
			}
			else
			{
				_AddNewUser();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			break;

		}

	}



	static clsUser GetNewUsers(string Username)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", Username, "", 0);
	}

	bool Delete()
	{
		vector<clsUser>vUsers = _LoadDataFromFileToVector();
		for (clsUser &U : vUsers)
		{
			if (U.Username == _Username)
			{
				U._MarkForDeleted = true;
				break;
			}
		}
		_SaveUserToFile(vUsers);
		*this = _GetEmptyUserObject();

		return true;
	}




	static vector<clsUser> GetUserList()
	{
		return (_LoadDataFromFileToVector());
	}






	

	 bool CheckAccessPerimission(enUserPerimission Perimission)
	{
		if (this->_Perimission == enUserPerimission::eAll)
		{
			return true;
		}

		if ((Perimission &this->_Perimission )== Perimission)


			return true;
		else

			return false;

	}


	 void RegisterLogin()
	 {
		
		  
		  string line = _PrepareLoginInRecord();
			  fstream MyFile;
			  MyFile.open("LoginRegister.txt", ios::out | ios::app);
			  if (MyFile.is_open())
			  {
				  MyFile << line << endl;
				  MyFile.close();
			  }

		  }
	 

	


	 static vector<stLoginRegisterRecord>GetLoginRegisterList()
	 {
		 vector<stLoginRegisterRecord>vLoginRegisterRecord;
		 fstream MyFile;
		 MyFile.open("LoginRegister.txt", ios::in);
		 if (MyFile.is_open())
		 {
			 string line;
			 stLoginRegisterRecord LoginRegisterRecord;
			 while (getline(MyFile, line))
			 {
				 LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(line);
				 vLoginRegisterRecord.push_back(LoginRegisterRecord);
			 }
			 MyFile.close();
		 }
		 return vLoginRegisterRecord;
	 }



	
	
};

