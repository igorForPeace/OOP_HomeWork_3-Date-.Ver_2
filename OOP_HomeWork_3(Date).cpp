#include "Date.h"
#include "Time.h"

ostream& operator<<(ostream& os,const Date& date)
{
	os << "����: " << date.Get_day() << " ";
	os << "�����: " << date.Get_month() << " ";
	os << "���: " << date.Get_year() << endl;
	return os;
}

ostream& operator<<(ostream& os, const Time& time)
{
	os << time.Get_hours() << " : ";
	os << time.Get_minutes() << " : ";
	os << time.Get_seconds() << endl;
	return os;
}

istream& operator>>(istream& is, Date& date)
{
	is >> date.day;
	is >> date.month;
	is >> date.year;
	return is;
}

istream& operator>>(istream& is, Time& time)
{
	is >> time.seconds;
	is >> time.minutes;
	is >> time.hours;
	return is;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	//������� �� ������ � ������
	
	//Date A(6, 2, 2021);
	//Date B(5, 2, 2020);
	//
	//bool result = A > B;
	//cout << boolalpha << result << endl;

	//bool result_2 = A != B;
	//cout << boolalpha << result_2 << endl;

	//int b = A - B;  // ������� � ���� ����� ����� ������
	//cout << b << endl;

	//A = A + 20;  // ���������� � ���� �������������� �������� ��� ��������� ����
	//A.Show_date();
	//A--; // ������ �������������� ���������� ������������ � ����������� ����������\����������
	//A.Show_date();
	//cout << endl;

	// ������� �� ������ � ��������

	/*Time a(40, 59, 23);
	a.Print_time();
	a=a + 120;
	a.Print_time();
	cout << endl;

	Time b(59, 59, 23);
	b.Print_time();
	++b;
	b.Print_time();
	b++;
	b.Print_time();

	cout << endl;
	Time c(0, 59, 23);
	c--;
	c.Print_time();
	--c;
	c.Print_time();

	cout << endl;
	Time d(1, 45, 22);
	Time f(1, 43, 22);
	bool diff = d > f;
	cout <<boolalpha<< diff << endl;*/



	// ���������� ��������� >> <<
	/*Date A;
	Date G(14, 5, 1997);
	cout << A<<endl;
	cout << G << endl;
	Time B;
	Time C(12, 45, 2);
	cout << B << endl;
	cout << C << endl;*/
	/*Date a;
	cout << a;
	cin >> a;
	cout << a;*/

	/*Time a;
	cout << a;
	cin >> a;
	cout << a;*/


	// ���������� ��������� ()
	/*Date a;
	a.Show_date();
	a(23, 5, 2056);
	a.Show_date();*/


	/*Time a;
	a.Print_time();
	a(45, 23, 4);
	a.Print_time();*/


	
	
	

	return 0;
	
}