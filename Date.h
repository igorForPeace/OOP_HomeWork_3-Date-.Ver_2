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

	int operator - (const Date& first);  // ������� ������� ����� ����� ������ 

	Date operator +(int day); // ��������� � ������� ���� ������������� ���. ����
	
	Date& operator ++(); // ���������� ���������

	Date& operator ++(int value); // ����������� ���������

	Date& operator -- (); // ���������� ���������

	Date& operator -- (int value); // ����������� ���������

	bool operator == (const Date& other); // ���������� ��������� ���������

	bool operator != (const Date& other); // ���������� ��������� �����������

	bool operator < (const Date& other); // �������� ��������� <

	bool operator > (const Date& other); // �������� ��������� >

	friend ostream& operator<<(ostream& os, const Date& date);
	friend istream& operator>>(istream& is, Date& date);
	
	Date& operator()(int day, int month, int year);
};





