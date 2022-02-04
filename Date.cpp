#include "Date.h"

Date::Date()
{
	day = 15;
	month = 1;
	year = 2022;
}

Date::Date(int day, int month, int year)
{

	this->year = year;
	if (day >= 1 && day <= 31)
	{
		this->day = day;
	}
	else
	{
		throw "OPPS!";
	}

	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		throw "OPPS!";
	}
	
}

void Date::Set_day(int day)
{
	if (day >= 1 && day <= 31)
	{
		this->day = day;
	}
	else
	{
		throw "OOPS!";
	}
}

int Date::Get_day() const
{
	return day;
}

void Date::Set_month(int month)
{
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		throw "OPPS!";
	}
}

int Date::Get_month() const
{
	return month;

}

void Date::Set_year(int year)
{
	this->year = year;
}

int Date::Get_year() const
{
	return year;
}

void Date::Show_date()
{
	cout << "число: " << Get_day() << ", ";
	cout << "мес€ц: " << Get_month() << ", ";
	cout << "год: " << Get_year() << endl;
}

int Date::operator - (const Date& first)  // выводит разницу между двум€ датами в дн€х
{
	return ((this->Get_year() * 365) + (this->Get_month() * 31) + this->Get_day()) -
		((first.Get_year() * 365) + (first.Get_month() * 31) + first.Get_day());
}

Date Date::operator +(int day)  // увеливает дату на задданное количество дней
{
	Date temp;
	if (day <= 30)
	{
		if ((this->day + day) > 31)
		{
			temp.day = this->day + day - 31;
			if (this->month == 12)
			{
				temp.month = 1;
				temp.year = ++this->year;
				return temp;
			}
			else
			{
				temp.month = this->month;
				temp.year = this->year;
				return temp;
			}
		}
		else
		{
			temp.day = this->day + day;
			temp.month = this->month;
			temp.year = this->year;
			return temp;
		}
	}
	else
	{
		int b = day / 31;
		if (day % 31 == 0)
		{
			temp.day = this->day;
			if (this->month + b > 12)
			{
				temp.month = this->month + b - 12;
				temp.year = ++this->year;
				return temp;
			}
			else
			{
				temp.month = this->month + b;
				temp.year = this->year;
				return temp;
			}
		}
		else
		{
			if (this->day + day % 31 <= 31)
			{
				temp.day = this->day + day % 31;
				if (this->month + b <= 12)
				{
					temp.month = this->month + b;
					temp.year = this->year;
					return temp;
				}
				else
				{
					temp.month = this->month + b - 12;
					temp.year = ++this->year;
					return temp;
				}
			}
			else
			{
				temp.day = this->day + day % 31 - 31;
				if (this->month + b <= 12)
				{
					temp.month = ++this->month + b;
					temp.year = this->year;
					return temp;
				}
				else
				{
					temp.month = ++this->month + b - 12;
					temp.year = ++this->year;
					return temp;
				}
			}
		}
	}
}

Date& Date::operator ++() // префиксный инкримент
{
	if (this->day != 31)
	{
		this->day++;
		return *this;
	}
	else
	{
		this->day = 1;
		if (this->month != 12)
		{
			this->month++;
			return *this;
		}
		else
		{
			this->month = 1;
			this->year++;
			return *this;
		}
	}
}

Date& Date:: operator ++(int value)
{
	Date temp(*this);
	if (this->day != 31)
	{
		this->day++;
		return temp;
	}
	else
	{
		this->day = 1;
		if (this->month != 12)
		{
			this->month++;
			return temp;
		}
		else
		{
			this->month = 1;
			this->year++;
			return temp;
		}
	}
}

Date& Date:: operator -- () // префиксный декремент
{
	if (this->day != 1)
	{
		this->day--;
		return *this;
	}
	else
	{
		this->day = 31;
		if (this->month != 1)
		{
			this->month--;
			return *this;
		}
		else
		{
			this->month = 12;
			this->year--;
			return *this;
		}
	}
}

Date& Date::operator -- (int value) // постфиксный декремент 
{
	Date temp(*this);
	if (this->day != 1)
	{
		this->day--;
		return temp;
	}
	else
	{
		this->day = 31;
		if (this->month != 1)
		{
			this->month--;
			return temp;
		}
		else
		{
			this->month = 12;
			this->year--;
			return temp;
		}
	}
}

bool Date::operator == (const Date& other)
{
	return this->day == other.day && this->month == other.month && this->year == other.year;
}

bool Date::operator != (const Date& other)
{
	return !(this->day == other.day && this->month == other.month && this->year == other.year);
}

bool Date::operator < (const Date&other)
{
	if (this->year == other.year && this->month == other.month)
	{
		return this->day < other.day;
	}
	else if (this->year == other.year)
	{
		return this->month < other.month;
	}
	else
	{
		return this->year < other.year;
	}
}

bool Date:: operator >(const Date& other)
{
	if (this->year == other.year && this->month == other.month)
	{
		return this->day > other.day;
	}
	else if (this->year == other.year)
	{
		return this->month > other.month;
	}
	else
	{
		return this->year > other.year;
	}
}

Date& Date:: operator()(int day, int month, int year)
{
	this->year = year;
	if (day >= 1 && day <= 31)
	{
		this->day = day;
	}
	else
	{
		throw "OPPS!";
	}
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		throw "OPPS!";
	}
	return *this;
}


