#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
class clsPeriod
{


private:

	clsDate _Start;
	clsDate _End;

public:





	clsPeriod(clsDate Start, clsDate End)
	{
		_Start = Start;
		_End = End;
	}


	void SetStart(clsDate Start)
	{
		_Start = Start;
	}

	clsDate GetStart()
	{
		return _Start;
	}

	__declspec(property(get = GetStart, put = SetStart))clsDate Start;


	void SentEnd(clsDate End)
	{
		_End = End;
	}



	clsDate GetEnd()
	{
		return _End;
	}

	__declspec(property(get = GetEnd, put = SentEnd))clsDate End;



	static bool IsOverLapPeriod(clsPeriod Period1, clsPeriod Period2)
	{

		if (clsDate::CompareDates(Period2.End, Period1.Start) == clsDate::eCompareDate::Before ||
			clsDate::CompareDates(Period2.Start, Period1.End) == clsDate::eCompareDate::After)
			return false;
		else
			return true;



	}


	bool IsOverLap(clsPeriod Period2)
	{
		return IsOverLapPeriod(*this, Period2);
	}






	static short PeriodLengthInDays(clsPeriod Period, bool IncludeEndDay = false)
	{
		return(clsDate::DiffrentBetweenDate1Date2(Period.Start, Period.End, IncludeEndDay));
	}




	short LengthInDays(bool IncludeEndDay = false)
	{
		return  PeriodLengthInDays(*this, IncludeEndDay);
	}



	static bool IsDateInPeriod(clsPeriod Period, clsDate Date)
	{
		return !(clsDate::CompareDates(Date, Period.Start) ==clsDate::eCompareDate::Before

			||clsDate::CompareDates(Date, Period.End) == clsDate::eCompareDate::After);
	}



	bool IsDateInPeriod(clsDate Date)
	{
		return  IsDateInPeriod(*this, Date);
	}





	static int CountOverLap(clsPeriod Period1, clsPeriod Period2)
	{

		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		int counter = 0;
		if (!IsOverLapPeriod(Period1, Period2))
			return 0;
		if (Period1Length < Period2Length)
		{
			while (clsDate::IsDate1BeforeDate2(Period1.Start, Period1.End))
			{
				if (IsDateInPeriod(Period2, Period1.Start))
					counter++;
				Period1.Start =clsDate::IncreaseByOneDay(Period1.Start);
			}
			return counter;
		}
		else
		{
			while (clsDate::IsDate1BeforeDate2(Period2.Start, Period2.End))
			{
				if (IsDateInPeriod(Period1, Period2.Start))
					counter++;
				Period2.Start = clsDate::IncreaseByOneDay(Period2.Start);
			}
		}
		return counter;



	}



	int CountOverLap(clsPeriod Period2)
	{
		return   CountOverLap(*this, Period2);
	
	
	
	
	
	
	
	
	
	
	
	}

	
};

