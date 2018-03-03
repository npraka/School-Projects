#include "TimeSpan.h"
#include <iostream>
#include <math.h>
using namespace std;



ostream&:: operator<<(ostream &outstream, const TimeSpan &Print)

{
	outstream << "Hours: " << Print.getHours() << " Minutes: " << Print.getMinutes() << " Seconds: " << Print.getSeconds() << endl;
	return outstream;

}

istream&:: operator>>(istream &instream, const TimeSpan &Input)

{
	int hourIn;
	int minIn;
	int secIn;

	instream >> hourIn >> minIn >> secIn;
	TimeSpan User(hourIn, minIn, secIn);
	cout << "New TimeSpan Created!" << endl;

	return instream;

}

TimeSpan::TimeSpan()
{

}

TimeSpan::~TimeSpan()
{

}

TimeSpan::TimeSpan(const int hoursin, const int minin,const int secin)
{
	setTime(hoursin, minin, secin);
}

TimeSpan::TimeSpan(const int secin)
{
	setTime(0, 0, secin);
}

TimeSpan::TimeSpan(int minin, int secin)
{
	setTime(0, minin, secin);
}

TimeSpan::TimeSpan(const double hoursin, const double minin, const double secin)
{
	double TotalSecs = 0;
	TotalSecs += hoursin * 3600;
	TotalSecs += minin * 60;
	TotalSecs += secin;
	int TotalSecsInt = (int)round(TotalSecs);
	setTime(0, 0, TotalSecsInt);

}

TimeSpan::TimeSpan(const double secin)
{
	int TotalSecsInt = (int)round(secin);
	setTime(0, 0, TotalSecsInt);
}

TimeSpan::TimeSpan(const double minin, const double secin)
{
	double TotalSecsd = 0;
	TotalSecsd += minin * 60;
	TotalSecsd += secin;
	int TotalSecsInt = (int)round(TotalSecsd);
	setTime(0, 0, TotalSecsInt);
}

TimeSpan::TimeSpan(const double hoursin, const int minin, const int secin)
{
	double TotalSecsd = 0;
	TotalSecsd += hoursin * 3600;
	int TotalSecsi  = 0;
	TotalSecsi  += minin * 60;
	TotalSecsi  += secin;
	int TotalSecsInt = (int)round(TotalSecsd) + TotalSecsi ;
	setTime(0, 0, TotalSecsInt);
}
TimeSpan::TimeSpan(const double hoursin, const double minin, const int secin)
{
	double TotalSecsd = 0;
	TotalSecsd += hoursin * 3600;
	int TotalSecsi  = 0;
	TotalSecsd += minin * 60;
	TotalSecsi  += secin;
	int TotalSecsInt = (int)round(TotalSecsd) + TotalSecsi ;
	setTime(0, 0, TotalSecsInt);
}
TimeSpan::TimeSpan(const int hoursin, const int minin, const double secin)
{	
	int TotalSecsi  = 0;
	double TotalSecsd = 0;
	TotalSecsi  += hoursin * 3600;
	TotalSecsi  += minin * 60;
	TotalSecsd += secin;
	int TotalSecsInt = (int)round(TotalSecsd) + TotalSecsi ;
	setTime(0, 0, TotalSecsInt);
}
TimeSpan::TimeSpan(const int hoursin, const double minin, const double secin)
{
	int TotalSecsi  = 0;
	double TotalSecsd = 0;
	TotalSecsi  += hoursin * 3600;
	TotalSecsd += minin * 60;
	TotalSecsd += secin;
	int TotalSecsInt = (int)round(TotalSecsd) + TotalSecsi ;
	setTime(0, 0, TotalSecsInt);
}
TimeSpan::TimeSpan(const int hoursin, const double minin, const int secin)
{
	int TotalSecsi  = 0;
	double TotalSecsd = 0;
	TotalSecsi  += hoursin * 3600;
	TotalSecsd += minin * 60;
	TotalSecsi  += secin;
	int TotalSecsInt = (int)round(TotalSecsd) + TotalSecsi ;
	setTime(0, 0, TotalSecsInt);
}
TimeSpan::TimeSpan(const double hoursin, const int minin, const double secin)
{
	int TotalSecsi  = 0;
	double TotalSecsd = 0;
	TotalSecsd += hoursin * 3600;
	TotalSecsi  += minin * 60;
	TotalSecsd += secin;
	int TotalSecsInt = (int)round(TotalSecsd) + TotalSecsi ;
	setTime(0, 0, TotalSecsInt);
}
TimeSpan::TimeSpan(const int minin, const double secin)
{
	int TotalSecsi = 0;
	double TotalSecsd = 0;
	TotalSecsi += minin * 60;
	TotalSecsd += secin;
	int TotalSecsInt = (int)round(TotalSecsd) + TotalSecsi;
	setTime(0, 0, TotalSecsInt);

}
TimeSpan::TimeSpan(const double minin, const int secin)
{
	int TotalSecsi = 0;
	double TotalSecsd = 0;
	TotalSecsd += minin * 60;
	TotalSecsi += secin;
	int TotalSecsInt = (int)round(TotalSecsd) + TotalSecsi;
	setTime(0, 0, TotalSecsInt);
}


int TimeSpan::getHours() const
{
	 return Hours;
}
 
int TimeSpan::getMinutes() const
 {
	 return Minutes;
 }

int TimeSpan:: getSeconds() const
 {
	 return Seconds;
 }

bool TimeSpan:: setTime(const int hours,const int minutes,const int seconds)
{
	

	int TotalSecs=0;
	TotalSecs += hours * 3600;
	TotalSecs += minutes * 60;
	TotalSecs += seconds;

	if (TotalSecs % 60 != 0)//Narrows down Minutes
	{
		Seconds = TotalSecs % 60;
		Minutes = (TotalSecs - (TotalSecs % 60)) / 60;
	}
	else
	{
		Minutes = TotalSecs/60;
	}

	if (Minutes >=60) //Adds an hour for every 60 minutes
	{
		Hours = (Minutes - (Minutes % 60)) / 60;
		Minutes = Minutes % 60;
		
	}
	else if (Minutes <= -60)
	{
		Hours = (Minutes + (Minutes % 60)) / 60;
		Minutes = Minutes % 60;
	}

	return true;

}
TimeSpan TimeSpan:: operator+(const TimeSpan &TimeSpan2)
{
	TimeSpan AddSpan = *this += TimeSpan2;
	return AddSpan;
}

TimeSpan TimeSpan::operator-(const TimeSpan &TimeSpan2)
{
	TimeSpan SubSpan= *this -= TimeSpan2;
	return SubSpan;

}

TimeSpan TimeSpan:: operator-()
{
	TimeSpan Negative(-Hours, -Minutes, -Seconds);


	return Negative;
}
bool TimeSpan:: operator==(const TimeSpan &TimeSpan2)
{
	return (Hours == TimeSpan2.Hours) && (Minutes == TimeSpan2.Minutes) && (Seconds == TimeSpan2.Seconds);
}

bool TimeSpan:: operator!=(const TimeSpan &TimeSpan2)
{
	if ((Hours == TimeSpan2.Hours) && (Minutes == TimeSpan2.Minutes) && (Seconds == TimeSpan2.Seconds))
	{
		return false;
	}
	else
	{
        return true;
	}
	
}

TimeSpan& TimeSpan::operator+=(const TimeSpan &TimeSpan2)
{
	Hours += TimeSpan2.getHours();
	Minutes += TimeSpan2.getMinutes();
	Seconds += TimeSpan2.getSeconds();
	return *this;

}

TimeSpan& TimeSpan::operator-=(const TimeSpan &TimeSpan2)
{
	Hours -= TimeSpan2.getHours();
	Minutes -= TimeSpan2.getMinutes();
	Seconds -= TimeSpan2.getSeconds();
	return *this;
}
