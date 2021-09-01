#pragma once

class Date
{
public:
	Date();
	Date(const unsigned int day, const unsigned int month, const unsigned int year);

	void addDays(const unsigned int days);
	void removeDays(const unsigned int days);
	bool isLeapYear();
	unsigned int daysToXmas();
	unsigned int daysUntilNextYear();
	unsigned int daysUntil(const Date& date);
	bool isLaterThen(const Date& date);

	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;	
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	int daysEachMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	void setDay(const unsigned int day);
	void setMonth(const unsigned int month);
	void setYear(const unsigned int year);
};