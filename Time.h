#pragma once
#include "AllLibreries.h"
class Time
{
private:
	int seconds;
	int minutes;
	int hours;
public:
	Time();
	Time(int seconds, int minutes, int hours);

	void Set_seconds(int second);
	int Get_seconds() const;

	void Set_minutes(int minutes);
	int Get_minutes() const;

	void Set_hours(int hours);
	int Get_hours() const;

	void Print_time();

	Time operator + (int seconds); // метод добавления ко времени секунд

	Time& operator ++(); // префиксный инкремент

	Time& operator ++(int value); // постфиксный декремент

	Time& operator -- (); // префиксный декремент

	Time& operator -- (int value); // постфиксный декремент

	bool operator == (const Time& other); // перегрузка оператора равенства

	bool operator != (const Time& other); // перегрузка оператора неравенства

	bool operator < (const Time& other); // оператор сравнения <

	bool operator > (const Time& other); // оператор сравнения >

	friend ostream& operator<<(ostream& os, const Time& time);
	friend istream& operator>>(istream& is, Time& time);

	Time& operator()(int seconds, int minutes, int hours);

};

