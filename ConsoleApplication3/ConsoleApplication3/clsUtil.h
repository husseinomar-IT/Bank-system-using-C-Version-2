#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include "clsDate.h"
using namespace std;
class clsUtil
{

public:
	static int RandomNumberBetweenRange(int from, int to)
	{
		int Random = rand() % (to - from + 1) + from;
		return Random;
	}




	static void Srand()
	{
		srand((unsigned)time(NULL));
	}


	enum encharType{ smallLeteer = 1, captellLetter = 2, SpecialLetter = 3, Digit = 4 ,Mixchars=5};



	static char GetRandomCharacters(encharType chartype)
	{


		if (chartype == Mixchars)
			chartype = (encharType)RandomNumberBetweenRange(1, 3);
		switch (chartype)
		{
		case encharType::captellLetter:
			return char(RandomNumberBetweenRange(65, 90));

		case encharType::smallLeteer:
			return char(RandomNumberBetweenRange(97, 122));


		case encharType::Digit:
			return char(RandomNumberBetweenRange(48, 57));

		case encharType::SpecialLetter:
			return char(RandomNumberBetweenRange(33, 47));



		default:
			return RandomNumberBetweenRange(1, 10);

		}
	}









	static string GenerateWord(encharType type, short Length)

	{
		string word = "";
		for (int i = 1; i <= Length; i++)
		{
			word = word + GetRandomCharacters(type);

		}
		return
			word;
	}

   


	static 	string GenerateKey(encharType type)
	{
		string Key = "";
		Key = GenerateWord(type, 4) + "-";
		Key = Key + GenerateWord(type, 4) + "-";
		Key = Key + GenerateWord(type, 4) + "-";
		Key = Key + GenerateWord(type, 4);


		return Key;
	}

static 	void  GenerateKeys(short Length,encharType type)
	{

		for (int i = 1; i <= Length; i++)
		{
			cout << "[" << i << "]" << "=";
			cout << GenerateKey(type) << endl;

		}

	}

   static void  GenerateKeys(encharType type,short Length)
{

	for (int i = 1; i <= Length; i++)
	{
		cout << "[" << i << "]" << "=";
		cout << GenerateKey(type) << endl;

	}

}




 static   void Swap(int &a, int &b)
   {
	   int Temp;
	   Temp = a;
	   a = b;
	   b = Temp;
   }





 static   void Swap(float &a, float &b)
 {
	 float Temp;
	 Temp = a;
	 a = b;
	 b = Temp;
 }




 static   void Swap(string &a, string &b)
 {
	 string Temp;
	 Temp = a;
	 a = b;
	 b = Temp;
 }



 static   void Swap(double &a, double &b)
 {
	 double Temp;
	 Temp = a;
	 a = b;
	 b = Temp;
 }





 static   void Swap(clsDate &a, clsDate &b)
 {
	 clsDate Temp;
	 Temp = a;
	 a = b;
	 b = Temp;
 }


 static   void Swap(bool &a, bool &b)
 {
	 bool Temp;
	 Temp = a;
	 a = b;
	 b = Temp;
 }


 static   void Swap(char &a, char &b)
 {
	 char Temp;
	 Temp = a;
	 a = b;
	 b = Temp;
 }






static  void ShuffleArray(int array[100], int size)
 {
	 for (int i = 0; i < size; i++)
	 {
		 Swap(array[RandomNumberBetweenRange(1, size) - 1], array[RandomNumberBetweenRange(1, size) - 1]);
	 }
 }










static void FullArrayWithRandom(int arr[100], int &size,int From,int To)

{
	cout << "Please enter the size of Array :";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		arr[i] = RandomNumberBetweenRange(From,To);
	}
}








static string Encyptiontxt(string txt, short EncryptionKey=123)
{
	for (int i = 0; i <= txt.length(); i++)
	{
		txt[i] = char((int)txt[i] + EncryptionKey);
	}
	return txt;
}


static  string DeEncyptiontxt(string txt, short DeEncryptionKey=123)
{
	for (int i = 0; i <= txt.length(); i++)
	{
		txt[i] = char((int)txt[i] - DeEncryptionKey);
	}
	return txt;
}












static void FullArrayWithKeys(string arr[100], int size,encharType type)

{
	for (int i = 0; i < size; i++)
	{
		arr[i] = GenerateKey(type);
	}
}




static void FullArrayWithRandomWords(string arr[100], int size,encharType type,short Length)

{
	for (int i = 0; i < size; i++)
	{
		arr[i] = GenerateWord(type, Length);
	}
}









static string  Tabs(short NumberofTabs)
{
	string t = "";
	for (short i = 0; i < NumberofTabs; i++)
	{
		t += "\t";
	}
	return t;
}




static string NumberToString(int Num)
{
	if (Num == 0)
	{
		return "";
	}

	if (Num >= 1 && Num <= 19)
	{
		string arr[] = { "", "One", "Tow", "Three", "Four", "Five",
			"Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
			"Twelve", "Thirteen", "Fourteen", "Fiveteen", "Sixteen",
			"Seventeen", "Eighteen", "Ninteen" };
		return arr[Num] + " ";
	}

	if (Num >= 20 && Num <= 99)
	{
		string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fivty", "Sixty", "Seventy", "Eighty", "Ninty" };
		return arr[Num / 10] + "" + NumberToString(Num % 10);
	}

	if (Num >= 100 && Num <= 199)
	{
		return "One Hundred" + NumberToString(Num % 100);
	}

	if (Num >= 200 && Num <= 999)
	{
		return NumberToString(Num / 100) + "Hundred" + NumberToString(Num % 100);
	}

	if (Num >= 1000 && Num <= 1999)
	{
		return "One thousent" + NumberToString(Num % 1000);
	}

	if (Num >= 2000 && Num <= 999999)
	{
		return NumberToString(Num / 1000) + "thousent" + NumberToString(Num % 1000);
	}

	if (Num >= 1000000 && Num <= 1999999)
	{
		return "One Millon" + NumberToString(Num % 100000);
	}

	if (Num >= 2000000 && Num <= 999999999)
	{
		return NumberToString(Num / 1000000) + "Millons" + NumberToString(Num % 1000000);
	}

	if (Num >= 1000000000 && Num <= 1999999999)
	{
		return "One Billion" + NumberToString(Num % 1000000000);
	}
	else
	{
		return NumberToString(Num / 1000000000) + "Billion" + NumberToString(Num % 1000000000);
	}




}

};






