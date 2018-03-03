#pragma once
#include <iostream>
using namespace std;


class TimeSpan
{
	friend ostream& operator<<(ostream &outstream, const TimeSpan &Print);
	friend istream& operator>>(istream &instream, const TimeSpan &Input);

public:
	TimeSpan();
	~TimeSpan();
	TimeSpan(const int hoursin, const int minin, const int secin);
	TimeSpan(const int secin);
	TimeSpan(int minin, int secin);
	TimeSpan(const double hoursin, const double minin, const double secin);
	TimeSpan(const double secin);
	TimeSpan(const double minin, const double secin);

	TimeSpan(const double hoursin, const int minin, const int secin);  
	TimeSpan(const double hoursin, const double minin, const int secin);   
	TimeSpan(const int hoursin, const int minin, const double secin);
	TimeSpan(const int hoursin, const double minin, const double secin); 
	TimeSpan(const int hoursin, const double minin, const int secin); 
	TimeSpan(const double hoursin, const int minin, const double secin); 

	TimeSpan(const int minin, const double secin);
	TimeSpan(const double minin, const int secin);

	int getHours() const; 
	int getMinutes() const; 
	int getSeconds() const;
	bool setTime(const int hours,const int minutes,const int seconds);

	TimeSpan operator+(const TimeSpan &TimeSpan2);
	TimeSpan operator-(const TimeSpan &TimeSpan2);
	TimeSpan operator-();
	bool operator==(const TimeSpan &TimeSpan2);
	bool operator!=(const TimeSpan &TimeSpan2);
	TimeSpan& operator+=(const TimeSpan &TimeSpan2);
	TimeSpan& operator-=(const TimeSpan &TimeSpan2);





private:
	int Hours = 0;
	int Minutes = 0;
	int Seconds = 0;



};
