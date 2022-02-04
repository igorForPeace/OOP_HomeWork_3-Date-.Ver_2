#pragma once
#include "AllLibreries.h"

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date( int day, int month, int year );

	void Set_day(int day);
	int Get_day() const;

	void Set_month(int month);
	int Get_month() const;

	void Set_year(int year);
	int Get_year() const;

	void Show_date();

	int operator - (const Date& first);  // выводит разницу между двумя датами 

	Date operator +(int day); // добавляет к текущей дате целочисленное кол. дней
	
	Date& operator ++(); // префиксный инкремент

	Date& operator ++(int value); // постфиксный декремент

	Date& operator -- (); // префиксный декремент

	Date& operator -- (int value); // постфиксный декремент

	bool operator == (const Date& other); // перегрузка оператора равенства

	bool operator != (const Date& other); // перегрузка оператора неравенства

	bool operator < (const Date& other); // оператор сравнения <

	bool operator > (const Date& other); // оператор сравнения >

	friend ostream& operator<<(ostream& os, const Date& date);
	friend istream& operator>>(istream& is, Date& date);
	
	Date& operator()(int day, int month, int year);
};





