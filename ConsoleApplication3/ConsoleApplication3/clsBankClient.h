#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"clsPerson.h"
#include "clsString.h"
#include"clsDate.h"
using namespace std;

class clsBankClient:public clsPerson
{
private:

	enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode};


	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelted = false;




	static clsBankClient _ConvertLineToObject(string line, string seperator = "#//#")
	{
		
		vector<string>vString = clsString::Split(line, seperator);
		clsBankClient Client(enMode::UpdateMode, vString[0], vString[1], vString[2], vString[3], vString[4], vString[5], stod(vString[6]));
		return Client;
		

	}




	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}




	


   static 	vector<clsBankClient>_LoadDataFromFileToVector()
	{
		vector<clsBankClient>vClicent;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;
		
			while (getline(MyFile, line))
			{
				clsBankClient Client = _ConvertLineToObject(line);
				vClicent.push_back(Client);
			}
			MyFile.close();
		}
		return vClicent;
	}





	static string _ConvertObjectToLine(clsBankClient Client, string Spletor = "#//#")
	{
		string line = "";
		line += Client.Firstname + Spletor;
		line += Client.Lastname + Spletor;
		line += Client.email + Spletor;
		line += Client.Phoen + Spletor;
		line += Client.GetAccountNumber() + Spletor;
		line += Client.PinCode + Spletor;
		line += to_string(Client.AccountBalance);
		return line;



	}



   static	void _SaveClientToFile( vector<clsBankClient> vClients)
	{
		string line = "";
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsBankClient &C : vClients)
			{
				if (C._MarkForDelted == false)
				{
					line = _ConvertObjectToLine(C);
					MyFile << line << endl;
				}
				
			}
			MyFile.close();
		}
	
	}


  static  void _AddLineToFile(string line)
   {
	   fstream MyFile;
	   MyFile.open("Clients.txt", ios::out | ios::app);
	   if (MyFile.is_open())
	   {
		   MyFile << line << endl;
		   MyFile.close();


	   }



   }




	void _Update()
	{
		vector<clsBankClient>vClients = _LoadDataFromFileToVector();
		for (clsBankClient &C : vClients)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C = *this;
				break;
			}
		}
		_SaveClientToFile(vClients);
	} 





	void _AddNew()
	{
		_AddLineToFile(_ConvertObjectToLine(*this));
	}




	string _PrepareTransferLog(double amount, clsBankClient DestinationClient, string Username, string Spletor = "#//#")
	{
		string Line = "";
		Line += clsDate::GetSystemDateTime() + Spletor;
		Line += GetAccountNumber() + Spletor;
		Line += DestinationClient.GetAccountNumber() + Spletor;
		Line += to_string(amount) + Spletor;
		Line += to_string(AccountBalance) + Spletor;
		Line += to_string(DestinationClient.AccountBalance) + Spletor;
		Line +=Username;
		return Line;


	}





	void _RegisterTransferLog(double amount, clsBankClient DestinationClient, string Username)
	{


		string line = _PrepareTransferLog(amount, DestinationClient, Username);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << line << endl;
			MyFile.close();
		}

	}


	struct stTransferLogRecord;

	static  stTransferLogRecord _ConvertTransferRegisterLineToRecord(string line)
	{
		vector<string>vTransferLogRecord = clsString::Split(line, "#//#");
		stTransferLogRecord Transferlog;
		Transferlog.DateTime = vTransferLogRecord[0];
		Transferlog.SouAccountNumber = vTransferLogRecord[1];
		Transferlog.DesAccountNumber = vTransferLogRecord[2];
		Transferlog.Amount = stod(vTransferLogRecord[3]);
		Transferlog.SouBalance = stod(vTransferLogRecord[4]);
		Transferlog.DesBalance = stod(vTransferLogRecord[5]);
		Transferlog.User = vTransferLogRecord[6];
		return Transferlog;
	}



public:
	clsBankClient(enMode Mode, string Firstname, string Lastname,string email, string Phone, string AccountNumber, string PinCode, double AccountBalance)
		:clsPerson(Firstname,Lastname,  email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}



	string GetAccountNumber()
	{
		return _AccountNumber;
	}

   void SetPINCode(string PinCode)
	{
	   _PinCode = PinCode;
	}

   string GetPINCode()
   {
	   return _PinCode;
   }

   __declspec(property(get = GetPINCode, put = SetPINCode)) string  PinCode;


   void SetAccountBalance(double AccountBalance)
   {
	   _AccountBalance = AccountBalance;
   }

   double GetAccountBalance()
   {
	   return _AccountBalance;
   }
   __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double  AccountBalance;

   static clsBankClient Find(string AccountNumber)
   {
	   vector<clsBankClient>vClients;
	   fstream MyFile;
	   MyFile.open("Clients.txt", ios::in);
	   if (MyFile.is_open())
	   {
		   string line;
		    
		   while (getline(MyFile, line))
		   { 

			   clsBankClient Client = _ConvertLineToObject(line);
			   if (Client._AccountNumber==AccountNumber)
			   {
				   MyFile.close();
				   return Client;
			   }
			   vClients.push_back(Client);
		   }
		   MyFile.close();
	   }
	   return _GetEmptyClientObject();




   }


   static clsBankClient Find(string AccountNumber,string PinCode)
   {
	   vector<clsBankClient>vClients;
	   fstream MyFile;
	   MyFile.open("Clients.txt", ios::in);
	   if (MyFile.is_open())
	   {
		   string line;

		   while (getline(MyFile, line))
		   {

			   clsBankClient Client = _ConvertLineToObject(line);
			   if (Client._AccountNumber == AccountNumber && Client.PinCode==PinCode)

			   {
				   MyFile.close();
				   return Client;
			   }
			   vClients.push_back(Client);
		   }
		   MyFile.close();
	   }
	   return _GetEmptyClientObject();

   }

 



   static bool ISClientExist(string AccountNumber)
   {
	   clsBankClient Client = clsBankClient::Find(AccountNumber);
	   return (!Client.IsEmpty());
   }

   enum enSaveResult{svFalidEmptyObject=0,svSucceeded=1,svFalidAccountExist};

   enSaveResult Save()
   {
	

	   switch (_Mode)
	   {
	   case clsBankClient::EmptyMode:

		   if (IsEmpty())
			   return enSaveResult::svFalidEmptyObject;

	   case clsBankClient::UpdateMode:
		   _Update();
		   return enSaveResult::svSucceeded;
		   
	   case clsBankClient::AddNewMode:

		   if (clsBankClient::ISClientExist(_AccountNumber))
		   {
			   return enSaveResult::svFalidAccountExist;
		   }
		   else
		   {
			   _AddNew();
			  _Mode = enMode::UpdateMode;
			   return enSaveResult::svSucceeded;
		   }
		   break;
	
	   }

   }

   static clsBankClient GetNewClient(string AccountNumber)
   {
	   return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
   }


   bool Delete()
   {
	   vector<clsBankClient>vClients = _LoadDataFromFileToVector();
	   for (clsBankClient &C : vClients)
	   {
		   if (C.GetAccountNumber() == _AccountNumber)
		   {
			   C._MarkForDelted = true;
			   break;
		   }
	   }
	   _SaveClientToFile(vClients);
	   *this = _GetEmptyClientObject();

	   return true;
   }







   static vector<clsBankClient> GetClientList()
   {
	   return (_LoadDataFromFileToVector());
   }


   static double GetTotalBalnce()
   {
	   vector<clsBankClient>vClicents = clsBankClient::GetClientList();
	   double TotalBalance=0;
	   for (clsBankClient &C : vClicents)
	   {
		   
		   
		   TotalBalance += C.AccountBalance;
			
		   
	   }
	   return TotalBalance;

   }


   void Deposit(double amount)
   {
	   _AccountBalance += amount;
	   Save();
	
   }


   bool Withdraw(double amount)
   {
	   if (amount > _AccountBalance)
	   {
		   return false;
	   }
	   else
	   {
		   _AccountBalance -= amount;
		   Save();
		   return true;
	   }
	   
   }



   bool Transfer(double amount, clsBankClient &DestinationClient,string Username)
   {
	   if (amount > AccountBalance)
	   {
		   return false;
	   }
	   Withdraw(amount);
	   DestinationClient.Deposit(amount);
	   _RegisterTransferLog(amount, DestinationClient, Username);
	   return true;
   }



   struct stTransferLogRecord{
	   string DateTime;
	   string SouAccountNumber;
	   string DesAccountNumber;
	   double Amount;
	   double SouBalance;
	   double DesBalance;
	   string User;
   };

   static vector<stTransferLogRecord>GetTransferRegisterList()
   {
	   vector<stTransferLogRecord>vTransferLogRecord;
	   fstream MyFile;
	   MyFile.open("TransferLog.txt", ios::in);
	   if (MyFile.is_open())
	   {
		   string line;
		   stTransferLogRecord TransferLogLine;
		   while (getline(MyFile, line))
		   {
			   TransferLogLine = _ConvertTransferRegisterLineToRecord(line);
			   vTransferLogRecord.push_back(TransferLogLine);
		   }
		   MyFile.close();
	   }
	   return vTransferLogRecord;
   }


  

};

