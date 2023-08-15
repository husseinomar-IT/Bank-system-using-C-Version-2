#pragma once
#include<iostream>
#include<string>


using namespace std;

class clsPerson{
private:


	string _Firstname;
	string _Lastname;
	string _email;
	string _phone;
public:




	clsPerson( string Firstname,string Lastname,  string email, string phone)
	{
		
		_Firstname = Firstname;
		_Lastname = Lastname;
		_email = email;
		_phone = phone;
	}


	
	void SetFirstname(string Name)
	{
		_Firstname = Name;
	}
	string GetFirstname()
	{
		return _Firstname;
	}

	__declspec(property(get = GetFirstname, put = SetFirstname)) string  Firstname;

	void SetLastname(string Name)
	{
		_Lastname = Name;
	}

	string GetLastname()
	{
		return _Lastname;
	}


	__declspec(property(get = GetLastname, put = SetLastname)) string  Lastname;

	string Fullname()
	{
		return _Firstname + " " + _Lastname;
	}


	void Setemail(string email)
	{
		_email = email;
	}


	string Getemail()
	{
		return _email;
	}

	__declspec(property(get = Getemail, put = Setemail)) string  email;


	void SetPhone(string Phone)
	{
		 _phone= Phone;
	}


	string GetPhone()
	{
		return _phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string  Phoen;


};
