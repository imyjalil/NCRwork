#include "pch.h"
#include <iostream>
using namespace std;
class Time
{
	int hours, minutes, seconds;
	public:
	Time()
	{
		hours = 0; minutes = 0; seconds = 0;
	}
	Time(int hour, int minute, int second)
	{
		hours = hour; minutes = minute; seconds = second;
	}
	void display()
	{
		cout << "Time is: ";
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}
	Time addTime(Time time1, Time time2)
	{
		Time time3;
		time3.hours = time1.hours + time2.hours;
		time3.minutes = time1.minutes + time2.minutes;
		time3.seconds = time1.seconds + time2.seconds;
		if (time3.seconds > 60)
		{
			time3.minutes++;
			time3.seconds -= 60;
		}
		if (time3.minutes > 60)
		{
			time3.hours++;
			time3.minutes -= 60;
		}
		if (time3.hours > 24)
		{
			time3.hours = 0;
		}
		return time3;
	}
};
int main()
{
	int hours = 0, minutes = 0, seconds = 0;
	Time time1;
	cout << "Enter hours" << endl; cin >> hours;
	cout << "Enter minutes" << endl; cin >> minutes;
	cout << "Enter seconds" << endl; cin >> seconds;
	if (hours >= 24 || hours < 0 || minutes >= 60 || minutes < 0 || seconds >= 60 || seconds < 0)
	{
		cout << "Invalid time" << endl; return 0;
	}
	Time time2(hours, minutes, seconds);
	Time time3 = time3.addTime(time1, time2);
	time3.display();
}