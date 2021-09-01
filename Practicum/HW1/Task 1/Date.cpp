#include <iostream>
#include "Date.hpp"
using namespace std;

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 2000;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

void Date::addDays(const unsigned int days)
{	
	unsigned int currentYear = getYear();
	unsigned int currentMonth = getMonth();
	unsigned int currentDay = getDay();

	int daysRemaining = days;
	while (daysRemaining > 0)
	{
		if (currentDay == this->daysEachMonth[currentMonth-1])
		{
			currentDay = 1;
			if (currentMonth == 12)
			{
				currentMonth = 1;
				currentYear++;
				setYear(currentYear);
			}
			else
			{
				currentMonth++;
			}			
		}
		else
		{
			currentDay++;
		}

		daysRemaining--;
	}

	setYear(currentYear);
	setMonth(currentMonth);
	setDay(currentDay);
}

void Date::removeDays(const unsigned int days)
{
	unsigned int currentYear = getYear();
	unsigned int currentMonth = getMonth();
	unsigned int currentDay = getDay();

	int daysRemaining = days;
	while (daysRemaining > 0)
	{
		if (currentDay == 1)
		{
			if (currentMonth == 1)
			{
				currentMonth = 12;
				currentYear--;
				setYear(currentYear);
			}
			else
			{
				currentMonth--;
			}

			currentDay = this->daysEachMonth[currentMonth - 1];			
		}
		else
		{
			currentDay--;
		}

		daysRemaining--;
	}

	setYear(currentYear);
	setMonth(currentMonth);
	setDay(currentDay);
}

unsigned int Date::daysToXmas()
{
	const int xMasDay = 25;
	const int xMasMonth = 12;

	const unsigned int currentYear = getYear();
	const Date xMasCurrentYear = Date(xMasDay, xMasMonth, currentYear);

	if (!isLaterThen(xMasCurrentYear))
	{
		const Date xMasNextYear = Date(xMasDay, xMasMonth, currentYear + 1);
		return daysUntil(xMasNextYear);
	}

	return daysUntil(xMasCurrentYear);
}

unsigned int Date::daysUntilNextYear()
{
	const unsigned int currentYear = getYear();
	const Date newYear = Date(1, 1, currentYear + 1);

	return daysUntil(newYear);
}

unsigned int Date::daysUntil(const Date& date)
{
	if (!isLaterThen(date))
	{
		cout << "Date given is before or same as the curren date." << endl;
		return 0;
	}

	const unsigned int targetYear = date.getYear();
	const unsigned int targetMonth = date.getMonth();
	const unsigned int targetDay = date.getDay();

	const unsigned int currentYear = getYear();
	const unsigned int currentMonth = getMonth();
	const unsigned int currenttDay = getDay();

	unsigned int daysUntil = 0;
	Date tmpDate = Date(currenttDay, currentMonth, currentYear);
	while (!(tmpDate.getDay() == targetDay && tmpDate.getMonth() == targetMonth && tmpDate.getYear() == targetYear))
	{
		tmpDate.addDays(1);
		daysUntil++;
	}

	return daysUntil;
}


bool Date::isLaterThen(const Date& date)
{
	if (date.getYear() > getYear())
	{
		return true;
	}
	if (date.getYear() == getYear())
	{
		if (date.getMonth() > getMonth())
		{
			return true;
		}
		if (date.getMonth() == getMonth())
		{
			if (date.getDay() > getDay())
			{
				return true;
			}
		}
	}

	return false;
}

bool Date::isLeapYear()
{
	return ((getYear() % 4 == 0) && (getYear() % 100 != 0)) || (getYear() % 400 == 0);
}

void Date::setYear(const unsigned int year)
{
	if (year >= 1)
	{
		this->year = year;
		if (isLeapYear())
		{
			this->daysEachMonth[1] = 29;
		}
		else
		{
			this->daysEachMonth[1] = 28;
		}
	}
	else
	{
		cout << "Invalid year." << endl;
	}
}

void Date::setMonth(const unsigned int month)
{
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		cout << "Invalid month." << endl;
	}
}

void Date::setDay(const unsigned int day)
{
	if (day >= 1 && day <= this->daysEachMonth[getMonth() - 1])
	{
		this->day = day;
	}
	else
	{
		cout << "Invalid day." << endl;
	}
}

unsigned int Date::getYear() const
{
	return this->year;
}

unsigned int Date::getMonth() const
{
	return this->month;
}

unsigned int Date::getDay() const
{
	return this->day;
}