#include "Time.h"

Time::Time()
{
	seconds = 30;
	minutes = 39;
	hours = 15;
}

Time::Time(int seconds, int minutes, int hours)
{
	if (seconds >= 0 && seconds <= 59)
	{
		this->seconds = seconds;
	}
	else
	{
		throw "OPPS!";
	}
	if (minutes >= 0 && minutes <= 59)
	{
		this->minutes = minutes;
	}
	else
	{
		throw "OPPS!";
	}
	if (hours >= 0 && hours <= 23)
	{
		this->hours = hours;
	}
	else
	{
		throw "OPPS!";
	}
}

void Time::Set_seconds(int seconds)
{
	if (seconds >= 0 && seconds <= 59)
	{
		this->seconds = seconds;
	}
	else
	{
		throw "OPPS!";
	}
}

int Time::Get_seconds()const
{
	return seconds;
}

void Time::Set_minutes(int minutes)
{
	if (minutes >= 0 && minutes <= 59)
	{
		this->minutes = minutes;
	}
	else
	{
		throw "OPPS!";
	}
}

int Time::Get_minutes() const
{
	return minutes;
}

void Time::Set_hours(int hours)
{
	if (hours >= 0 && hours <= 23)
	{
		this->hours = hours;
	}
	else
	{
		throw "OPPS!";
	}
}

int Time::Get_hours() const
{
	return hours;
}

void Time::Print_time()
{
	cout << "Текущее время: " << endl;
	cout << "секунд: " << Get_seconds() << " ,";
	cout << "минут: " << Get_minutes() << " ,";
	cout << "часов: " << Get_hours() << endl;
}

Time Time::operator + (int seconds)
{
	Time temp;
	if (seconds <= 59)
	{
		if (this->seconds + seconds >= 60)
		{
			temp.seconds = this->seconds + seconds - 60;
			if (this->minutes + 1 == 60)
			{
				temp.minutes = 0;
				if (this->hours + 1 == 24)
				{
					temp.hours = 0;
					return temp;
				}
				else
				{
					temp.hours = this->hours + 1;
					return temp;
				}
			}
			else
			{
				temp.minutes = this->minutes + 1;
				temp.hours = this->hours;
				return temp;
			}
			
		}
		else
		{
			temp.seconds =this->seconds + seconds;
			temp.minutes = this->minutes;
			temp.hours = this->hours;
			return temp;
		}
	}
	else
	{
		int b = seconds / 60; 
		if (seconds % 60 == 0)
		{
			temp.seconds = this->seconds;
			if (this->minutes + b >= 60)
			{
				temp.minutes = this->minutes + b - 60;
				if (this->hours + 1 == 24)
				{
					temp.hours = 0;
					return temp;
				}
				else
				{
					temp.hours = ++this->hours;
					return temp;
				}
			}
			else
			{
				temp.minutes = this->minutes + b;
				temp.hours = this->hours;
				return temp;
			}
		}
		else
		{
			if (this->seconds + seconds % 60 <60)
			{
				temp.seconds = this->seconds + seconds % 60;
				if (this->minutes + b <= 59)
				{
					temp.minutes = this->minutes + b;
					temp.hours = this->hours;
					return temp;
				}
				else
				{
					temp.minutes = this->minutes + b - 60;
					temp.hours = ++this->hours;
					return temp;
				}
			}
			else
			{
				temp.seconds = this->seconds + seconds % 60 - 60;
				if (this->minutes + b <= 59)
				{
					temp.minutes = ++this->minutes + b;
					temp.hours = this->hours;
					return temp;
				}
				else
				{
					temp.minutes = ++this->minutes + b - 60;
					temp.hours = ++this->hours;
					return temp;
				}
			}
		}
	}
}

Time& Time::operator ++() // префиксный инкримент
{
	if (this->seconds != 59)
	{
		this->seconds++;
		return *this;
	}
	else
	{
		this->seconds = 0;
		if (this->minutes != 59)
		{
			this->minutes++;
			return *this;
		}
		else
		{
			this->minutes = 0;
			if (this->hours != 23)
			{
				this->hours++;
				return *this;
			}
			else
			{
				this->hours = 0;
				return *this;
			}
		}
	}
}

Time& Time:: operator ++(int value)
{
	Time temp(*this);
	if (this->seconds != 59)
	{
		this->seconds++;
		return *this;
	}
	else
	{
		this->seconds = 0;
		if (this->minutes != 59)
		{
			this->minutes++;
			return *this;
		}
		else
		{
			this->minutes = 0;
			if (this->hours != 23)
			{
				this->hours++;
				return *this;
			}
			else
			{
				this->hours = 0;
				return *this;
			}
		}
	}
}

Time& Time:: operator -- () // префиксный декремент
{
	if (this->seconds != 0)
	{
		this->seconds--;
		return *this;
	}
	else
	{
		this->seconds = 59;
		if (this->minutes != 0)
		{
			this->minutes--;
			return *this;
		}
		else
		{
			this->minutes = 59;
			if (this->hours != 0)
			{
				this->hours--;
				return *this;
			}
			else
			{
				this->hours = 23;
				return *this;
			}
			return *this;
		}
	}
}

Time& Time::operator -- (int value) // постфиксный декремент 
{
	Time temp(*this);
	if (this->seconds != 0)
	{
		this->seconds--;
		return *this;
	}
	else
	{
		this->seconds = 59;
		if (this->minutes != 0)
		{
			this->minutes--;
			return *this;
		}
		else
		{
			this->minutes = 59;
			if (this->hours != 0)
			{
				this->hours--;
				return *this;
			}
			else
			{
				this->hours = 23;
				return *this;
			}
			return *this;
		}
	}
}

bool Time::operator == (const Time& other)
{
	return this->seconds == other.seconds && this->minutes == other.minutes && this->hours == other.hours;
}

bool Time::operator != (const Time& other)
{
	return !(this->seconds == other.seconds && this->minutes == other.minutes && this->hours == other.hours);
}

bool Time::operator < (const Time& other)
{
	if (this->hours == other.hours && this->minutes == other.minutes)
	{
		return this->seconds < other.seconds;
	}
	else if (this->hours == other.hours)
	{
		return this->minutes < other.minutes;
	}
	else
	{
		return this->hours < other.hours;
	}
}

bool Time:: operator >(const Time& other)
{
	if (this->hours == other.hours && this->minutes == other.minutes)
	{
		return this->seconds > other.seconds;
	}
	else if (this->hours == other.hours)
	{
		return this->minutes > other.minutes;
	}
	else
	{
		return this->hours > other.hours;
	}
}

Time& Time::operator()(int seconds, int minutes, int hours)
{
	if (seconds >= 0 && seconds <= 59)
	{
		this->seconds = seconds;
	}
	else
	{
		throw "OPPS!";
	}
	if (minutes >= 0 && minutes <= 59)
	{
		this->minutes = minutes;
	}
	else
	{
		throw "OPPS!";
	}
	if (hours >= 0 && hours <= 23)
	{
		this->hours = hours;
	}
	else
	{
		throw "OPPS!";
	}
	return *this;
}


