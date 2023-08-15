#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<ctime>
#include<vector>
#include "clsString.h"
using namespace std;


class clsDate
{

private:


	

		short _Day;
		short _Month;
		short _Year;
	

		


	


public:
	
	

	clsDate()
	{
		time_t t = time(0);
		tm*now = localtime(&t);
		 _Day= now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}
	
	



	clsDate(string sDate)
	{
		vector<string>Vstring = clsString::Split(sDate, "/");
		_Day = stoi(Vstring[0]);
		_Month = stoi(Vstring[1]);
		 _Year= stoi(Vstring[2]);
	}


	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}



	clsDate(short NumberOfDays, short Year)
	{
	
		clsDate Date = GetDateFromDayOrderInYear(NumberOfDays, Year);
		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year;
		

	}

	void SetDay(short Day)
	{
		_Day = Day;
	}

	short GetDay()
	{
		return _Day;
	}


	__declspec(property(get = GetDay, put = SetDay))short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth()
	{
		return _Month;
	}


	__declspec(property(get = GetMonth, put = SetMonth))short Month;


	void SetYear(short Year)
	{
		_Year = Year;
	}



	short GetYear()
	{
		return _Year;
	}



	__declspec(property(get = GetYear, put = SetYear))short Year;




	static clsDate SystemDate()
	{
		time_t t = time(0);
		tm*now = localtime(&t);
		//sDate Date;
		short Day, Month, Year;
		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year + 1900;
		return clsDate(Day, Month,Year);
	}


	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

 	string DateToString()
	{
		return DateToString(*this);
	}
  

	




      static  void Print(clsDate Date)
	{
		cout << DateToString(Date) << endl;
	}
	  

	

	  void Print()
	  {
		  Print(*this);
	  }






  static short IsLeapYear(short Year)

	{
		return(Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

   short IsLeapYear()
  {
	  return   IsLeapYear(_Year);
  }



 static short NumberOfDaysInYear(short Year)
  {
	  return(IsLeapYear(Year) ? 366 : 365);
  }

 short NumberOfDaysInYear()
 {
	 return  NumberOfDaysInYear(_Year);
 }





  static short NumberOfHoursInYear(short Year)
  {
	  return NumberOfDaysInYear(Year) * 24;
  }

  short NumberOfHoursInYear()
  {
	  return  NumberOfHoursInYear(_Year);
	
  }



  static  int NumberOfMintueInYear(short Year)
  {
	  return NumberOfHoursInYear(Year) * 60;
  }

  int NumberOfMintueInYear()
  {
	  return  NumberOfMintueInYear(_Year);

  }




 static  int NumberOfSecondsInYear(short Year)
  {
	  return NumberOfMintueInYear(Year) * 60;
  }

 int NumberOfSecondsInYear()
 {
	 return  NumberOfSecondsInYear(_Year);
 }




	  static short NumberOfDaysInMonth(short Year, short Month)
	{

		if (Month<1 || Month>12)
			return 0;
		int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return	(Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];


	}


	  short NumberOfDaysInMonth()
	  {
		  return   NumberOfDaysInMonth(_Year, _Month);
	  }







  static   clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	  {
		  clsDate Date;
		 

		  short RemainingDays = DateOrderInYear;
		  short MonthDays = 0;

		  Date.Year = Year;
		  Date.Month = 1;
		  while (true)
		  {
			  MonthDays = NumberOfDaysInMonth(Year, Date.Month);
			  if (RemainingDays > MonthDays)
			  {
				  RemainingDays -= MonthDays;
				  Date.Month++;
			  }
			  else
			  {
				  Date.Day = RemainingDays;
				  break;
			  }
		  }
		  return Date;
	  }


  clsDate GetDateFromDayOrderInYear(short DateOrderInYear)
  {
	  return  GetDateFromDayOrderInYear(DateOrderInYear, _Year);
  }



 static string MonthShortName(short Month)
	{
		string arrMonth[12] = { "Jan", "Feb", "Mar",
			"April", "May", "Jun",
			"July", "Aug", "Sep",
			"Oct", "Nov", "Dec" };
		return arrMonth[Month - 1];
	}

 string MonthShortName()
 {
	 return MonthShortName(_Month);
 }



 static	short DayOfWeekOrder(short Year, short Month, short Day)
	{
		short a, y, m;
		a = (14 - Month) / (12);
		y = Year - a;
		m = Month + 12 * a - 2;
		return  (Day + Year + (Year) / (4) - (Year) / (100) + (Year) / (400) + (31 * m) / (12)) % 7;


	}

 short DayOfWeekOrder()
 {
	 return DayOfWeekOrder(_Year, _Month, _Day);
 }







 static void PrintCelender(short Year, short Month)
	{
	 short Current = DayOfWeekOrder(Year, Month, 1);
		short NumberOfDays = NumberOfDaysInMonth(Year, Month);


		printf("\n-----------------%s-------------------\n\n", MonthShortName(Month).c_str());
		printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat \n");
		short i;
		for (i = 0; i < Current; i++)
			printf("     ");

		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n---------------------------------------\n");
	}

 void PrintCelender()
 {
	 PrintCelender(_Year,_Month);
 }






  static void PrintYearCelender(short Year)
 {
	 printf("\n--------------------------------------------------------\n\n\n");
	 printf("                   Calender-%d\n ", Year);
	 printf("\n\n\n--------------------------------------------------------\n");
	 for (short i = 1; i <= 12; i++)
	 {

		 PrintCelender(Year, i);
	 }


 }





  void PrintYearCelender()
  {
	  PrintYearCelender(_Year);
  }









 static bool IsValidDate( clsDate Date)
  {
	  if (Date.Day<1 || Date.Day>31)
		  return false;
	  if (Date.Month<1 || Date.Month>12)
		  return false;
	  if (Date.Month == 2)
	  {
		  if (IsLeapYear(Date.Year))
		  {
			  if (Date.Day > 29)
				  return false;
		  }
		  else
		  {
			  if (Date.Day > 28)
				  return false;
		  }

	  }
	  short Days = NumberOfDaysInMonth(Date.Year, Date.Month);
	  if (Date.Day > Days)
		  return false;
	  return true;

  }






 bool IsValid()
 {
	 return   IsValidDate(*this);
 }









 static  bool ISLastDayInMonth(clsDate Date)
 {

	 return(Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
 }

 bool ISLastDayInMonth()
 {
	 return  ISLastDayInMonth(*this);
 }

 
  static bool isLastMonthInYear(short Month)
 {

	 return(Month == 12);
 }









 static  clsDate IncreaseByOneDay(clsDate Date)
  {

	  if (ISLastDayInMonth(Date))
	  {
		  if (isLastMonthInYear(Date.Month))
		  {
			  Date.Day = 1;
			  Date.Month = 1;
			  Date.Year++;
		  }
		  else
		  {
			  Date.Day = 1;
			  Date.Month++;
		  }
	  }
	  else
	  {
		  Date.Day++;
	  }





	  return Date;
  }


 void IncreaseByOneDay()
 {
	 *this = IncreaseByOneDay(*this);
 }


 static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
 {

	 return(Date1.Year < Date2.Year) ? true
		 : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true
		 : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

 }

 bool IsBeforeDate2( clsDate Date2)
 {
	 return IsDate1BeforeDate2(*this, Date2);
 }







 static void SwapDate(clsDate &Date1, clsDate &Date2)
 {
	 clsDate Temp;
	 Temp.Day = Date1.Day;
	 Temp.Month = Date1.Month;
	 Temp.Year = Date1.Year;



	 Date1.Day = Date2.Day;
	 Date1.Month = Date2.Month;
	 Date1.Year = Date2.Year;


	 Date2.Day = Temp.Day;
	 Date2.Month = Temp.Month;
	 Date2.Year = Temp.Year;

 }




 static int DiffrentBetweenDate1Date2(clsDate Date1, clsDate Date2, bool includeEndDay = false)
{
	short TempFlag = 1;
	if (!IsDate1BeforeDate2(Date1, Date2))
	{
		SwapDate(Date1, Date2);
		TempFlag = -1;
	}

	short Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseByOneDay(Date1);

	}
	return includeEndDay ? (++Days*TempFlag) : (Days*TempFlag);

}



int DiffrentBetweenDateAndDate2(clsDate Date2, bool includeEndDay = false)
{
	return  DiffrentBetweenDate1Date2(*this, Date2, includeEndDay);
}








static  int MyBirthDayInDays(clsDate BirthDay)
{


	return(DiffrentBetweenDate1Date2(BirthDay, clsDate::SystemDate(),true));

}





static clsDate IncreaseByOneWeek(clsDate &Date1)
{


	for (short i = 1; i <= 7; i++)
	{
		Date1 = IncreaseByOneDay(Date1);
	}

	return Date1;

}


void IncreaseByOneWeek()

{
	IncreaseByOneWeek(*this);
}







static clsDate IncreaseXWeeks(short Week, clsDate &Date1)
{


	for (short i = 1; i <= Week; i++)
	{
		Date1 = IncreaseByOneWeek(Date1);
	}

	return Date1;


}


void IncreaseXWeeks(short Weeks)

{
	 IncreaseXWeeks(Weeks, *this);
}









 static clsDate IncreaceDateByOneMonth(clsDate &Date1)
{


	if (Date1.Month == 12)
	{
		Date1.Month = 1;
		Date1.Year++;
	}
	else
	{
		Date1.Month++;
	}
	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date1.Year, Date1.Month);
	if (Date1.Day > NumberOfDaysInCurrentMonth)
	{
		Date1.Day = NumberOfDaysInCurrentMonth;
	}

	return Date1;
}

 void IncreaceByOneMonth()
 {
	IncreaceDateByOneMonth(*this);
 }




 

 static clsDate IncreaceDateByXMonth(short Month, clsDate &Date1)
{
	for (short i = 1; i <= Month; i++)
	{
		Date1 = IncreaceDateByOneMonth(Date1);
	}

	return Date1;
}

 void IncreaceByXMonth(short Months)
 {
	 IncreaceDateByXMonth(Months, *this);
 }




static clsDate IncreaceDateByOneYear(clsDate &Date1)
{
	Date1.Year++;
	return Date1;
}

void IncreaceByOneYear()
{
      IncreaceDateByOneYear(*this);
}








static clsDate IncreaceDateByXYear(short Year, clsDate &Date1)
{
	Date1.Year += Year;

	return Date1;
}

void IncreaceByXYearFaster(short Years)
{
	IncreaceDateByXYear(Years, *this);
}




 static  clsDate IncreaceDateByOneDecade(clsDate &Date1)
{
	Date1.Year += 10;

	return Date1;
}
 
 void IncreaceByOneDecade()
 {
	 IncreaceDateByOneDecade(*this);
 }
   



static clsDate IncreaceDateByXDecade(short Decade, clsDate &Date1)
{
	/*for (short i = 1; i <= Decade; i++)
	{
		Date1.Date = IncreaceDateByOneDecade(Date1);
	}*/
	//the Second solutioon is faster than this

	Date1.Year += Decade * 10;

	return Date1;
}


void  IncreaceByXDecade(short Decade)
{
	 IncreaceDateByXDecade(Decade, *this);
}




static clsDate IncreaceDateByOneCentury(clsDate &Date1)
{

	Date1.Year += 100;

	return Date1;
}


void IncreaceByOneCentury()
{
	 IncreaceDateByOneCentury(*this);
}





 static clsDate IncreaceDateByOneMillennium(clsDate &Date1)
{

	Date1.Year += 1000;

	return Date1;
}

 void IncreaceByOneMillennium()
 {
	  IncreaceDateByOneMillennium(*this);
 }



 static bool ISFirstDayInMonth(clsDate Date)
 {

	 return(Date.Day == 1);


 }





 static bool isFirstMonthInYear(short Month)
 {

	 return(Month == 1);
 }



 bool isFirstMonthInYear()
 {
	 return   isFirstMonthInYear(_Month);
 }





 static clsDate DeccreaseDateOneDay(clsDate Date1)
 {

	 if (ISFirstDayInMonth(Date1))
	 {
		 if (isFirstMonthInYear(Date1.Month))
		 {
			 Date1.Day = 31;
			 Date1.Month = 12;
			 Date1.Year--;
		 }
		 else
		 {
			 Date1.Month--;
			 Date1.Day = NumberOfDaysInMonth(Date1.Year, Date1.Month);


		 }
	 }
	 else
	 {
		 Date1.Day--;
	 }





	 return Date1;
 }



 void DeccreaseOneDay()
 {
	*this= DeccreaseDateOneDay(*this);
 }




static  clsDate  DeccreaseDateXDays(short Days, clsDate &Date1)
 {
	 for (short i = 1; i <= Days; i++)
	 {
		 Date1 = DeccreaseDateOneDay(Date1);
	 }
	 return Date1;
 }

void  DeccreaseXDays(short Days)
{
   DeccreaseDateXDays(Days, *this);
}



 static clsDate  DeccreaseDateOneWeek(clsDate &Date1)
 {
	 for (short i = 1; i <= 7; i++)
	 {
		 Date1 = DeccreaseDateOneDay(Date1);
	 }
	 return Date1;
 }

 void  DeccreaseOneWeek()
 {
	 DeccreaseDateOneWeek(*this);
 }





static   clsDate  DeccreaseDateOneWeek(short Weeks, clsDate &Date1)
 {
	 for (short i = 1; i <= Weeks; i++)
	 {
		 Date1 = DeccreaseDateOneWeek(Date1);
	 }
	 return Date1;
 }

void  DeccreaseOneWeek(short Week=7)
{
	 DeccreaseDateOneWeek(Week, *this);
}




 static clsDate DeccreaseDateByOneMonth(clsDate &Date)
 {
	 if (Date.Month == 1)
	 {
		 Date.Month = 12;
		 Date.Year--;
	 }
	 else
	 {
		 Date.Month--;
	 }


	 short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	 if (Date.Day > NumberOfDaysInCurrentMonth)
	 {
		 Date.Day = NumberOfDaysInCurrentMonth;
	 }
	 return Date;
 }

 void DeccreaseByOneMonth()
 {
	  DeccreaseDateByOneMonth(*this);
 }



static clsDate DeccreaseDateByXMonths(short Months, clsDate &Date)
 {
	 for (short i = 1; i <= Months; i++)
	 {
		 Date = DeccreaseDateByOneMonth(Date);
	 }
	 return Date;
 }



void DeccreaseByXMonths(short Months)
{
	DeccreaseDateByXMonths(Months, *this);
}




 static clsDate DeccreaseDateByOneYear(clsDate &Date)
 {
	 Date.Year--;
	 return Date;
 }

 void DeccreaseByOneYear()
 {
	  DeccreaseDateByOneYear(*this);
 }










 static clsDate DeccreaseDateXYear(short Years, clsDate &Date)
 {
	 Date.Year -= Years;

	 return Date;
 }

 void DeccreaseXYear(short Years)
 {
	 DeccreaseDateXYear(Years, *this);
 }


static clsDate DeccreaseDateByOneDecade(clsDate &Date)
 {
	 Date.Year -= 10;

	 return Date;
 }


void DeccreaseByOneDecade()
{
	DeccreaseDateByOneDecade(*this);
}




 static clsDate DeccreaseDateByXDecade(short Decade, clsDate &Date)
 {
	 Date.Year -= 10 * Decade;

	 return Date;
 }


 void DeccreaseByXDecade(short Decade)
 {
	 DeccreaseDateByXDecade(Decade, *this);
 }



static clsDate DeccreaseDateByOneCentury(clsDate &Date)
 {
	
	 Date.Year -= 100;

	 return Date;
 }

void DeccreaseByOneCentury()
{
	 DeccreaseDateByOneCentury(*this);
}


 static clsDate DeccreaseDateByOneMillennium(clsDate &Date)
 {
	 Date.Year -= 1000;

	 return Date;
 }



 void DeccreaseByOneMillennium()
 {
	  DeccreaseDateByOneMillennium(*this);
 }




 static short NumberofDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
 {

	 short TotalDays = 0;
	 for (short i = 1; i <= Month - 1; i++)

	 {
		 TotalDays += NumberOfDaysInMonth(Year, i);
	 }
	 TotalDays += Day;
	 return TotalDays;

 }


 static bool IsEqualDate1Date2(clsDate Date1, clsDate Date2)
 {


	 return(Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;

 }


 static clsDate AddDaysToDate(short AddDays, clsDate &Date)
 {



	 short RemainingDays = AddDays + NumberofDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
	 short MonthDays = 0;


	 Date.Month = 1;
	 while (true)
	 {
		 MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
		 if (RemainingDays > MonthDays)
		 {
			 RemainingDays -= MonthDays;
			 Date.Month++;
			 if (Date.Month > 12)
			 {
				 Date.Month = 1;
				 Date.Year++;
			 }

		 }
		 else
		 {
			 Date.Day = RemainingDays;
			 break;
		 }
	 }
	 return Date;
 }

 void AddDaysToDate(short AddDays)
 {
	   AddDaysToDate(AddDays, *this);
 }









 string PrintShortNameDay(short Day)

 {
	 string Daysarr[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	 return Daysarr[Day];


 }


  static bool IsEndOfWeek(clsDate Date)
 {
	 return(DayOfWeekOrder(Date.Year,Date.Month,Date.Day) == 6);
 }


  bool IsEndOfWeek()
  {
	  return IsEndOfWeek(*this);
  }


 static  bool IsWeekEnd(clsDate Date)
 {
	 return(DayOfWeekOrder(Date.Year, Date.Month, Date.Day) == 5);
 }



 bool IsWeekEnd()
 {
	 return  IsWeekEnd(*this);
 }

 static bool IsBusinessDay(clsDate Date)
 {
	 return(!IsWeekEnd(Date));
 }

 bool IsBusinessDay()
 {
	 return   IsBusinessDay(*this);
 }


 static short DaysUntilTheEndOfWeek(clsDate Date)
 {
	 return 6 - DayOfWeekOrder(Date.Year,Date.Month,Date.Day);
 }


 short DaysUntilTheEndOfWeek()
 {
	 return  DaysUntilTheEndOfWeek(*this);
 }




static short DaysUntilTheEndOfMonth(clsDate Date)
 {
	// sDate DaysOfCurrentMont;
	 clsDate DaysOfCurrentMont;
	 DaysOfCurrentMont.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
	 DaysOfCurrentMont.Month = Date.Month;
	 DaysOfCurrentMont.Year = Date.Year;


	 return DiffrentBetweenDate1Date2(Date, DaysOfCurrentMont);
}

short DaysUntilTheEndOfMonth()
{
	return  DaysUntilTheEndOfMonth(*this);
}


static short DaysUntilTheEndOfYear(clsDate Date)
 {
	/* sDate DaysOfCurrentMont;*/
	 clsDate DaysOfCurrentMont;
	 DaysOfCurrentMont.Day = 31;
	 DaysOfCurrentMont.Month = 12;
	 DaysOfCurrentMont.Year = Date.Year;

	 return DiffrentBetweenDate1Date2(Date, DaysOfCurrentMont);
 }

short DaysUntilTheEndOfYear()
{
	return  DaysUntilTheEndOfYear(*this);
}



static  short CalcVacationPeriod(clsDate Date1, clsDate Date2)
{

	short Dayscount = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		if (IsBusinessDay(Date1))
			Dayscount++;
		Date1 = IncreaseByOneDay(Date1);

	}
	return Dayscount;
}


short VacationPeriod(clsDate Date2)
{
	return  CalcVacationPeriod(*this, Date2);
}



 static clsDate CalcVactionReturnDate(clsDate startDate, short Days)
 {
	 short counterDays = 0;
	 for (short i = 1; i <= Days; i++)
	 {
		 if (IsWeekEnd(startDate))
			 counterDays++;


		 startDate = IncreaseByOneDay(startDate);
	 }
	 for (short i = 1; i <= counterDays; i++)
		 startDate = IncreaseByOneDay(startDate);
	 while (IsWeekEnd(startDate))
	 {
		 startDate = IncreaseByOneDay(startDate);
	 }

	 return startDate;
 }

  void VactionReturnDate(short Days)
 {
	  *this = CalcVactionReturnDate(*this, Days);
 }



 static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
 {
	 return(!IsDate1BeforeDate2(Date1, Date2) && !IsEqualDate1Date2(Date1, Date2));
 }

 bool IsAfterDate2(clsDate Date2)
 {
	 return IsDate1AfterDate2(*this, Date2);
 }


 enum  eCompareDate{ Before = -1, Equal = 0, After = 1 };



static eCompareDate CompareDates(clsDate Date1, clsDate Date2)
 {
	 if (IsDate1BeforeDate2(Date1, Date2))
		 return eCompareDate::Before;
	 if (IsEqualDate1Date2(Date1, Date2))
		 return eCompareDate::Equal;
	 return eCompareDate::After;
 }



eCompareDate CompareDates(clsDate Date2)
{
	return CompareDates(*this, Date2);
}





 static string PrintDateFormate(clsDate Date, string Format = "dd/mm/yyyy")
{
	string DateFormating = "";
	DateFormating = clsString::ReplaceWord(Format, "dd", to_string(Date.Day));
	DateFormating = clsString::ReplaceWord(DateFormating, "mm", to_string(Date.Month));
	DateFormating = clsString::ReplaceWord(DateFormating, "yyyy", to_string(Date.Year));
	return DateFormating;
}



 string DateFormate(string Format)
 {
	 return  PrintDateFormate(*this, Format);
 }


 static string GetSystemDateTime()
 {

	 time_t t = time(0);
	 tm*now = localtime(&t);
	 short Day, Month, Year, Hour, Min, Sec;
	 Day = now->tm_mday;
	 Month = now->tm_mon + 1;
	 Year = now->tm_year + 1900;
	 Hour = now->tm_hour;
	 Min = now->tm_min;
	 Sec = now->tm_sec;
	 return (to_string(Day) + "/" + to_string(Month) + "/" +
		 to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Min) + ":" + to_string(Sec));
 }
	



};

