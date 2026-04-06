#include <iostream>
#include "MyLib.h";


stDate AgeCalculatorBeforDevelopement(stDate Date, stDate BirthdayDate)
{

	stDate AgeDate;

	
	AgeDate.Day = 30 - BirthdayDate.Day + Date.Day;
	AgeDate.Month = 12 - BirthdayDate.Month - 1 + Date.Month;
	AgeDate.Year = Date.Year - BirthdayDate.Year - 1;
	   
	
	 if (AgeDate.Day >= 30)
	 {
		 AgeDate.Day = AgeDate.Day - 30;

		 AgeDate.Month++;

	 }

	 if (AgeDate.Month >= 12)
	 {
		AgeDate.Month= AgeDate.Month - 12;

		AgeDate.Year++;

	}


	 return AgeDate;
}

stDate AgeCalculatorBeforDevelopement2(stDate Date, stDate BirthdayDate)
{
	stDate AgeDate;
	short MonthDays = MyLib::DataTime::NumberOfDaysInMonth(BirthdayDate.Year, BirthdayDate.Month);

	if (Date.Month > BirthdayDate.Month)
	{
		if (Date.Day == BirthdayDate.Day)
		{
			AgeDate.Day = 0;
			AgeDate.Year = Date.Year - BirthdayDate.Year;
			AgeDate.Month = Date.Month - BirthdayDate.Month;
		}
		else
		{

			if (Date.Month == 1)
			{
				MonthDays = MyLib::DataTime::NumberOfDaysInMonth(Date.Year, 12);

			}
			else
			{
				MonthDays = MyLib::DataTime::NumberOfDaysInMonth(Date.Year, Date.Month - 1);
			}

			AgeDate.Day = MonthDays - BirthdayDate.Day + Date.Day;

			if (AgeDate.Day > 30)
			{
				AgeDate.Day -= 30;
				AgeDate.Month++;

			}


			BirthdayDate.Month++;

			AgeDate.Month = AgeDate.Month + (Date.Month - BirthdayDate.Month);
			AgeDate.Year = Date.Year - BirthdayDate.Year;
		}
	}
	else if (Date.Month < BirthdayDate.Month)
	{
		if (Date.Day == BirthdayDate.Day)
		{
			BirthdayDate.Year++;
			AgeDate.Day = 0;
			AgeDate.Year = Date.Year - BirthdayDate.Year;
			AgeDate.Month = 12 - BirthdayDate.Month + Date.Month;
		}

		else
		{


			if (Date.Month == 1)
			{
				MonthDays = MyLib::DataTime::NumberOfDaysInMonth(Date.Year, 12);

			}
			else
			{
				MonthDays = MyLib::DataTime::NumberOfDaysInMonth(Date.Year, Date.Month - 1);
			}


			AgeDate.Day = MonthDays - BirthdayDate.Day + Date.Day;



			if (AgeDate.Day > 30)
			{
				AgeDate.Day -= 30;
				AgeDate.Month++;

			}

			BirthdayDate.Month++;
			AgeDate.Month += (12 - BirthdayDate.Month) + Date.Month;
			BirthdayDate.Year++;
			AgeDate.Year = Date.Year - BirthdayDate.Year;

		}
	}
	else
	{
		if (BirthdayDate.Day > Date.Day)
		{
			if (Date.Month == 1)
			{
				MonthDays = MyLib::DataTime::NumberOfDaysInMonth(Date.Year, 12);

			}
			else
			{
				MonthDays = MyLib::DataTime::NumberOfDaysInMonth(Date.Year, Date.Month - 1);
			}



			AgeDate.Day = MonthDays - BirthdayDate.Day + Date.Day;

			if (AgeDate.Day > 30)
			{
				AgeDate.Day -= 30;
				AgeDate.Month++;

			}

			BirthdayDate.Month++;
			BirthdayDate.Year++;
			AgeDate.Month += (12 - BirthdayDate.Month) + Date.Month;
			AgeDate.Year = Date.Year - BirthdayDate.Year;


		}
		else
		{

			AgeDate.Day = Date.Day - BirthdayDate.Day;
			AgeDate.Month = 0;
			AgeDate.Year = Date.Year - BirthdayDate.Year;
		}
	}
	return AgeDate;

}

stDate AgeCalculator(stDate Date, stDate BirthdayDate)
{

	stDate AgeDate;

	if (Date.Day < BirthdayDate.Day)
	{
		short PrevMonth = (Date.Month == 1) ? 12 : Date.Month - 1;
		short PrevYear = (Date.Month == 1) ? Date.Year - 1 : Date.Year;
		Date.Day += MyLib::DataTime::NumberOfDaysInMonth(PrevYear, PrevMonth);
		Date.Month--;
	}

	AgeDate.Day = abs(Date.Day - BirthdayDate.Day);


	if (Date.Month < BirthdayDate.Month)
	{
		Date.Month += 12;
		Date.Year--;
	}

	AgeDate.Month = Date.Month - BirthdayDate.Month;

	AgeDate.Year = Date.Year - BirthdayDate.Year;

	return AgeDate;
}

stDate  NextBirthdayCalculator(stDate Date, stDate BirthdayDate)
{

	stDate Christmas;

	if (Date.Day > BirthdayDate.Day)
	{
		short PrevMonth = (BirthdayDate.Month == 1) ? 12 : BirthdayDate.Month - 1;
		short PrevYear = (BirthdayDate.Month == 1) ? BirthdayDate.Year - 1 : BirthdayDate.Year;
		BirthdayDate.Day += MyLib::DataTime::NumberOfDaysInMonth(PrevYear, PrevMonth);
		BirthdayDate.Month--;
	}
	Christmas.Day = BirthdayDate.Day - Date.Day;

	if (Date.Month > BirthdayDate.Month)
	{
		Christmas.Month = (12 - Date.Month + BirthdayDate.Month);
	}
	else if (Date.Month < BirthdayDate.Month)
	{
		
		Christmas.Month = BirthdayDate.Month - Date.Month;
	}
	else
	{
		Christmas.Month = 0;
	}

	return Christmas;

}

stAgeCustom AgeCalculatorCustom(stDate Date, stDate BirthdayDate, stDate AgeDate)
{
	stAgeCustom AgeCustom;
	int TotalDays = 0;

	TotalDays = MyLib::DataTime::GetDeferanceInDays(BirthdayDate, Date);

	AgeCustom.Days = TotalDays;
	AgeCustom.Week = AgeCustom.Days / 7;
	AgeCustom.Hours = AgeCustom.Days * 24;
	AgeCustom.Min = AgeCustom.Hours * 60;
	AgeCustom.Month = AgeDate.Year * 12 + AgeDate.Month;

	return AgeCustom;
}

void PrintAgePerson(stDate AgeDate, stDate BirthdayDate, stDate InfoData, stDate Christmas, stAgeCustom AgeCustom, string DayShortName)
{


	cout << "Data Now   : " << InfoData.Year << "/" << InfoData.Month << "/" << InfoData.Day << endl;
	cout << "Year Birth : " << BirthdayDate.Year << "/" << BirthdayDate.Month << "/" << BirthdayDate.Day << endl;

	cout << "______________________________________________\n\n";

	cout << "Your Age Is :";
	if (AgeDate.Month == 0 && AgeDate.Year == 0)
		cout << AgeDate.Day << " Day \n";
	else if (AgeDate.Day == 0 && AgeDate.Year == 0)
		cout << AgeDate.Month << " Month \n";
	else if (AgeDate.Day == 0 && AgeDate.Month == 0)
		cout << AgeDate.Year << " Year \n";
	else if (AgeDate.Day == 0)
		cout << AgeDate.Year << " Year And " << AgeDate.Month << " Month \n";
	else if (AgeDate.Year == 0)
		cout << AgeDate.Month << " Month And " << AgeDate.Day << " Day \n";
	else if (AgeDate.Month == 0)
		cout << AgeDate.Year << " Year And " << AgeDate.Day << " Day \n";
	else
		cout << AgeDate.Year << " Year And " << AgeDate.Month << " Month And " << AgeDate.Day << " Day \n";


	cout << "You Were Born In The Day : " << DayShortName << endl;


	if (Christmas.Month == 0 && Christmas.Day == 0)
		cout << "Your Next Birthday Is : " << "Happy Birthday :)\n";
	else if (Christmas.Month == 0)
		cout << "Your Next Birthday Is : " << Christmas.Day << " Day \n";
	else if (Christmas.Day == 0)
		cout << "Your Next Birthday Is : " << Christmas.Month << " Month \n";
	else
		cout << "Your Next Birthday Is : " << Christmas.Month << " Month And " << Christmas.Day << " Day\n";

	cout << "----------------------------------------------\n";

	cout << "Your Age In Months   Is : " << AgeCustom.Month << endl;
	cout << "Your Age In Weeks    Is : " << AgeCustom.Week << endl;
	cout << "Your Age In Days     Is : " << AgeCustom.Days << endl;
	cout << "Your Age In Hours    Is : " << AgeCustom.Hours << endl;
	cout << "Your Age In Minutes  Is : " << AgeCustom.Min << endl;

	cout << "______________________________________________\n\n";

}

void ReadAgeAndData(stDate& BirthdayDate, stDate& InfoDate)
{
	do
	{
		cout << "Enter Date Now:\n";
		cout << "----------------------------------\n";
		InfoDate = MyLib::DataTime::ReadFullDate();

		cout << "\nEnter Date Of Birth:\n";
		cout << "----------------------------------\n";
		BirthdayDate = MyLib::DataTime::ReadFullDate();
		cout << "----------------------------------\n";

		if ((BirthdayDate.Year > InfoDate.Year) ||
			(BirthdayDate.Year == InfoDate.Year && BirthdayDate.Month > InfoDate.Month) ||
			(BirthdayDate.Year == InfoDate.Year && BirthdayDate.Month == InfoDate.Month && BirthdayDate.Day > InfoDate.Day))
		{
			cout << "Sorry Please Enter The Correct Date:\n";

		}
	} while ((BirthdayDate.Year > InfoDate.Year) ||
		(BirthdayDate.Year == InfoDate.Year && BirthdayDate.Month > InfoDate.Month) ||
		(BirthdayDate.Year == InfoDate.Year && BirthdayDate.Month == InfoDate.Month && BirthdayDate.Day > InfoDate.Day));


}

int main()
{
	stDate BirthdayDate;
	stDate InfoData;
	stDate AgeDate;
	stDate Christmas;
	stAgeCustom AgeCustom;

	char TryAgain = 'y';

	do {

	MyLib::PrintOutPut::ResetScreen();

	ReadAgeAndData(BirthdayDate,InfoData);

	short DayOfWeekOreder = MyLib::DataTime::DayOfWeekOrder(BirthdayDate.Year, BirthdayDate.Month, BirthdayDate.Day);
	string DayShortName = MyLib::DataTime::DayShortName(DayOfWeekOreder);

	AgeDate = AgeCalculator(InfoData, BirthdayDate);
	Christmas = NextBirthdayCalculator(InfoData, BirthdayDate);
	AgeCustom = AgeCalculatorCustom(InfoData, BirthdayDate, AgeDate);

	PrintAgePerson(AgeDate, BirthdayDate, InfoData, Christmas,AgeCustom, DayShortName);


	cout << "Do You Want Calculed Age Try Again ? Y/N" << endl;
	cin >> TryAgain;
	cout << endl;

	} while (TryAgain == 'y' || TryAgain == 'Y');

	system("Pause>0");
	return 0;
}

