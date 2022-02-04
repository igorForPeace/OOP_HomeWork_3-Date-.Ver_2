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

	Time operator + (int seconds); // ����� ���������� �� ������� ������

	Time& operator ++(); // ���������� ���������

	Time& operator ++(int value); // ����������� ���������

	Time& operator -- (); // ���������� ���������

	Time& operator -- (int value); // ����������� ���������

	bool operator == (const Time& other); // ���������� ��������� ���������

	bool operator != (const Time& other); // ���������� ��������� �����������

	bool operator < (const Time& other); // �������� ��������� <

	bool operator > (const Time& other); // �������� ��������� >

	friend ostream& operator<<(ostream& os, const Time& time);
	friend istream& operator>>(istream& is, Time& time);

	Time& operator()(int seconds, int minutes, int hours);

};

