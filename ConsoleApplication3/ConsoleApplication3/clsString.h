#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class clsString
{

private:
	string _Value;



	


	short ReadWhatToCount()
	{
		short num;
		cout << " What you want to count: 1-[SmallLeter] 2-[CaptialLetter] 3-[AllLeter] ? ";
		cin >> num;
		return num;
	}







public:

	clsString()
	{
		_Value = "";
	}


	clsString(string Value)
	{
		_Value = Value;
	}


	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string  Value;








   static short CountOfWord(string S1)
	{
		string delim = " ";

		short pos = 0;
		short Counter = 0;
		string sWord;
		while ((pos = S1.find(delim)) != std::string::npos)
		{

			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				Counter++;
			}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			Counter++;
		}

		return Counter;

	}

	short CountOfWord()
	{
		return 	 CountOfWord(_Value);
	}






static 	vector<string>Split(string S1, string delim=" ")
	{
		vector<string>vstring;
		
		short pos = 0;

		string sWord;
		while ((pos = S1.find(delim)) != std::string::npos)
		{

			sWord = S1.substr(0, pos);
		//	if (sWord != "")
			//{
				vstring.push_back(sWord);
		//	}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			vstring.push_back(S1);
		}

		return vstring;
	}


	vector<string>Split(string delim = " ")
	{
		return Split(_Value, delim);
	}











   static	short Length(string txt)
	{
		return txt.length();
	}


	short Length()
	{
		return Length(_Value);
	}







 static	string printTerimRight(string txt)
	{

		for (short i = txt.length() - 1; i >= 0; i--)
		{
			if (txt[i] != ' ')
			{
				return txt.substr(0, i + 1);
			}
		}
		return "";


	}

 void printTerimRight()
 {
	 _Value=printTerimRight(_Value);
 }





  static string printTremLeft(string txt)
 {

	 for (short i = 0; i < txt.length(); i++)
	 {
		 if (txt[i] != ' ')
		 {
			 return txt.substr(i, txt.length() - i);
		 }
	 }
	 return "";

 }

  void printTremLeft()
  {
	  _Value= printTremLeft(_Value);
  }






  static  string JoinString(vector<string>vstring, string delim)
  {



	  string S1 = "";
	  for (string &s : vstring)
	  {

		  S1 += s + delim;

	  }
	  S1 = S1.substr(0, S1.length() - delim.length());
	  return S1;

  }

  static string JoinString(string arr[], short length, string delim)
  {
	  string S1 = "";
	  for (short i = 0; i < length; i++)
	  {
		  S1 += arr[i] + delim;
	  }
	  S1 = S1.substr(0, S1.length() - delim.length());
	  return S1;
  }










 static  string ReplaceWord(string txt, string Replacetxt, string ToReplace)
  {
	  short pos = txt.find(Replacetxt);
	  //while ((pos = txt.find(Replacetxt)) != std::string::npos)
	  while (pos != std::string::npos)
	  {
		  txt = txt.replace(pos, Replacetxt.length(), ToReplace);
		  pos = txt.find(Replacetxt);
	  }
	  return txt;
  }

 void ReplaceWord(string Replacetxt, string ToReplace)
 {
	 _Value = ReplaceWord(_Value, Replacetxt, ToReplace);
 }





  



    string ReverceWord(string txt, string delim=" ")
  {
	  vector<string>vstring;
	  vstring = Split(txt, delim);
	  vector<string>::iterator itr = vstring.end();
	  string S = "";
	  while (itr != vstring.begin())
	  {
		  itr--;
		  S += *itr + " ";

	  }
	  S = S.substr(0, S.length() - 1);
	  return S;

  }

	void ReverceWord(string delim = " ")
	{
		_Value = ReverceWord(_Value, delim);
	}
  




   static string RemovePunctuations(string txt)
  {
	  string S = "";
	  for (short i = 0; i < txt.length(); i++)
	  {
		  if (!ispunct(txt[i]))
		  {
			  S += txt[i];
		  }

	  }
	  return S;

  }

  void RemovePunctuations()
  {
	  _Value= RemovePunctuations(_Value);
  }




  static void FirstLetterFromEachWords(string txt)
  {
	  bool isFirstLetter = true;
	  cout << "firstLetters of this string: \n";
	  for (short i = 0; i < txt.length(); i++)
	  {
		  if (txt[i] != ' ' && isFirstLetter)
		  {
			  cout << txt[i] << "  ";
		  }
		  isFirstLetter = (txt[i] == ' ' ? true : false);
	  }

  }



  



 static string UperFirstLetter(string txt)
  {
	  bool isFirstLetter = true;
	  cout << "firstLetters of this string: \n";
	  for (short i = 0; i < txt.length(); i++)
	  {
		  if (txt[i] != ' ' && isFirstLetter)
		  {
			  txt[i] = toupper(txt[i]);
		  }
		  isFirstLetter = (txt[i] == ' ' ? true : false);

	  }
	  return txt;

  }

 void UperFirstLetter()
 {
	 _Value=UperFirstLetter(_Value);
 }








  static string LowerFirstLetter(string txt)
 {
	 bool isFirstLetter = true;
	 cout << "firstLetters of this string: \n";
	 for (short i = 0; i < txt.length(); i++)
	 {
		 if (txt[i] != ' ' && isFirstLetter)
		 {
			 txt[i] = tolower(txt[i]);
		 }
		 isFirstLetter = (txt[i] == ' ' ? true : false);

	 }
	 return txt;

 }

  void LowerFirstLetter()
  {
	  _Value= LowerFirstLetter(_Value);
  }






  static string LowerAllLetters(string txt)
  {


	  for (short i = 0; i < txt.length(); i++)
	  {

		  txt[i] = tolower(txt[i]);

	  }
	  return txt;

  }

  void LowerAllLetters()
  {
	  _Value = LowerAllLetters(_Value);
  }






 static  string UpperAllString(string txt)
  {


	  for (short i = 0; i < txt.length(); i++)
	  {


		  txt[i] = toupper(txt[i]);


	  }
	  return txt;

  }


 void UpperAllString()
 {
	 _Value = UpperAllString(_Value);
 }



 

 static char InvertLetterCase(char Letter)
 {
	 return(isupper(Letter) ? tolower(Letter) : toupper(Letter));


 }





     static string InvertedLetters(string txt)

 {
	 for (short i = 0; i < txt.length(); i++)
	 {
		 txt[i] = InvertLetterCase(txt[i]);
	 }
	 return txt;


 }

	 void InvertedLetters()
   {
		 _Value = InvertedLetters(_Value);
   }







   enum enWhatToCount{ SmallLetter = 1, CaptialLetter = 2, ALL = 3 };




  static  short CountLetters(string txt, enWhatToCount WhatToCount=enWhatToCount::ALL )
   {

	   if (WhatToCount == enWhatToCount::ALL)
	   {
		   return txt.length();
	   }
	   short Counter = 0;

	   for (short i = 0; i < txt.length(); i++)
	   {
		   if (WhatToCount == enWhatToCount::CaptialLetter && isupper(txt[i]))
			   Counter++;
		   if (WhatToCount == enWhatToCount::SmallLetter && islower(txt[i]))
			   Counter++;


	   }
	   return Counter;


   }


 

 /*  short CountLetters()
   {
	   return   CountLetters(_Value, (enWhatToCount)ReadWhatToCount());
   }*/






  static  short CountofCharMatchCase(string txt, char Letter, bool MatchCase = true)
   {
	   short Counter = 0;
	   for (int i = 0; i< txt.length(); i++)
	   {
		   if (MatchCase)
		   {
			   if (txt[i] == Letter)
				   Counter++;
		   }
		   else
		   {
			   if (tolower(txt[i]) == tolower(Letter))
				   Counter++;
		   }


	   }
	   return Counter;
   }



  short CountofCharMatchCase(char Letter, bool MatchCase=true)
  {
	  return   CountofCharMatchCase(_Value, Letter, MatchCase);
  }







  static bool IsVowel(char Letter)
  {
	  Letter = tolower(Letter);
	  return(Letter == 'a' || Letter == 'i' || Letter == 'u' || Letter == 'e' || Letter == 'o');

  }





  static  short CountVowelLetter(string txt)
  {
	  short Counter = 0;
	  for (short i = 0; i < txt.length(); i++)
	  {
		  if (IsVowel(txt[i]))
			  Counter++;
	  }
	  return Counter;
  }


   short CountVowelLetter()
   {
	   return  CountVowelLetter(_Value);
   }








   void PrintAllVowel(string txt)
   {
	   short Counter = 0;
	   cout << "\nVowels in string are: ";
	   for (short i = 0; i < txt.length(); i++)
	   {
		   if (IsVowel(txt[i]))
			   cout << txt[i] << "  ";
	   }
	   cout << endl;
   }




   void PrintAllVowel()
   {
	   PrintAllVowel(_Value);
   }





};

